; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLeftView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ExplorerTest.h"
LastPage=0

ClassCount=7
Class1=CExplorerTestApp
Class2=CExplorerTestDoc
Class3=CExplorerTestView
Class4=CMainFrame

ResourceCount=5
Resource1=IDR_CONTEXTMENU
Resource2=IDR_MAINFRAME
Class5=CLeftView
Class6=CAboutDlg
Resource4=IDD_ABOUTBOX
Resource3=IDR_CNTR_INPLACE
Class7=CInfoDlg
Resource5=IDD_INFO_DLG

[CLS:CExplorerTestApp]
Type=0
HeaderFile=ExplorerTest.h
ImplementationFile=ExplorerTest.cpp
Filter=N

[CLS:CExplorerTestDoc]
Type=0
HeaderFile=ExplorerTestDoc.h
ImplementationFile=ExplorerTestDoc.cpp
Filter=N
BaseClass=COleDocument
VirtualFilter=ODC
LastObject=CExplorerTestDoc

[CLS:CExplorerTestView]
Type=0
HeaderFile=ExplorerTestView.h
ImplementationFile=ExplorerTestView.cpp
Filter=C
LastObject=CExplorerTestView
BaseClass=CListView
VirtualFilter=VWC

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame
BaseClass=CFrameWnd
VirtualFilter=fWC



[CLS:CLeftView]
Type=0
HeaderFile=LeftView.h
ImplementationFile=LeftView.cpp
Filter=T
BaseClass=CTreeView
VirtualFilter=VWC
LastObject=CLeftView

[CLS:CAboutDlg]
Type=0
HeaderFile=ExplorerTest.cpp
ImplementationFile=ExplorerTest.cpp
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
Command14=ID_EDIT_PASTE_SPECIAL
Command15=ID_OLE_INSERT_NEW
Command16=ID_OLE_EDIT_LINKS
Command17=ID_OLE_VERB_FIRST
Command18=ID_VIEW_TOOLBAR
Command19=ID_VIEW_STATUS_BAR
Command20=ID_APP_ABOUT
CommandCount=20

[MNU:IDR_CNTR_INPLACE]
Type=1
Class=CExplorerTestView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
CommandCount=9

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
Command15=ID_CANCEL_EDIT_CNTR
CommandCount=15

[ACL:IDR_CNTR_INPLACE]
Type=1
Class=CExplorerTestView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_NEXT_PANE
Command6=ID_PREV_PANE
Command7=ID_CANCEL_EDIT_CNTR
CommandCount=7

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
Command9=ID_VIEW_LARGEICON
Command10=ID_VIEW_SMALLICON
Command11=ID_VIEW_LIST
Command12=ID_VIEW_DETAILS
CommandCount=12

[DLG:IDR_MAINFRAME]
Type=1
Class=?
ControlCount=0

[MNU:IDR_CONTEXTMENU]
Type=1
Class=?
Command1=ID_FILE_DELETE
Command2=ID_FILE_RENAME
Command3=ID_INFORMATION
Command4=ID_VIEW_LARGEICON
Command5=ID_VIEW_SMALLICON
Command6=ID_VIEW_LIST
Command7=ID_VIEW_DETAILS
Command8=ID_FOLDER_NEW
Command9=ID_FILE_DELETE
Command10=ID_FILE_RENAME
CommandCount=10

[DLG:IDD_INFO_DLG]
Type=1
Class=CInfoDlg
ControlCount=24
Control1=IDC_NAME,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_KIND,static,1342308352
Control6=IDC_POSITION,static,1342308352
Control7=IDC_FILESIZE,static,1342308352
Control8=IDC_STATIC,static,1342177287
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_FILE_NAME,static,1342308352
Control14=IDC_CREATION,static,1342308352
Control15=IDC_LAST_WRITE,static,1342308352
Control16=IDC_LAST_ACCESS,static,1342308352
Control17=IDC_STATIC,static,1342177287
Control18=IDC_STATIC,static,1342308352
Control19=IDC_CHECK_READONLY,button,1476460547
Control20=IDC_CHECK_ARCHIVE,button,1476460547
Control21=IDC_CHECK_HIDDEN,button,1476460547
Control22=IDC_CHECK_SYSTEM,button,1476460547
Control23=IDOK,button,1342242817
Control24=IDCANCEL,button,1342242816

[CLS:CInfoDlg]
Type=0
HeaderFile=InfoDlg.h
ImplementationFile=InfoDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CInfoDlg
VirtualFilter=dWC

