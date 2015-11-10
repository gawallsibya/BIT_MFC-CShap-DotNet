// MovieDoc.cpp : implementation of the CMovieDoc class
//

#include "stdafx.h"
#include "Movie.h"

#include "MovieDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMovieDoc

IMPLEMENT_DYNCREATE(CMovieDoc, CDocument)

BEGIN_MESSAGE_MAP(CMovieDoc, CDocument)
	//{{AFX_MSG_MAP(CMovieDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMovieDoc construction/destruction

CMovieDoc::CMovieDoc()
{
	// TODO: add one-time construction code here

}

CMovieDoc::~CMovieDoc()
{
}

BOOL CMovieDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMovieDoc serialization

void CMovieDoc::Serialize(CArchive& ar)
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
// CMovieDoc diagnostics

#ifdef _DEBUG
void CMovieDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMovieDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMovieDoc commands
