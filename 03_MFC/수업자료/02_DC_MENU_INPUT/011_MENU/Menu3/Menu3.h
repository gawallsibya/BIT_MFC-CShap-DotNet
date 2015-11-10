// Menu3.h : main header file for the MENU3 application
//

#if !defined(AFX_MENU3_H__3DC4614D_6F3C_4216_A7D2_855F34FAAFE8__INCLUDED_)
#define AFX_MENU3_H__3DC4614D_6F3C_4216_A7D2_855F34FAAFE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMenu3App:
// See Menu3.cpp for the implementation of this class
//

class CMenu3App : public CWinApp
{
public:
	CMenu3App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenu3App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CMenu3App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MENU3_H__3DC4614D_6F3C_4216_A7D2_855F34FAAFE8__INCLUDED_)
