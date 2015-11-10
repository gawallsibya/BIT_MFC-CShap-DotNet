// VideoShop2Doc.cpp : implementation of the CVideoShop2Doc class
//

#include "stdafx.h"
#include "VideoShop2.h"

#include "VideoShop2Set.h"
#include "VideoShop2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVideoShop2Doc

IMPLEMENT_DYNCREATE(CVideoShop2Doc, CDocument)

BEGIN_MESSAGE_MAP(CVideoShop2Doc, CDocument)
	//{{AFX_MSG_MAP(CVideoShop2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVideoShop2Doc construction/destruction

CVideoShop2Doc::CVideoShop2Doc()
{
	// TODO: add one-time construction code here
	m_videoShop2Set = NULL;
}

CVideoShop2Doc::~CVideoShop2Doc()
{
}

BOOL CVideoShop2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	if(m_videoShop2Set == NULL)
	{
		// 기본 레코드 셋 지정 
		m_videoShop2Set = new CVideoShop2Set(&m_DB);

		// 지정된 데이터 소스와 연결문을 얻음 
		CString strConnection = m_videoShop2Set->GetDefaultConnect();

		// 데이터베이스 오픈 
		m_DB.Open(NULL, FALSE, FALSE, strConnection, FALSE);
	}

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CVideoShop2Doc diagnostics

#ifdef _DEBUG
void CVideoShop2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CVideoShop2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVideoShop2Doc commands
