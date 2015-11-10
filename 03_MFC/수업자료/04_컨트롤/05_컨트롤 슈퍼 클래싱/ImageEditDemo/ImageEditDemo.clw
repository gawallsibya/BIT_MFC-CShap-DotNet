; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CImageEdit
LastTemplate=CEdit
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ImageEditDemo.h"

ClassCount=4
Class1=CImageEditDemoApp
Class2=CImageEditDemoDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CImageEdit
Resource3=IDD_IMAGEEDITDEMO_DIALOG

[CLS:CImageEditDemoApp]
Type=0
HeaderFile=ImageEditDemo.h
ImplementationFile=ImageEditDemo.cpp
Filter=N

[CLS:CImageEditDemoDlg]
Type=0
HeaderFile=ImageEditDemoDlg.h
ImplementationFile=ImageEditDemoDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CImageEditDemoDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=ImageEditDemoDlg.h
ImplementationFile=ImageEditDemoDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_IMAGEEDITDEMO_DIALOG]
Type=1
Class=CImageEditDemoDlg
ControlCount=3
Control1=IDOK,button,1342242816
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT,edit,1350631428

[CLS:CImageEdit]
Type=0
HeaderFile=ImageEdit.h
ImplementationFile=ImageEdit.cpp
BaseClass=CEdit
Filter=W
VirtualFilter=WC
LastObject=CImageEdit

