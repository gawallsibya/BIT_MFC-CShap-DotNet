; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFileCopyDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FileCopy.h"

ClassCount=2
Class1=CFileCopyApp
Class2=CFileCopyDlg

ResourceCount=3
Resource2=IDR_MAINFRAME
Resource3=IDD_FILECOPY_DIALOG

[CLS:CFileCopyApp]
Type=0
HeaderFile=FileCopy.h
ImplementationFile=FileCopy.cpp
Filter=N

[CLS:CFileCopyDlg]
Type=0
HeaderFile=FileCopyDlg.h
ImplementationFile=FileCopyDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_FILECOPY_DIALOG]
Type=1
Class=CFileCopyDlg
ControlCount=5
Control1=IDC_LIST1,listbox,1352728835
Control2=IDC_FROM,button,1342242816
Control3=IDC_TO,button,1342242816
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_START_COPY,button,1342242816

