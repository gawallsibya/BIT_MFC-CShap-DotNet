; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTicTacView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "tictac.h"
LastPage=0

ClassCount=5
Class1=CMainFrame
Class2=CTicTacApp
Class3=CAboutDlg
Class4=CTicTacDoc
Class5=CTicTacView

ResourceCount=3
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Resource3=IDD_DIALOG1

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp

[CLS:CTicTacApp]
Type=0
BaseClass=CWinApp
HeaderFile=TicTac.h
ImplementationFile=TicTac.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=TicTac.cpp
ImplementationFile=TicTac.cpp

[CLS:CTicTacDoc]
Type=0
BaseClass=CDocument
HeaderFile=TicTacDoc.h
ImplementationFile=TicTacDoc.cpp

[CLS:CTicTacView]
Type=0
BaseClass=CFormView
HeaderFile=TicTacView.h
ImplementationFile=TicTacView.cpp
LastObject=CTicTacView
Filter=D
VirtualFilter=VWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DIALOG1]
Type=1
Class=CTicTacView
ControlCount=8
Control1=IDC_GAMEBOARD,static,1342177287
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC_TIMER,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC_MODE,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC_WINCOUNT,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=IDC_GAME_START
Command8=IDC_GAME_END
Command9=IDC_GAME_ONE
Command10=IDC_GAME_THREE
Command11=IDC_GAME_FIVE
Command12=ID_APP_ABOUT
CommandCount=12

[ACL:IDR_MAINFRAME]
Type=1
Class=?
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

