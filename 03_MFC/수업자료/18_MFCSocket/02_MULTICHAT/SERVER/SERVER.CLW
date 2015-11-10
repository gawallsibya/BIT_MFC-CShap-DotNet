; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CServerDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "server.h"
LastPage=0

ClassCount=5
Class1=CChildSock
Class2=CListenSock
Class3=CServerApp
Class4=CAboutDlg
Class5=CServerDlg

ResourceCount=2
Resource1=IDD_ABOUTBOX
Resource2=IDD_SERVER_DIALOG

[CLS:CChildSock]
Type=0
BaseClass=CAsyncSocket
HeaderFile=ChildSock.h
ImplementationFile=ChildSock.cpp
Filter=N
VirtualFilter=q
LastObject=CChildSock

[CLS:CListenSock]
Type=0
BaseClass=CAsyncSocket
HeaderFile=ListenSock.h
ImplementationFile=ListenSock.cpp

[CLS:CServerApp]
Type=0
BaseClass=CWinApp
HeaderFile=Server.h
ImplementationFile=Server.cpp
LastObject=CServerApp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=ServerDlg.cpp
ImplementationFile=ServerDlg.cpp
LastObject=CAboutDlg

[CLS:CServerDlg]
Type=0
BaseClass=CDialog
HeaderFile=ServerDlg.h
ImplementationFile=ServerDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=CServerDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SERVER_DIALOG]
Type=1
Class=CServerDlg
ControlCount=5
Control1=IDC_LIST1,listbox,1352728835
Control2=IDC_DATA,edit,1350631552
Control3=IDC_SEND,button,1342242816
Control4=IDC_STATIC,static,1342308864
Control5=IDC_USERCOUNT,static,1342308864

