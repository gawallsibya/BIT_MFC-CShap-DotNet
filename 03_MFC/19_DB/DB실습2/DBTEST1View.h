// DBTEST1View.h : interface of the CDBTEST1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBTEST1VIEW_H__E79A0F53_4794_4070_AC7D_4065E6386DE0__INCLUDED_)
#define AFX_DBTEST1VIEW_H__E79A0F53_4794_4070_AC7D_4065E6386DE0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDBTEST1Set;

class CDBTEST1View : public CRecordView
{
protected: // create from serialization only
	CDBTEST1View();
	DECLARE_DYNCREATE(CDBTEST1View)

public:
	//{{AFX_DATA(CDBTEST1View)
	enum { IDD = IDD_DBTEST1_FORM };
	CDBTEST1Set* m_pSet;
	//}}AFX_DATA

// Attributes
public:
	CDBTEST1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDBTEST1View)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL OnMove(UINT nIDMoveCommand);
	virtual ~CDBTEST1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDBTEST1View)
	afx_msg void OnDestroy();
	afx_msg void OnBtnAdd();
	afx_msg void OnBtnDel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DBTEST1View.cpp
inline CDBTEST1Doc* CDBTEST1View::GetDocument()
   { return (CDBTEST1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DBTEST1VIEW_H__E79A0F53_4794_4070_AC7D_4065E6386DE0__INCLUDED_)
