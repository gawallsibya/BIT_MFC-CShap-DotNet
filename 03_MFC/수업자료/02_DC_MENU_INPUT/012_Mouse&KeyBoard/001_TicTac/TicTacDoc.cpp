// TicTacDoc.cpp : implementation of the CTicTacDoc class
//

#include "stdafx.h"
#include "TicTac.h"

#include "TicTacDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTicTacDoc

IMPLEMENT_DYNCREATE(CTicTacDoc, CDocument)

BEGIN_MESSAGE_MAP(CTicTacDoc, CDocument)
	//{{AFX_MSG_MAP(CTicTacDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTicTacDoc construction/destruction

CTicTacDoc::CTicTacDoc()
{
	// TODO: add one-time construction code here

}

CTicTacDoc::~CTicTacDoc()
{
}

BOOL CTicTacDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTicTacDoc serialization

void CTicTacDoc::Serialize(CArchive& ar)
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
// CTicTacDoc diagnostics

#ifdef _DEBUG
void CTicTacDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTicTacDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTicTacDoc commands
