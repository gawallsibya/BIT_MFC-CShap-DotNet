; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CHelloView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SplitWnd.h"
LastPage=0

ClassCount=6
Class1=CSplitWndApp
Class2=CHelloDoc
Class3=CHelloView
Class4=CMainFrame

ResourceCount=8
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource8=IDD_TEXT_FORM
Class5=CAboutDlg
Class6=CTextFormView

[CLS:CSplitWndApp]
Type=0
HeaderFile=SplitWnd.h
ImplementationFile=SplitWnd.cpp
Filter=N
LastObject=CSplitWndApp

[CLS:CHelloDoc]
Type=0
HeaderFile=HelloDoc.h
ImplementationFile=HelloDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=ID_COLOR_BLUE

[CLS:CHelloView]
Type=0
HeaderFile=HelloVw.h
ImplementationFile=HelloVw.cpp
Filter=C
LastObject=CHelloView
BaseClass=CView
VirtualFilter=VWC

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T



[CLS:CAboutDlg]
Type=0
HeaderFile=SplitWnd.cpp
ImplementationFile=SplitWnd.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
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
Command16=ID_WINDOW_SPLIT
Command17=ID_COLOR_BLACK
Command18=ID_COLOR_RED
Command19=ID_COLOR_GREEN
Command20=ID_COLOR_BLUE
Command21=ID_APP_ABOUT
CommandCount=21

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
Class=CTextFormView

[TB:IDR_MAINFRAME]
Type=1
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[CLS:CTextFormView]
Type=0
HeaderFile=textform.h
ImplementationFile=textform.cpp
BaseClass=CFormView
LastObject=CTextFormView

