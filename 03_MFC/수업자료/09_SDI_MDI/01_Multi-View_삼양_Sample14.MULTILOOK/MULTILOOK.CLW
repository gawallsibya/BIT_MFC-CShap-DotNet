; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMultiLookApp
LastTemplate=CScrollView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MultiLook.h"
LastPage=0

ClassCount=7
Class1=CMultiLookApp
Class2=CMultiLookDoc
Class3=CMultiLookView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CFontView
Class7=CPaintView
Resource3=IDD_MULTILOOK_FORM

[CLS:CMultiLookApp]
Type=0
HeaderFile=MultiLook.h
ImplementationFile=MultiLook.cpp
Filter=N
LastObject=CMultiLookApp

[CLS:CMultiLookDoc]
Type=0
HeaderFile=MultiLookDoc.h
ImplementationFile=MultiLookDoc.cpp
Filter=N

[CLS:CMultiLookView]
Type=0
HeaderFile=MultiLookView.h
ImplementationFile=MultiLookView.cpp
Filter=D
LastObject=IDC_TAB1
BaseClass=CFormView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_PAINT_VIEW




[CLS:CAboutDlg]
Type=0
HeaderFile=MultiLook.cpp
ImplementationFile=MultiLook.cpp
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
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_VIEW_TOOLBAR
Command8=ID_VIEW_STATUS_BAR
Command9=ID_APP_ABOUT
CommandCount=9

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_MULTILOOK_FORM]
Type=1
Class=CMultiLookView
ControlCount=2
Control1=IDC_TAB1,SysTabControl32,1342179523
Control2=IDC_RICHEDIT1,RICHEDIT,1353781252

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_APP_ABOUT
Command2=ID_FORM_VIEW
Command3=ID_FONT_VIEW
Command4=ID_PAINT_VIEW
CommandCount=4

[CLS:CFontView]
Type=0
HeaderFile=FontView.h
ImplementationFile=FontView.cpp
BaseClass=CView
Filter=C
LastObject=CFontView
VirtualFilter=VWC

[CLS:CPaintView]
Type=0
HeaderFile=PaintView.h
ImplementationFile=PaintView.cpp
BaseClass=CScrollView
Filter=C
LastObject=CPaintView
VirtualFilter=VWC

