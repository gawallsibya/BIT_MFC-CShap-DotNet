; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CInsTapeDlg
LastTemplate=CRecordset
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "VideoShop2.h"
LastPage=0

ClassCount=11
Class1=CVideoShop2App
Class2=CVideoShop2Doc
Class3=CVideoShop2View
Class4=CMainFrame
Class6=CAboutDlg

ResourceCount=6
Resource1=IDD_ABOUTBOX
Resource2=IDD_TAPE_DLG
Class5=CVideoShop2Set
Resource3=IDD_CUSTAPE_DLG
Resource4=IDR_MAINFRAME
Class7=CCusTapeDlg
Class8=CTapeDlg
Resource5=IDD_VIDEOSHOP2_FORM
Class9=CInsTapeDlg
Class10=CCusTapeSet
Class11=CTapeSet
Resource6=IDD_INSTAPE_DLG

[CLS:CVideoShop2App]
Type=0
HeaderFile=VideoShop2.h
ImplementationFile=VideoShop2.cpp
Filter=N

[CLS:CVideoShop2Doc]
Type=0
HeaderFile=VideoShop2Doc.h
ImplementationFile=VideoShop2Doc.cpp
Filter=N

[CLS:CVideoShop2View]
Type=0
HeaderFile=VideoShop2View.h
ImplementationFile=VideoShop2View.cpp
Filter=D
BaseClass=CRecordView
VirtualFilter=RVWC
LastObject=CVideoShop2View

[CLS:CVideoShop2Set]
Type=0
HeaderFile=VideoShop2Set.h
ImplementationFile=VideoShop2Set.cpp
Filter=N
LastObject=CVideoShop2Set
BaseClass=CRecordset
VirtualFilter=r

[DB:CVideoShop2Set]
DB=1
DBType=ODBC
ColumnCount=4
Column1=[CUSTOM_CD], 4, 4
Column2=[NAME], 12, 20
Column3=[TEL], 12, 20
Column4=[ADDRESS], 12, 60


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T



[CLS:CAboutDlg]
Type=0
HeaderFile=VideoShop2.cpp
ImplementationFile=VideoShop2.cpp
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
Command13=ID_RECORD_CUSTOM
Command14=ID_RECORD_TAPE
Command15=ID_CUSTAPE_ADD
Command16=ID_VIEW_TOOLBAR
Command17=ID_VIEW_STATUS_BAR
Command18=ID_APP_ABOUT
CommandCount=18

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

[DLG:IDD_VIDEOSHOP2_FORM]
Type=1
Class=CVideoShop2View
ControlCount=13
Control1=IDC_STATIC,static,1342308865
Control2=IDC_STATIC,static,1342308865
Control3=IDC_STATIC,static,1342308865
Control4=IDC_NAME_EDIT,edit,1350631552
Control5=IDC_TEL_EDIT,edit,1350631552
Control6=IDC_ADDRESS_EDIT,edit,1350631552
Control7=IDC_TAPE_LIST,SysListView32,1350633473
Control8=IDC_STATIC,static,1342308865
Control9=IDC_STATIC,static,1342308865
Control10=IDC_CODE_EDIT,edit,1350631554
Control11=IDC_ADD_BTN,button,1342242816
Control12=IDC_ADDCANCEL_BTN,button,1342242816
Control13=IDC_DELETE_BTN,button,1342242816

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

[DLG:IDD_CUSTAPE_DLG]
Type=1
Class=CCusTapeDlg
ControlCount=19
Control1=IDC_RENTDAY_EDIT,edit,1350631552
Control2=IDC_RECDAY_EDIT,edit,1350631552
Control3=IDC_TAPECODE_EDIT,edit,1350631552
Control4=IDC_TAPETTLE_EDIT,edit,1350631552
Control5=IDC_TITLE_LIST,SysListView32,1350633477
Control6=IDOK,button,1342242817
Control7=ID_CUSTAPE_ADD,button,1342242817
Control8=ID_CUSTAPE_DELETE,button,1342242817
Control9=ID_CUSTAPE_UPDATE,button,1342242817
Control10=ID_CUSTAPE_COMPLETE,button,1342242817
Control11=IDCANCEL,button,1342242816
Control12=IDC_CUSNAME_EDIT,edit,1350568064
Control13=IDC_CUSCODE_EDIT,edit,1350568064
Control14=IDC_STATIC,static,1342308353
Control15=IDC_STATIC,static,1342308353
Control16=IDC_STATIC,static,1342308353
Control17=IDC_STATIC,static,1342308353
Control18=IDC_STATIC,static,1342308353
Control19=IDC_STATIC,static,1342308353

[DLG:IDD_TAPE_DLG]
Type=1
Class=CTapeDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=ID_TAPE_DELETE,button,1342242817
Control4=IDC_TAPE_LIST,SysListView32,1350633473

[CLS:CCusTapeDlg]
Type=0
HeaderFile=CusTapeDlg.h
ImplementationFile=CusTapeDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_CUSTAPE_DELETE
VirtualFilter=dWC

[CLS:CTapeDlg]
Type=0
HeaderFile=TapeDlg.h
ImplementationFile=TapeDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDOK
VirtualFilter=dWC

[DLG:IDD_INSTAPE_DLG]
Type=1
Class=CInsTapeDlg
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308865
Control4=IDC_CODE_EDIT,edit,1350631552
Control5=IDC_STATIC,static,1342308865
Control6=IDC_STATIC,static,1342308865
Control7=IDC_STATIC,static,1342308865
Control8=IDC_STATIC,static,1342308865
Control9=IDC_STATIC,static,1342308865
Control10=IDC_TITLE_EDIT,edit,1350631552
Control11=IDC_INDAY_EDIT,edit,1350631552
Control12=IDC_DIRECTOR_EDIT,edit,1350631552
Control13=IDC_ACTOR_EDIT,edit,1350631552
Control14=IDC_MONEY_EDIT,edit,1350631552

[CLS:CInsTapeDlg]
Type=0
HeaderFile=InsTapeDlg.h
ImplementationFile=InsTapeDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CInsTapeDlg
VirtualFilter=dWC

[CLS:CCusTapeSet]
Type=0
HeaderFile=CusTapeSet.h
ImplementationFile=CusTapeSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CCusTapeSet

[DB:CCusTapeSet]
DB=1
DBType=ODBC
ColumnCount=5
Column1=[TAPE_CD], 4, 4
Column2=[CUSTOM_CD], 4, 4
Column3=[RENT_DAY], 11, 16
Column4=[REC_DAY], 11, 16
Column5=[ISREC], -7, 1

[CLS:CTapeSet]
Type=0
HeaderFile=TapeSet.h
ImplementationFile=TapeSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CTapeSet

[DB:CTapeSet]
DB=1
DBType=ODBC
ColumnCount=6
Column1=[TAPE_CD], 4, 4
Column2=[TITLE], 12, 50
Column3=[INDAY], 11, 16
Column4=[DIRECTOR], 12, 30
Column5=[ACTOR], 12, 30
Column6=[MONEY], 4, 4

