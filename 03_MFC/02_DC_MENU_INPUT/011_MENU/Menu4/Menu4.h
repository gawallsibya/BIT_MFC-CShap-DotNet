// Menu4.h : main header file for the MENU4 application
//

#if !defined(AFX_MENU4_H__FE4421AF_3E08_44E9_9F97_7E3DD7B0D174__INCLUDED_)
#define AFX_MENU4_H__FE4421AF_3E08_44E9_9F97_7E3DD7B0D174__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMenu4App:
// See Menu4.cpp for the implementation of this class
//

class CMenu4App : public CWinApp
{
public:
	CMenu4App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenu4App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CMenu4App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MENU4_H__FE4421AF_3E08_44E9_9F97_7E3DD7B0D174__INCLUDED_)
