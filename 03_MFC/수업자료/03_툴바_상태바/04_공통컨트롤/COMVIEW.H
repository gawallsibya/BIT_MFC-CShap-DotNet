// ComView.h : interface of the CComDlgView class
//
/////////////////////////////////////////////////////////////////////////////

class CComDlgView : public CView
{
protected: // create from serialization only
	CComDlgView();
	DECLARE_DYNCREATE(CComDlgView)

// Attributes
public:
	CComDlgDoc* GetDocument();
protected:
	CFindReplaceDialog* pDlg;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComDlgView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CComDlgView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CComDlgView)
	afx_msg void OnComdlgOpen();
	afx_msg void OnComdlgSaveas();
	afx_msg void OnComdlgColor();
	afx_msg void OnComdlgFont();
	afx_msg void OnComdlgPrint();
	afx_msg void OnComdlgPrintersetup();
	afx_msg void OnComdlgPagesetup();
	afx_msg void OnComdlgFind();
	afx_msg void OnComdlgReplace();
	afx_msg void OnComdlgDelete();
	//}}AFX_MSG
	afx_msg LRESULT OnFindReplaceMsg(UINT wParam, LONG lParam);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ComView.cpp
inline CComDlgDoc* CComDlgView::GetDocument()
   { return (CComDlgDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
