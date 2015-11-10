// DBTEST1Doc.cpp : implementation of the CDBTEST1Doc class
//

#include "stdafx.h"
#include "DBTEST1.h"

#include "DBTEST1Set.h"
#include "DBTEST1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDBTEST1Doc

IMPLEMENT_DYNCREATE(CDBTEST1Doc, CDocument)

BEGIN_MESSAGE_MAP(CDBTEST1Doc, CDocument)
	//{{AFX_MSG_MAP(CDBTEST1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDBTEST1Doc construction/destruction

CDBTEST1Doc::CDBTEST1Doc()
{
	// TODO: add one-time construction code here

}

CDBTEST1Doc::~CDBTEST1Doc()
{
}

BOOL CDBTEST1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDBTEST1Doc diagnostics

#ifdef _DEBUG
void CDBTEST1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDBTEST1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDBTEST1Doc commands
