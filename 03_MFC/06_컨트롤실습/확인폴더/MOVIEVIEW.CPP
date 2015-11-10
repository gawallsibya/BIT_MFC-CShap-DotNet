// MovieView.cpp : implementation of the CMovieView class
//

#include "stdafx.h"
#include "Movie.h"

#include "MovieDoc.h"
#include "MovieView.h"
#include "DataDlg.h"
#include "MySheet.h"
#include "mmsystem.h "

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMovieView


IMPLEMENT_DYNCREATE(CMovieView, CFormView)

BEGIN_MESSAGE_MAP(CMovieView, CFormView)
	//{{AFX_MSG_MAP(CMovieView)
	ON_BN_CLICKED(IDC_FORM_MODAL, OnFormModal)
	ON_BN_CLICKED(IDC_FORM_MODELESS, OnFormModeless)
	ON_BN_CLICKED(IDC_FORM_PROPERTY, OnFormProperty)
	ON_BN_CLICKED(IDC_FORM_WIZARD, OnFormWizard)
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMovieView construction/destruction

CMovieView::CMovieView()
	: CFormView(CMovieView::IDD)
{
	//{{AFX_DATA_INIT(CMovieView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	m_pDlg = NULL;
}

CMovieView::~CMovieView()
{
}

void CMovieView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMovieView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CMovieView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMovieView diagnostics

#ifdef _DEBUG
void CMovieView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMovieView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMovieDoc* CMovieView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMovieDoc)));
	return (CMovieDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMovieView message handlers

void CMovieView::OnFormModal() 
{
	// 모달 다이얼로그를 화면에 출력
	CDataDlg  dlg;
	if(dlg.DoModal() == IDOK)
	{
		SetDlgItemText(IDC_FORM_COUNT, dlg.m_strCount);
	}
}

void CMovieView::OnFormModeless() 
{
	// 모덜리스 다이얼로그를 화면에 출력
	if(m_pDlg->GetSafeHwnd() == NULL)
	{
		m_pDlg = new CPixelDlg;
		m_pDlg->Create(IDD_MODELESS);
	}
}

void CMovieView::OnProperties()
{
	/*** 컴포넌트 갤러리에 의해 추가된 부분 ****/
	// 프로퍼티 다이얼로그를  화면에 출력
	CMySheet propSheet;
	propSheet.m_psh.dwFlags |= PSH_NOAPPLYNOW; // [적용]버튼 제거
	propSheet.DoModal();
}

void CMovieView::OnFormProperty() 
{
	OnProperties(); 
}

void CMovieView::OnFormWizard() 
{
	// 위저드 다이얼로그 출력
	CMySheet propSheet;
	propSheet.SetWizardMode(); // 위저드 다이얼로그 형식 설정
	propSheet.DoModal();
}


void CMovieView::OnMouseMove(UINT nFlags, CPoint point) 
{
	CRect rc;
	CStatic* pFrame = (CStatic*)GetDlgItem(IDC_FORM_IMAGE);
	pFrame->GetWindowRect(rc);
	ScreenToClient(rc);

	if(rc.PtInRect(point))
	{
		// 리소스를 이용하는 경우 
		PlaySound(MAKEINTRESOURCE(IDR_WAVE1), AfxGetInstanceHandle(), 
			SND_ASYNC | SND_RESOURCE); 
        
		// 파일을 이용하는 경우 
		//PlaySound("c:\\Ricochet.wav", NULL, SND_ASYNC | SND_FILENAME); 
	}	
	CFormView::OnMouseMove(nFlags, point);
}
