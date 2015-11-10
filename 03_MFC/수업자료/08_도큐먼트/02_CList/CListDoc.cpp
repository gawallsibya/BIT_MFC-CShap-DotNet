// CListDoc.cpp : implementation of the CCListDoc class
//

#include "stdafx.h"
#include "CList.h"

#include "CListDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCListDoc

IMPLEMENT_DYNCREATE(CCListDoc, CDocument)

BEGIN_MESSAGE_MAP(CCListDoc, CDocument)
	//{{AFX_MSG_MAP(CCListDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCListDoc construction/destruction

CCListDoc::CCListDoc()
{
	// TODO: add one-time construction code here

}

CCListDoc::~CCListDoc()
{
}

BOOL CCListDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCListDoc serialization

void CCListDoc::Serialize(CArchive& ar)
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
// CCListDoc diagnostics

#ifdef _DEBUG
void CCListDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCListDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCListDoc commands
