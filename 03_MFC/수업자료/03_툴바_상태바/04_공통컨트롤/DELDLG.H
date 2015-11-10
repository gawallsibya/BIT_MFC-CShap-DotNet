// DelDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDeleteDialog dialog

class CDeleteDialog : public CFileDialog
{
// Construction
public:
	CDeleteDialog(BOOL bOpenFileDialog, LPCTSTR lpszDefExt = NULL,
				  LPCTSTR lpszFileName = NULL,
				  DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
				  LPCTSTR lpszFilter = NULL,
				  CWnd* pParent = NULL);   // standard constructor
	BOOL m_bDeleteAll;
// Dialog Data
	//{{AFX_DATA(CDeleteDialog)
	enum { IDD = IDD_FILE_DELETE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeleteDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDeleteDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
