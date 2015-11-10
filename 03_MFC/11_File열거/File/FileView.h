// FileView.h : interface of the CFileView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILEVIEW_H__AAAEEF32_582E_4A69_B8A9_6C37D818D42C__INCLUDED_)
#define AFX_FILEVIEW_H__AAAEEF32_582E_4A69_B8A9_6C37D818D42C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFileView : public CListView
{
protected: // create from serialization only
	CFileView();
	DECLARE_DYNCREATE(CFileView)

// Attributes
public:
	CFileDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void Refresh( char* dir);
	virtual ~CFileView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFileView)
	afx_msg void OnViewIcon();
	afx_msg void OnViewList();
	afx_msg void OnViewReport();
	afx_msg void OnViewSmall();
	afx_msg void OnViewChange();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FileView.cpp
inline CFileDoc* CFileView::GetDocument()
   { return (CFileDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEVIEW_H__AAAEEF32_582E_4A69_B8A9_6C37D818D42C__INCLUDED_)
