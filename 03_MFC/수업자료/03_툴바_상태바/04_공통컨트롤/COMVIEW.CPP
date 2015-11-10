// ComView.cpp : implementation of the CComDlgView class
//

#include "stdafx.h"
#include "ComDlg.h"

#include "ComDoc.h"
#include "ComView.h"
#include "DelDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComDlgView
static const UINT nMsgFindReplace = ::RegisterWindowMessage(FINDMSGSTRING);

IMPLEMENT_DYNCREATE(CComDlgView, CView)

BEGIN_MESSAGE_MAP(CComDlgView, CView)
	//{{AFX_MSG_MAP(CComDlgView)
	ON_COMMAND(ID_COMDLG_OPEN, OnComdlgOpen)
	ON_COMMAND(ID_COMDLG_SAVEAS, OnComdlgSaveas)
	ON_COMMAND(ID_COMDLG_COLOR, OnComdlgColor)
	ON_COMMAND(ID_COMDLG_FONT, OnComdlgFont)
	ON_COMMAND(ID_COMDLG_PRINT, OnComdlgPrint)
	ON_COMMAND(ID_COMDLG_PRINTERSETUP, OnComdlgPrintersetup)
	ON_COMMAND(ID_COMDLG_PAGESETUP, OnComdlgPagesetup)
	ON_COMMAND(ID_COMDLG_FIND, OnComdlgFind)
	ON_COMMAND(ID_COMDLG_REPLACE, OnComdlgReplace)
	ON_COMMAND(ID_COMDLG_DELETE, OnComdlgDelete)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_REGISTERED_MESSAGE(nMsgFindReplace, OnFindReplaceMsg)
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComDlgView construction/destruction

CComDlgView::CComDlgView()
{
	// TODO: add construction code here
	pDlg = NULL;
}

CComDlgView::~CComDlgView()
{
}

BOOL CComDlgView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CComDlgView drawing

void CComDlgView::OnDraw(CDC* pDC)
{
	CComDlgDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CComDlgView printing

BOOL CComDlgView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CComDlgView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CComDlgView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CComDlgView diagnostics

#ifdef _DEBUG
void CComDlgView::AssertValid() const
{
	CView::AssertValid();
}

void CComDlgView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CComDlgDoc* CComDlgView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CComDlgDoc)));
	return (CComDlgDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CComDlgView message handlers

void CComDlgView::OnComdlgOpen() 
{
	// TODO: Add your command handler code here
	CFileDialog dlg(TRUE, "txt", "*.txt");
	if(dlg.DoModal() == IDOK)
		AfxMessageBox(dlg.GetPathName());
}

void CComDlgView::OnComdlgSaveas() 
{
	// TODO: Add your command handler code here
	CFileDialog dlg(FALSE, "txt", "*.txt");
	if(dlg.DoModal() == IDOK)
		AfxMessageBox(dlg.GetPathName());
}

void CComDlgView::OnComdlgColor() 
{
	// TODO: Add your command handler code here
	COLORREF color = RGB(0, 0, 0);
	CColorDialog dlg(color);
	if(dlg.DoModal() == IDOK) {
		CString str;
		color = dlg.GetColor();
		str.Format("색상 : (%d, %d, %d)", GetRValue(color),
										  GetGValue(color),
										  GetBValue(color));
		AfxMessageBox(str);
	}
}

void CComDlgView::OnComdlgFont() 
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
	CFont* pFont = dc.GetCurrentFont();
	LOGFONT logFont;
	pFont->GetLogFont(&logFont);

	CFontDialog dlg(&logFont);
	if(dlg.DoModal() == IDOK) {
		CString str;
		str.Format("서체 : %s, 크기 : %d", dlg.GetFaceName(),
										   dlg.GetSize()/10);
		AfxMessageBox(str);
	}
}

void CComDlgView::OnComdlgPrint() 
{
	// TODO: Add your command handler code here
	CPrintDialog dlg(FALSE);
	if(dlg.DoModal() == IDOK) {
		CString str, str1;
		str1.Format("페이지 : %d - %d \n", dlg.GetFromPage(),
										   dlg.GetToPage());
		str += str1;
		str1.Format("모든 페이지? : %s\n", 
			dlg.PrintAll() ? "예" : "아니오");
		str += str1;
		str1.Format("선택 페이지? : %s\n", 
			dlg.PrintSelection() ? "예" : "아니오");
		str += str1;
		str1.Format("범위 페이지? : %s\n", 
			dlg.PrintRange() ? "예" : "아니오");
		str += str1;
		str1.Format("인쇄 매수 : %d", dlg.GetCopies());
		str += str1;
		AfxMessageBox(str);
	}
}

void CComDlgView::OnComdlgPrintersetup() 
{
	// TODO: Add your command handler code here
	CPrintDialog dlg(TRUE);
	if(dlg.DoModal() == IDOK) {
		CString str;
		str.Format("%s, %s, %s", dlg.GetDeviceName(),
								 dlg.GetDriverName(),
								 dlg.GetPortName());
		AfxMessageBox(str);
	}
}

void CComDlgView::OnComdlgPagesetup() 
{
	// TODO: Add your command handler code here
	CPageSetupDialog dlg;
	if(dlg.DoModal() == IDOK) {
		CString str, str1;
		CRect rectMargin;
		CSize sizePaper;
		dlg.GetMargins(&rectMargin, NULL);
		str1.Format("프린터 여백 : (%d, %d, %d, %d)\n",
					 rectMargin.left, rectMargin.top,
					 rectMargin.right, rectMargin.bottom);
		str += str1;
		sizePaper = dlg.GetPaperSize();
		str1.Format("용지 크기 : (%d, %d)", sizePaper.cx,
											sizePaper.cy);
		str += str1;
		AfxMessageBox(str);
	}
}

LRESULT CComDlgView::OnFindReplaceMsg(UINT wParam, LONG lParam)
{
	CFindReplaceDialog* pDialog = CFindReplaceDialog::GetNotifier(lParam);
	CString str, str1;

	if(pDialog->IsTerminating()) {
		str = "다이얼로그 박스 종료";
		AfxMessageBox(str);
		pDlg = NULL;
		return TRUE;
	}

	str1.Format("찾을 문자열 : %s\n", pDialog->GetFindString());
	str += str1;
	str1.Format("바꿀 문자열 : %s\n", pDialog->GetReplaceString());
	str += str1;
	if(pDialog->FindNext())
		str1 = "다음 찾기";
	if(pDialog->ReplaceCurrent())
		str1 = "바꾸기";
	if(pDialog->ReplaceAll())
		str1 = "모두 바꾸기";
	str += str1;
	AfxMessageBox(str);
	return TRUE;
}

void CComDlgView::OnComdlgFind() 
{
	// TODO: Add your command handler code here
	if(!pDlg) {
		pDlg = new CFindReplaceDialog;
		pDlg->Create(TRUE, "찾을 문자열", NULL, FR_DOWN, this);
	}
}

void CComDlgView::OnComdlgReplace() 
{
	// TODO: Add your command handler code here
	if(!pDlg) {
		pDlg = new CFindReplaceDialog;
		pDlg->Create(FALSE, "찾을 문자열", NULL, FR_DOWN, this);
	}
}

void CComDlgView::OnComdlgDelete() 
{
	// TODO: Add your command handler code here
	CDeleteDialog dlg(TRUE, "obj", "*.obj");
	BOOL bRet = dlg.DoModal();
	CString msg;
	if(bRet == IDCANCEL && dlg.m_bDeleteAll) {
		msg = "*.obj 모든 파일을 삭제합니다.";
		AfxMessageBox(msg);
	}
	else if(bRet == IDOK) {
		msg.Format("%s 파일을 삭제합니다.", dlg.GetPathName());
		AfxMessageBox(msg);
	}
}
