#if !defined(AFX_TAPESET_H__04DD4965_39A5_11D2_947A_02608CA0D980__INCLUDED_)
#define AFX_TAPESET_H__04DD4965_39A5_11D2_947A_02608CA0D980__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// TapeSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTapeSet recordset

class CTapeSet : public CRecordset
{
public:
	CTapeSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CTapeSet)

// Field/Param Data
	//{{AFX_FIELD(CTapeSet, CRecordset)
	long	m_TAPE_CD;
	CString	m_TITLE;
	CTime	m_INDAY;
	CString	m_DIRECTOR;
	CString	m_ACTOR;
	long	m_MONEY;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTapeSet)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TAPESET_H__04DD4965_39A5_11D2_947A_02608CA0D980__INCLUDED_)
