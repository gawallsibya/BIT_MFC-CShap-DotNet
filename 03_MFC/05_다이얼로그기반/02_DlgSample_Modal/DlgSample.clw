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

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class2=CChildView
Class5=CMyDialog
Resource3=IDD_MYDIALOG

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
LastObject=CChildView

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=DlgSample.cpp
ImplementationFile=DlgSample.cpp
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
Command1=ID_APP_EXIT
Command2=ID_EDIT_UNDO
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_VIEW_TOOLBAR
Command7=IDM_SETTING_DIALOG
Command8=ID_APP_ABOUT
CommandCount=8

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

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_FILE_PRINT
Command5=ID_APP_ABOUT
CommandCount=5

[CLS:CMyDialog]
Type=0
HeaderFile=MyDialog.h
ImplementationFile=MyDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CMyDialog
VirtualFilter=dWC

[DLG:IDD_MYDIALOG]
Type=1
Class=CMyDialog
ControlCount=6
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_EDIT2,edit,1350631552
Control3=IDC_SPIN1,msctls_updown32,1342177334
Control4=IDOK,button,1342242817
Control5=IDCANCEL,button,1342242816
Control6=IDC_BUTTON1,button,1342242816

