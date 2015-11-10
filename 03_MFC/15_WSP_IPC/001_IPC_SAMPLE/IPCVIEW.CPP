// IPCView.cpp : implementation of the CIPCView class
//

#include "stdafx.h"
#include "IPC.h"

#include "IPCDoc.h"
#include "IPCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIPCView

IMPLEMENT_DYNCREATE(CIPCView, CFormView)

BEGIN_MESSAGE_MAP(CIPCView, CFormView)
	//{{AFX_MSG_MAP(CIPCView)
	ON_BN_CLICKED(IDC_COPY_DATA, OnCopyData)
	ON_BN_CLICKED(IDC_USER_MSG, OnUserMsg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIPCView construction/destruction

CIPCView::CIPCView()
	: CFormView(CIPCView::IDD)
{
	//{{AFX_DATA_INIT(CIPCView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CIPCView::~CIPCView()
{
}

void CIPCView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIPCView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CIPCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CIPCView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CIPCView diagnostics

#ifdef _DEBUG
void CIPCView::AssertValid() const
{
	CFormView::AssertValid();
}

void CIPCView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CIPCDoc* CIPCView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIPCDoc)));
	return (CIPCDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CIPCView message handlers

void CIPCView::OnUserMsg() 
{
	CWnd* pWnd = CWnd::FindWindow(NULL, "받기프로그램");
	if(!pWnd)
	{
		AfxMessageBox("프로그램을 못찾음");
		return;
	}
	//pWnd->SendMessage(WM_MY_MSG, (WPARAM)GetCurrentProcessId());
	pWnd->PostMessage(WM_MY_MSG, (WPARAM)GetCurrentProcessId());
	AfxMessageBox("메시지 전송 완료");
}

void CIPCView::OnCopyData() 
{
	CString strData;
	GetDlgItemText(IDC_DATA, strData); // 에디트 컨트롤의 문자열 얻음

	COPYDATASTRUCT  cds;
	cds.dwData = 1004;  // 사용 목적에 따른 식별값
	cds.cbData = strData.GetLength()+1;  // 전달될 정보 lpData의 크기 
	cds.lpData = (LPSTR)(LPCSTR)strData; // 전달될 정보

	CWnd* pWnd = CWnd::FindWindow(NULL, "받기프로그램");
	if(!pWnd)
	{
		AfxMessageBox("프로그램을 못찾음");
		return;
	}
	pWnd->SendMessage(WM_COPYDATA, (WPARAM)m_hWnd, (LPARAM)&cds);
}

