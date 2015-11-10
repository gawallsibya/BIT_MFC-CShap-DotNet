// CriticalSectionDemo.h : main header file for the CRITICALSECTIONDEMO application
//

#if !defined(AFX_CRITICALSECTIONDEMO_H__6FD2E9CA_34C7_463B_89A2_11342EC107AC__INCLUDED_)
#define AFX_CRITICALSECTIONDEMO_H__6FD2E9CA_34C7_463B_89A2_11342EC107AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCriticalSectionDemoApp:
// See CriticalSectionDemo.cpp for the implementation of this class
//

class CCriticalSectionDemoApp : public CWinApp
{
public:
	CCriticalSectionDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCriticalSectionDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCriticalSectionDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CRITICALSECTIONDEMO_H__6FD2E9CA_34C7_463B_89A2_11342EC107AC__INCLUDED_)
