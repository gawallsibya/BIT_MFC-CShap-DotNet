// FileView.cpp : implementation of the CFileView class
//

#include "stdafx.h"
#include "File.h"

#include "FileDoc.h"
#include "FileView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileView

IMPLEMENT_DYNCREATE(CFileView, CListView)

BEGIN_MESSAGE_MAP(CFileView, CListView)
	//{{AFX_MSG_MAP(CFileView)
	ON_COMMAND(IDM_VIEW_ICON, OnViewIcon)
	ON_COMMAND(IDM_VIEW_LIST, OnViewList)
	ON_COMMAND(IDM_VIEW_REPORT, OnViewReport)
	ON_COMMAND(IDM_VIEW_SMALL, OnViewSmall)
	ON_COMMAND(IDM_VIEW_CHANGE, OnViewChange)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CListView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileView construction/destruction

CFileView::CFileView()
{
	// TODO: add construction code here

}

CFileView::~CFileView()
{
}

BOOL CFileView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CFileView drawing

void CFileView::OnDraw(CDC* pDC)
{
	CFileDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CFileView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	CListCtrl& list = GetListCtrl();

	// 1. 보기 style 결정.
	list.ModifyStyle( LVS_TYPEMASK,// 제거 style. 기존 style 제거 
					  LVS_REPORT); // Add style. report 보기 적용.

	// 2. ImageList연결하기.
	CImageList img;

	img.Create( IDB_BITMAP1, 16, 1, RGB(255,255,255));
	list.SetImageList(&img, LVSIL_SMALL);
	img.Detach();

	img.Create( IDB_BITMAP2, 32, 1, RGB(255,255,255));
	list.SetImageList(&img, LVSIL_NORMAL);
	img.Detach();

	////////////////////////////////////////////
	// 3. REPORT 보기 일때는 컬럼 헤더 필요.
	list.InsertColumn(0, "화일", LVCFMT_LEFT, 150);
	list.InsertColumn(1, "크기", LVCFMT_RIGHT, 150);
	list.InsertColumn(3, "날짜", LVCFMT_RIGHT, 150);

	// ListView에 확장 style 넣기. - MSDN에 다양한 style 참고.	
	list.SetExtendedStyle( LVS_EX_HEADERDRAGDROP |
						   LVS_EX_GRIDLINES |
						   LVS_EX_FULLROWSELECT );



	Refresh( "C:\\" ); // 파일을 열거.
}

/////////////////////////////////////////////////////////////////////////////
// CFileView printing

BOOL CFileView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFileView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFileView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CFileView diagnostics

#ifdef _DEBUG
void CFileView::AssertValid() const
{
	CListView::AssertValid();
}

void CFileView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CFileDoc* CFileView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFileDoc)));
	return (CFileDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFileView message handlers

void CFileView::Refresh(char *dir)
{
	// listview을 모두 지운다.
	CListCtrl& list = GetListCtrl(); // !!!!!!!!!!!
	list.DeleteAllItems();
	SetCurrentDirectory( dir );

	CFileFind f; BOOL b = f.FindFile("*.*");

	while ( b )
	{
		b = f.FindNextFile();

		if ( ! f.IsDirectory() && ! f.IsHidden() )
		{
			list.InsertItem(0, f.GetFileName(), 0);
			
			CString msg;
			msg.Format( "%d KB", (f.GetLength() / 1024) + 1 );
			list.SetItemText(0, 1, msg );
		}
	}
}



void CFileView::OnViewIcon() 
{
	CListCtrl& list = GetListCtrl();
	list.ModifyStyle( LVS_TYPEMASK, LVS_ICON);
}
void CFileView::OnViewList() 
{
	CListCtrl& list = GetListCtrl();
	list.ModifyStyle( LVS_TYPEMASK, LVS_LIST);
}
void CFileView::OnViewReport() 
{
	CListCtrl& list = GetListCtrl();
	list.ModifyStyle( LVS_TYPEMASK, LVS_REPORT);
}
void CFileView::OnViewSmall() 
{
	CListCtrl& list = GetListCtrl();
	list.ModifyStyle( LVS_TYPEMASK, LVS_SMALLICON);	
}

void CFileView::OnViewChange() 
{
	// 폴더 선택 다이얼로그 나타내기. 	
	BROWSEINFO bi = { 0};
	bi.hwndOwner = this->m_hWnd;
	bi.lpszTitle = "폴더를 선택해 주세요";

	LPITEMIDLIST pidl = SHBrowseForFolder( & bi );

	// pidl을 문자열로 바꾼다.
	char buf[256];
	SHGetPathFromIDList( pidl, buf);

	Refresh(buf);
}









