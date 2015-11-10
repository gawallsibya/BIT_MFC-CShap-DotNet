; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CColorDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "RGBdisplay.h"
LastPage=0

ClassCount=6
Class1=CRGBdisplayApp
Class2=CRGBdisplayDoc
Class3=CRGBdisplayView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Class5=CAboutDlg
Resource2=IDR_MAINFRAME
Class6=CColorDlg
Resource3=IDD_DIALOG_COLOR

[CLS:CRGBdisplayApp]
Type=0
HeaderFile=RGBdisplay.h
ImplementationFile=RGBdisplay.cpp
Filter=N

[CLS:CRGBdisplayDoc]
Type=0
HeaderFile=RGBdisplayDoc.h
ImplementationFile=RGBdisplayDoc.cpp
Filter=N

[CLS:CRGBdisplayView]
Type=0
HeaderFile=RGBdisplayView.h
ImplementationFile=RGBdisplayView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CRGBdisplayView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=RGBdisplay.cpp
ImplementationFile=RGBdisplay.cpp
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
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_APP_ABOUT
Command12=ID_FONTCOLOR
Command13=ID_BACKCOLOR
CommandCount=13

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

[DLG:IDD_DIALOG_COLOR]
Type=1
Class=CColorDlg
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_COLOR,static,1342177287
Control4=IDC_SC_RED,scrollbar,1342177280
Control5=IDC_SC_GREEN,scrollbar,1342177280
Control6=IDC_SC_BLUE,scrollbar,1342177280
Control7=IDC_EDIT_RED_VAL,edit,1350631552
Control8=IDC_EDIT_GREEN_VAL,edit,1350631552
Control9=IDC_EDIT_BLUE_VAL,edit,1350631552

[CLS:CColorDlg]
Type=0
HeaderFile=ColorDlg.h
ImplementationFile=ColorDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CColorDlg
VirtualFilter=dWC

