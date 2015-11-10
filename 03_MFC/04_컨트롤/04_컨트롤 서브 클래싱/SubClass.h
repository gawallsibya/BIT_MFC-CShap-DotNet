// SubClass.h : main header file for the SUBCLASS application
//

#if !defined(AFX_SUBCLASS_H__4EDB607B_516A_4565_8D8F_66E3602AC7CA__INCLUDED_)
#define AFX_SUBCLASS_H__4EDB607B_516A_4565_8D8F_66E3602AC7CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSubClassApp:
// See SubClass.cpp for the implementation of this class
//

class CSubClassApp : public CWinApp
{
public:
	CSubClassApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubClassApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CSubClassApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBCLASS_H__4EDB607B_516A_4565_8D8F_66E3602AC7CA__INCLUDED_)
