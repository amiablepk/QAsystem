# Microsoft Developer Studio Project File - Name="QAsystem" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=QAsystem - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "QAsystem.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "QAsystem.mak" CFG="QAsystem - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "QAsystem - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "QAsystem - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "QAsystem - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "QAsystem - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:"Debug/EureQA!!.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "QAsystem - Win32 Release"
# Name "QAsystem - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=".\analyze-linkage.cpp"
# End Source File
# Begin Source File

SOURCE=.\and.cpp
# End Source File
# Begin Source File

SOURCE=.\api.cpp
# End Source File
# Begin Source File

SOURCE=.\binsrch.cpp
# End Source File
# Begin Source File

SOURCE=".\build-disjuncts.cpp"
# End Source File
# Begin Source File

SOURCE=.\categoryofuser.cpp
# End Source File
# Begin Source File

SOURCE=".\command-line.cpp"
# End Source File
# Begin Source File

SOURCE=.\constituents.cpp
# End Source File
# Begin Source File

SOURCE=.\count.cpp
# End Source File
# Begin Source File

SOURCE=.\error.cpp
# End Source File
# Begin Source File

SOURCE=".\extract-links.cpp"
# End Source File
# Begin Source File

SOURCE=".\fast-match.cpp"
# End Source File
# Begin Source File

SOURCE=.\feedback.cpp
# End Source File
# Begin Source File

SOURCE=.\getopt.cpp
# End Source File
# Begin Source File

SOURCE=.\hash.cpp
# End Source File
# Begin Source File

SOURCE=.\heap.cpp
# End Source File
# Begin Source File

SOURCE=.\idiom.cpp
# End Source File
# Begin Source File

SOURCE=.\linkset.cpp
# End Source File
# Begin Source File

SOURCE=.\local_strings.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\massage.cpp
# End Source File
# Begin Source File

SOURCE=.\morph.cpp
# End Source File
# Begin Source File

SOURCE=.\OleRichEditCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\path.cpp
# End Source File
# Begin Source File

SOURCE=".\post-process.cpp"
# End Source File
# Begin Source File

SOURCE=.\pp_knowledge.cpp
# End Source File
# Begin Source File

SOURCE=.\pp_lexer.cpp
# End Source File
# Begin Source File

SOURCE=.\pp_linkset.cpp
# End Source File
# Begin Source File

SOURCE=.\preparation.cpp
# End Source File
# Begin Source File

SOURCE=".\print-util.cpp"
# End Source File
# Begin Source File

SOURCE=.\print.cpp
# End Source File
# Begin Source File

SOURCE=.\prune.cpp
# End Source File
# Begin Source File

SOURCE=.\QAsystem.cpp
# End Source File
# Begin Source File

SOURCE=.\hlp\QAsystem.hpj

!IF  "$(CFG)" == "QAsystem - Win32 Release"

# PROP Ignore_Default_Tool 1
USERDEP__QASYS="hlp\AfxCore.rtf"	"hlp\AfxPrint.rtf"	"hlp\$(TargetName).hm"	
# Begin Custom Build - Making help file...
OutDir=.\Release
TargetName=QAsystem
InputPath=.\hlp\QAsystem.hpj
InputName=QAsystem

"$(OutDir)\$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	start /wait hcw /C /E /M "hlp\$(InputName).hpj" 
	if errorlevel 1 goto :Error 
	if not exist "hlp\$(InputName).hlp" goto :Error 
	copy "hlp\$(InputName).hlp" $(OutDir) 
	goto :done 
	:Error 
	echo hlp\$(InputName).hpj(1) : error: 
	type "hlp\$(InputName).log" 
	:done 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "QAsystem - Win32 Debug"

# PROP Ignore_Default_Tool 1
USERDEP__QASYS="hlp\AfxCore.rtf"	"hlp\AfxPrint.rtf"	"hlp\$(TargetName).hm"	
# Begin Custom Build - Making help file...
OutDir=.\Debug
TargetName=EureQA!!
InputPath=.\hlp\QAsystem.hpj
InputName=QAsystem

"$(OutDir)\$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	start /wait hcw /C /E /M "hlp\$(InputName).hpj" 
	if errorlevel 1 goto :Error 
	if not exist "hlp\$(InputName).hlp" goto :Error 
	copy "hlp\$(InputName).hlp" $(OutDir) 
	goto :done 
	:Error 
	echo hlp\$(InputName).hpj(1) : error: 
	type "hlp\$(InputName).log" 
	:done 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\QAsystem.rc
# End Source File
# Begin Source File

SOURCE=.\QAsystemDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\QAsystemView.cpp
# End Source File
# Begin Source File

SOURCE=.\Question.cpp
# End Source File
# Begin Source File

SOURCE=".\read-dict.cpp"
# End Source File
# Begin Source File

SOURCE=.\resources.cpp
# End Source File
# Begin Source File

SOURCE=.\search.cpp
# End Source File
# Begin Source File

SOURCE=.\seft.cpp
# End Source File
# Begin Source File

SOURCE=.\setutil.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\stem.cpp
# End Source File
# Begin Source File

SOURCE=.\stopsearch.cpp
# End Source File
# Begin Source File

SOURCE=".\string-set.cpp"
# End Source File
# Begin Source File

SOURCE=.\tokenize.cpp
# End Source File
# Begin Source File

SOURCE=.\util.cpp
# End Source File
# Begin Source File

SOURCE=.\utilities.cpp
# End Source File
# Begin Source File

SOURCE=.\wnglobal.cpp
# End Source File
# Begin Source File

SOURCE=.\wnhelp.cpp
# End Source File
# Begin Source File

SOURCE=.\wnrtl.cpp
# End Source File
# Begin Source File

SOURCE=.\wnutil.cpp
# End Source File
# Begin Source File

SOURCE=".\word-file.cpp"
# End Source File
# Begin Source File

SOURCE=".\www-parse.cpp"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=".\analyze-linkage.h"
# End Source File
# Begin Source File

SOURCE=.\and.h
# End Source File
# Begin Source File

SOURCE=".\api-structures.h"
# End Source File
# Begin Source File

SOURCE=.\api.h
# End Source File
# Begin Source File

SOURCE=".\build-disjuncts.h"
# End Source File
# Begin Source File

SOURCE=.\categoryofuser.h
# End Source File
# Begin Source File

SOURCE=".\command-line.h"
# End Source File
# Begin Source File

SOURCE=.\command_line.h
# End Source File
# Begin Source File

SOURCE=.\constituents.h
# End Source File
# Begin Source File

SOURCE=.\count.h
# End Source File
# Begin Source File

SOURCE=.\error.h
# End Source File
# Begin Source File

SOURCE=.\externs.h
# End Source File
# Begin Source File

SOURCE=".\extract-links.h"
# End Source File
# Begin Source File

SOURCE=".\fast-match.h"
# End Source File
# Begin Source File

SOURCE=.\feedback.h
# End Source File
# Begin Source File

SOURCE=.\idiom.h
# End Source File
# Begin Source File

SOURCE=.\license.h
# End Source File
# Begin Source File

SOURCE=".\link-includes.h"
# End Source File
# Begin Source File

SOURCE=.\linkset.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\massage.h
# End Source File
# Begin Source File

SOURCE=.\OleRichEditCtrl.h
# End Source File
# Begin Source File

SOURCE=.\path.h
# End Source File
# Begin Source File

SOURCE=".\phrase-parse.h"
# End Source File
# Begin Source File

SOURCE=".\post-process.h"
# End Source File
# Begin Source File

SOURCE=.\pp_knowledge.h
# End Source File
# Begin Source File

SOURCE=.\pp_lexer.h
# End Source File
# Begin Source File

SOURCE=.\pp_linkset.h
# End Source File
# Begin Source File

SOURCE=.\preparation.h
# End Source File
# Begin Source File

SOURCE=".\print-util.h"
# End Source File
# Begin Source File

SOURCE=.\print.h
# End Source File
# Begin Source File

SOURCE=.\prune.h
# End Source File
# Begin Source File

SOURCE=.\QAsystem.h
# End Source File
# Begin Source File

SOURCE=.\QAsystemDoc.h
# End Source File
# Begin Source File

SOURCE=.\QAsystemView.h
# End Source File
# Begin Source File

SOURCE=.\Question.h
# End Source File
# Begin Source File

SOURCE=".\read-dict.h"
# End Source File
# Begin Source File

SOURCE=.\Resource.h

!IF  "$(CFG)" == "QAsystem - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Making help include file...
TargetName=QAsystem
InputPath=.\Resource.h

"hlp\$(TargetName).hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo. >"hlp\$(TargetName).hm" 
	echo // Commands (ID_* and IDM_*) >>"hlp\$(TargetName).hm" 
	makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Prompts (IDP_*) >>"hlp\$(TargetName).hm" 
	makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Resources (IDR_*) >>"hlp\$(TargetName).hm" 
	makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Dialogs (IDD_*) >>"hlp\$(TargetName).hm" 
	makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Frame Controls (IDW_*) >>"hlp\$(TargetName).hm" 
	makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\$(TargetName).hm" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "QAsystem - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Making help include file...
TargetName=EureQA!!
InputPath=.\Resource.h

"hlp\$(TargetName).hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo. >"hlp\$(TargetName).hm" 
	echo // Commands (ID_* and IDM_*) >>"hlp\$(TargetName).hm" 
	makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Prompts (IDP_*) >>"hlp\$(TargetName).hm" 
	makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Resources (IDR_*) >>"hlp\$(TargetName).hm" 
	makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Dialogs (IDD_*) >>"hlp\$(TargetName).hm" 
	makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Frame Controls (IDW_*) >>"hlp\$(TargetName).hm" 
	makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\$(TargetName).hm" 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\resources.h
# End Source File
# Begin Source File

SOURCE=.\setutil.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=".\string-set.h"
# End Source File
# Begin Source File

SOURCE=.\structures.h
# End Source File
# Begin Source File

SOURCE=.\tokenize.h
# End Source File
# Begin Source File

SOURCE=.\utilities.h
# End Source File
# Begin Source File

SOURCE=.\wn.h
# End Source File
# Begin Source File

SOURCE=.\wnconsts.h
# End Source File
# Begin Source File

SOURCE=.\wnglobal.h
# End Source File
# Begin Source File

SOURCE=.\wnhelp.h
# End Source File
# Begin Source File

SOURCE=.\wnrtl.h
# End Source File
# Begin Source File

SOURCE=.\wntypes.h
# End Source File
# Begin Source File

SOURCE=".\word-file.h"
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\QAsystem.ico
# End Source File
# Begin Source File

SOURCE=.\res\QAsystem.rc2
# End Source File
# Begin Source File

SOURCE=.\res\QAsystemDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Group "Help Files"

# PROP Default_Filter "cnt;rtf"
# Begin Source File

SOURCE=.\hlp\AfxCore.rtf
# End Source File
# Begin Source File

SOURCE=.\hlp\AfxPrint.rtf
# End Source File
# Begin Source File

SOURCE=.\hlp\AppExit.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\Bullet.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\CurArw2.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\CurArw4.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\CurHelp.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditCopy.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditCut.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditPast.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditUndo.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FileNew.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FileOpen.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FilePrnt.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FileSave.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\HlpSBar.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\HlpTBar.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\QAsystem.cnt

!IF  "$(CFG)" == "QAsystem - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Copying contents file...
OutDir=.\Release
InputPath=.\hlp\QAsystem.cnt
InputName=QAsystem

"$(OutDir)\$(InputName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "hlp\$(InputName).cnt" $(OutDir)

# End Custom Build

!ELSEIF  "$(CFG)" == "QAsystem - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Copying contents file...
OutDir=.\Debug
InputPath=.\hlp\QAsystem.cnt
InputName=QAsystem

"$(OutDir)\$(InputName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "hlp\$(InputName).cnt" $(OutDir)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\RecFirst.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\RecLast.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\RecNext.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\RecPrev.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\Scmax.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\ScMenu.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\Scmin.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\QAsystem.reg
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
