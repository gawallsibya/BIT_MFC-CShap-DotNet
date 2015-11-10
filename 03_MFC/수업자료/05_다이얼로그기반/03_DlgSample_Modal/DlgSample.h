// DlgSample.h : main header file for the DLGSAMPLE application
//

#if !defined(AFX_DLGSAMPLE_H__1152D0C5_1188_40C6_9833_A5224ACC8485__INCLUDED_)
#define AFX_DLGSAMPLE_H__1152D0C5_1188_40C6_9833_A5224ACC8485__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDlgSampleApp:
// See DlgSample.cpp for the implementation of this class
//

class CDlgSampleApp : public CWinApp
{
public:
	CDlgSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CDlgSampleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSAMPLE_H__1152D0C5_1188_40C6_9833_A5224ACC8485__INCLUDED_)
