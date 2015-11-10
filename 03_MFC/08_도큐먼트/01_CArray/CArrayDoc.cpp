// CArrayDoc.cpp : implementation of the CCArrayDoc class
//

#include "stdafx.h"
#include "CArray.h"

#include "CArrayDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCArrayDoc

IMPLEMENT_DYNCREATE(CCArrayDoc, CDocument)

BEGIN_MESSAGE_MAP(CCArrayDoc, CDocument)
	//{{AFX_MSG_MAP(CCArrayDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCArrayDoc construction/destruction

CCArrayDoc::CCArrayDoc()
{
	// TODO: add one-time construction code here

}

CCArrayDoc::~CCArrayDoc()
{
}

BOOL CCArrayDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCArrayDoc serialization

void CCArrayDoc::Serialize(CArchive& ar)
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
// CCArrayDoc diagnostics

#ifdef _DEBUG
void CCArrayDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCArrayDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCArrayDoc commands
