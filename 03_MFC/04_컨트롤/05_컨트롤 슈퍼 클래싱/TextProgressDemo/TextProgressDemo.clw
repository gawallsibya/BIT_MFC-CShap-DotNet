; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTextProgressDemoDlg
LastTemplate=CProgressCtrl
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TextProgressDemo.h"

ClassCount=4
Class1=CTextProgressDemoApp
Class2=CTextProgressDemoDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CTextProgress
Resource3=IDD_TEXTPROGRESSDEMO_DIALOG

[CLS:CTextProgressDemoApp]
Type=0
HeaderFile=TextProgressDemo.h
ImplementationFile=TextProgressDemo.cpp
Filter=N

[CLS:CTextProgressDemoDlg]
Type=0
HeaderFile=TextProgressDemoDlg.h
ImplementationFile=TextProgressDemoDlg.cpp
Filter=D
LastObject=CTextProgressDemoDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=TextProgressDemoDlg.h
ImplementationFile=TextProgressDemoDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TEXTPROGRESSDEMO_DIALOG]
Type=1
Class=CTextProgressDemoDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_PROGRESS,msctls_progress32,1350565889
Control4=IDC_EDIT,edit,1350631552
Control5=IDC_Button_SetValue,button,1342242817

[CLS:CTextProgress]
Type=0
HeaderFile=TextProgress.h
ImplementationFile=TextProgress.cpp
BaseClass=CProgressCtrl
Filter=W
VirtualFilter=NWC

