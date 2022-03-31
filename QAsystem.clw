; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CQAsystemView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "QAsystem.h"
LastPage=0

ClassCount=10
Class1=CQAsystemApp
Class2=CQAsystemDoc
Class3=CQAsystemView
Class4=CMainFrame

ResourceCount=6
Resource1=IDD_DIALOG2
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Resource3=IDD_DIALOG1
Class6=Cpath
Resource4=IDD_ABOUTBOX
Class7=CQuestion
Resource5=IDD_QASYSTEM_FORM11
Class8=Suggest
Class9=Cfeedback
Class10=categoryofuser
Resource6=IDD_DIALOG4

[CLS:CQAsystemApp]
Type=0
HeaderFile=QAsystem.h
ImplementationFile=QAsystem.cpp
Filter=N

[CLS:CQAsystemDoc]
Type=0
HeaderFile=QAsystemDoc.h
ImplementationFile=QAsystemDoc.cpp
Filter=N

[CLS:CQAsystemView]
Type=0
HeaderFile=QAsystemView.h
ImplementationFile=QAsystemView.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=CQAsystemView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=QAsystem.cpp
ImplementationFile=QAsystem.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_HELP_FINDER
Command17=ID_APP_ABOUT
Command18=ID_Entity
CommandCount=18

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
Command15=ID_CONTEXT_HELP
Command16=ID_HELP
CommandCount=16

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_CONTEXT_HELP
CommandCount=9

[DLG:IDD_DIALOG1]
Type=1
Class=Cpath
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_Path,edit,1350631552

[CLS:Cpath]
Type=0
HeaderFile=path.h
ImplementationFile=path.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_Path

[DLG:IDD_DIALOG2]
Type=1
Class=CQuestion
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_Question,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_Keywords,edit,1350631552
Control7=IDC_BUTTON1,button,1342242816

[CLS:CQuestion]
Type=0
HeaderFile=Question.h
ImplementationFile=Question.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CQuestion

[CLS:Suggest]
Type=0
HeaderFile=Suggest.h
ImplementationFile=Suggest.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=ID_APP_ABOUT

[DLG:IDD_DIALOG4]
Type=1
Class=Cfeedback
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_Suggest,edit,1352732676

[CLS:Cfeedback]
Type=0
HeaderFile=feedback.h
ImplementationFile=feedback.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LIST1
VirtualFilter=dWC

[DLG:IDD_QASYSTEM_FORM11]
Type=1
Class=CQAsystemView
ControlCount=19
Control1=IDC_QUERRY,edit,1350631552
Control2=IDC_BUTTON2,button,1342242816
Control3=IDC_BUTTON3,button,1342185473
Control4=IDC_BUTTONp1,button,1342242816
Control5=IDC_BUTTONp2,button,1342242816
Control6=IDC_BUTTONp3,button,1342242816
Control7=IDC_PROGRESS2,msctls_progress32,1350565888
Control8=IDC_STATIC,static,1342374796
Control9=IDC_STATIC,static,1350701964
Control10=IDC_STATIC,static,1342312449
Control11=IDC_RICHEDIT0,RICHEDIT,1352732676
Control12=IDC_STATIC,static,1342182145
Control13=IDC_QUERRY2,edit,1350631552
Control14=IDC_RICHEDIT4,RICHEDIT,1352732676
Control15=IDC_RICHEDIT5,RICHEDIT,1352732676
Control16=IDC_RADIO2,button,1342177289
Control17=IDC_RADIO3,button,1342177289
Control18=IDC_STATIC,button,1342177287
Control19=IDC_COMBO2,combobox,1344471298

[CLS:categoryofuser]
Type=0
HeaderFile=categoryofuser.h
ImplementationFile=categoryofuser.cpp
BaseClass=CDialog
Filter=D
LastObject=categoryofuser
VirtualFilter=dWC

