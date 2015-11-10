// MultiLookDoc.cpp : implementation of the CMultiLookDoc class
//

#include "stdafx.h"
#include "MultiLook.h"

#include "MultiLookDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMultiLookDoc

IMPLEMENT_DYNCREATE(CMultiLookDoc, CDocument)

BEGIN_MESSAGE_MAP(CMultiLookDoc, CDocument)
	//{{AFX_MSG_MAP(CMultiLookDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiLookDoc construction/destruction

CMultiLookDoc::CMultiLookDoc()
{
	// TODO: add one-time construction code here

}

CMultiLookDoc::~CMultiLookDoc()
{
}

BOOL CMultiLookDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMultiLookDoc serialization

void CMultiLookDoc::Serialize(CArchive& ar)
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
// CMultiLookDoc diagnostics

#ifdef _DEBUG
void CMultiLookDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMultiLookDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMultiLookDoc commands
