// NamDoc.cpp : implementation of the CNamDoc class
//

#include "stdafx.h"
#include "Nam.h"

#include "NamDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNamDoc

IMPLEMENT_DYNCREATE(CNamDoc, CDocument)

BEGIN_MESSAGE_MAP(CNamDoc, CDocument)
	//{{AFX_MSG_MAP(CNamDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNamDoc construction/destruction

CNamDoc::CNamDoc()
{
	m_str = "Sample";
	m_color = RGB(0,0,0); // °ËÁ¤»ö.
}

CNamDoc::~CNamDoc()
{
}

BOOL CNamDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CNamDoc serialization

void CNamDoc::Serialize(CArchive& ar)
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
// CNamDoc diagnostics

#ifdef _DEBUG
void CNamDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CNamDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNamDoc commands
