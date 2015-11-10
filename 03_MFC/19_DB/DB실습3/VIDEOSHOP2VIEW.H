// VideoShop2View.h : interface of the CVideoShop2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIDEOSHOP2VIEW_H__83BD48AD_399B_11D2_941F_006097DCA739__INCLUDED_)
#define AFX_VIDEOSHOP2VIEW_H__83BD48AD_399B_11D2_941F_006097DCA739__INCLUDED_

#include "CusTapeSet.h"	// Added by ClassView
#include "TapeSet.h"
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CVideoShop2Set;

class CVideoShop2View : public CRecordView
{
protected: // create from serialization only
	CVideoShop2View();
	DECLARE_DYNCREATE(CVideoShop2View)

public:
	//{{AFX_DATA(CVideoShop2View)
	enum { IDD = IDD_VIDEOSHOP2_FORM };
	CListCtrl	m_listTape;
	CVideoShop2Set* m_pSet;
	CString	m_strAddress;
	CString	m_strName;
	CString	m_strTel;
	long	m_lCode;
	//}}AFX_DATA

// Attributes
public:
	CVideoShop2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVideoShop2View)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnMove(UINT nIDMoveCommand);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL m_flagLast;
	BOOL m_flagFirst;
	BOOL m_flagAdd;
	void UpdateList();
	CCusTapeSet* m_ctSet;
	CTapeSet* m_tSet;
	void DBToResource();
	void ResourceToDB();
	virtual ~CVideoShop2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CVideoShop2View)
	afx_msg void OnDestroy();
	afx_msg void OnRecordCustom();
	afx_msg void OnRecordTape();
	afx_msg void OnCustapeAdd();
	afx_msg void OnAddBtn();
	afx_msg void OnUpdateCustapeAdd(CCmdUI* pCmdUI);
	afx_msg void OnAddcancelBtn();
	afx_msg void OnRecordFirst();
	afx_msg void OnUpdateRecordFirst(CCmdUI* pCmdUI);
	afx_msg void OnRecordLast();
	afx_msg void OnUpdateRecordLast(CCmdUI* pCmdUI);
	afx_msg void OnRecordNext();
	afx_msg void OnUpdateRecordNext(CCmdUI* pCmdUI);
	afx_msg void OnRecordPrev();
	afx_msg void OnUpdateRecordPrev(CCmdUI* pCmdUI);
	afx_msg void OnDeleteBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in VideoShop2View.cpp
inline CVideoShop2Doc* CVideoShop2View::GetDocument()
   { return (CVideoShop2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIDEOSHOP2VIEW_H__83BD48AD_399B_11D2_941F_006097DCA739__INCLUDED_)
