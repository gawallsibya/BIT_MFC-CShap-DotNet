; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Paint1.h"
LastPage=0

ClassCount=6
Class1=CPaint1App
Class2=CPaint1Doc
Class3=CPaint1View
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX
Class6=CLineAttr
Resource3=IDD_DIALOG1

[CLS:CPaint1App]
Type=0
HeaderFile=Paint1.h
ImplementationFile=Paint1.cpp
Filter=N

[CLS:CPaint1Doc]
Type=0
HeaderFile=Paint1Doc.h
ImplementationFile=Paint1Doc.cpp
Filter=N

[CLS:CPaint1View]
Type=0
HeaderFile=Paint1View.h
ImplementationFile=Paint1View.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_PAINT_LINE


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_PAINT_LINEATTR
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=Paint1.cpp
ImplementationFile=Paint1.cpp
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
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=ID_PAINT_DRAW
Command18=ID_PAINT_LINE
Command19=ID_PAINT_ELLIPSE
Command20=ID_PAINT_RECTANGLE
Command21=ID_PAINT_LINEATTR
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

[DLG:IDD_DIALOG1]
Type=1
Class=CLineAttr
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_WIDTHPEN,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_RCOLOR,edit,1350631552
Control7=IDC_EDIT_GCOLOR,edit,1350631552
Control8=IDC_EDIT_BCOLOR,edit,1350631552

[CLS:CLineAttr]
Type=0
HeaderFile=LineAttr.h
ImplementationFile=LineAttr.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT_BCOLOR

