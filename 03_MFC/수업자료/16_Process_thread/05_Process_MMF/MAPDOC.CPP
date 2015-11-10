// MapDoc.cpp : implementation of the CMapDoc class
//

#include "stdafx.h"
#include "Map.h"

#include "MapDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMapDoc

IMPLEMENT_DYNCREATE(CMapDoc, CDocument)

BEGIN_MESSAGE_MAP(CMapDoc, CDocument)
	//{{AFX_MSG_MAP(CMapDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMapDoc construction/destruction

CMapDoc::CMapDoc()
{
	// TODO: add one-time construction code here

}

CMapDoc::~CMapDoc()
{
}

BOOL CMapDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMapDoc serialization

void CMapDoc::Serialize(CArchive& ar)
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
// CMapDoc diagnostics

#ifdef _DEBUG
void CMapDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMapDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMapDoc commands
