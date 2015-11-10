// MOUSEEC.h : main header file for the MOUSEEC application
//

#if !defined(AFX_MOUSEEC_H__F839CACF_6C06_473B_B517_67AAE774FCB2__INCLUDED_)
#define AFX_MOUSEEC_H__F839CACF_6C06_473B_B517_67AAE774FCB2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMOUSEECApp:
// See MOUSEEC.cpp for the implementation of this class
//

class CMOUSEECApp : public CWinApp
{
public:
	CMOUSEECApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMOUSEECApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMOUSEECApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOUSEEC_H__F839CACF_6C06_473B_B517_67AAE774FCB2__INCLUDED_)
