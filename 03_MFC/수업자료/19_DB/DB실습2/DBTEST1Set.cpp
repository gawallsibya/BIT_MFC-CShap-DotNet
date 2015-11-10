// DBTEST1Set.cpp : implementation of the CDBTEST1Set class
//

#include "stdafx.h"
#include "DBTEST1.h"
#include "DBTEST1Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDBTEST1Set implementation

IMPLEMENT_DYNAMIC(CDBTEST1Set, CRecordset)

CDBTEST1Set::CDBTEST1Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CDBTEST1Set)
	m_CUSTOM_CD = 0;
	m_NAME = _T("");
	m_TEL = _T("");
	m_ADDRESS = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}

CString CDBTEST1Set::GetDefaultConnect()
{
	return _T("ODBC;DSN=Video Shop Administration");
}

CString CDBTEST1Set::GetDefaultSQL()
{
	return _T("[Customer]");
}

void CDBTEST1Set::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CDBTEST1Set)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[CUSTOM_CD]"), m_CUSTOM_CD);
	RFX_Text(pFX, _T("[NAME]"), m_NAME);
	RFX_Text(pFX, _T("[TEL]"), m_TEL);
	RFX_Text(pFX, _T("[ADDRESS]"), m_ADDRESS);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CDBTEST1Set diagnostics

#ifdef _DEBUG
void CDBTEST1Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDBTEST1Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
