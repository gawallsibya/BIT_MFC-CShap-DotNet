// WmPaintTestDoc.cpp : implementation of the CWmPaintTestDoc class
//

#include "stdafx.h"
#include "WmPaintTest.h"

#include "WmPaintTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWmPaintTestDoc

IMPLEMENT_DYNCREATE(CWmPaintTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CWmPaintTestDoc, CDocument)
	//{{AFX_MSG_MAP(CWmPaintTestDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWmPaintTestDoc construction/destruction

CWmPaintTestDoc::CWmPaintTestDoc()
{
	// TODO: add one-time construction code here

}

CWmPaintTestDoc::~CWmPaintTestDoc()
{
}

BOOL CWmPaintTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CWmPaintTestDoc serialization

void CWmPaintTestDoc::Serialize(CArchive& ar)
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
// CWmPaintTestDoc diagnostics

#ifdef _DEBUG
void CWmPaintTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWmPaintTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWmPaintTestDoc commands
