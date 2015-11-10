// CusTapeSet.cpp : implementation file
//

#include "stdafx.h"
#include "VideoShop2.h"
#include "CusTapeSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCusTapeSet

IMPLEMENT_DYNAMIC(CCusTapeSet, CRecordset)

CCusTapeSet::CCusTapeSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CCusTapeSet)
	m_TAPE_CD = 0;
	m_CUSTOM_CD = 0;
	m_ISREC = FALSE;
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}


CString CCusTapeSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Video Shop Administration");
}

CString CCusTapeSet::GetDefaultSQL()
{
	return _T("[Custom_Tape]");
}

void CCusTapeSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CCusTapeSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[TAPE_CD]"), m_TAPE_CD);
	RFX_Long(pFX, _T("[CUSTOM_CD]"), m_CUSTOM_CD);
	RFX_Date(pFX, _T("[RENT_DAY]"), m_RENT_DAY);
	RFX_Date(pFX, _T("[REC_DAY]"), m_REC_DAY);
	RFX_Bool(pFX, _T("[ISREC]"), m_ISREC);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CCusTapeSet diagnostics

#ifdef _DEBUG
void CCusTapeSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CCusTapeSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
