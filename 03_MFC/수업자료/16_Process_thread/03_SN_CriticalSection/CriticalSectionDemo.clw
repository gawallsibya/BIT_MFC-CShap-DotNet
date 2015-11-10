; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCriticalSectionDemoDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CriticalSectionDemo.h"

ClassCount=3
Class1=CCriticalSectionDemoApp
Class2=CCriticalSectionDemoDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_CRITICALSECTIONDEMO_DIALOG

[CLS:CCriticalSectionDemoApp]
Type=0
HeaderFile=CriticalSectionDemo.h
ImplementationFile=CriticalSectionDemo.cpp
Filter=N

[CLS:CCriticalSectionDemoDlg]
Type=0
HeaderFile=CriticalSectionDemoDlg.h
ImplementationFile=CriticalSectionDemoDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CCriticalSectionDemoDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=CriticalSectionDemoDlg.h
ImplementationFile=CriticalSectionDemoDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CRITICALSECTIONDEMO_DIALOG]
Type=1
Class=CCriticalSectionDemoDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_Button_Thread1,button,1342242816
Control4=IDC_Button_Thread2,button,1342242816
Control5=IDC_Button_GetString,button,1342242816

