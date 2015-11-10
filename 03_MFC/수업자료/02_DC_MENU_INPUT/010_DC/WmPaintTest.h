// WmPaintTest.h : main header file for the WMPAINTTEST application
//

#if !defined(AFX_WMPAINTTEST_H__7519ECC5_4C3A_497B_BAAB_F0D5AD75C61A__INCLUDED_)
#define AFX_WMPAINTTEST_H__7519ECC5_4C3A_497B_BAAB_F0D5AD75C61A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CWmPaintTestApp:
// See WmPaintTest.cpp for the implementation of this class
//

class CWmPaintTestApp : public CWinApp
{
public:
	CWmPaintTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWmPaintTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CWmPaintTestApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WMPAINTTEST_H__7519ECC5_4C3A_497B_BAAB_F0D5AD75C61A__INCLUDED_)
