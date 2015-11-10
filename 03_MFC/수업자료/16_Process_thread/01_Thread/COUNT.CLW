; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCountDlg
LastTemplate=CWinThread
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Count.h"

ClassCount=4
Class1=CCountApp
Class2=CCountDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CMyThread
Resource3=IDD_COUNT_DIALOG

[CLS:CCountApp]
Type=0
HeaderFile=Count.h
ImplementationFile=Count.cpp
Filter=N

[CLS:CCountDlg]
Type=0
HeaderFile=CountDlg.h
ImplementationFile=CountDlg.cpp
Filter=D
LastObject=IDC_CHECK1
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=CountDlg.h
ImplementationFile=CountDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_COUNT_DIALOG]
Type=1
Class=CCountDlg
ControlCount=12
Control1=IDC_STATIC,button,1342177287
Control2=IDC_RESULT,edit,1350639744
Control3=IDC_START_COUNT,button,1342242816
Control4=IDC_STATIC,button,1342177287
Control5=IDC_PROGRESS1,msctls_progress32,1350565889
Control6=IDC_START_PROGRESS,button,1342242816
Control7=IDC_CHECK1,button,1342242819
Control8=IDC_STATIC,button,1342177287
Control9=IDC_DATA,edit,1353781252
Control10=IDOK,button,1342242817
Control11=IDCANCEL,button,1342242816
Control12=IDC_PERCENT,static,1342308352

[CLS:CMyThread]
Type=0
HeaderFile=MyThread.h
ImplementationFile=MyThread.cpp
BaseClass=CWinThread
Filter=N
LastObject=CMyThread
VirtualFilter=TC

