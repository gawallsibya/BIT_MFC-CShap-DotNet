// ImageEditDemo.h : main header file for the IMAGEEDITDEMO application
//

#if !defined(AFX_IMAGEEDITDEMO_H__35E2FC5C_D331_48C2_BBD7_9E3E5B32B609__INCLUDED_)
#define AFX_IMAGEEDITDEMO_H__35E2FC5C_D331_48C2_BBD7_9E3E5B32B609__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CImageEditDemoApp:
// See ImageEditDemo.cpp for the implementation of this class
//

class CImageEditDemoApp : public CWinApp
{
public:
	CImageEditDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageEditDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CImageEditDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEEDITDEMO_H__35E2FC5C_D331_48C2_BBD7_9E3E5B32B609__INCLUDED_)
