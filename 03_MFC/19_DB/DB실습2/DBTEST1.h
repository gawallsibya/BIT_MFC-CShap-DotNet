// DBTEST1.h : main header file for the DBTEST1 application
//

#if !defined(AFX_DBTEST1_H__9EFB1A20_E061_4A8D_A025_A41A45FA9B04__INCLUDED_)
#define AFX_DBTEST1_H__9EFB1A20_E061_4A8D_A025_A41A45FA9B04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDBTEST1App:
// See DBTEST1.cpp for the implementation of this class
//

class CDBTEST1App : public CWinApp
{
public:
	CDBTEST1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDBTEST1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDBTEST1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DBTEST1_H__9EFB1A20_E061_4A8D_A025_A41A45FA9B04__INCLUDED_)
