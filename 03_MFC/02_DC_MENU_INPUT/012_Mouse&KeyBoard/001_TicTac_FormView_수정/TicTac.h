// TicTac.h : main header file for the TICTAC application
//

#if !defined(AFX_TICTAC_H__12B16E5D_67E6_4F8C_BA11_3EF6C9912B16__INCLUDED_)
#define AFX_TICTAC_H__12B16E5D_67E6_4F8C_BA11_3EF6C9912B16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTicTacApp:
// See TicTac.cpp for the implementation of this class
//

class CTicTacApp : public CWinApp
{
public:
	CTicTacApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTicTacApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTicTacApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TICTAC_H__12B16E5D_67E6_4F8C_BA11_3EF6C9912B16__INCLUDED_)
