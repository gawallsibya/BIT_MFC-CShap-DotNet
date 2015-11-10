// ExplorerTestView.cpp : implementation of the CExplorerTestView class
//

#include "stdafx.h"
#include "ExplorerTest.h"

#include "ExplorerTestDoc.h"
#include "CntrItem.h"
#include "ExplorerTestView.h"
//
#include "data.h"
#include "InfoDlg.h"
#include "MainFrm.h"
//

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExplorerTestView

IMPLEMENT_DYNCREATE(CExplorerTestView, CListView)

BEGIN_MESSAGE_MAP(CExplorerTestView, CListView)
	//{{AFX_MSG_MAP(CExplorerTestView)
	ON_WM_DESTROY()
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	ON_COMMAND(ID_OLE_INSERT_NEW, OnInsertObject)
	ON_COMMAND(ID_CANCEL_EDIT_CNTR, OnCancelEditCntr)
	ON_WM_CREATE()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_VIEW_SMALLICON, OnViewSmallicon)
	ON_COMMAND(ID_VIEW_LARGEICON, OnViewLargeicon)
	ON_COMMAND(ID_VIEW_LIST, OnViewList)
	ON_COMMAND(ID_VIEW_DETAILS, OnViewDetails)
	ON_COMMAND(ID_INFORMATION, OnInformation)
	ON_NOTIFY_REFLECT(LVN_BEGINLABELEDIT, OnBeginlabeledit)
	ON_NOTIFY_REFLECT(LVN_ENDLABELEDIT, OnEndlabeledit)
	ON_COMMAND(ID_FILE_RENAME, OnFileRename)
	ON_COMMAND(ID_FILE_DELETE, OnFileDelete)
	ON_NOTIFY_REFLECT(LVN_BEGINDRAG, OnBegindrag)
	ON_NOTIFY_REFLECT(LVN_ITEMCHANGED, OnItemchanged)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CListView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExplorerTestView construction/destruction

CExplorerTestView::CExplorerTestView()
{
	m_pSelection = NULL;
	// TODO: add construction code here

}

CExplorerTestView::~CExplorerTestView()
{
}

BOOL CExplorerTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CExplorerTestView drawing

void CExplorerTestView::OnDraw(CDC* pDC)
{
	CExplorerTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CListCtrl& refCtrl = GetListCtrl();
	refCtrl.InsertItem(0, "Item!");

	// TODO: remove this code when final draw code is complete.

	if (m_pSelection == NULL)
	{
		POSITION pos = pDoc->GetStartPosition();
		m_pSelection = (CExplorerTestCntrItem*)pDoc->GetNextClientItem(pos);
	}
	if (m_pSelection != NULL)
		m_pSelection->Draw(pDC, CRect(10, 10, 210, 210));
}

void CExplorerTestView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();
	m_pSelection = NULL;    // initialize selection
}

/////////////////////////////////////////////////////////////////////////////
// CExplorerTestView printing

BOOL CExplorerTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CExplorerTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CExplorerTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CExplorerTestView::OnDestroy()
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

BOOL CExplorerTestView::IsSelected(const CObject* pDocItem) const
{
	// The implementation below is adequate if your selection consists of
	//  only CExplorerTestCntrItem objects.  To handle different selection
	//  mechanisms, the implementation here should be replaced.

	// TODO: implement this function that tests for a selected OLE client item

	return pDocItem == m_pSelection;
}

void CExplorerTestView::OnInsertObject()
{
	// Invoke the standard Insert Object dialog box to obtain information
	//  for new CExplorerTestCntrItem object.
	COleInsertDialog dlg;
	if (dlg.DoModal() != IDOK)
		return;

	BeginWaitCursor();

	CExplorerTestCntrItem* pItem = NULL;
	TRY
	{
		// Create new item connected to this document.
		CExplorerTestDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pItem = new CExplorerTestCntrItem(pDoc);
		ASSERT_VALID(pItem);

		// Initialize the item from the dialog data.
		if (!dlg.CreateItem(pItem))
			AfxThrowMemoryException();  // any exception will do
		ASSERT_VALID(pItem);

		// If item created from class list (not from file) then launch
		//  the server to edit the item.
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
void CExplorerTestView::OnCancelEditCntr()
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
void CExplorerTestView::OnSetFocus(CWnd* pOldWnd)
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

void CExplorerTestView::OnSize(UINT nType, int cx, int cy)
{
	CListView::OnSize(nType, cx, cy);
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
		pActiveItem->SetItemRects();
}

/////////////////////////////////////////////////////////////////////////////
// CExplorerTestView diagnostics

#ifdef _DEBUG
void CExplorerTestView::AssertValid() const
{
	CListView::AssertValid();
}

void CExplorerTestView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CExplorerTestDoc* CExplorerTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExplorerTestDoc)));
	return (CExplorerTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExplorerTestView public functions

void CExplorerTestView::SetFileList()
{
	CListCtrl&	listCtrl = GetListCtrl();

	listCtrl.DeleteAllItems();
	m_pFileList = GetDocument()->GetFileList();

	DisplayListView();
}

/////////////////////////////////////////////////////////////////////////////
// CExplorerTestView private functions

void CExplorerTestView::InitListHeader()
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
	pH->ModifyStyle(0, HDS_HOTTRACK);
}

void CExplorerTestView::DisplayListView()
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

void CExplorerTestView::SetEnableMenu(CMenu* pMenu)
{
	CListCtrl&	listCtrl = GetListCtrl();

	if (listCtrl.GetSelectedCount() > 1)
	{
		pMenu->EnableMenuItem(ID_FILE_RENAME, MF_GRAYED);
	}
}

UINT CExplorerTestView::GetCurrentID()
{
	UINT		uStyle;
	DWORD		dwStyle;
	CListCtrl&	listCtrl = GetListCtrl();

	// 현재의 리스트 콘트롤의 스타일을 알아낸다.
	dwStyle = listCtrl.GetStyle() & LVS_TYPEMASK;

	if (dwStyle == LVS_ICON)
	{
		uStyle = ID_VIEW_LARGEICON;
	}
	else if(dwStyle == LVS_SMALLICON)
	{
		uStyle = ID_VIEW_SMALLICON;
	}
	else if(dwStyle == LVS_LIST)
	{
		uStyle = ID_VIEW_LIST;
	}
	else if(dwStyle == LVS_REPORT)
	{
		uStyle = ID_VIEW_DETAILS;
	}

	return	uStyle;
}

BOOL CExplorerTestView::DeleteFiles(int nItem, CString strPath)
{
	CListCtrl&	listCtrl = GetListCtrl();

	if (::DeleteFile(strPath) == FALSE)		// 파일을 실제로 지운다.
	{										// 실패하면...
		if (GetDocument()->DeleteReadOnlyFile(strPath) == FALSE)
		{
			return	FALSE;
		}
	}

	listCtrl.DeleteItem(nItem);

	return	TRUE;
}
/*
void CExplorerTestView::TransferData(CSharedFile* pSharedFile)
{
	int				nItem = -1;
	//CStringArray	fileList;
	CObList			fileList;
	LIST_VIEW*		pListView;
	CListCtrl&		listCtrl = GetListCtrl();

	while( (nItem = listCtrl.GetNextItem(nItem, LVNI_SELECTED)) != -1 )
	{
		pListView = (LIST_VIEW*)listCtrl.GetItemData(nItem);
		//fileList.Add(pListView->strPath);
		fileList.AddTail((CObject*)pListView);
	}
	CArchive	ar(pSharedFile, CArchive::store);
	
	CExplorerTestDoc*	pDoc = (CExplorerTestDoc*)GetDocument();
	pDoc->SetCopyFileList(&fileList);
	pDoc->SerializeCopyFiles(ar);

	ar.Close();
}
*/
/////////////////////////////////////////////////////////////////////////////
// CExplorerTestView message handlers

void CExplorerTestView::OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct)
{
	//TODO: add code to react to the user changing the view style of your window
}

int CExplorerTestView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
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

	// CExplorerTestView 클래스 포인터를 도큐먼트에 셋팅시킨다.
	GetDocument()->SetListViewPointer(this);

	return 0;
}

void CExplorerTestView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	CMenu		menu;
	CMenu*		pSubMenu;
	CListCtrl&	listCtrl = GetListCtrl();

	//m_ptRButton = point;
	menu.LoadMenu(IDR_CONTEXTMENU);

	if (listCtrl.GetSelectedCount() < 1)	// 뷰 영역을 클릭하면
	{
		UINT	nID = GetCurrentID();

		pSubMenu = menu.GetSubMenu(1);
		// 라디오 버튼으로 체크한다.
		pSubMenu->CheckMenuRadioItem(ID_VIEW_SMALLICON, ID_VIEW_DETAILS,
			nID, MF_BYCOMMAND);
	}
	else	// 파일을 클릭하면
	{
		pSubMenu = menu.GetSubMenu(0);
		SetEnableMenu(pSubMenu);
	}

	pSubMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
}

void CExplorerTestView::OnViewSmallicon() 
{
	// TODO: Add your command handler code here
	((CMainFrame*)::AfxGetMainWnd())->SetListViewStyle(ID_VIEW_SMALLICON);
}

void CExplorerTestView::OnViewLargeicon() 
{
	// TODO: Add your command handler code here
	((CMainFrame*)::AfxGetMainWnd())->SetListViewStyle(ID_VIEW_LARGEICON);
}

void CExplorerTestView::OnViewList() 
{
	// TODO: Add your command handler code here
	((CMainFrame*)::AfxGetMainWnd())->SetListViewStyle(ID_VIEW_LIST);
}

void CExplorerTestView::OnViewDetails() 
{
	// TODO: Add your command handler code here
	((CMainFrame*)::AfxGetMainWnd())->SetListViewStyle(ID_VIEW_DETAILS);
}

void CExplorerTestView::OnInformation() 
{
	// TODO: Add your command handler code here
	CInfoDlg	dlg;	// 파일 정보 다이알로그 박스 클래스
	LIST_VIEW*	pListView;
	int			nItem = -1;
	CObList		obList;	// 선택된 파일 리스트들
	CListCtrl&	listCtrl = GetListCtrl();

	// 리스트 뷰에서 선택된 항목들만 CObList에 추가시킨다.
	while( (nItem = listCtrl.GetNextItem(nItem, LVNI_SELECTED)) != -1 )
	{
		pListView = new LIST_VIEW;
		*pListView = *(LIST_VIEW*)listCtrl.GetItemData(nItem);
		obList.AddTail((CObject*)pListView);
	}
	dlg.SetInfo(&obList);	// 다이알로그가 화면에 보여지기 전에
							// 먼저 파일정보를 다이알로그에 셋팅한다.
	dlg.DoModal();	// OnInitDialog를 호출하여 화면에 보이게 한다.

	// 모든 선택된 파일 리스트들을 메모리에서 삭제한다.
	for(POSITION pos = obList.GetHeadPosition() ; pos != NULL ; )
	{
		pListView = (LIST_VIEW*)obList.GetNext(pos);
		delete	pListView;
	}
	obList.RemoveAll();
}

void CExplorerTestView::OnBeginlabeledit(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LV_DISPINFO* pDispInfo = (LV_DISPINFO*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void CExplorerTestView::OnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LV_DISPINFO* pDispInfo = (LV_DISPINFO*)pNMHDR;
	// TODO: Add your control notification handler code here
	// 프로그램이 종료되는 경우
	if (((CMainFrame*)::AfxGetMainWnd())->IsProgramExit() == TRUE)
	{
		*pResult = 0;
		return;
	}

	int			nItem;
	CString		strNewFile;
	LIST_VIEW*	pListView;
	LV_ITEM		lvItem = pDispInfo->item;
	CListCtrl&	listCtrl = GetListCtrl();
	CEdit*		pEdit = listCtrl.GetEditControl();

	pEdit->GetWindowText(strNewFile);	// 변경된 파일 이름을 가져온다.

	nItem = lvItem.iItem;
	pListView = (LIST_VIEW*)listCtrl.GetItemData(nItem);

	// 파일 이름이 바뀌지 않았으면
	if (strNewFile == pListView->strName)
	{
		*pResult = 0;
		return;
	}

	// 파일 이름이 없으면
	if (strNewFile.IsEmpty())
	{
		MessageBox("파일 이름을 입력해야 합니다.", "이름 바꾸기", MB_ICONSTOP);
		listCtrl.EditLabel(nItem);
		*pResult = 0;
		return;
	}

	CFileStatus		fs;
	CString			strPath;
	
	strPath = GetDocument()->GetCurrentPath() + strNewFile;

	// 같은 이름의 파일이 존재하면
	if (CFile::GetStatus(strPath, fs))
	{
		CString		str = pListView->strName + "의 이름을 바꿀수 없습니다.\n"
			+ "지정한 이름을 가진 파일이 이미 있습니다.\n"
			+ "다른 파일 이름을 지정하십시오.";
		MessageBox(str, "파일 이름 바꾸기 오류", MB_ICONSTOP);
		listCtrl.EditLabel(nItem);
		*pResult = 0;
		return;
	}

	// 새로이 바뀐 파일로 Rename 시킨다.
	rename(pListView->strPath, strPath);	// 파일을 실제로 바꾼다.

	pListView->strName = strNewFile;
	pListView->strPath = strPath;

	CString		strExt;
	int			nIndex = strNewFile.FindOneOf(".");

	if (nIndex == -1)
		strExt = "";
	else
	{
		int		nNum = strNewFile.GetLength() - nIndex - 1;
		strExt = strNewFile.Right(nNum);
	}

	pListView->strKind = strExt + " 파일";
	listCtrl.SetItemText(nItem, 0, strNewFile);
	listCtrl.SetItemText(nItem, 2, pListView->strKind);

	*pResult = 0;
}

void CExplorerTestView::OnFileRename() 
{
	// TODO: Add your command handler code here
	int			nItem = -1;
	CListCtrl&	listCtrl = GetListCtrl();

	nItem = listCtrl.GetNextItem(nItem, LVNI_SELECTED);
	listCtrl.EditLabel(nItem);
}

void CExplorerTestView::OnFileDelete() 
{
	// TODO: Add your command handler code here
	int			nItem = -1;
	int			nSelectedCount;
	CString		strMessage;
	LIST_VIEW*	pListView;
	CListCtrl&	listCtrl = GetListCtrl();

	nSelectedCount = listCtrl.GetSelectedCount();

	// 파일 하나만 선택되어 졌으면
	if (nSelectedCount == 1)
	{
		nItem = listCtrl.GetNextItem(nItem, LVNI_SELECTED);
		pListView = (LIST_VIEW*)listCtrl.GetItemData(nItem);

		strMessage = "'" + pListView->strName + "'" + "항목을 삭제하시겠습니까?";
		if (MessageBox(strMessage, "파일 삭제 확인", MB_ICONQUESTION | MB_YESNO) != IDYES)
			return;

		CWaitCursor		waitCursor;	// 커서를 모래시계로 바꾼다.
		if (DeleteFiles(nItem, pListView->strPath) == FALSE)
		{
			strMessage = pListView->strName + " 파일을 삭제할 수가 없습니다.";
			MessageBox(strMessage, "파일 삭제", MB_ICONSTOP);
			return;
		}
	}
	else	// 하나 이상이 선택되어 졌으면
	{
		strMessage.Format("%d파일을 삭제하시겠습니까?", nSelectedCount);
		if (MessageBox(strMessage, "파일 삭제 확인", MB_ICONQUESTION | MB_YESNO) != IDYES)
			return;

		CWaitCursor		waitCursor;
		while((nItem = listCtrl.GetNextItem(nItem, LVNI_SELECTED)) != -1)
		{
			pListView = (LIST_VIEW*)listCtrl.GetItemData(nItem);

			if (DeleteFiles(nItem, pListView->strPath) == FALSE)
			{
				strMessage = pListView->strName + " 파일을 삭제할 수가 없습니다.";
				MessageBox(strMessage, "파일 삭제", MB_ICONSTOP);
				return;
			}
			nItem = -1;
		}
	}
}

void CExplorerTestView::OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	int				nItem = -1;
	CObList			fileList;
	LIST_VIEW*		pListView;
	CListCtrl&		listCtrl = GetListCtrl();
	CSharedFile		sharedFile;
	COleDataSource*	dataSource = new COleDataSource;

	while((nItem = listCtrl.GetNextItem(nItem, LVNI_SELECTED)) != -1)
	{
		pListView = (LIST_VIEW*)listCtrl.GetItemData(nItem);
		fileList.AddTail((CObject*)pListView);
	}

	CArchive	ar(&sharedFile, CArchive::store);
	
	CExplorerTestDoc*	pDoc = (CExplorerTestDoc*)GetDocument();
	pDoc->SetCopyFileList(&fileList);
	pDoc->SerializeCopyFiles(ar);

	ar.Close();

	dataSource->CacheGlobalData(m_cbFormat, sharedFile.Detach());
	dataSource->DoDragDrop();

	delete dataSource;

	*pResult = 0;
}

void CExplorerTestView::OnItemchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	int nSel = pNMListView->iItem; // 선택된 항목의 인덱스
	if(nSel != -1) // 항목을 제대로 선택했는지 판단
	{
		CString strText = GetListCtrl().GetItemText(nSel, 0);
	}
	*pResult = 0;
}
