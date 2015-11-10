// TapeSet.cpp : implementation file
//

#include "stdafx.h"
#include "VideoShop2.h"
#include "TapeSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTapeSet

IMPLEMENT_DYNAMIC(CTapeSet, CRecordset)

CTapeSet::CTapeSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CTapeSet)
	m_TAPE_CD = 0;
	m_TITLE = _T("");
	m_DIRECTOR = _T("");
	m_ACTOR = _T("");
	m_MONEY = 0;
	m_nFields = 6;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}


CString CTapeSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Video Shop Administration");
}

CString CTapeSet::GetDefaultSQL()
{
	return _T("[Tape]");
}

void CTapeSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CTapeSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[TAPE_CD]"), m_TAPE_CD);
	RFX_Text(pFX, _T("[TITLE]"), m_TITLE);
	RFX_Date(pFX, _T("[INDAY]"), m_INDAY);
	RFX_Text(pFX, _T("[DIRECTOR]"), m_DIRECTOR);
	RFX_Text(pFX, _T("[ACTOR]"), m_ACTOR);
	RFX_Long(pFX, _T("[MONEY]"), m_MONEY);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CTapeSet diagnostics

#ifdef _DEBUG
void CTapeSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CTapeSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
