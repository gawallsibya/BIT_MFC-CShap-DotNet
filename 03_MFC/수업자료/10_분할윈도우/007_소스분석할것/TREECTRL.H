// MyTreeCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyTreeCtrl window

class CMyTreeCtrl : public CTreeCtrl
{
// Construction
public:
	CMyTreeCtrl();

// Attributes
public:
	HTREEITEM AddItem(HTREEITEM hParent, LPSTR szText, 
					  HTREEITEM hInsAfter, int image, int selImage);
	void SetNewStyle(long lStyleMask, BOOL bSetBits);
	BOOL IsChildNodeOf(HTREEITEM hItemChild, HTREEITEM hItemParent);
	BOOL TransferItem(HTREEITEM hItemDrag, HTREEITEM hItemDrop);
protected:
	BOOL m_bDragging;
	HTREEITEM m_hItemDrag;
	HTREEITEM m_hItemDrop;
	CImageList* m_pDragImage;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyTreeCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyTreeCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyTreeCtrl)
	afx_msg void OnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
