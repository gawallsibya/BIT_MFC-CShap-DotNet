; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyDialog
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DlgSample.h"
LastPage=0

ClassCount=5
Class1=CDlgSampleApp
Class3=CMainFrame
Class4=CAboutDlg

ResourceCount=4
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class2=CChildView
Class5=CMyDialog
Resource3=IDD_DIALOG1
Resource4=IDR_TOOLBAR1

[CLS:CDlgSampleApp]
Type=0
HeaderFile=DlgSample.h
ImplementationFile=DlgSample.cpp
Filter=N

[CLS:CChildView]
Type=0
HeaderFile=ChildView.h
ImplementationFile=ChildView.cpp
Filter=N
BaseClass=CWnd 
VirtualFilter=WC

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=DlgSample.cpp
ImplementationFile=DlgSample.cpp
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
Command1=ID_APP_EXIT
Command2=IDM_COLOR_RED
Command3=IDM_COLOR_GREEN
Command4=IDM_COLOR_BLUE
Command5=IDM_COLOR_BLACK
Command6=IDM_COLOR_OTHER
Command7=IDM_COLOR_SETTING
Command8=IDM_SIZE_SMALL
Command9=IDM_SIZE_NORMAL
Command10=IDM_SIZE_BIG
Command11=ID_VIEW_TOOLBAR
Command12=ID_APP_ABOUT
CommandCount=12

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_COPY
Command2=ID_EDIT_PASTE
Command3=ID_EDIT_UNDO
Command4=ID_EDIT_CUT
Command5=ID_NEXT_PANE
Command6=ID_PREV_PANE
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_CUT
Command10=ID_EDIT_UNDO
CommandCount=10

[DLG:IDD_DIALOG1]
Type=1
Class=CMyDialog
ControlCount=11
Control1=IDC_STATIC,button,1342177287
Control2=IDC_RADIO1,button,1342308361
Control3=IDC_RADIO2,button,1342177289
Control4=IDC_RADIO3,button,1342177289
Control5=IDC_RADIO4,button,1342177289
Control6=IDC_EDIT1,edit,1350762624
Control7=IDC_SPIN1,msctls_updown32,1342177334
Control8=IDC_EDIT2,edit,1350631552
Control9=IDC_SPIN2,msctls_updown32,1342177334
Control10=IDOK,button,1342242817
Control11=IDCANCEL,button,1342242816

[CLS:CMyDialog]
Type=0
HeaderFile=MyDialog.h
ImplementationFile=MyDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CMyDialog

[TB:IDR_TOOLBAR1]
Type=1
Class=?
Command1=IDM_COLOR_RED
Command2=IDM_COLOR_BLUE
Command3=IDM_COLOR_GREEN
Command4=IDM_COLOR_BLACK
Command5=IDM_COLOR_SETTING
CommandCount=5

