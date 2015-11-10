// VisualKBDoc.cpp : implementation of the CVisualKBDoc class
//

#include "stdafx.h"
#include "VisualKB.h"

#include "VisualKBDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVisualKBDoc

IMPLEMENT_DYNCREATE(CVisualKBDoc, CDocument)

BEGIN_MESSAGE_MAP(CVisualKBDoc, CDocument)
	//{{AFX_MSG_MAP(CVisualKBDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVisualKBDoc construction/destruction

CVisualKBDoc::CVisualKBDoc()
{
	// TODO: add one-time construction code here

}

CVisualKBDoc::~CVisualKBDoc()
{
}

BOOL CVisualKBDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CVisualKBDoc serialization

void CVisualKBDoc::Serialize(CArchive& ar)
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
// CVisualKBDoc diagnostics

#ifdef _DEBUG
void CVisualKBDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CVisualKBDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVisualKBDoc commands
