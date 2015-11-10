; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDBTEST1View
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DBTEST1.h"
LastPage=0

ClassCount=6
Class1=CDBTEST1App
Class2=CDBTEST1Doc
Class3=CDBTEST1View
Class4=CMainFrame
Class6=CAboutDlg

ResourceCount=7
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class5=CDBTEST1Set
Resource7=IDD_DBTEST1_FORM

[CLS:CDBTEST1App]
Type=0
HeaderFile=DBTEST1.h
ImplementationFile=DBTEST1.cpp
Filter=N

[CLS:CDBTEST1Doc]
Type=0
HeaderFile=DBTEST1Doc.h
ImplementationFile=DBTEST1Doc.cpp
Filter=N

[CLS:CDBTEST1View]
Type=0
HeaderFile=DBTEST1View.h
ImplementationFile=DBTEST1View.cpp
Filter=D
BaseClass=CRecordView
VirtualFilter=RVWC
LastObject=CDBTEST1View


[CLS:CDBTEST1Set]
Type=0
HeaderFile=DBTEST1Set.h
ImplementationFile=DBTEST1Set.cpp
Filter=N

[DB:CDBTEST1Set]
DB=1
DBType=ODBC
ColumnCount=4
Column1=[CUSTOM_CD], 4, 4
Column2=[NAME], 12, 40
Column3=[TEL], 12, 40
Column4=[ADDRESS], 12, 120


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=DBTEST1.cpp
ImplementationFile=DBTEST1.cpp
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
Command1=ID_FILE_PRINT
Command2=ID_FILE_PRINT_PREVIEW
Command3=ID_FILE_PRINT_SETUP
Command4=ID_APP_EXIT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_RECORD_FIRST
Command10=ID_RECORD_PREV
Command11=ID_RECORD_NEXT
Command12=ID_RECORD_LAST
Command13=ID_VIEW_TOOLBAR
Command14=ID_VIEW_STATUS_BAR
Command15=ID_APP_ABOUT
CommandCount=15

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_PRINT
Command2=ID_EDIT_UNDO
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_EDIT_UNDO
Command7=ID_EDIT_CUT
Command8=ID_EDIT_COPY
Command9=ID_EDIT_PASTE
Command10=ID_NEXT_PANE
Command11=ID_PREV_PANE
CommandCount=11

[DLG:IDD_DBTEST1_FORM]
Type=1
Class=CDBTEST1View
ControlCount=8
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_NAME,edit,1350631552
Control5=IDC_EDIT_PHONE,edit,1350631552
Control6=IDC_EDIT_ADDRESS,edit,1350631552
Control7=IDC_BTN_ADD,button,1342242816
Control8=IDC_BTN_DEL,button,1342242816

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_FILE_PRINT
Command5=ID_RECORD_FIRST
Command6=ID_RECORD_PREV
Command7=ID_RECORD_NEXT
Command8=ID_RECORD_LAST
Command9=ID_APP_ABOUT
CommandCount=9

