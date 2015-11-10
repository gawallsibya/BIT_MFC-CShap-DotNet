// LeftView.h : interface of the CLeftView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LEFTVIEW_H__9B78EFB1_6A74_432A_A71F_303D692BBDFA__INCLUDED_)
#define AFX_LEFTVIEW_H__9B78EFB1_6A74_432A_A71F_303D692BBDFA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMyExplorerDoc;

class CLeftView : public CTreeView
{
public:
	// Drag & Drop
	COleDropTarget	m_dropTarget;
	CLIPFORMAT		m_cbFormat;

	COleDataObject*	m_pDataObject;
	DROPEFFECT		m_dropEffect;

	// variables
	CImageList		m_imageList;

	// 컨텍스트 메뉴 
	BOOL			m_bRButtonDown;			// 마우스 우측 버튼이 눌렸는지 여부
	CPoint			m_ptRButton;			// 마우스 우측 버튼 클릭시 위치
	HTREEITEM		m_hContextItem;			// 마우스 우측 버튼으로 선택된 아이템 핸들


protected: // create from serialization only
	CLeftView();
	DECLARE_DYNCREATE(CLeftView)

// Attributes
public:
	CMyExplorerDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeftView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	void ViewContextMenu(int nSubIndex, CPoint point);
	void DeleteChildItems(HTREEITEM hItem);
	CString GetFullPathName(HTREEITEM hItem);
	HTREEITEM InsertFolder(CString strFolderName, HTREEITEM hParentItem);
	HTREEITEM DisplayDrive(CString strDriveName, int nImage);
	void InitFolders(CStringArray* driveNames);
	void GetDriveNames(CStringArray* driveArray);
	virtual ~CLeftView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLeftView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnItemexpanding(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnCaptureChanged(CWnd *pWnd);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in LeftView.cpp
inline CMyExplorerDoc* CLeftView::GetDocument()
   { return (CMyExplorerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEFTVIEW_H__9B78EFB1_6A74_432A_A71F_303D692BBDFA__INCLUDED_)
