// Sample3Doc.cpp : implementation of the CSample3Doc class
//

#include "stdafx.h"
#include "Sample3.h"

#include "Sample3Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSample3Doc

IMPLEMENT_DYNCREATE(CSample3Doc, CDocument)

BEGIN_MESSAGE_MAP(CSample3Doc, CDocument)
	//{{AFX_MSG_MAP(CSample3Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSample3Doc construction/destruction

CSample3Doc::CSample3Doc()
{
	// TODO: add one-time construction code here

}

CSample3Doc::~CSample3Doc()
{
}

BOOL CSample3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSample3Doc serialization

void CSample3Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSample3Doc diagnostics

#ifdef _DEBUG
void CSample3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSample3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSample3Doc commands
