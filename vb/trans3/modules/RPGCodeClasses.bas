Attribute VB_Name = "RPGCodeClasses"
'=========================================================================
' All contents copyright 2004, Colin James Fitzpatrick (KSNiloc)
' All rights reserved. YOU MAY NOT REMOVE THIS NOTICE.
' Read LICENSE.txt for licensing info
'=========================================================================

'=========================================================================
' RPGCode classes
'=========================================================================

Option Explicit

'=========================================================================
' Globals
'=========================================================================
Public g_objects() As RPGCODE_CLASS_INSTANCE ' All objects
Public g_objHandleUsed() As Boolean          ' This handle used?

'=========================================================================
' An instance of a class
'=========================================================================
Private Type RPGCODE_CLASS_INSTANCE
    hClass As Long                          ' Handle to this class
    strInstancedFrom As String              ' It was instanced from this class
End Type

'=========================================================================
' A method
'=========================================================================
Private Type RPGCodeMethod
    name As String                          ' Name of the method
    line As Long                            ' Line method is defined on
    override As String                      ' Name used in inheritance situations
End Type

'=========================================================================
' A scope in a class
'=========================================================================
Private Type RPGCODE_CLASS_SCOPE
    strVars() As String                     ' Variables in this scope
    isDynamicArray() As Boolean             ' Are these vars dynamic arrays?
    methods() As RPGCodeMethod              ' Methods in this scope
End Type

'=========================================================================
' A class
'=========================================================================
Public Type RPGCODE_CLASS
    strName As String                       ' Name of this class
    scopePrivate As RPGCODE_CLASS_SCOPE     ' Private scope
    scopePublic As RPGCODE_CLASS_SCOPE      ' Public scope
    isInterface As Boolean                  ' Is an interface?
End Type

'=========================================================================
' Main data on classes (per program)
'=========================================================================
Private Type RPGCODE_CLASS_MAIN_DATA
    classes() As RPGCODE_CLASS              ' Classes this program can instance
    nestle() As Long                        ' Nestle of classes
    insideClass As Boolean                  ' Inside a class?
End Type

'=========================================================================
' An RPGCode program
'=========================================================================
Public Type RPGCodeProgram
    program() As String                     ' The program text
    methods() As RPGCodeMethod              ' Methods in this program
    programPos As Long                      ' Current position in program
    included(50) As String                  ' Included files
    Length As Long                          ' Length of program
    heapStack() As Long                     ' Stack of local heaps
    currentHeapFrame As Long                ' Current heap frame
    boardNum As Long                        ' The corresponding board index of the program (default to 0)
    threadID As Long                        ' The thread id (-1 if not a thread)
    compilerStack() As String               ' Stack used by 'compiled' programs
    currentCompileStackIdx As Long          ' Current index of compilerStack
    looping As Boolean                      ' Is a multitask program looping?
    autoLocal As Boolean                    ' Force implicitly created variables to the local scope?
    classes As RPGCODE_CLASS_MAIN_DATA      ' Class stuff
    strict As Boolean                       ' Is the program strict?
End Type

'=========================================================================
' Check a method override name
'=========================================================================
Public Function checkOverrideName(ByRef theClass As RPGCODE_CLASS, ByVal theMethod As String) As String

    ' Capitalize theMethod
    theMethod = UCase$(Trim$(theMethod))

    ' Loop variables
    Dim scopeIdx As Long, idx As Long

    ' A scope
    Dim scope As RPGCODE_CLASS_SCOPE

    ' Loop over each scope
    For scopeIdx = 0 To 1
        ' Get this scope
        If (scopeIdx = 0) Then
            scope = theClass.scopePublic
        Else
            scope = theClass.scopePrivate
        End If
        ' Loop over each of its methods
        For idx = 0 To UBound(scope.methods)
            ' Found the method
            If (scope.methods(idx).name = theMethod) Then
                ' Check for an override
                If (LenB(scope.methods(idx).override)) Then
                    ' Return this
                    checkOverrideName = scope.methods(idx).override
                End If
                ' Either way, bail
                Exit Function
            End If
        Next idx
    Next scopeIdx

End Function

'=========================================================================
' Determine if something is an object
'=========================================================================
Public Function isObject(ByVal hClass As Long, ByRef prg As RPGCodeProgram) As Boolean

    On Error Resume Next

    ' Return if it's an object
    isObject = (LenB(g_objects(hClass).strInstancedFrom))

End Function

'=========================================================================
' Add a class to a program
'=========================================================================
Public Sub addClassToProgram(ByRef theClass As RPGCODE_CLASS, ByRef prg As RPGCodeProgram)

    On Error Resume Next

    Dim idx As Long         ' Loop var
    Dim pos As Long         ' Position to use

    ' Make pos void
    pos = -1

    ' Check all classes already in program
    For idx = 0 To UBound(prg.classes.classes)
        If (theClass.strName = prg.classes.classes(idx).strName) Then
            ' Already in program
            Exit Sub

        ElseIf (LenB(prg.classes.classes(idx).strName) = 0) Then
            ' Free space
            If (pos = -1) Then
                pos = idx
            End If

        End If
    Next idx

    If (pos = -1) Then
        ' No free spaces
        ReDim Preserve prg.classes.classes(UBound(prg.classes.classes) + 1)
        pos = UBound(prg.classes.classes)
    End If

    ' Write in the data
    prg.classes.classes(pos) = theClass

End Sub

'=========================================================================
' Read all data on classes from a program
'=========================================================================
Public Sub spliceUpClasses(ByRef prg As RPGCodeProgram)

    Const SCOPE_PUBLIC = 0      ' Public scope
    Const SCOPE_PRIVATE = 1     ' Private scope

    Dim lineIdx As Long         ' Current line
    Dim inClass As Boolean      ' Inside a class?
    Dim scope As Long           ' Current scope (public or private)
    Dim cmd As String           ' The command
    Dim opening As Boolean      ' Looking for { bracket?
    Dim depth As Long           ' Depth in class
    Dim classIdx As Long        ' Current class
    Dim inStruct As Boolean     ' In a structure?
    Dim methodHere As Boolean   ' Method declared on this line?
    Dim ignoreCheck As Long     ' Ignore a check of some kind

    ' Some vars for splitting up the line
    Dim parts() As String, delimiters() As String, chars(1) As String

    ' See which position to start at in the classes array
    On Error GoTo error
    classIdx = UBound(prg.classes.classes)
    On Error Resume Next

    ' Loop over each line
    For lineIdx = 0 To UBound(prg.program)

        If (LeftB$(LCase$(prg.program(lineIdx)), 12) = "global") Then

            ' Define a var
            Dim constParts() As String, constDelimiters(0) As String, uD() As String
            constDelimiters(0) = " "
            constParts = multiSplit(prg.program(lineIdx), constDelimiters, uD, True, True)

            ' Check for correct number of parts
            If (UBound(constParts) = 2) Then

                ' Only define if it's not existent
                If ( _
                        (Not (numVarExists(constParts(1), globalHeap)) And _
                        (Not (numVarExists(constParts(1), prg.heapStack(prg.currentHeapFrame)))))) _
                            Then

                    ' Create the var
                    Dim retval As RPGCODE_RETURN
                    Call DoSingleCommand(constParts(1) & "=" & constParts(2), prg, retval)

                End If

                ' Don't run this line
                cmd = vbNullString

            End If

        Else

            ' Get the command on this line
            cmd = UCase$(GetCommandName(prg.program(lineIdx)))

        End If

        ignoreCheck = ignoreCheck - 1

        If (opening And inClass And (cmd = "OPENBLOCK")) Then
            ' Found first { bracket
            opening = False
            depth = depth + 1

        ElseIf (inClass And (Not (opening)) And (cmd = "OPENBLOCK")) Then
            ' Getting deeper
            depth = depth + 1

        ElseIf (inClass And (Not (opening)) And (cmd = "CLOSEBLOCK")) Then
            ' Coming out
            depth = depth - 1
            ' Check if we're completely out
            If (depth = 0) Then
                If (UBound(parts) >= 1) Then
                    ' Inheritance here
                    Dim inheritIdx As Long
                    For inheritIdx = 1 To UBound(parts)
                        If (inheritIdx <> 1) Then
                            If (delimiters(inheritIdx - 1) = ":") Then
                                ' Syntax error
                                Call debugger("Syntax error: " & prg.program(lineIdx))
                            End If
                        End If
                        Dim toInherit As String
                        toInherit = Trim$(parts(inheritIdx))
                        If Not (canInstanceClass(toInherit, prg)) Then
                            Call debugger("Base class " & toInherit & " not found-- " & prg.program(lineIdx))
                        Else
                            ' Make toInherit caps
                            toInherit = UCase$(toInherit)
                            ' Loop over every class it could be
                            Dim idx As Long, theClass As RPGCODE_CLASS
                            For idx = 0 To UBound(prg.classes.classes)
                                If (prg.classes.classes(idx).strName = toInherit) Then
                                    ' Found it!
                                    theClass = prg.classes.classes(idx)
                                    ' Make sure it's an interface if this class is an interface
                                    If ((Not (theClass.isInterface)) And (prg.classes.classes(classIdx).isInterface)) Then
                                        ' Not an interface
                                        Call debugger("Interfaces can only inherit other interfaces! -- " & prg.program(lineIdx))
                                        Exit Sub
                                    End If
                                    ' Break
                                    Exit For
                                End If
                            Next idx
                            ' For each scope
                            Dim scopeIdx As Long
                            For scopeIdx = SCOPE_PUBLIC To SCOPE_PRIVATE
                                ' Get this scope
                                Dim theScope As RPGCODE_CLASS_SCOPE
                                If (scopeIdx = SCOPE_PUBLIC) Then
                                    theScope = theClass.scopePublic
                                Else
                                    theScope = theClass.scopePrivate
                                End If
                                ' Loop over each method
                                If Not (theClass.isInterface) Then
                                    For idx = 0 To UBound(theScope.methods)
                                        If (scopeIdx = SCOPE_PUBLIC) Then
                                            Call addMethodToScope(prg.classes.classes(classIdx).strName, theScope.methods(idx).name, prg, prg.classes.classes(classIdx).scopePublic, toInherit, , , True)
                                        Else
                                            Call addMethodToScope(prg.classes.classes(classIdx).strName, theScope.methods(idx).name, prg, prg.classes.classes(classIdx).scopePrivate, toInherit, , , True)
                                        End If
                                    Next idx
                                Else
                                    ' Inheriting class should implement an interface's methods
                                    For idx = 0 To UBound(theScope.methods)
                                        If (scopeIdx = SCOPE_PUBLIC) Then
                                            Call addMethodToScope(prg.classes.classes(classIdx).strName, theScope.methods(idx).name, prg, prg.classes.classes(classIdx).scopePublic)
                                        Else
                                            Call addMethodToScope(prg.classes.classes(classIdx).strName, theScope.methods(idx).name, prg, prg.classes.classes(classIdx).scopePrivate)
                                        End If
                                    Next idx
                                End If
                                ' Loop over each var
                                For idx = 0 To UBound(theScope.strVars)
                                    If (InStr(1, prg.program(lineIdx), "[")) Then
                                        ' It's an array
                                        If (scopeIdx = 1) Then
                                            Call addArrayToScope(theScope.strVars(idx), prg.classes.classes(classIdx).scopePrivate)
                                        Else
                                            Call addArrayToScope(theScope.strVars(idx), prg.classes.classes(classIdx).scopePublic)
                                        End If
                                    Else
                                        If (scopeIdx = 1) Then
                                            Call addVarToScope(theScope.strVars(idx), prg.classes.classes(classIdx).scopePrivate)
                                        Else
                                            Call addVarToScope(theScope.strVars(idx), prg.classes.classes(classIdx).scopePublic)
                                        End If
                                    End If
                                Next idx
                            Next scopeIdx
                        End If
                    Next inheritIdx
                End If
                inClass = False
                inStruct = False
                scope = vbNullString
            End If

        ElseIf (cmd = "CLASS" Or cmd = "STRUCT" Or cmd = "INTERFACE") Then

            ' Found a class

            Dim oldParts() As String, strName As String
            oldParts = parts
            chars(0) = ":"
            chars(1) = ","
            parts = multiSplit(UCase$(prg.program(lineIdx)), chars, delimiters, False)
            strName = GetMethodName(Trim$(parts(0)))

            If (canInstanceClass(strName, prg)) Then

                ' Restore old parts
                parts = oldParts

            Else

                depth = 0
                ignoreCheck = 0
                methodHere = False
                inClass = True
                opening = True
                classIdx = classIdx + 1
                ReDim Preserve prg.classes.classes(classIdx)
                ReDim prg.classes.classes(classIdx).scopePrivate.methods(0)
                ReDim prg.classes.classes(classIdx).scopePrivate.strVars(0)
                ReDim prg.classes.classes(classIdx).scopePrivate.isDynamicArray(0)
                ReDim prg.classes.classes(classIdx).scopePublic.methods(0)
                ReDim prg.classes.classes(classIdx).scopePublic.strVars(0)
                ReDim prg.classes.classes(classIdx).scopePublic.isDynamicArray(0)
                prg.classes.classes(classIdx).isInterface = (cmd = "INTERFACE")
                prg.classes.classes(classIdx).strName = strName

                If (cmd = "STRUCT") Then
                    ' It's a structure, default to public visibility
                    scope = SCOPE_PUBLIC
                    inStruct = True
                ElseIf (cmd = "INTERFACE") Then
                    ' Default to public in interfaces
                    scope = SCOPE_PUBLIC
                    inStruct = False
                Else
                    ' Default to private in classes
                    scope = SCOPE_PRIVATE
                    inStruct = False
                End If

            End If

        ElseIf (inClass And (LenB(scope) <> 0) And (LenB(prg.program(lineIdx)) <> 0) And (Right$(prg.program(lineIdx), 1) <> ":") And (depth = 1)) Then
            If (InStrB(1, prg.program(lineIdx), "(")) Then
                ' Found a method
                If Not (inStruct) Then
                    ' Check if the method is right here
                    Dim methodCheckIdx As Long
                    methodCheckIdx = lineIdx
                    Do
                        methodCheckIdx = methodCheckIdx + 1
                        If (LenB(prg.program(methodCheckIdx))) Then
                            ' Check if the method is here
                            methodHere = (prg.program(methodCheckIdx) = "{")
                            ignoreCheck = methodCheckIdx - lineIdx + 2 ' + 2 to compensate for
                                                                       ' block opening and closing
                            ' Leave this loop
                            Exit Do
                        End If
                    Loop
                    If (scope = SCOPE_PRIVATE) Then
                        Call addMethodToScope(prg.classes.classes(classIdx).strName, prg.program(lineIdx), prg, prg.classes.classes(classIdx).scopePrivate, , (prg.classes.classes(classIdx).isInterface))
                    Else
                        Call addMethodToScope(prg.classes.classes(classIdx).strName, prg.program(lineIdx), prg, prg.classes.classes(classIdx).scopePublic, , (prg.classes.classes(classIdx).isInterface))
                    End If
                Else
                    Call debugger("Methods are not valid in structures-- " & prg.program(lineIdx))
                End If
            Else
                ' Found a variable
                If Not (inStruct) Then
                    If (scope = SCOPE_PUBLIC) Then
                        ' Issue a warning
                        Call debugger("You seem to be exposing variables from your class--this defeats abstraction by circumventing encapsulation--you may want to reconsider this choice of action; " & prg.program(lineIdx))
                    End If
                End If
                If (InStrB(1, prg.program(lineIdx), "[")) Then
                    ' It's an array
                    If (scope = SCOPE_PRIVATE) Then
                        Call addArrayToScope(prg.program(lineIdx), prg.classes.classes(classIdx).scopePrivate)
                    Else
                        Call addArrayToScope(prg.program(lineIdx), prg.classes.classes(classIdx).scopePublic)
                    End If
                Else
                    If (scope = SCOPE_PRIVATE) Then
                        Call addVarToScope(prg.program(lineIdx), prg.classes.classes(classIdx).scopePrivate)
                    Else
                        Call addVarToScope(prg.program(lineIdx), prg.classes.classes(classIdx).scopePublic)
                    End If
                End If
            End If

        End If

        If ((inClass) And ((depth = 1) Or (depth = 0))) Then

            Select Case LCase$(Trim$(prg.program(lineIdx)))

                Case "private:"
                    ' Found start of private scope
                    methodHere = False
                    If (inStruct) Then
                        scope = -1
                    Else
                        scope = SCOPE_PRIVATE
                    End If

                Case "public:"
                    ' Found start of public scope
                    methodHere = False
                    If (inStruct) Then
                        scope = -1
                    Else
                        scope = SCOPE_PUBLIC
                    End If

            End Select

            If (scope = -1) Then
                ' No scope in structures
                Call debugger("Scope is not valid in structures-- " & prg.program(lineIdx))
                scope = SCOPE_PUBLIC
            End If

            ' Make sure this line isn't run
            If Not (methodHere) Then
                prg.program(lineIdx) = vbNullString
            End If

        End If

        If ((depth = 1) And (ignoreCheck = 0)) Then
            methodHere = False
        End If

    Next lineIdx

    Exit Sub

error:

    ' Start at position 0
    classIdx = -1

End Sub

'=========================================================================
' Add an array to a scope
'=========================================================================
Private Sub addArrayToScope(ByVal theVar As String, ByRef scope As RPGCODE_CLASS_SCOPE)

    On Error Resume Next

    Dim toParse As String           ' Text to parse
    Dim variableType As String      ' Type of var
    Dim start As Long               ' First [
    Dim tEnd As Long                ' Last ]
    Dim variableName As String      ' Name of var
    Dim parseArrayD() As String     ' Dimensions
    Dim idx As Long                 ' Loop var

    ' Set toParse to the text passed in
    toParse = Trim$(theVar)

    ' Grab the variable's type (! or $)
    variableType = Right$(toParse, 1)
    If (variableType <> "!" And variableType <> "$") Then
        ' It's an object
        variableType = vbNullString
    End If

    ' See where the first [ is
    start = InStr(1, toParse, "[")

    ' Grab the variable's name
    variableName = Mid$(toParse, 1, start - 1)

    ' Find the last ]
    tEnd = InStr(1, StrReverse(toParse), "]")
    tEnd = Len(toParse) - tEnd + 1

    ' Just keep what's inbetween the two
    toParse = Trim$(Mid$(toParse, start + 1, tEnd - start - 1))

    ' Check if it's a dynamic array
    If (LenB(toParse) = 0) Then

        ' Add var to the scope as is
        Call addVarToScope(variableName & variableType, scope, True)
        Exit Sub

    End If

    ' Split it at '][' (bewteen elements)
    parseArrayD = Split(toParse, "][")

    ' Add the vars
    On Error GoTo error
    ReDim x(UBound(parseArrayD)) As Long
    ReDim size(UBound(parseArrayD)) As Long
    For idx = 0 To UBound(size)
        size(idx) = CLng(parseArrayD(idx))
    Next idx
    Call getVarsFromArray(0, size, x, scope, variableName, variableType)

    Exit Sub

error:

    ' They are attempting to add a map: add as regular variable
    Call addVarToScope(theVar, scope)

End Sub

'=========================================================================
' Add a variable to a scope
'=========================================================================
Private Sub addVarToScope(ByVal theVar As String, ByRef scope As RPGCODE_CLASS_SCOPE, Optional ByVal isDynamicArray As Boolean)

    On Error Resume Next

    Dim origName As String  ' Name in original case
    Dim idx As Long         ' Loop var
    Dim pos As Long         ' Position we're using

    ' Check for some idiot trying to send an inital value
    theVar = Trim$(theVar)
    Dim spacePos As Long
    spacePos = InStr(1, theVar, " ")
    If (spacePos) Then
        ' Check if they really were stupid enough to set an inital value:
        If (InStrB(1, theVar, "=")) Then
            Call debugger("You cannot set initial values in abstract types, use the constructor to acomplish this-- " & theVar)
        End If
        ' Keep only until first space
        theVar = Left$(theVar, spacePos - 1)
    End If

    ' Make theVar all caps
    origName = theVar
    theVar = UCase$(theVar)

    ' Default to ! if no type def character
    Dim tdc As String
    tdc = RightB$(theVar, 2)
    If ((tdc <> "!") And (tdc <> "$")) Then
        ' Add the !
        theVar = theVar & "!"
    End If

    ' Make pos void
    pos = -1

    ' Loop over all vars in this scope
    For idx = 0 To UBound(scope.strVars)
        If (scope.strVars(idx) = theVar) Then
            Call debugger("Illegal redefinition of variable " & origName)
            Exit Sub

        ElseIf (LenB(scope.strVars(idx)) = 0) Then
            If (pos = -1) Then
                ' Free position!
                pos = idx
            End If

        End If
    Next idx

    If (pos = -1) Then
        ' Didn't find a position
        ReDim Preserve scope.strVars(UBound(scope.strVars) + 1)
        ReDim Preserve scope.isDynamicArray(UBound(scope.isDynamicArray) + 1)
        pos = UBound(scope.strVars)
    End If

    ' Write in the data
    scope.strVars(pos) = theVar
    scope.isDynamicArray(pos) = isDynamicArray

End Sub

'=========================================================================
' Add a method to a scope
'=========================================================================
Public Sub addMethodToScope(ByVal theClass As String, ByVal Text As String, ByRef prg As RPGCodeProgram, ByRef scope As RPGCODE_CLASS_SCOPE, Optional ByVal overrideName As String = vbNullString, Optional ByVal needNotExist As Boolean, Optional ByVal internalClass As Boolean, Optional ByVal noErrorOnRedefine As Boolean)

    On Error Resume Next

    Dim theLine As Long         ' Line method starts on
    Dim methodName As String    ' Name of method
    Dim origName As String      ' Name of method in orig case
    Dim idx As Long             ' Loop variable
    Dim pos As Long             ' Pos we're using

    If (LenB(Text) = 0) Then
        ' No text, no method, no wasted time
        Exit Sub
    End If

    If Not (internalClass) Then

        ' Get the method's name
        origName = GetMethodName(removeClassName(Text))
        If (LenB(overrideName) = 0) Then
            methodName = UCase$(theClass) & "::" & UCase$(origName)
        Else
            methodName = overrideName & "::" & UCase$(origName)
        End If

        ' Get line method starts on
        theLine = getMethodLine(methodName, prg)

        ' Check if we errored out
        If ((theLine = -1) And (Not (needNotExist))) Then
            Call debugger("Could not find method " & origName & " -- " & Text)
            Exit Sub
        ElseIf ((theLine <> -1) And (needNotExist)) Then
            Call debugger("Interfaces should not implement methods -- will be implemented by the inheriting class -- " & Text)
            Exit Sub
        End If

    Else

        ' Use the text passed in
        origName = Text

    End If

    ' Make pos void
    pos = -1

    ' Find an open position
    For idx = 0 To UBound(scope.methods)
        If (scope.methods(idx).name = UCase$(origName)) Then
            ' Illegal redifinition
            If Not (noErrorOnRedefine) Then
                Call debugger("Illegal redefinition of method " & origName & " -- " & Text)
            End If
            Exit Sub

        ElseIf (LenB(scope.methods(idx).name) = 0) Then
            If (pos = -1) Then
                ' Found a spot
                pos = idx
            End If
        End If
    Next idx

    ' Check if we found a spot
    If (pos = -1) Then
        ' Didn't find one
        ReDim Preserve scope.methods(UBound(scope.methods) + 1)
        pos = UBound(scope.methods)
    End If

    ' Add in the data
    scope.methods(pos).line = theLine
    scope.methods(pos).name = UCase$(origName)
    scope.methods(pos).override = overrideName

End Sub

'=========================================================================
' Remove class name from a function
'=========================================================================
Private Function removeClassName(ByVal Text As String) As String

    On Error Resume Next

    Dim idx As Long         ' For loop var
    Dim char As String * 2  ' Characters

    For idx = 1 To Len(Text)
        ' Get a character
        char = Mid$(Text, idx, 2)
        ' Check if it's the scope operator
        If (char = "::") Then
            ' Found it
            removeClassName = Mid$(Text, idx + 2)
            Exit Function
        End If
    Next idx

    ' Didn't find it
    removeClassName = Text

End Function

'=========================================================================
' Initiate the class system
'=========================================================================
Public Sub initRPGCodeClasses()
    ReDim g_objHandleUsed(250)
    ReDim g_objects(250)
    Call newHandle
End Sub

'=========================================================================
' Kill a handle number
'=========================================================================
Private Sub killHandle(ByVal hClass As Long)

    On Error Resume Next

    If (UBound(g_objHandleUsed) >= hClass) Then
        ' Write in the data
        g_objHandleUsed(hClass) = False
    End If

End Sub

'=========================================================================
' Get a new handle number
'=========================================================================
Private Function newHandle() As Long

    On Error Resume Next

    Dim idx As Long     ' Loop var
    Dim pos As Long     ' Position to use

    ' Make pos void
    pos = -1

    ' Loop over each handle
    For idx = 0 To UBound(g_objHandleUsed)
        If Not (g_objHandleUsed(idx)) Then
            ' Free position
            pos = idx
            Exit For
        End If
    Next idx

    If (pos = -1) Then
        ' Didn't find a spot
        pos = UBound(g_objHandleUsed) + 1
        ReDim Preserve g_objHandleUsed(UBound(g_objHandleUsed) + 250)
    End If

    ' Write in the data
    g_objHandleUsed(pos) = True
    newHandle = pos

End Function

'=========================================================================
' Check if a program can instance a class
'=========================================================================
Public Function canInstanceClass(ByVal theClass As String, ByRef prg As RPGCodeProgram) As Boolean

    On Error Resume Next

    Dim idx As Long     ' Loop var

    ' Loop over each class we can instance
    theClass = UCase$(theClass)
    For idx = 0 To UBound(prg.classes.classes)
        If (prg.classes.classes(idx).strName = theClass) Then
            ' Yes, we can
            canInstanceClass = True
            Exit Function
        End If
    Next idx

    ' If we get here, we can't instance this class

End Function

'=========================================================================
' Determine if a variable is a member of a class
'=========================================================================
Public Function isVarMember(ByVal var As String, ByVal hClass As Long, ByRef prg As RPGCodeProgram, Optional ByVal outside As Boolean) As Boolean

    On Error Resume Next

    Dim idx As Long, scopeIdx As Long   ' Loop var
    Dim theClass As RPGCODE_CLASS       ' The class
    Dim scope As RPGCODE_CLASS_SCOPE    ' A scope

    ' Get the class
    theClass = getClass(hClass, prg)

    If (theClass.strName = "INVALID") Then
        ' Class doesn't exist!
        Exit Function
    End If

    ' Make the var all caps
    var = Trim$(UCase$(var))

    ' Get location of first "[" character
    Dim istr As Long, anArray As String
    istr = InStr(1, var, "[")
    If (istr) Then
        ' Get the var without its brackets
        anArray = Left$(var, istr - 1) & Right$(var, 1)
    End If

    ' For each scope
    For scopeIdx = 0 To 1

        ' Get the scope
        If (scopeIdx = 1) Then
            ' Private scope
            scope = theClass.scopePrivate
        Else
            ' Public scope
            scope = theClass.scopePublic
        End If

        ' For each var within that scope
        For idx = 0 To UBound(scope.strVars)

            If (scope.isDynamicArray(idx)) Then
                ' Check this dynamic array
                If (istr) Then
                    If (scope.strVars(idx) = anArray) Then
                        ' It is a member
                        isVarMember = True
                        Exit Function
                    End If
                End If

            ElseIf (scope.strVars(idx) = var) Then
                ' Found it
                isVarMember = True
                Exit Function

            End If

        Next idx

        If (outside) Then
            ' Don't check private scope
            Exit Function
        End If

    Next scopeIdx

    ' It we get here, then this variable is not a member of the class

End Function

'=========================================================================
' Determine if a method is a member of a class
'=========================================================================
Public Function isMethodMember(ByVal methodName As String, ByVal hClass As Long, ByRef prg As RPGCodeProgram, Optional ByVal outside As Boolean) As Boolean

    On Error Resume Next

    Dim idx As Long, scopeIdx As Long   ' Loop var
    Dim theClass As RPGCODE_CLASS       ' The class
    Dim scope As RPGCODE_CLASS_SCOPE    ' A scope

    ' Get the class
    theClass = getClass(hClass, prg)

    If (theClass.strName = "INVALID") Then
        ' Class doesn't exist!
        Exit Function
    End If

    ' Make the method name all caps
    methodName = Trim$(UCase$(methodName))

    ' For each scope
    For scopeIdx = 0 To 1
        ' Get the scope
        If (scopeIdx = 1) Then
            ' Private scope
            scope = theClass.scopePrivate
        Else
            ' Public scope
            scope = theClass.scopePublic
        End If
        ' For each method within that scope
        For idx = 0 To UBound(scope.methods)
            If (scope.methods(idx).name = methodName) Then
                ' Found it
                isMethodMember = True
                Exit Function
            End If
        Next idx
        If (outside) Then
            ' Don't check private scope
            Exit Function
        End If
    Next scopeIdx

    ' It we get here, then this method is not a member of the class

End Function

'=========================================================================
' Get the *real* name of a variable
'=========================================================================
Public Function getObjectVarName(ByVal theVar As String, ByVal hClass As Long) As String

    On Error Resume Next

    ' Return the new name
    getObjectVarName = CStr(hClass) & "::" & theVar

End Function

'=========================================================================
' Decrease the nestle
'=========================================================================
Public Sub decreaseNestle(ByRef prg As RPGCodeProgram)

    On Error Resume Next

    ' Shrink the nestle array
    ReDim Preserve prg.classes.nestle(UBound(prg.classes.nestle) - 1)

    If (UBound(prg.classes.nestle) = 0) Then
        ' Flag we're out of all classes
        prg.classes.insideClass = False
    End If

End Sub

'=========================================================================
' Get value on top of nestle stack
'=========================================================================
Public Function topNestle(ByRef prg As RPGCodeProgram) As Long

    On Error Resume Next

    ' Return the value
    topNestle = prg.classes.nestle(UBound(prg.classes.nestle))

End Function

'=========================================================================
' Increase nestle
'=========================================================================
Public Sub increaseNestle(ByVal push As Long, ByRef prg As RPGCodeProgram)

    On Error Resume Next

    ' Enlarge the nestle array
    ReDim Preserve prg.classes.nestle(UBound(prg.classes.nestle) + 1)

    ' Push on the value
    prg.classes.nestle(UBound(prg.classes.nestle)) = push

    ' Flag we're inside a class
    prg.classes.insideClass = True

End Sub

'=========================================================================
' Get a class from an instance of it
'=========================================================================
Public Function getClass(ByVal hClass As Long, ByRef prg As RPGCodeProgram) As RPGCODE_CLASS

    On Error Resume Next

    Dim strClass As String  ' The class' name
    Dim idx As Long         ' Loop var

    ' Get the class' name
    strClass = g_objects(hClass).strInstancedFrom

    ' Loop over every class it could be
    For idx = 0 To UBound(prg.classes.classes)
        If (prg.classes.classes(idx).strName = strClass) Then
            ' Found it!
            getClass = prg.classes.classes(idx)
            Exit Function
        End If
    Next idx

    ' If we get here, it wasn't a valid class
    getClass.strName = "INVALID"

End Function

'=========================================================================
' Clear an object
'=========================================================================
Private Sub clearObject(ByRef object As RPGCODE_CLASS_INSTANCE, ByRef prg As RPGCodeProgram)

    On Error Resume Next

    Dim idx As Long, scopeIdx As Long           ' Loop var
    Dim theClass As RPGCODE_CLASS               ' The class
    Dim scope As RPGCODE_CLASS_SCOPE            ' A scope
    Dim oldDebug As Long, oldError As String    ' Old stuff

    ' Get the class
    theClass = getClass(object.hClass, prg)

    If (theClass.strName = "INVALID") Then
        ' Class doesn't exist!
        Exit Sub
    End If

    ' Get old values
    oldDebug = debugYN
    oldError = errorBranch

    ' Clear values
    debugYN = 0
    oldError = vbNullString

    ' For each scope
    For scopeIdx = 0 To 1
        ' Get the scope
        If (scopeIdx = 0) Then
            ' Private scope
            scope = theClass.scopePrivate
        Else
            ' Public scope
            scope = theClass.scopePublic
        End If
        ' For each var within that scope
        For idx = 0 To UBound(scope.strVars)
            ' Kill the variable
            Call KillRPG("Kill(" & getObjectVarName(scope.strVars(idx), object.hClass) & ")", prg)
        Next idx
    Next scopeIdx

    ' Restore values
    debugYN = oldDebug
    errorBranch = oldError

End Sub

'=========================================================================
' Create a new instance of a class
'=========================================================================
Public Function createRPGCodeObject(ByVal theClass As String, ByRef prg As RPGCodeProgram, ByRef constructParams() As String, ByVal noParams As Boolean) As Long

    On Error Resume Next

    Dim hClass As Long              ' Handle to use
    Dim retval As RPGCODE_RETURN    ' Return value

    ' Check if we can instance this class
    If (canInstanceClass(theClass, prg)) Then
        ' Create a new handle
        hClass = newHandle()
        ' Make sure we have enough room in the instances array
        If (UBound(g_objects) < hClass) Then
            ' Enlarge the array
            ReDim Preserve g_objects(hClass + 250)
        End If
        ' Write in the data
        g_objects(hClass).strInstancedFrom = UCase$(theClass)
        g_objects(hClass).hClass = hClass
        ' Clear the object
        Call clearObject(g_objects(hClass), prg)
        ' Call the constructor
        Call callObjectMethod(hClass, theClass & createParams(constructParams, noParams), prg, retval, theClass)
    End If

    ' Return a handle to the class
    createRPGCodeObject = hClass

End Function

'=========================================================================
' Grab vars from an array
'=========================================================================
Private Sub getVarsFromArray(ByVal depth As Long, ByRef size() As Long, ByRef x() As Long, ByRef scope As RPGCODE_CLASS_SCOPE, ByVal prefix As String, ByVal postFix As String)

    On Error Resume Next

    Dim dimIdx As Long      ' Dimension index
    Dim theVar As String    ' The variable

    For x(depth) = 0 To size(depth)
        If (depth <= UBound(size)) Then
            Call getVarsFromArray(depth + 1, size, x, scope, prefix, postFix)
        Else
            theVar = vbNullString
            For dimIdx = 0 To UBound(size)
                theVar = theVar & "[" & CStr(x(dimIdx)) & "]"
            Next dimIdx
            Call addVarToScope(prefix & theVar & postFix, scope)
        End If
    Next x(depth)

End Sub

'=========================================================================
' Create a string for params from an array
'=========================================================================
Private Function createParams(ByRef params() As String, ByVal noParams As Boolean) As String

    On Error Resume Next

    Dim idx As Long     ' Loop var

    ' Begin the return string
    createParams = "("

    If Not (noParams) Then
        ' Loop over each param
        For idx = 0 To UBound(params)
            createParams = createParams & params(idx) & ","
        Next idx
        createParams = Left$(createParams, Len(createParams) - 1)
    End If

    ' Finish the return string
    createParams = createParams & ")"

End Function

'=========================================================================
' Splice up a line for object things
'=========================================================================
Public Function spliceForObjects(ByVal Text As String, ByRef prg As RPGCodeProgram) As String

    On Error Resume Next

    Dim arrayDepth As Long          ' Depth in arrays
    Dim value As String             ' Value of function
    Dim retval As RPGCODE_RETURN    ' Return value
    Dim begin As Long               ' Char to begin at
    Dim char As String              ' Character(s)
    Dim spacesOK As Boolean         ' Spaces are okay?
    Dim cLine As String             ' Command line
    Dim object As String            ' Object name
    Dim depth As Long               ' Depth
    Dim ignore As Boolean           ' In quotes?
    Dim lngEnd As Long              ' End of text
    Dim start As Long               ' Start of object manipulation
    Dim hClassDbl As Double         ' Handle to a class (double)
    Dim hClass As Long              ' Handle to a class
    Dim var As Boolean              ' Variable?
    Dim outside As Boolean          ' Calling from outside class?
    Dim cmdName As String           ' Command's name
    Dim Length As Long              ' Length of the text
    Dim a As Long                   ' Loop var

    ' Get location of first ->
    begin = inStrOutsideQuotes(1, Text, "->")

    If (begin = 0) Then
        ' Contains no object manipulation
        spliceForObjects = Text
        Exit Function
    End If

    ' Get the length of the text
    Length = Len(Text)

    ' Loop over each charater, forwards
    For a = (begin + 2) To Length
        ' Get a character
        char = Mid$(Text, a, 1)
        Select Case char

            Case "!", "$", "-"
                ' Could be a public var
                If (depth = 0 And (Not (ignore)) And (arrayDepth = 0)) Then
                    If (char <> "-") Then
                        lngEnd = a
                    Else
                        lngEnd = a - 1
                    End If
                    var = True
                    Exit For
                End If

            Case "("
                If Not (ignore) Then
                    ' Increase depth
                    depth = depth + 1
                End If

            Case ")"
                If Not (ignore) Then
                    ' Decrease depth
                    depth = depth - 1
                    If (depth = 0) Then
                        lngEnd = a
                        Exit For
                    End If
                End If

            Case "["
                ' Entering array
                arrayDepth = arrayDepth + 1

            Case "]"
                ' Leaving array
                arrayDepth = arrayDepth - 1

            Case """"
                ' Found a quote
                ignore = Not (ignore)

        End Select
    Next a

    ' Record the method's command line
    cLine = ParseRPGCodeCommand(Trim$(Mid$(Text, begin + 2, lngEnd - begin - 1)), prg)
    If Not (var) Then
        cmdName = UCase$(GetCommandName(cLine))
    Else
        ' Parse the var
        cLine = parseArray(cLine, prg)
        Dim rcl As String
        rcl = RightB$(cLine, 2)
        If ((rcl <> "!") And (rcl <> "$")) Then
            ' Assume object
            cLine = cLine & "!"
        End If
    End If

    ' Flag we're not in quotes
    ignore = False

    ' Flag that spaces are okay
    spacesOK = True

    ' Make sure start has a value
    start = 1

    ' Set array depth at 0
    arrayDepth = 0

    ' Loop over each charater, backwards
    For a = (begin - 1) To 1 Step -1
        ' Get a character
        char = Mid$(Text, a, 1)
        If ((spacesOK) And (char = " ")) Then
            ' Alter char
            char = vbNullString
            ' Flag spaces are no longer okay
            spacesOK = False
        End If
        Select Case char

            Case " ", ",", "#", "=", "<", ">", "+", "-", ";", "*", "\", "/", "^", "(", ")", _
            "%", "`", "|", "&", "~"
                ' It's a divider
                If ((Not (ignore)) And (arrayDepth = 0)) Then
                    start = a + 1
                    Exit For
                End If

            Case """"
                ' Found a quote
                ignore = Not (ignore)
                spacesOK = False

            Case "["
                ' Entering array
                arrayDepth = arrayDepth + 1

            Case "]"
                ' Leaving array
                arrayDepth = arrayDepth - 1

            Case Else
                ' Not a space, so they aren't okay anymore
                spacesOK = False

        End Select
    Next a

    ' Record the object
    object = parseArray(UCase$(Trim$(Mid$(Text, start, begin - start))), prg)
    If (LenB(object) = 0) Then object = GetWithPrefix()

    ' Get its handle
    Dim robj As String
    robj = RightB$(object, 2)
    If ((robj <> "!") And (robj <> "$")) Then
        ' Append an "!"
        Call getValue(object & "!", object, hClassDbl, prg)
    Else
        ' "!" already found
        Call getValue(object, object, hClassDbl, prg)
    End If

    ' Convert the handle to long
    hClass = CLng(hClassDbl)

    ' Check if we have an object
    If Not (isObject(hClass, prg)) Then

        ' Not an object
        Call debugger("Error: " & object & " is not an object!-- " & Text)

    Else

        ' Check if we're calling from outside
        outside = (topNestle(prg) <> hClass)

        If Not (var) Then

            ' Check if we're to release
            If (cmdName = "RELEASE") Then

                ' Call the deconstructor
                Call callObjectMethod(hClass, "~" & g_objects(hClass).strInstancedFrom, prg, retval, "~" & g_objects(hClass).strInstancedFrom)

                ' Kill the object's members
                Call clearObject(g_objects(hClass), prg)

                ' Kill the object
                Call killHandle(hClass)

                ' Clear the object's hClass
                g_objects(hClass).hClass = 0

                ' Clear what the object was instanced from
                g_objects(hClass).strInstancedFrom = vbNullString

            ElseIf (cmdName = "GETTYPE") Then

                ' Return type of object
                value = g_objects(hClass).strInstancedFrom

            Else

                If (isMethodMember(cmdName, hClass, prg, outside)) Then

                    ' Execute the method
                    Call callObjectMethod(hClass, cLine, prg, retval, cmdName)

                    ' Replace text with value the method returned
                    If (retval.dataType = DT_NUM) Then
                        value = " " & CStr(retval.num)
                    ElseIf (retval.dataType = DT_LIT) Then
                        value = " """ & retval.lit & """"
                    ElseIf (retval.dataType = DT_REFERENCE) Then
                        value = " " & retval.ref
                    End If

                Else

                    If (isMethodMember(cLine, hClass, prg, False)) Then
                        Call debugger("Error: Method " & cLine & " is not avaliable from outside " & g_objects(hClass).strInstancedFrom & "; " & Text)
                    Else
                        Call debugger("Error: Method " & cLine & " is not a member of " & g_objects(hClass).strInstancedFrom & "; " & Text)
                    End If

                End If

            End If

        Else

            ' It's a variable
            If (isVarMember(cLine, hClass, prg, outside)) Then
                ' It's a member
                value = getObjectVarName(cLine, hClass)
            Else
                If (isVarMember(cLine, hClass, prg, False)) Then
                    Call debugger("Error: Variable " & cLine & " is not avaliable from outside " & g_objects(hClass).strInstancedFrom & "; " & Text)
                Else
                    Call debugger("Error: Variable " & cLine & " is not a member of " & g_objects(hClass).strInstancedFrom & "; " & Text)
                End If
            End If

        End If

    End If

    If Not ((lngEnd = Length) And (start = 1)) Then
        ' Recurse, passing in the running text
        spliceForObjects = spliceForObjects( _
                                               Mid$(Text, 1, start - 1) & _
                                               value & _
                                               Mid$(Text, lngEnd + 1), prg _
                                                                             )
    End If

End Function
