// StudentView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStudentView view

class CStudentView : public CListView
{
protected:
	CStudentView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CStudentView)

// Attributes
public:
	CImageList* GetImageSmall();
	CImageList* GetImageLarge();
	static int CALLBACK CompareFunc(LPARAM lParam1, LPARAM lParam2,
									LPARAM lParamSort);
protected:
	// 이미지 리스트
	CImageList m_ImageLarge;	// 큰 아이콘
	CImageList m_ImageSmall;	// 작은 아이콘
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL
	CEnrollDoc* GetDocument()
	{
		return (CEnrollDoc*)m_pDocument;
	}
// Implementation
protected:
	virtual ~CStudentView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CStudentView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnBeginlabeledit(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnColumnclick(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
