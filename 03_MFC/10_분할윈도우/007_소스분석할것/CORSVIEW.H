// CourseView.h : interface of the CCourseView class
//
/////////////////////////////////////////////////////////////////////////////

class CCourseView : public CTreeView
{
protected: // create from serialization only
	CCourseView();
	DECLARE_DYNCREATE(CCourseView)

// Attributes
public:
	CImageList* GetImage();
	CEnrollDoc* GetDocument();
protected:
	// 이미지 이스트
	CImageList m_ImageList;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCourseView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCourseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCourseView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBeginlabeledit(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CourseView.cpp
inline CEnrollDoc* CCourseView::GetDocument()
   { return (CEnrollDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
