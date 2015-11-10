; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CHTStaticDemoDlg
LastTemplate=CStatic
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "HTStaticDemo.h"

ClassCount=5
Class1=CHTStaticDemoApp
Class2=CHTStaticDemoDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CHTStatic
Class5=CGraphStatic
Resource3=IDD_HTSTATICDEMO_DIALOG

[CLS:CHTStaticDemoApp]
Type=0
HeaderFile=HTStaticDemo.h
ImplementationFile=HTStaticDemo.cpp
Filter=N

[CLS:CHTStaticDemoDlg]
Type=0
HeaderFile=HTStaticDemoDlg.h
ImplementationFile=HTStaticDemoDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_Edit

[CLS:CAboutDlg]
Type=0
HeaderFile=HTStaticDemoDlg.h
ImplementationFile=HTStaticDemoDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_HTSTATICDEMO_DIALOG]
Type=1
Class=CHTStaticDemoDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_Static_Normal,static,1342308352
Control4=IDC_Static_HTStatic,static,1342308352
Control5=IDC_Static_Graph,static,1342308352
Control6=IDC_Button_SetData,button,1342242816
Control7=IDC_Edit,edit,1350631552
Control8=IDC_STATIC,button,1342177287

[CLS:CHTStatic]
Type=0
HeaderFile=HTStatic.h
ImplementationFile=HTStatic.cpp
BaseClass=CStatic
Filter=W
LastObject=CHTStatic
VirtualFilter=WC

[CLS:CGraphStatic]
Type=0
HeaderFile=GraphStatic.h
ImplementationFile=GraphStatic.cpp
BaseClass=CStatic
Filter=W
VirtualFilter=WC
LastObject=CGraphStatic

