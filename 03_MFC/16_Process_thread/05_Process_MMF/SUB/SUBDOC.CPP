// SubDoc.cpp : implementation of the CSubDoc class
//

#include "stdafx.h"
#include "Sub.h"

#include "SubDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubDoc

IMPLEMENT_DYNCREATE(CSubDoc, CDocument)

BEGIN_MESSAGE_MAP(CSubDoc, CDocument)
	//{{AFX_MSG_MAP(CSubDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubDoc construction/destruction

CSubDoc::CSubDoc()
{
	// TODO: add one-time construction code here

}

CSubDoc::~CSubDoc()
{
}

BOOL CSubDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSubDoc serialization

void CSubDoc::Serialize(CArchive& ar)
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
// CSubDoc diagnostics

#ifdef _DEBUG
void CSubDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSubDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSubDoc commands
