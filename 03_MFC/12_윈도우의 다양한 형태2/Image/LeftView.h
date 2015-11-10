#if !defined(AFX_LEFTVIEW_H__4912382E_9A46_43D8_B2CB_83BEDB3E836C__INCLUDED_)
#define AFX_LEFTVIEW_H__4912382E_9A46_43D8_B2CB_83BEDB3E836C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LeftView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLeftView view
#include <afxcview.h>

class CLeftView : public CTreeView
{
protected:
	CLeftView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CLeftView)

// Attributes
public:

// Operations
public:
	void Refresh( CString path );

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeftView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CLeftView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CLeftView)
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeFolder();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEFTVIEW_H__4912382E_9A46_43D8_B2CB_83BEDB3E836C__INCLUDED_)
