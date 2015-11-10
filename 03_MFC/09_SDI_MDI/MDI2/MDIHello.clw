; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTextFormView
LastTemplate=CFormView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MDIHello.h"
LastPage=0

ClassCount=7
Class1=CMDIHelloApp
Class2=CMDIHelloDoc
Class3=CMDIHelloView
Class4=CMainFrame

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CChildFrame
Class6=CAboutDlg
Resource3=IDR_MDIHELTYPE
Class7=CTextFormView
Resource4=IDD_TEXT_FORM

[CLS:CMDIHelloApp]
Type=0
HeaderFile=MDIHello.h
ImplementationFile=MDIHello.cpp
Filter=N

[CLS:CMDIHelloDoc]
Type=0
HeaderFile=MDIHelloDoc.h
ImplementationFile=MDIHelloDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=ID_VIEW_DATAFORM

[CLS:CMDIHelloView]
Type=0
HeaderFile=MDIHelloView.h
ImplementationFile=MDIHelloView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M


[CLS:CAboutDlg]
Type=0
HeaderFile=MDIHello.cpp
ImplementationFile=MDIHello.cpp
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
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_APP_ABOUT
CommandCount=8

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_MDIHELTYPE]
Type=1
Class=CMDIHelloView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_VIEW_DATAFORM
Command18=ID_COLOR_BLACK
Command19=ID_COLOR_RED
Command20=ID_COLOR_GREEN
Command21=ID_COLOR_BLUE
Command22=ID_WINDOW_NEW
Command23=ID_WINDOW_CASCADE
Command24=ID_WINDOW_TILE_HORZ
Command25=ID_WINDOW_ARRANGE
Command26=ID_APP_ABOUT
CommandCount=26

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

[DLG:IDD_TEXT_FORM]
Type=1
Class=CTextFormView
ControlCount=15
Control1=IDC_STATIC,static,1342308352
Control2=IDC_TEXT,edit,1350631552
Control3=IDC_STATIC,button,1342177287
Control4=IDC_COLOR,button,1342308361
Control5=IDC_RADIO2,button,1342177289
Control6=IDC_RADIO3,button,1342177289
Control7=IDC_RADIO4,button,1342177289
Control8=IDC_STATIC,button,1342308359
Control9=IDC_STATIC,static,1342308352
Control10=IDC_X,edit,1350631552
Control11=IDC_SPINX,msctls_updown32,1342177335
Control12=IDC_STATIC,static,1342308352
Control13=IDC_Y,edit,1350631552
Control14=IDC_SPINY,msctls_updown32,1342177335
Control15=ID_DATA_UPDATE,button,1342242817

[CLS:CTextFormView]
Type=0
HeaderFile=TextFormView.h
ImplementationFile=TextFormView.cpp
BaseClass=CFormView
Filter=D
VirtualFilter=VWC
LastObject=IDC_Y

