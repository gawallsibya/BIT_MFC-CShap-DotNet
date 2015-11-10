// Data.cpp: implementation of the CData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Seri.h"
#include "Data.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CData::CData()
{

}

CData::~CData()
{

}

void CData::Serialize(CArchive &ar)
{

	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar << m_ptHead;
		ar << m_ptTail;
		ar << m_nType;
		ar << m_colorPen;
		ar << m_colorBrush;
	}
	else
	{
		// TODO: add loading code here
		ar >> m_ptHead;
		ar >> m_ptTail;
		ar >> m_nType;
		ar >> m_colorPen;
		ar >> m_colorBrush;
	}
}
