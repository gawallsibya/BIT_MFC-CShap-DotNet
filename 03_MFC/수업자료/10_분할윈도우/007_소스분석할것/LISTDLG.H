// ListPropertyDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CListPropertyDlg dialog

class CListPropertyDlg : public CDialog
{
// Construction
public:
	void SetParentListView(CStudentView* pView);
	CListPropertyDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CListPropertyDlg)
	enum { IDD = IDD_LIST_PROPERTY };
	CListCtrl	m_ctlList;
	BOOL	m_bAutoArrange;
	BOOL	m_bEditLabel;
	BOOL	m_bNoColumnHeader;
	BOOL	m_bNoLabelWrap;
	BOOL	m_bNoSortHeader;
	BOOL	m_bSingleSel;
	int		m_nSortMode;
	int		m_nViewMode;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListPropertyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void FillListControl();
	void ChangeStyle(long lStyle, BOOL bSetBit);
	void SetControlsState(long lStyle);

	CStudentView* m_pParentListView;
	CListCtrl* m_pList;
	CImageList* m_pImageLarge;
	CImageList* m_pImageSmall;

	// Generated message map functions
	//{{AFX_MSG(CListPropertyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnAutoarrange();
	afx_msg void OnEditlabel();
	afx_msg void OnNocolumnheader();
	afx_msg void OnNolablewrap();
	afx_msg void OnNosortheader();
	afx_msg void OnSinglesel();
	virtual void OnOK();
	afx_msg void OnSelchangeSortmode();
	afx_msg void OnSelchangeViewmode();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
