// VideoShop2.h : main header file for the VIDEOSHOP2 application
//

#if !defined(AFX_VIDEOSHOP2_H__83BD48A5_399B_11D2_941F_006097DCA739__INCLUDED_)
#define AFX_VIDEOSHOP2_H__83BD48A5_399B_11D2_941F_006097DCA739__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CVideoShop2App:
// See VideoShop2.cpp for the implementation of this class
//

class CVideoShop2App : public CWinApp
{
public:
	CVideoShop2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVideoShop2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CVideoShop2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIDEOSHOP2_H__83BD48A5_399B_11D2_941F_006097DCA739__INCLUDED_)
