// CMap.h : main header file for the CMAP application
//

#if !defined(AFX_CMAP_H__383987A5_7699_4927_B8F5_CDA16A4E4598__INCLUDED_)
#define AFX_CMAP_H__383987A5_7699_4927_B8F5_CDA16A4E4598__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCMapApp:
// See CMap.cpp for the implementation of this class
//

class CCMapApp : public CWinApp
{
public:
	CCMapApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCMapApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCMapApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMAP_H__383987A5_7699_4927_B8F5_CDA16A4E4598__INCLUDED_)
