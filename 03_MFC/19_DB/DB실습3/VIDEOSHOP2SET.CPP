// VideoShop2Set.cpp : implementation of the CVideoShop2Set class
//

#include "stdafx.h"
#include "VideoShop2.h"
#include "VideoShop2Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVideoShop2Set implementation

IMPLEMENT_DYNAMIC(CVideoShop2Set, CRecordset)

CVideoShop2Set::CVideoShop2Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CVideoShop2Set)
	m_CUSTOM_CD = 0;
	m_NAME = _T("");
	m_TEL = _T("");
	m_ADDRESS = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}

CString CVideoShop2Set::GetDefaultConnect()
{
	return _T("ODBC;DSN=Video Shop Administration");
}

CString CVideoShop2Set::GetDefaultSQL()
{
	return _T("[Customer]");
}

void CVideoShop2Set::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CVideoShop2Set)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[CUSTOM_CD]"), m_CUSTOM_CD);
	RFX_Text(pFX, _T("[NAME]"), m_NAME);
	RFX_Text(pFX, _T("[TEL]"), m_TEL);
	RFX_Text(pFX, _T("[ADDRESS]"), m_ADDRESS);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CVideoShop2Set diagnostics

#ifdef _DEBUG
void CVideoShop2Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CVideoShop2Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
