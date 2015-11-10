// MyExplorerView.cpp : implementation of the CMyExplorerView class
//

#include "stdafx.h"
#include "MyExplorer.h"

#include "MyExplorerDoc.h"
#include "CntrItem.h"
#include "MyExplorerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyExplorerView

IMPLEMENT_DYNCREATE(CMyExplorerView, CListView)

BEGIN_MESSAGE_MAP(CMyExplorerView, CListView)
	//{{AFX_MSG_MAP(CMyExplorerView)
	ON_WM_DESTROY()
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	ON_COMMAND(ID_OLE_INSERT_NEW, OnInsertObject)
	ON_COMMAND(ID_CANCEL_EDIT_CNTR, OnCancelEditCntr)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CListView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyExplorerView construction/destruction

CMyExplorerView::CMyExplorerView()
{
	m_pSelection = NULL;
	// TODO: add construction code here

}

CMyExplorerView::~CMyExplorerView()
{
}

BOOL CMyExplorerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyExplorerView drawing

void CMyExplorerView::OnDraw(CDC* pDC)
{
	CMyExplorerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CListCtrl& refCtrl = GetListCtrl();
	refCtrl.InsertItem(0, "Item!");
	// TODO: add draw code for native data here
	// TODO: also draw all OLE items in the document

	// Draw the selection at an arbitrary position.  This code should be
	//  removed once your real drawing code is implemented.  This position
	//  corresponds exactly to the rectangle returned by CMyExplorerCntrItem,
	//  to give the effect of in-place editing.

	// TODO: remove this code when final draw code is complete.

	if (m_pSelection == NULL)
	{
		POSITION pos = pDoc->GetStartPosition();
		m_pSelection = (CMyExplorerCntrItem*)pDoc->GetNextClientItem(pos);
	}
	if (m_pSelection != NULL)
		m_pSelection->Draw(pDC, CRect(10, 10, 210, 210));
}

void CMyExplorerView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: You may populate your ListView with items by directly accessing
	//  its list control through a call to GetListCtrl().

	// TODO: remove this code when final selection model code is written
	m_pSelection = NULL;    // initialize selection

}

/////////////////////////////////////////////////////////////////////////////
// CMyExplorerView printing

BOOL CMyExplorerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyExplorerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyExplorerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMyExplorerView::OnDestroy()
{
	// Deactivate the item on destruction; this is important
	// when a splitter view is being used.
   CListView::OnDestroy();
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
}


/////////////////////////////////////////////////////////////////////////////
// OLE Client support and commands

BOOL CMyExplorerView::IsSelected(const CObject* pDocItem) const
{
	// The implementation below is adequate if your selection consists of
	//  only CMyExplorerCntrItem objects.  To handle different selection
	//  mechanisms, the implementation here should be replaced.

	// TODO: implement this function that tests for a selected OLE client item

	return pDocItem == m_pSelection;
}

void CMyExplorerView::OnInsertObject()
{
	// Invoke the standard Insert Object dialog box to obtain information
	//  for new CMyExplorerCntrItem object.
	COleInsertDialog dlg;
	if (dlg.DoModal() != IDOK)
		return;

	BeginWaitCursor();

	CMyExplorerCntrItem* pItem = NULL;
	TRY
	{
		// Create new item connected to this document.
		CMyExplorerDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pItem = new CMyExplorerCntrItem(pDoc);
		ASSERT_VALID(pItem);

		// Initialize the item from the dialog data.
		if (!dlg.CreateItem(pItem))
			AfxThrowMemoryException();  // any exception will do
		ASSERT_VALID(pItem);
		
        if (dlg.GetSelectionType() == COleInsertDialog::createNewItem)
			pItem->DoVerb(OLEIVERB_SHOW, this);

		ASSERT_VALID(pItem);

		// As an arbitrary user interface design, this sets the selection
		//  to the last item inserted.

		// TODO: reimplement selection as appropriate for your application

		m_pSelection = pItem;   // set selection to last inserted item
		pDoc->UpdateAllViews(NULL);
	}
	CATCH(CException, e)
	{
		if (pItem != NULL)
		{
			ASSERT_VALID(pItem);
			pItem->Delete();
		}
		AfxMessageBox(IDP_FAILED_TO_CREATE);
	}
	END_CATCH

	EndWaitCursor();
}

// The following command handler provides the standard keyboard
//  user interface to cancel an in-place editing session.  Here,
//  the container (not the server) causes the deactivation.
void CMyExplorerView::OnCancelEditCntr()
{
	// Close any in-place active item on this view.
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
	{
		pActiveItem->Close();
	}
	ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
}

// Special handling of OnSetFocus and OnSize are required for a container
//  when an object is being edited in-place.
void CMyExplorerView::OnSetFocus(CWnd* pOldWnd)
{
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL &&
		pActiveItem->GetItemState() == COleClientItem::activeUIState)
	{
		// need to set focus to this item if it is in the same view
		CWnd* pWnd = pActiveItem->GetInPlaceWindow();
		if (pWnd != NULL)
		{
			pWnd->SetFocus();   // don't call the base class
			return;
		}
	}

	CListView::OnSetFocus(pOldWnd);
}

void CMyExplorerView::OnSize(UINT nType, int cx, int cy)
{
	CListView::OnSize(nType, cx, cy);
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
		pActiveItem->SetItemRects();
}

/////////////////////////////////////////////////////////////////////////////
// CMyExplorerView diagnostics

#ifdef _DEBUG
void CMyExplorerView::AssertValid() const
{
	CListView::AssertValid();
}

void CMyExplorerView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CMyExplorerDoc* CMyExplorerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyExplorerDoc)));
	return (CMyExplorerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyExplorerView message handlers
void CMyExplorerView::OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct)
{
	//TODO: add code to react to the user changing the view style of your window
}

int CMyExplorerView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{

	// 리스트 콘트롤의 스타일을 설정한다.
    lpCreateStruct->style |= LVS_ICON | LVS_SORTASCENDING | LVS_EDITLABELS;

	if (CListView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	CListCtrl&	listCtrl = GetListCtrl();

	// Drag & Drop 을 설정해 놓는다.
	//LONG	exStyle = ::GetWindowLong(listCtrl.m_hWnd, GWL_EXSTYLE);
	//exStyle |= WS_EX_ACCEPTFILES;
	//::SetWindowLong( listCtrl.m_hWnd, GWL_EXSTYLE, exStyle );
	GetListCtrl().ModifyStyleEx(0, WS_EX_ACCEPTFILES);

	m_dropTarget.Register(this);
	m_cbFormat = (CLIPFORMAT)::RegisterClipboardFormat(FORMAT_FILECOPY);

	// 파일 이미지를 초기화 시킨다.
	CBitmap		bitmap, bitmap32;
	bitmap.LoadBitmap(IDB_SHELL);
	bitmap32.LoadBitmap(IDB_BIG_SHELL);

	m_imageList.Create(16, 16, ILC_COLOR8, 1, 1);
	m_imageList32.Create(32, 32, ILC_COLOR8, 1, 1);
	m_imageList.Add(&bitmap, RGB(255, 0, 255));
	m_imageList32.Add(&bitmap32, RGB(255, 0, 255));

	listCtrl.SetImageList(&m_imageList, LVSIL_SMALL);
	listCtrl.SetImageList(&m_imageList32, LVSIL_NORMAL);

	// 헤더를 초기화 시킨다.
	InitListHeader();

	// 자신의 포인터를 Doc에게 전달
	GetDocument()->SetListViewPointer(this);
	return 0;
}

//	Report 형식일때 헤더에 나오는 이름과 가로의 크기.
static	char*	cListHeader[] = {"이름", "크기", "종류", "바뀐 날짜", NULL};
const	int		nHeaderWidth[] = {130, 60, 70, 80};

void CMyExplorerView::InitListHeader()
{
	LV_COLUMN	lvColumn;
	CString		strHeader;
	CListCtrl&	listCtrl = GetListCtrl();
	lvColumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
	for(int i = 0 ; cListHeader[i] != NULL ; i++)
	{
		strHeader = cListHeader[i];
		lvColumn.fmt = (strHeader.Compare("크기") == 0 ? LVCFMT_RIGHT : LVCFMT_LEFT);
		lvColumn.cx = nHeaderWidth[i];
		lvColumn.pszText = cListHeader[i];
		lvColumn.iSubItem = i;
		listCtrl.InsertColumn(i, &lvColumn);
	}
	CHeaderCtrl* pH = (CHeaderCtrl*)GetListCtrl().GetDlgItem(0);

	// 헤더 컨트롤에 핫트래킹 속성 설정 
	// 마우스가 버튼 위에 있을 때 버튼이 선택되어 있음을 
	// 보여주는 기능
	pH->ModifyStyle(0, HDS_HOTTRACK);
}

void CMyExplorerView::SetFileList()
{
	CListCtrl&	listCtrl = GetListCtrl();

	listCtrl.DeleteAllItems();
	m_pFileList = GetDocument()->GetFileList();

	DisplayListView();
}

void CMyExplorerView::DisplayListView()
{
	int			i = 0;
	int			nIndex;
	CString		strFileSize;
	CString		strTime;
	POSITION	pos;
	LIST_VIEW*	pListView;
	LV_ITEM		lvItem;
	CListCtrl&	listCtrl = GetListCtrl();

	lvItem.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM;
	lvItem.iSubItem = 0;

	for( pos = m_pFileList->GetHeadPosition() ; pos != NULL ; i++ )
	{
		pListView = (LIST_VIEW*)m_pFileList->GetNext(pos);

		lvItem.iItem = i;
		if (pListView->bIsHidden == FALSE)
			lvItem.iImage = 0;
		else
			lvItem.iImage = 1;
		lvItem.pszText = (LPTSTR)(LPCTSTR)pListView->strName;		
		lvItem.lParam = (LPARAM)pListView;
	
		nIndex = listCtrl.InsertItem(&lvItem);

		strFileSize.Format("%d", pListView->dwFileSize);
		strTime.Format("%d/%d/%d", pListView->tLastWriteTime.GetYear(),
			pListView->tLastWriteTime.GetMonth(), pListView->tLastWriteTime.GetDay());

		listCtrl.SetItemText(nIndex, 1, strFileSize);
		listCtrl.SetItemText(nIndex, 2, pListView->strKind);
		listCtrl.SetItemText(nIndex, 3, strTime);
	}
}






