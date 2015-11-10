// Page.h : header file
//

#ifndef __PAGE_H__
#define __PAGE_H__

/////////////////////////////////////////////////////////////////////////////
// CMyPage1 dialog

class CMyPage1 : public CPropertyPage
{
	DECLARE_DYNCREATE(CMyPage1)

// Construction
public:
	CMyPage1();
	~CMyPage1();

// Dialog Data
	//{{AFX_DATA(CMyPage1)
	enum { IDD = IDD_PROPPAGE1 };
	CSpinButtonCtrl	m_Spin;
	CProgressCtrl	m_Progress;
	CAnimateCtrl	m_Animate;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CMyPage1)
	public:
	virtual BOOL OnSetActive();
	virtual LRESULT OnWizardNext();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CMyPage1)
	virtual BOOL OnInitDialog();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////
// CMyPage2 dialog

class CMyPage2 : public CPropertyPage
{
	DECLARE_DYNCREATE(CMyPage2)

// Construction
public:
	void CurrentFillColor();
	CMyPage2();
	~CMyPage2();

// Dialog Data
	//{{AFX_DATA(CMyPage2)
	enum { IDD = IDD_PROPPAGE2 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CMyPage2)
	public:
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CMyPage2)
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////
// CMyPage3 dialog

class CMyPage3 : public CPropertyPage
{
	DECLARE_DYNCREATE(CMyPage3)

// Construction
public:
	void FillTree();
	void FillList();
	CMyPage3();
	~CMyPage3();

// Dialog Data
	//{{AFX_DATA(CMyPage3)
	enum { IDD = IDD_PROPPAGE3 };
	CListCtrl	m_List;
	CTreeCtrl	m_Tree;
	//}}AFX_DATA
    

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CMyPage3)
	public:
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CImageList m_imageList; // 트리 컨트롤에서 사용할 이미지 관리
	CImageList m_imageTree; // 리스트 컨트롤에서 사용할 이미지 관리
	CImageList m_imageLarge; // 리스트 컨트롤에서 사용할 큰 아이콘 

	// Generated message map functions
	//{{AFX_MSG(CMyPage3)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnReportType();
	afx_msg void OnListType();
	afx_msg void OnIconType();
	afx_msg void OnSmallType();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

#endif // __PAGE_H__
