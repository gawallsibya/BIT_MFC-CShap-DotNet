; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMSNButtonDemoDlg
LastTemplate=CButton
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MSNButtonDemo.h"

ClassCount=4
Class1=CMSNButtonDemoApp
Class2=CMSNButtonDemoDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CMSNButton
Resource3=IDD_MSNBUTTONDEMO_DIALOG

[CLS:CMSNButtonDemoApp]
Type=0
HeaderFile=MSNButtonDemo.h
ImplementationFile=MSNButtonDemo.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC
LastObject=CMSNButtonDemoApp

[CLS:CMSNButtonDemoDlg]
Type=0
HeaderFile=MSNButtonDemoDlg.h
ImplementationFile=MSNButtonDemoDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CMSNButtonDemoDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=MSNButtonDemoDlg.h
ImplementationFile=MSNButtonDemoDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MSNBUTTONDEMO_DIALOG]
Type=1
Class=CMSNButtonDemoDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_Button_MSN,button,1342242827
Control4=IDC_STATIC,static,1342177294

[CLS:CMSNButton]
Type=0
HeaderFile=MSNButton.h
ImplementationFile=MSNButton.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC
LastObject=CMSNButton

