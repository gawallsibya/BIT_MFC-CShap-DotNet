#if !defined(AFX_CUSTAPESET_H__04DD4963_39A5_11D2_947A_02608CA0D980__INCLUDED_)
#define AFX_CUSTAPESET_H__04DD4963_39A5_11D2_947A_02608CA0D980__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// CusTapeSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCusTapeSet recordset

class CCusTapeSet : public CRecordset
{
public:
	CCusTapeSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CCusTapeSet)

// Field/Param Data
	//{{AFX_FIELD(CCusTapeSet, CRecordset)
	long	m_TAPE_CD;
	long	m_CUSTOM_CD;
	CTime	m_RENT_DAY;
	CTime	m_REC_DAY;
	BOOL	m_ISREC;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCusTapeSet)
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

#endif // !defined(AFX_CUSTAPESET_H__04DD4963_39A5_11D2_947A_02608CA0D980__INCLUDED_)
