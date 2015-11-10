#if !defined(AFX_MYDIALOG_H__4136AE65_0A81_4EAC_9398_7CBC862D15D5__INCLUDED_)
#define AFX_MYDIALOG_H__4136AE65_0A81_4EAC_9398_7CBC862D15D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyDialog dialog

#include "NumEdit.h"
#include "xpbutton.h"
class CMyDialog : public CDialog
{
// Construction
public:
	CMyDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMyDialog)
	enum { IDD = IDD_DIALOG1 };
	CXPButton	m_btn2;
	CXPButton	m_btn1;
	CNumEdit	m_edit2;
	CNumEdit	m_edit1;
	CSpinButtonCtrl	m_spin2;
	CSpinButtonCtrl	m_spin1;
	int		m_cx;
	int		m_cy;
	int		m_color;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMyDialog)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYDIALOG_H__4136AE65_0A81_4EAC_9398_7CBC862D15D5__INCLUDED_)
