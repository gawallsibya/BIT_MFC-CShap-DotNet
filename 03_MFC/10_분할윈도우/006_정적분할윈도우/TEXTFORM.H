// TextForm.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTextFormView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CTextFormView : public CFormView
{
protected:
	CTextFormView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CTextFormView)
public:
	CHelloDoc* GetDocument();

// Form Data
public:
	//{{AFX_DATA(CTextFormView)
	enum { IDD = IDD_TEXT_FORM };
	CSpinButtonCtrl	m_ctlSpinY;
	CSpinButtonCtrl	m_ctlSpinX;
	CString	m_strText;
	UINT	m_nX;
	UINT	m_nY;
	int		m_nColor;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextFormView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CTextFormView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CTextFormView)
	afx_msg void OnDataUpdate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TextForm.cpp
inline CHelloDoc* CHelloView::GetDocument()
   { return (CHelloDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
