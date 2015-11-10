; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTestDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DialogDemo.h"

ClassCount=4
Class1=CDialogDemoApp
Class2=CDialogDemoDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOGDEMO_DIALOG
Class4=CTestDlg
Resource4=IDD_Dialog_Test

[CLS:CDialogDemoApp]
Type=0
HeaderFile=DialogDemo.h
ImplementationFile=DialogDemo.cpp
Filter=N
LastObject=CDialogDemoApp

[CLS:CDialogDemoDlg]
Type=0
HeaderFile=DialogDemoDlg.h
ImplementationFile=DialogDemoDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CDialogDemoDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=DialogDemoDlg.h
ImplementationFile=DialogDemoDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DIALOGDEMO_DIALOG]
Type=1
Class=CDialogDemoDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_Button_Modal,button,1342242816
Control4=IDC_Button_Modaless,button,1342242816
Control5=IDC_Button_NModaless,button,1342242816

[DLG:IDD_Dialog_Test]
Type=1
Class=CTestDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_Static_Message,static,1342308352
Control4=IDC_Edit_Name,edit,1350631552
Control5=IDC_STATIC,static,1342308352

[CLS:CTestDlg]
Type=0
HeaderFile=TestDlg.h
ImplementationFile=TestDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CTestDlg

