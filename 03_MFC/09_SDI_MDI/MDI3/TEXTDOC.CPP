// TextDoc.cpp : implementation file
//

#include "stdafx.h"
#include "MultiDoc.h"
#include "TextDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTextDoc

IMPLEMENT_DYNCREATE(CTextDoc, CDocument)

CTextDoc::CTextDoc()
{
}

BOOL CTextDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CTextDoc::~CTextDoc()
{
}


BEGIN_MESSAGE_MAP(CTextDoc, CDocument)
	//{{AFX_MSG_MAP(CTextDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextDoc diagnostics

#ifdef _DEBUG
void CTextDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTextDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTextDoc serialization

void CTextDoc::Serialize(CArchive& ar)
{
	POSITION pos = GetFirstViewPosition();
	CEditView* pView = (CEditView*)GetNextView(pos);
	if(pView)
		pView->SerializeRaw(ar);

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
// CTextDoc commands
