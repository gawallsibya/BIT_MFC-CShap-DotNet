// VideoShop2Set.h : interface of the CVideoShop2Set class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIDEOSHOP2SET_H__83BD48AF_399B_11D2_941F_006097DCA739__INCLUDED_)
#define AFX_VIDEOSHOP2SET_H__83BD48AF_399B_11D2_941F_006097DCA739__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CVideoShop2Set : public CRecordset
{
public:
	CVideoShop2Set(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CVideoShop2Set)

// Field/Param Data
	//{{AFX_FIELD(CVideoShop2Set, CRecordset)
	long	m_CUSTOM_CD;
	CString	m_NAME;
	CString	m_TEL;
	CString	m_ADDRESS;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVideoShop2Set)
	public:
	virtual CString GetDefaultConnect();	// Default connection string
	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIDEOSHOP2SET_H__83BD48AF_399B_11D2_941F_006097DCA739__INCLUDED_)
