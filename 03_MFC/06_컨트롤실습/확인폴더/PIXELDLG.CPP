// PixelDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Movie.h"
#include "PixelDlg.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPixelDlg dialog

CPixelDlg::CPixelDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPixelDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPixelDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPixelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPixelDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPixelDlg, CDialog)
	//{{AFX_MSG_MAP(CPixelDlg)
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPixelDlg message handlers

void CPixelDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	CClientDC  dc(this);
    COLORREF color;
	color = dc.GetPixel(point);

	SetDlgItemInt(IDC_CORD_X, point.x);
	SetDlgItemInt(IDC_CORD_Y, point.y);

	SetDlgItemInt(IDC_RED_VALUE, GetRValue(color));
	SetDlgItemInt(IDC_GREEN_VALUE, GetGValue(color));
	SetDlgItemInt(IDC_BLUE_VALUE, GetBValue(color));

	CurrentPixelColor(color);  // 현재 픽셀의 색상을 표시 
	SendCurrentColor(color);   // 폼 뷰에 현재 색상을 전달
	CDialog::OnMouseMove(nFlags, point);
}

void CPixelDlg::OnOK() 
{
	//CDialog::OnOK(); 모달 다이얼로그인 경우
	
	UpdateData(TRUE); // DDX/DDV 기능을 위해 호출
	DestroyWindow();  // 모덜리스 다이얼로그인 경우
}

void CPixelDlg::CurrentPixelColor(COLORREF color)
{
	CRect  rc;
	CStatic* pFrame = (CStatic*)GetDlgItem(IDC_STATIC_COLOR);
	pFrame->GetClientRect(rc);

	CClientDC dc(pFrame);

	CBrush br(color);
	CBrush* pOld = dc.SelectObject(&br);
    dc.FillRect(rc, &br);
	dc.SelectObject(pOld);
}

void CPixelDlg::SendCurrentColor(COLORREF color)
{
	CRect  rc;
    CStatic* pFrame = 
		(CStatic*)(GetParentFrame()->GetActiveView()->GetDlgItem(IDC_FORM_COLOR));

	/** 다음 방법을 사용할 경우 #include "MainFrm.h"를 추가해야 한다.
	CMainFrame* pS = (CMainFrame*)AfxGetMainWnd();
	CStatic* pFrame =
		(CStatic*)(pS->GetActiveView()->GetDlgItem(IDC_FORM_COLOR));
	*******************************************************/

	pFrame->GetClientRect(rc); 

	CClientDC dc(pFrame);

	CBrush br(color);
	CBrush* pOld = dc.SelectObject(&br);
    dc.FillRect(rc, &br);
	dc.SelectObject(pOld);
}

void CPixelDlg::PostNcDestroy() 
{
	delete this; // 힙 메모리에 할당된 자신을 해제한다.	
	CDialog::PostNcDestroy();
}

void CPixelDlg::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// About 다이얼로그를 출력한다.
	AfxGetMainWnd()->SendMessage(WM_COMMAND, ID_APP_ABOUT);
	CDialog::OnRButtonDown(nFlags, point);
}
