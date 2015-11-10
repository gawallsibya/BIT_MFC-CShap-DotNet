#if !defined(AFX_TEXTFORMVIEW_H__C4E0BE09_6D79_11D2_B0B6_0080C7C912B9__INCLUDED_)
#define AFX_TEXTFORMVIEW_H__C4E0BE09_6D79_11D2_B0B6_0080C7C912B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TextFormView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTextFormView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CTextFormView : public CFormView
{
protected:
	CTextFormView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CTextFormView)

// Form Data
public:
	//{{AFX_DATA(CTextFormView)
	enum { IDD = IDD_TEXT_FORM };
	CSpinButtonCtrl	m_ctlSpinY;
	CSpinButtonCtrl	m_ctlSpinX;
	CString	m_strText;
	int		m_nColor;
	UINT	m_nX;
	UINT	m_nY;
	//}}AFX_DATA

// Attributes
public:
	CMDIHelloDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextFormView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CTextFormView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CTextFormView)
	afx_msg void OnDataUpdate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TextFormView.cpp
inline CMDIHelloDoc* CMDIHelloView::GetDocument()
   { return (CMDIHelloDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTFORMVIEW_H__C4E0BE09_6D79_11D2_B0B6_0080C7C912B9__INCLUDED_)
