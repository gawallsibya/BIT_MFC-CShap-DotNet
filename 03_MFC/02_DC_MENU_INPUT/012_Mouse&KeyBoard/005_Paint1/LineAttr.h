#if !defined(AFX_LINEATTR_H__44E3064E_63FB_4F16_B89B_D26BB2EDB09F__INCLUDED_)
#define AFX_LINEATTR_H__44E3064E_63FB_4F16_B89B_D26BB2EDB09F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LineAttr.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLineAttr dialog

class CLineAttr : public CDialog
{
// Construction
public:
	CLineAttr(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLineAttr)
	enum { IDD = IDD_DIALOG1 };
	BYTE	m_GColor;
	BYTE	m_BColor;
	BYTE	m_RColor;
	int		m_PenWidth;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLineAttr)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLineAttr)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINEATTR_H__44E3064E_63FB_4F16_B89B_D26BB2EDB09F__INCLUDED_)
