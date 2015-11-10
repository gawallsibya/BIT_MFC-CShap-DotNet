// DBTEST1Set.h : interface of the CDBTEST1Set class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBTEST1SET_H__BC955EF3_D42E_4A30_A089_2D062D6D2D2F__INCLUDED_)
#define AFX_DBTEST1SET_H__BC955EF3_D42E_4A30_A089_2D062D6D2D2F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDBTEST1Set : public CRecordset
{
public:
	CDBTEST1Set(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CDBTEST1Set)

// Field/Param Data
	//{{AFX_FIELD(CDBTEST1Set, CRecordset)
	long	m_CUSTOM_CD;
	CString	m_NAME;
	CString	m_TEL;
	CString	m_ADDRESS;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDBTEST1Set)
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
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DBTEST1SET_H__BC955EF3_D42E_4A30_A089_2D062D6D2D2F__INCLUDED_)

