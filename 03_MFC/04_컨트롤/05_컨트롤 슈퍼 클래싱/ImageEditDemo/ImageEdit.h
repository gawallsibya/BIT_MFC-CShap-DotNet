#if !defined(AFX_IMAGEEDIT_H__8C13DB38_7C81_4BD6_9F57_25D195978BB8__INCLUDED_)
#define AFX_IMAGEEDIT_H__8C13DB38_7C81_4BD6_9F57_25D195978BB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ImageEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CImageEdit window

class CImageEdit : public CEdit
{
// Construction
public:
	CImageEdit();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	HBRUSH m_hBrush;
	virtual ~CImageEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CImageEdit)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnUpdate();
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEEDIT_H__8C13DB38_7C81_4BD6_9F57_25D195978BB8__INCLUDED_)
