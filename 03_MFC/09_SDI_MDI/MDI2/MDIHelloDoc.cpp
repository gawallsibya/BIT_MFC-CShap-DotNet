// MDIHelloDoc.cpp : implementation of the CMDIHelloDoc class
//

#include "stdafx.h"
#include "MDIHello.h"

#include "MDIHelloDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMDIHelloDoc

IMPLEMENT_DYNCREATE(CMDIHelloDoc, CDocument)

BEGIN_MESSAGE_MAP(CMDIHelloDoc, CDocument)
	//{{AFX_MSG_MAP(CMDIHelloDoc)
	ON_COMMAND(ID_COLOR_BLACK, OnColorBlack)
	ON_COMMAND(ID_COLOR_RED, OnColorRed)
	ON_COMMAND(ID_COLOR_GREEN, OnColorGreen)
	ON_COMMAND(ID_COLOR_BLUE, OnColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLACK, OnUpdateColorBlack)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, OnUpdateColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, OnUpdateColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, OnUpdateColorBlue)
	ON_COMMAND(ID_VIEW_DATAFORM, OnViewDataform)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMDIHelloDoc construction/destruction

CMDIHelloDoc::CMDIHelloDoc()
{
	// TODO: add one-time construction code here
	m_ptLoc = CPoint(0, 0);
	m_clrCur = BLACK;
	m_nMax = CPoint(100, 100);
	m_strText = "안녕하세요? 윈도우입니다.";
	m_pDataForm = NULL;
}

CMDIHelloDoc::~CMDIHelloDoc()
{
}

BOOL CMDIHelloDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMDIHelloDoc serialization

void CMDIHelloDoc::Serialize(CArchive& ar)
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
// CMDIHelloDoc diagnostics

#ifdef _DEBUG
void CMDIHelloDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMDIHelloDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMDIHelloDoc commands
CPoint CMDIHelloDoc::GetLocation()
{
	return m_ptLoc;
}

void CMDIHelloDoc::SetLocation(CPoint point)
{
	m_ptLoc = point;
	UpdateAllViews(NULL);
	SetModifiedFlag();
}

COLORREF CMDIHelloDoc::GetColor()
{
	return m_clrCur;
}

void CMDIHelloDoc::SetColor(COLORREF color)
{
	m_clrCur = color;
	UpdateAllViews(NULL);
	SetModifiedFlag();
}

void CMDIHelloDoc::SetData(CString str, CPoint point, COLORREF color)
{
	m_strText = str;
	m_ptLoc = point;
	m_clrCur = color;
	UpdateAllViews(NULL);
	SetModifiedFlag();
}

CString CMDIHelloDoc::GetText()
{
	return m_strText;
}

CPoint CMDIHelloDoc::GetMax()
{
	return m_nMax;
}

void CMDIHelloDoc::SetMax(CPoint point)
{
	m_nMax = point;
}

void CMDIHelloDoc::OnColorBlack() 
{
	// TODO: Add your command handler code here
	SetColor(BLACK);
}

void CMDIHelloDoc::OnColorRed() 
{
	// TODO: Add your command handler code here
	SetColor(RED);
}

void CMDIHelloDoc::OnColorGreen() 
{
	// TODO: Add your command handler code here
	SetColor(GREEN);
}

void CMDIHelloDoc::OnColorBlue() 
{
	// TODO: Add your command handler code here
	SetColor(BLUE);
}

void CMDIHelloDoc::OnUpdateColorBlack(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GetColor() == BLACK);
}

void CMDIHelloDoc::OnUpdateColorRed(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GetColor() == RED);
}

void CMDIHelloDoc::OnUpdateColorGreen(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GetColor() == GREEN);
}

void CMDIHelloDoc::OnUpdateColorBlue(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GetColor() == BLUE);
}

void CMDIHelloDoc::OnViewDataform() 
{
	// TODO: Add your command handler code here
	if(m_pDataForm) {
		m_pDataForm->MDIActivate();
		if(m_pDataForm->IsIconic())
			m_pDataForm->ShowWindow(SW_RESTORE);
	}
	else {
		CMDIHelloApp* pApp = (CMDIHelloApp*)AfxGetApp();
		CMultiDocTemplate* pTemplate = pApp->GetFormTemplate();
		m_pDataForm = (CMDIChildWnd*)pTemplate->CreateNewFrame(this, NULL);
		pTemplate->InitialUpdateFrame(m_pDataForm, this);
	}
}
