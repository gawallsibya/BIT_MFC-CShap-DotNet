// LeftView.h : interface of the CLeftView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LEFTVIEW_H__4798FD6F_3B8A_11D2_A360_D86A33074DD9__INCLUDED_)
#define AFX_LEFTVIEW_H__4798FD6F_3B8A_11D2_A360_D86A33074DD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CExplorerTestDoc;

class CLeftView : public CTreeView
{
protected: // create from serialization only
	CLeftView();
	DECLARE_DYNCREATE(CLeftView)

public:
	CExplorerTestDoc* GetDocument();

private:
	// variables
	CImageList		m_imageList;

	BOOL			m_bRButtonDown;
	CPoint			m_ptRButton;
	HTREEITEM		m_hContextItem;
	BOOL			m_bContextCopy;

	// Drag & Drop
	COleDropTarget	m_dropTarget;
	CLIPFORMAT		m_cbFormat;

	COleDataObject*	m_pDataObject;
	DROPEFFECT		m_dropEffect;

	// functions
	void		GetDriveNames(CStringArray* driveArray);
	void		InitFolders(CStringArray* driveNames);
	HTREEITEM	DisplayDrive(CString strDriveName, int nImage);
	HTREEITEM	InsertFolder(CString strFolderName, HTREEITEM hParentItem);
	CString		GetFullPathName(HTREEITEM hItem);
	void		DeleteChildItems(HTREEITEM hItem);
	BOOL		IsDiskDrive(HTREEITEM hTreeItem);

	void		ViewContextMenu(int nSubIndex, CPoint point);
	CString		GetNewFolderName(HTREEITEM hTreeItem);

	void		CopyFilesToFolder(CString strFolderName);
	BOOL		DeleteDirectory(CString strFolderName, HTREEITEM hTreeItem);

public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeftView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnDragLeave();
	virtual DROPEFFECT OnDragOver(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point);
	virtual BOOL OnDrop(COleDataObject* pDataObject, DROPEFFECT dropEffect, CPoint point);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
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
	afx_msg void OnFileRename();
	afx_msg void OnBeginlabeledit(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnFolderNew();
	afx_msg void OnFileDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in LeftView.cpp
inline CExplorerTestDoc* CLeftView::GetDocument()
   { return (CExplorerTestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEFTVIEW_H__4798FD6F_3B8A_11D2_A360_D86A33074DD9__INCLUDED_)
