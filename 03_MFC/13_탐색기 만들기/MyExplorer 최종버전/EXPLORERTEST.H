// ExplorerTest.h : main header file for the EXPLORERTEST application
//

#if !defined(AFX_EXPLORERTEST_H__4798FD65_3B8A_11D2_A360_D86A33074DD9__INCLUDED_)
#define AFX_EXPLORERTEST_H__4798FD65_3B8A_11D2_A360_D86A33074DD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CExplorerTestApp:
// See ExplorerTest.cpp for the implementation of this class
//

class CExplorerTestApp : public CWinApp
{
public:
	CExplorerTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExplorerTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CExplorerTestApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPLORERTEST_H__4798FD65_3B8A_11D2_A360_D86A33074DD9__INCLUDED_)
