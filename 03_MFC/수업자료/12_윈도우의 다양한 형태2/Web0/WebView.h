// WebView.h : interface of the CWebView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WEBVIEW_H__5C7697EA_D88E_423B_90C6_5EA42BA68DBE__INCLUDED_)
#define AFX_WEBVIEW_H__5C7697EA_D88E_423B_90C6_5EA42BA68DBE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CWebView : public CHtmlView
{
protected: // create from serialization only
	CWebView();
	DECLARE_DYNCREATE(CWebView)

// Attributes
public:
	CWebDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWebView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnTitleChange(LPCTSTR lpszText);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWebView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWebView)
	afx_msg void OnGoBack();
	afx_msg void OnGoHome();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in WebView.cpp
inline CWebDoc* CWebView::GetDocument()
   { return (CWebDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WEBVIEW_H__5C7697EA_D88E_423B_90C6_5EA42BA68DBE__INCLUDED_)
