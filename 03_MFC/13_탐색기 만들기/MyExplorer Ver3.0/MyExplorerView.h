// MyExplorerView.h : interface of the CMyExplorerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYEXPLORERVIEW_H__A42A5E8A_CAF9_42A7_A85B_7C3189877F78__INCLUDED_)
#define AFX_MYEXPLORERVIEW_H__A42A5E8A_CAF9_42A7_A85B_7C3189877F78__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMyExplorerCntrItem;

class CMyExplorerView : public CListView
{
	// variables
	CImageList		m_imageList;
	CImageList		m_imageList32;

	CObList*		m_pFileList;

	// Drag & Drop
	COleDropTarget	m_dropTarget;
	CLIPFORMAT		m_cbFormat;

protected: // create from serialization only
	CMyExplorerView();
	DECLARE_DYNCREATE(CMyExplorerView)

// Attributes
public:
	CMyExplorerDoc* GetDocument();
	// m_pSelection holds the selection to the current CMyExplorerCntrItem.
	// For many applications, such a member variable isn't adequate to
	//  represent a selection, such as a multiple selection or a selection
	//  of objects that are not CMyExplorerCntrItem objects.  This selection
	//  mechanism is provided just to help you get started.

	// TODO: replace this selection mechanism with one appropriate to your app.
	CMyExplorerCntrItem* m_pSelection;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyExplorerView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL IsSelected(const CObject* pDocItem) const;// Container support
	//}}AFX_VIRTUAL

// Implementation
public:
	void DisplayListView();
	void SetFileList();
	void InitListHeader();
	virtual ~CMyExplorerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyExplorerView)
	afx_msg void OnDestroy();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnInsertObject();
	afx_msg void OnCancelEditCntr();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	afx_msg void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MyExplorerView.cpp
inline CMyExplorerDoc* CMyExplorerView::GetDocument()
   { return (CMyExplorerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYEXPLORERVIEW_H__A42A5E8A_CAF9_42A7_A85B_7C3189877F78__INCLUDED_)
