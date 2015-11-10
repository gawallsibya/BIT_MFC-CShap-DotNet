// CriticalSection.h : main header file for the CRITICALSECTION application
//

#if !defined(AFX_CRITICALSECTION_H__21B71722_E465_4FDD_AFF7_F15BB1DD8D5A__INCLUDED_)
#define AFX_CRITICALSECTION_H__21B71722_E465_4FDD_AFF7_F15BB1DD8D5A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCriticalSectionApp:
// See CriticalSection.cpp for the implementation of this class
//

class CCriticalSectionApp : public CWinApp
{
public:
	CCriticalSectionApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCriticalSectionApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCriticalSectionApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CRITICALSECTION_H__21B71722_E465_4FDD_AFF7_F15BB1DD8D5A__INCLUDED_)
