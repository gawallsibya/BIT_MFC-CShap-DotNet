// Data.cpp: implementation of the CData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "test.h"
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

	if( ar.IsStoring())
	{
		ar << a << b;
	}
	else
	{
		ar >> a >> b;
	}
}

void CData::SetData(CPoint _a, CPoint _b)
{
	a = _a;
	b = _b;
}
