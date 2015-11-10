#if !defined(AFX_MYTHREAD_H__49F14621_35B4_11D2_A843_00A02486730F__INCLUDED_)
#define AFX_MYTHREAD_H__49F14621_35B4_11D2_A843_00A02486730F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyThread.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyThread thread
#include "CountDlg.h"

class CMyThread : public CWinThread
{
	DECLARE_DYNCREATE(CMyThread)
protected:
	CMyThread();           // protected constructor used by dynamic creation

// Attributes
public:
	CCountDlg*  m_pDlg; // 다이얼로그의 객체 포인터
// Operations
public:
	void SetOwner(CCountDlg*  pDlg); 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyThread)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual int Run();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMyThread();

	// Generated message map functions
	//{{AFX_MSG(CMyThread)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYTHREAD_H__49F14621_35B4_11D2_A843_00A02486730F__INCLUDED_)
