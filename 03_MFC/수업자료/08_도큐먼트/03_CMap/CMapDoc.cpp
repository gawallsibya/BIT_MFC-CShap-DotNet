// CMapDoc.cpp : implementation of the CCMapDoc class
//

#include "stdafx.h"
#include "CMap.h"

#include "CMapDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCMapDoc

IMPLEMENT_DYNCREATE(CCMapDoc, CDocument)

BEGIN_MESSAGE_MAP(CCMapDoc, CDocument)
	//{{AFX_MSG_MAP(CCMapDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCMapDoc construction/destruction

CCMapDoc::CCMapDoc()
{
	// TODO: add one-time construction code here

}

CCMapDoc::~CCMapDoc()
{
}

BOOL CCMapDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCMapDoc serialization

void CCMapDoc::Serialize(CArchive& ar)
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
// CCMapDoc diagnostics

#ifdef _DEBUG
void CCMapDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCMapDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCMapDoc commands
