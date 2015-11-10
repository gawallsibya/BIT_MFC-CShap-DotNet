// DialogDemo.h : main header file for the DIALOGDEMO application
//

#if !defined(AFX_DIALOGDEMO_H__4157A06A_B249_4EB1_84E8_76AEAC89E04C__INCLUDED_)
#define AFX_DIALOGDEMO_H__4157A06A_B249_4EB1_84E8_76AEAC89E04C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDialogDemoApp:
// See DialogDemo.cpp for the implementation of this class
//

class CDialogDemoApp : public CWinApp
{
public:
	CDialogDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDialogDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGDEMO_H__4157A06A_B249_4EB1_84E8_76AEAC89E04C__INCLUDED_)
