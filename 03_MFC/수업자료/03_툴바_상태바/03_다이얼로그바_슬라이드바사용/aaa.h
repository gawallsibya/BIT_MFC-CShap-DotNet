// aaa.h : main header file for the AAA application
//

#if !defined(AFX_AAA_H__3643980B_755F_476D_9B8E_53734C7450BA__INCLUDED_)
#define AFX_AAA_H__3643980B_755F_476D_9B8E_53734C7450BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CAaaApp:
// See aaa.cpp for the implementation of this class
//

class CAaaApp : public CWinApp
{
public:
	CAaaApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAaaApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CAaaApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AAA_H__3643980B_755F_476D_9B8E_53734C7450BA__INCLUDED_)
