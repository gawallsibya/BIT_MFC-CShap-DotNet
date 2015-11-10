#if !defined(AFX_WINTHREAD_UI_H__C7A938C5_2F0A_41F5_B570_AC54EA3C5352__INCLUDED_)
#define AFX_WINTHREAD_UI_H__C7A938C5_2F0A_41F5_B570_AC54EA3C5352__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WinThread_UI.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CWinThread_UI thread

class CWinThread_UI : public CWinThread
{
	DECLARE_DYNCREATE(CWinThread_UI)
protected:
	CWinThread_UI();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWinThread_UI)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CWinThread_UI();

	// Generated message map functions
	//{{AFX_MSG(CWinThread_UI)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINTHREAD_UI_H__C7A938C5_2F0A_41F5_B570_AC54EA3C5352__INCLUDED_)
