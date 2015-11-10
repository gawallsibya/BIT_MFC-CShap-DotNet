; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CFormView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Nam.h"
LastPage=0

ClassCount=6
Class1=CNamApp
Class2=CNamDoc
Class3=CNamView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CPaneView
Resource3=IDD_FORMVIEW

[CLS:CNamApp]
Type=0
HeaderFile=Nam.h
ImplementationFile=Nam.cpp
Filter=N

[CLS:CNamDoc]
Type=0
HeaderFile=NamDoc.h
ImplementationFile=NamDoc.cpp
Filter=N

[CLS:CNamView]
Type=0
HeaderFile=NamView.h
ImplementationFile=NamView.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=Nam.cpp
ImplementationFile=Nam.cpp
Filter=D
LastObject=CAboutDlg

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
Command16=ID_APP_ABOUT
CommandCount=16

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
CommandCount=14

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
CommandCount=8

[CLS:CPaneView]
Type=0
HeaderFile=PaneView.h
ImplementationFile=PaneView.cpp
BaseClass=CFormView
Filter=D
LastObject=IDC_BUTTON1
VirtualFilter=VWC

[DLG:IDD_FORMVIEW]
Type=1
Class=CPaneView
ControlCount=7
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_STATIC,button,1342177287
Control3=IDC_RADIO1,button,1342308361
Control4=IDC_RADIO2,button,1342177289
Control5=IDC_RADIO3,button,1342177289
Control6=IDC_RADIO4,button,1342177289
Control7=IDC_BUTTON1,button,1342242816

