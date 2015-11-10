// HTStaticDemo.h : main header file for the HTSTATICDEMO application
//

#if !defined(AFX_HTSTATICDEMO_H__D234D75B_DFA7_4131_A451_9FD46205E8CB__INCLUDED_)
#define AFX_HTSTATICDEMO_H__D234D75B_DFA7_4131_A451_9FD46205E8CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHTStaticDemoApp:
// See HTStaticDemo.cpp for the implementation of this class
//

class CHTStaticDemoApp : public CWinApp
{
public:
	CHTStaticDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHTStaticDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHTStaticDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HTSTATICDEMO_H__D234D75B_DFA7_4131_A451_9FD46205E8CB__INCLUDED_)
