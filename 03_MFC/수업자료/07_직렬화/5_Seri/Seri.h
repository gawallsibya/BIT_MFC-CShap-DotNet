// Seri.h : main header file for the SERI application
//

#if !defined(AFX_SERI_H__0CD32F55_8245_47F7_B2B1_B35CA23F4B18__INCLUDED_)
#define AFX_SERI_H__0CD32F55_8245_47F7_B2B1_B35CA23F4B18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSeriApp:
// See Seri.cpp for the implementation of this class
//

class CSeriApp : public CWinApp
{
public:
	CSeriApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSeriApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSeriApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERI_H__0CD32F55_8245_47F7_B2B1_B35CA23F4B18__INCLUDED_)
