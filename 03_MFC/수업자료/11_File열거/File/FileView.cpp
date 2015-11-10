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

	// 1. ���� style ����.
	list.ModifyStyle( LVS_TYPEMASK,// ���� style. ���� style ���� 
					  LVS_REPORT); // Add style. report ���� ����.

	// 2. ImageList�����ϱ�.
	CImageList img;

	img.Create( IDB_BITMAP1, 16, 1, RGB(255,255,255));
	list.SetImageList(&img, LVSIL_SMALL);
	img.Detach();

	img.Create( IDB_BITMAP2, 32, 1, RGB(255,255,255));
	list.SetImageList(&img, LVSIL_NORMAL);
	img.Detach();

	////////////////////////////////////////////
	// 3. REPORT ���� �϶��� �÷� ��� �ʿ�.
	list.InsertColumn(0, "ȭ��", LVCFMT_LEFT, 150);
	list.InsertColumn(1, "ũ��", LVCFMT_RIGHT, 150);
	list.InsertColumn(3, "��¥", LVCFMT_RIGHT, 150);

	// ListView�� Ȯ�� style �ֱ�. - MSDN�� �پ��� style ����.	
	list.SetExtendedStyle( LVS_EX_HEADERDRAGDROP |
						   LVS_EX_GRIDLINES |
						   LVS_EX_FULLROWSELECT );



	Refresh( "C:\\" ); // ������ ����.
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
	// listview�� ��� �����.
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
	// ���� ���� ���̾�α� ��Ÿ����. 	
	BROWSEINFO bi = { 0};
	bi.hwndOwner = this->m_hWnd;
	bi.lpszTitle = "������ ������ �ּ���";

	LPITEMIDLIST pidl = SHBrowseForFolder( & bi );

	// pidl�� ���ڿ��� �ٲ۴�.
	char buf[256];
	SHGetPathFromIDList( pidl, buf);

	Refresh(buf);
}









