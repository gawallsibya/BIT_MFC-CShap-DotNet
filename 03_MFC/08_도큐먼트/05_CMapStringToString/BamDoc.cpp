// BamDoc.cpp : implementation of the CBamDoc class
//

#include "stdafx.h"
#include "Bam.h"

#include "BamDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBamDoc

IMPLEMENT_DYNCREATE(CBamDoc, CDocument)

BEGIN_MESSAGE_MAP(CBamDoc, CDocument)
	//{{AFX_MSG_MAP(CBamDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBamDoc construction/destruction

CBamDoc::CBamDoc()
{
	// TODO: add one-time construction code here

}

CBamDoc::~CBamDoc()
{
}

BOOL CBamDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBamDoc serialization

void CBamDoc::Serialize(CArchive& ar)
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
// CBamDoc diagnostics

#ifdef _DEBUG
void CBamDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBamDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBamDoc commands
