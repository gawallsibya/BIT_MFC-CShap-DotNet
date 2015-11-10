// TreePropertyDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTreePropertyDlg dialog
#include "TreeCtrl.h"

class CTreePropertyDlg : public CDialog
{
// Construction
public:
	void SetParentTreeView(CCourseView* pView);
	CTreePropertyDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTreePropertyDlg)
	enum { IDD = IDD_TREE_PROPERTY };
	CMyTreeCtrl	m_ctlTree;
	BOOL	m_bEditLabels;
	BOOL	m_bHasButtons;
	BOOL	m_bHasLines;
	BOOL	m_bLinesAtRoot;
	BOOL	m_bShowSelAlways;
	BOOL	m_bDisableDragDrop;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreePropertyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CCourseView* m_pParentTreeView;
	CTreeCtrl* m_pTree;
	CImageList* m_pImage;

	void FillTreeControl();
	void SetControlsState(long lStyle);

	// Generated message map functions
	//{{AFX_MSG(CTreePropertyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnEditlabels();
	afx_msg void OnHasbuttons();
	afx_msg void OnHaslines();
	afx_msg void OnLinesatroot();
	afx_msg void OnShowselalways();
	afx_msg void OnDisabledragdrop();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
