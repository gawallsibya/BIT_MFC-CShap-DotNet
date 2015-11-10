// FontView.cpp : implementation file
//

#include "stdafx.h"
#include "MultiLook.h"
#include "FontView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFontView

IMPLEMENT_DYNCREATE(CFontView, CView)

CFontView::CFontView()
{
	ZeroMemory(&m_lf, sizeof(LOGFONT)); // 논리 글꼴 구조체 초기화
	m_strFaceName = "디폴트";
	m_nFontSize = -1;
}

CFontView::~CFontView()
{
}


BEGIN_MESSAGE_MAP(CFontView, CView)
	//{{AFX_MSG_MAP(CFontView)
	ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFontView drawing

void CFontView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
	CFont newFont, *pOldFont;
	CString strInfo;

	if(!newFont.CreateFontIndirect(&m_lf)) // 폰트 생성 실패시
	{
		AfxMessageBox("새로운 폰트 생성 실패");
		return;
	}

	CRect rc;
	GetClientRect(rc);
	pOldFont = pDC->SelectObject(&newFont);
	strInfo.Format("선택한 글꼴은 %s, 크기는 %d 입니다",
		m_strFaceName, m_nFontSize);
	
	pDC->SetTextColor(m_color);
	pDC->DrawText(strInfo, rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER); // 중앙에 문자열 출력
	pDC->SelectObject(pOldFont);
}

/////////////////////////////////////////////////////////////////////////////
// CFontView diagnostics

#ifdef _DEBUG
void CFontView::AssertValid() const
{
	CView::AssertValid();
}

void CFontView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFontView message handlers

void CFontView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	CFontDialog dlg(&m_lf); // m_lf에 설정된 값으로 폰트 다이얼로그 초기화
	dlg.m_cf.rgbColors = m_color;
	if(dlg.DoModal() == IDOK)
	{
		// 폰트 다이얼로그에서 사용자가 선택한 정보를 설정한다.
		dlg.GetCurrentFont(&m_lf); // 논리 글꼴 구조체 설정
		m_strFaceName = dlg.GetFaceName(); // 글꼴 이름
		m_nFontSize = dlg.GetSize() / 10;  // 글꼴 크기 
		m_color = dlg.GetColor();  // 글자색 설정
		Invalidate();
	}
	CView::OnLButtonDblClk(nFlags, point);
}
