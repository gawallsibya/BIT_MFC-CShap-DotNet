// MDIHello.h : main header file for the MDIHELLO application
//

#if !defined(AFX_MDIHELLO_H__C4E0BDF5_6D79_11D2_B0B6_0080C7C912B9__INCLUDED_)
#define AFX_MDIHELLO_H__C4E0BDF5_6D79_11D2_B0B6_0080C7C912B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMDIHelloApp:
// See MDIHello.cpp for the implementation of this class
//

class CMDIHelloApp : public CWinApp
{
public:
	CMDIHelloApp();
protected:
	CMultiDocTemplate* m_pFormTemplate;
public:
	CMultiDocTemplate* GetFormTemplate() const
		{ return m_pFormTemplate; }

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMDIHelloApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMDIHelloApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDIHELLO_H__C4E0BDF5_6D79_11D2_B0B6_0080C7C912B9__INCLUDED_)
