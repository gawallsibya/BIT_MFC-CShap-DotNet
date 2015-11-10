// MFC Shape.h : main header file for the MFC SHAPE application
//

#if !defined(AFX_MFCSHAPE_H__86436FB2_15A8_4394_B8A9_BE0B01AE4338__INCLUDED_)
#define AFX_MFCSHAPE_H__86436FB2_15A8_4394_B8A9_BE0B01AE4338__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCShapeApp:
// See MFC Shape.cpp for the implementation of this class
//

class CMFCShapeApp : public CWinApp
{
public:
	CMFCShapeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCShapeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CMFCShapeApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCSHAPE_H__86436FB2_15A8_4394_B8A9_BE0B01AE4338__INCLUDED_)
