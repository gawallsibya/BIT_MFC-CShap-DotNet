// HelloDoc.cpp : implementation of the CHelloDoc class
//

#include "stdafx.h"
#include "SplitWnd.h"

#include "HelloDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHelloDoc

IMPLEMENT_DYNCREATE(CHelloDoc, CDocument)

BEGIN_MESSAGE_MAP(CHelloDoc, CDocument)
	//{{AFX_MSG_MAP(CHelloDoc)
	ON_COMMAND(ID_COLOR_BLACK, OnColorBlack)
	ON_COMMAND(ID_COLOR_RED, OnColorRed)
	ON_COMMAND(ID_COLOR_GREEN, OnColorGreen)
	ON_COMMAND(ID_COLOR_BLUE, OnColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLACK, OnUpdateColorBlack)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, OnUpdateColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, OnUpdateColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, OnUpdateColorBlue)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHelloDoc construction/destruction

CHelloDoc::CHelloDoc()
{
	// TODO: add one-time construction code here

}

CHelloDoc::~CHelloDoc()
{
}

BOOL CHelloDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	m_ptLoc = CPoint(0, 0);
	m_clrCur = BLACK;
	m_nMax = CPoint(100, 100);
	m_strText = "안녕하세요? 윈도우입니다.";

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CHelloDoc serialization

void CHelloDoc::Serialize(CArchive& ar)
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
// CHelloDoc diagnostics

#ifdef _DEBUG
void CHelloDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHelloDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHelloDoc commands
CPoint CHelloDoc::GetLocation()
{
	return m_ptLoc;
}

void CHelloDoc::SetLocation(CPoint point)
{
	m_ptLoc = point;
	UpdateAllViews(NULL);
	SetModifiedFlag();
}

COLORREF CHelloDoc::GetColor()
{
	return m_clrCur;
}

void CHelloDoc::SetColor(COLORREF color)
{
	m_clrCur = color;
	UpdateAllViews(NULL);
	SetModifiedFlag();
}

void CHelloDoc::SetData(CString str, CPoint point, COLORREF color)
{
	m_strText = str;
	m_ptLoc = point;
	m_clrCur = color;
	UpdateAllViews(NULL);
	SetModifiedFlag();
}

CString CHelloDoc::GetText()
{
	return m_strText;
}

CPoint CHelloDoc::GetMax()
{
	return m_nMax;
}

void CHelloDoc::SetMax(CPoint point)
{
	m_nMax = point;
}

void CHelloDoc::OnColorBlack() 
{
	// TODO: Add your command handler code here
	SetColor(BLACK);		
}

void CHelloDoc::OnColorRed() 
{
	// TODO: Add your command handler code here
	SetColor(RED);		
}

void CHelloDoc::OnColorGreen() 
{
	// TODO: Add your command handler code here
	SetColor(GREEN);
}

void CHelloDoc::OnColorBlue() 
{
	// TODO: Add your command handler code here
	SetColor(BLUE);
}

void CHelloDoc::OnUpdateColorBlack(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GetColor() == BLACK);
}

void CHelloDoc::OnUpdateColorRed(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GetColor() == RED);
}

void CHelloDoc::OnUpdateColorGreen(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GetColor() == GREEN);
}

void CHelloDoc::OnUpdateColorBlue(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GetColor() == BLUE);
}
