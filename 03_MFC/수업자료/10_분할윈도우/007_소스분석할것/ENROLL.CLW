; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyTreeCtrl
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "enroll.h"
LastPage=0

ClassCount=11
Class1=CCourseView
Class2=CCourseDlg
Class3=CStudentDlg
Class4=CEnrollDoc
Class5=CEnrollApp
Class6=CAboutDlg
Class7=CListPropertyDlg
Class8=CMainFrame
Class9=CStudentView
Class10=CMyTreeCtrl
Class11=CTreePropertyDlg

ResourceCount=6
Resource1=IDD_TREE_PROPERTY
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDD_COURSE
Resource5=IDD_STUDENT
Resource6=IDD_LIST_PROPERTY

[CLS:CCourseView]
Type=0
BaseClass=CTreeView
HeaderFile=CorsView.h
ImplementationFile=CorsView.cpp

[CLS:CCourseDlg]
Type=0
BaseClass=CDialog
HeaderFile=dlg.h
ImplementationFile=dlg.cpp
LastObject=CCourseDlg

[CLS:CStudentDlg]
Type=0
BaseClass=CDialog
HeaderFile=dlg.h
ImplementationFile=dlg.cpp

[CLS:CEnrollDoc]
Type=0
BaseClass=CDocument
HeaderFile=EnrlDoc.h
ImplementationFile=EnrlDoc.cpp

[CLS:CEnrollApp]
Type=0
BaseClass=CWinApp
HeaderFile=Enroll.h
ImplementationFile=Enroll.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=Enroll.cpp
ImplementationFile=Enroll.cpp

[CLS:CListPropertyDlg]
Type=0
BaseClass=CDialog
HeaderFile=ListDlg.h
ImplementationFile=ListDlg.cpp

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
LastObject=CMainFrame

[CLS:CStudentView]
Type=0
BaseClass=CListView
HeaderFile=StudView.h
ImplementationFile=StudView.cpp

[CLS:CMyTreeCtrl]
Type=0
BaseClass=CTreeCtrl
HeaderFile=TreeCtrl.h
ImplementationFile=TreeCtrl.cpp
LastObject=CMyTreeCtrl

[CLS:CTreePropertyDlg]
Type=0
BaseClass=CDialog
HeaderFile=TreeDlg.h
ImplementationFile=TreeDlg.cpp

[DLG:IDD_COURSE]
Type=1
Class=CCourseDlg
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_NAME,edit,1350631552
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816

[DLG:IDD_STUDENT]
Type=1
Class=CStudentDlg
ControlCount=11
Control1=IDC_STATIC,static,1342308352
Control2=IDC_NAME,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_TELNO,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_BIRTH,edit,1350631552
Control7=IDC_STATIC,button,1342177287
Control8=IDC_SEX,button,1342308361
Control9=IDC_RADIO2,button,1342177289
Control10=IDOK,button,1342373889
Control11=IDCANCEL,button,1342242816

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_LIST_PROPERTY]
Type=1
Class=CListPropertyDlg
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LIST1,SysListView32,1350631425
Control4=IDC_VIEWMODE,combobox,1344339971
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_SORTMODE,combobox,1344339971
Control8=IDC_STATIC,button,1342177287
Control9=IDC_AUTOARRANGE,button,1342242819
Control10=IDC_SINGLESEL,button,1342242819
Control11=IDC_EDITLABEL,button,1342242819
Control12=IDC_NOLABLEWRAP,button,1342242819
Control13=IDC_NOCOLUMNHEADER,button,1342242819
Control14=IDC_NOSORTHEADER,button,1342242819

[DLG:IDD_TREE_PROPERTY]
Type=1
Class=CTreePropertyDlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_TREE1,SysTreeView32,1350631424
Control4=IDC_STATIC,button,1342177287
Control5=IDC_EDITLABELS,button,1342242819
Control6=IDC_HASBUTTONS,button,1342242819
Control7=IDC_HASLINES,button,1342242819
Control8=IDC_LINESATROOT,button,1342242819
Control9=IDC_DISABLEDRAGDROP,button,1342242819
Control10=IDC_SHOWSELALWAYS,button,1342242819

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_COURSE_INSERT
Command8=ID_STUDENT_INSERT
Command9=ID_FILE_PRINT
Command10=ID_APP_ABOUT
CommandCount=10

[MNU:IDR_MAINFRAME]
Type=1
Class=?
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
Command11=ID_COURSE_INSERT
Command12=ID_STUDENT_INSERT
Command13=ID_VIEW_TOOLBAR
Command14=ID_VIEW_STATUS_BAR
Command15=ID_LIST_PROPERTY
Command16=ID_TREE_PROPERTY
Command17=ID_APP_ABOUT
CommandCount=17

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

