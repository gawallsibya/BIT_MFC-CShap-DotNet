// RGBdisplayDoc.cpp : implementation of the CRGBdisplayDoc class
//

#include "stdafx.h"
#include "RGBdisplay.h"

#include "RGBdisplayDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRGBdisplayDoc

IMPLEMENT_DYNCREATE(CRGBdisplayDoc, CDocument)

BEGIN_MESSAGE_MAP(CRGBdisplayDoc, CDocument)
	//{{AFX_MSG_MAP(CRGBdisplayDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRGBdisplayDoc construction/destruction

CRGBdisplayDoc::CRGBdisplayDoc()
{
	// TODO: add one-time construction code here

}

CRGBdisplayDoc::~CRGBdisplayDoc()
{
}

BOOL CRGBdisplayDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRGBdisplayDoc serialization

void CRGBdisplayDoc::Serialize(CArchive& ar)
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
// CRGBdisplayDoc diagnostics

#ifdef _DEBUG
void CRGBdisplayDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRGBdisplayDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRGBdisplayDoc commands
