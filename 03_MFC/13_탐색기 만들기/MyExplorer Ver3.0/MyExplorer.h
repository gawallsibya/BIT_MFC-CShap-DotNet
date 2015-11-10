// MyExplorer.h : main header file for the MYEXPLORER application
//

#if !defined(AFX_MYEXPLORER_H__E0F39083_7FA6_46FC_A34F_E921835424EC__INCLUDED_)
#define AFX_MYEXPLORER_H__E0F39083_7FA6_46FC_A34F_E921835424EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyExplorerApp:
// See MyExplorer.cpp for the implementation of this class
//

class CMyExplorerApp : public CWinApp
{
public:
	CMyExplorerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyExplorerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMyExplorerApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYEXPLORER_H__E0F39083_7FA6_46FC_A34F_E921835424EC__INCLUDED_)
