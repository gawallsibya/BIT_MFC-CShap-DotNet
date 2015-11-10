// Web.h : main header file for the WEB application
//

#if !defined(AFX_WEB_H__AAF75F31_1B77_41C3_91CF_B4F5FCD6A69D__INCLUDED_)
#define AFX_WEB_H__AAF75F31_1B77_41C3_91CF_B4F5FCD6A69D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CWebApp:
// See Web.cpp for the implementation of this class
//

class CWebApp : public CWinApp
{
public:
	CWebApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWebApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CWebApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WEB_H__AAF75F31_1B77_41C3_91CF_B4F5FCD6A69D__INCLUDED_)
