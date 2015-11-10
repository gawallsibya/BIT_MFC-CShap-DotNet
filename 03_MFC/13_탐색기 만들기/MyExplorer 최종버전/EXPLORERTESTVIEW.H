// ExplorerTestView.h : interface of the CExplorerTestView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPLORERTESTVIEW_H__4798FD6D_3B8A_11D2_A360_D86A33074DD9__INCLUDED_)
#define AFX_EXPLORERTESTVIEW_H__4798FD6D_3B8A_11D2_A360_D86A33074DD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxadv.h>	// CSharedFile

/////////////////////////////////////////////////////////////////////////////
//	Report 형식일때 헤더에 나오는 이름과 가로의 크기.

static	char*	cListHeader[] = {"이름", "크기", "종류", "바뀐 날짜", NULL};
const	int		nHeaderWidth[] = {130, 60, 70, 80};

class CExplorerTestCntrItem;
/////////////////////////////////////////////////////////////////////////////

class CExplorerTestView : public CListView
{
protected: // create from serialization only
	CExplorerTestView();
	DECLARE_DYNCREATE(CExplorerTestView)

// Attributes
public:
	CExplorerTestDoc* GetDocument();
	// m_pSelection holds the selection to the current CExplorerTestCntrItem.
	// For many applications, such a member variable isn't adequate to
	//  represent a selection, such as a multiple selection or a selection
	//  of objects that are not CExplorerTestCntrItem objects.  This selection
	//  mechanism is provided just to help you get started.

	// TODO: replace this selection mechanism with one appropriate to your app.
	CExplorerTestCntrItem* m_pSelection;

public:
	void		SetFileList();

private:
	// variables
	CImageList		m_imageList;
	CImageList		m_imageList32;

	CObList*		m_pFileList;

	// Drag & Drop
	COleDropTarget	m_dropTarget;
	CLIPFORMAT		m_cbFormat;

	// functions
	void		InitListHeader();
	void		DisplayListView();
	void		SetEnableMenu(CMenu* pMenu);
	BOOL		DeleteFiles(int nItem, CString strPath);

	UINT		GetCurrentID();
	//void		TransferData(CSharedFile* pSharedFile);

public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExplorerTestView)
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
	virtual ~CExplorerTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CExplorerTestView)
	afx_msg void OnDestroy();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnInsertObject();
	afx_msg void OnCancelEditCntr();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnViewSmallicon();
	afx_msg void OnViewLargeicon();
	afx_msg void OnViewList();
	afx_msg void OnViewDetails();
	afx_msg void OnInformation();
	afx_msg void OnBeginlabeledit(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnFileRename();
	afx_msg void OnFileDelete();
	afx_msg void OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemchanged(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	afx_msg void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ExplorerTestView.cpp
inline CExplorerTestDoc* CExplorerTestView::GetDocument()
   { return (CExplorerTestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPLORERTESTVIEW_H__4798FD6D_3B8A_11D2_A360_D86A33074DD9__INCLUDED_)
