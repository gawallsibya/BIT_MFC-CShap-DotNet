// VisualKB.h : main header file for the VISUALKB application
//

#if !defined(AFX_VISUALKB_H__467156D6_55D0_4BFE_A189_8D7F8A8D7BED__INCLUDED_)
#define AFX_VISUALKB_H__467156D6_55D0_4BFE_A189_8D7F8A8D7BED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CVisualKBApp:
// See VisualKB.cpp for the implementation of this class
//

class CVisualKBApp : public CWinApp
{
public:
	CVisualKBApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVisualKBApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CVisualKBApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VISUALKB_H__467156D6_55D0_4BFE_A189_8D7F8A8D7BED__INCLUDED_)
