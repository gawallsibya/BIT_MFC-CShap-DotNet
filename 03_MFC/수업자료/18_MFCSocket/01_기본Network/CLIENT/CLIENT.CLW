; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CClientDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "client.h"
LastPage=0

ClassCount=5
Class1=CClientApp
Class2=CAboutDlg
Class3=CClientDlg
Class4=CClientSock

ResourceCount=3
Resource1=IDD_CLIENT_DIALOG
Resource2=IDD_ABOUTBOX
Class5=CConnectDlg
Resource3=IDD_CONNECT_DLG

[CLS:CClientApp]
Type=0
BaseClass=CWinApp
HeaderFile=Client.h
ImplementationFile=Client.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=ClientDlg.cpp
ImplementationFile=ClientDlg.cpp
LastObject=CAboutDlg

[CLS:CClientDlg]
Type=0
BaseClass=CDialog
HeaderFile=ClientDlg.h
ImplementationFile=ClientDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=CClientDlg

[CLS:CClientSock]
Type=0
BaseClass=CAsyncSocket
HeaderFile=ClientSock.h
ImplementationFile=ClientSock.cpp
Filter=N
VirtualFilter=q
LastObject=CClientSock

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CLIENT_DIALOG]
Type=1
Class=CClientDlg
ControlCount=4
Control1=IDC_LIST1,listbox,1352728835
Control2=IDC_DATA,edit,1350631552
Control3=IDC_SEND,button,1342242827
Control4=IDC_CONNECT,button,1342242827

[DLG:IDD_CONNECT_DLG]
Type=1
Class=CConnectDlg
ControlCount=3
Control1=IDC_IPADDRESS1,SysIPAddress32,1342242816
Control2=IDOK,button,1342242817
Control3=IDCANCEL,button,1342242816

[CLS:CConnectDlg]
Type=0
HeaderFile=ConnectDlg.h
ImplementationFile=ConnectDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CConnectDlg

