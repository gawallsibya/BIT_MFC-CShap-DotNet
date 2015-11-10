// TextProgressDemo.h : main header file for the TEXTPROGRESSDEMO application
//

#if !defined(AFX_TEXTPROGRESSDEMO_H__BC2A86FE_B667_4412_9A50_B9D79CCF27B8__INCLUDED_)
#define AFX_TEXTPROGRESSDEMO_H__BC2A86FE_B667_4412_9A50_B9D79CCF27B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTextProgressDemoApp:
// See TextProgressDemo.cpp for the implementation of this class
//

class CTextProgressDemoApp : public CWinApp
{
public:
	CTextProgressDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextProgressDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTextProgressDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTPROGRESSDEMO_H__BC2A86FE_B667_4412_9A50_B9D79CCF27B8__INCLUDED_)
