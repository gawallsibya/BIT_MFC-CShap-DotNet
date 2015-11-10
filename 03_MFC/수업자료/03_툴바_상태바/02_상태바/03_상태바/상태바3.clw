; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CProgressStatusBar
LastTemplate=CButton
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "상태바3.h"
LastPage=0

ClassCount=5
Class1=CMy3App
Class3=CMainFrame
Class4=CAboutDlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class2=CChildView
Class5=CProgressStatusBar
Resource2=IDD_ABOUTBOX

[CLS:CMy3App]
Type=0
HeaderFile=상태바3.h
ImplementationFile=상태바3.cpp
Filter=N

[CLS:CChildView]
Type=0
HeaderFile=ChildView.h
ImplementationFile=ChildView.cpp
Filter=N

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
HeaderFile=상태바3.cpp
ImplementationFile=상태바3.cpp
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
Command7=ID_VIEW_STATUS_BAR
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

[CLS:CProgressStatusBar]
Type=0
HeaderFile=ProgressStatusBar.h
ImplementationFile=ProgressStatusBar.cpp
BaseClass=CStatusBar
Filter=W
LastObject=CProgressStatusBar

