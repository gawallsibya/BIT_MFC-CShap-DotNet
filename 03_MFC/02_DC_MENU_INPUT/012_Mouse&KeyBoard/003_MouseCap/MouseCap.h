// MouseCap.h : main header file for the MOUSECAP application
//

#if !defined(AFX_MOUSECAP_H__501B5A76_3568_4D84_9E87_9C7CC98CA516__INCLUDED_)
#define AFX_MOUSECAP_H__501B5A76_3568_4D84_9E87_9C7CC98CA516__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMouseCapApp:
// See MouseCap.cpp for the implementation of this class
//

class CMouseCapApp : public CWinApp
{
public:
	CMouseCapApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMouseCapApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMouseCapApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOUSECAP_H__501B5A76_3568_4D84_9E87_9C7CC98CA516__INCLUDED_)
