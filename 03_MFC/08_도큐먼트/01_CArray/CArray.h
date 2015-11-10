// CArray.h : main header file for the CARRAY application
//

#if !defined(AFX_CARRAY_H__505BB940_0E9D_4308_A3E7_918106C5C0C0__INCLUDED_)
#define AFX_CARRAY_H__505BB940_0E9D_4308_A3E7_918106C5C0C0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCArrayApp:
// See CArray.cpp for the implementation of this class
//

class CCArrayApp : public CWinApp
{
public:
	CCArrayApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCArrayApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCArrayApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARRAY_H__505BB940_0E9D_4308_A3E7_918106C5C0C0__INCLUDED_)
