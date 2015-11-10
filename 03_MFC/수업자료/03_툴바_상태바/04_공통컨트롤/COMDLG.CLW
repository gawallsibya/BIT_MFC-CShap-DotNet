; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CComDlgView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ComDlg.h"
LastPage=0

ClassCount=6
Class1=CComDlgApp
Class2=CComDlgDoc
Class3=CComDlgView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=CDeleteDialog
Resource3=IDD_FILE_DELETE

[CLS:CComDlgApp]
Type=0
HeaderFile=ComDlg.h
ImplementationFile=ComDlg.cpp
Filter=N
LastObject=CComDlgApp

[CLS:CComDlgDoc]
Type=0
HeaderFile=ComDoc.h
ImplementationFile=ComDoc.cpp
Filter=N

[CLS:CComDlgView]
Type=0
HeaderFile=ComView.h
ImplementationFile=ComView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CComDlgView

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_COMDLG_PRINTERSETUP



[CLS:CAboutDlg]
Type=0
HeaderFile=ComDlg.cpp
ImplementationFile=ComDlg.cpp
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
Command16=ID_COMDLG_OPEN
Command17=ID_COMDLG_SAVEAS
Command18=ID_COMDLG_COLOR
Command19=ID_COMDLG_FONT
Command20=ID_COMDLG_PRINT
Command21=ID_COMDLG_PRINTERSETUP
Command22=ID_COMDLG_PAGESETUP
Command23=ID_COMDLG_FIND
Command24=ID_COMDLG_REPLACE
Command25=ID_COMDLG_DELETE
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

[DLG:IDD_FILE_DELETE]
Type=1
Class=CDeleteDialog
ControlCount=2
Control1=IDC_DELETE,button,1342242816
Control2=stc32,static,1342308352

[CLS:CDeleteDialog]
Type=0
HeaderFile=DelDlg.h
ImplementationFile=DelDlg.cpp
BaseClass=CFileDialog
Filter=D
LastObject=CDeleteDialog
VirtualFilter=dWC

