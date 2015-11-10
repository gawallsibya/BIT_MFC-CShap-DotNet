// LeftView.cpp : implementation of the CLeftView class
//

#include "stdafx.h"
#include "ExplorerTest.h"

#include "ExplorerTestDoc.h"
#include "LeftView.h"
//
#include "data.h"
#include "MainFrm.h"
#include <afxadv.h>	// CSharedFile
//

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeftView

IMPLEMENT_DYNCREATE(CLeftView, CTreeView)

BEGIN_MESSAGE_MAP(CLeftView, CTreeView)
	//{{AFX_MSG_MAP(CLeftView)
	ON_WM_CREATE()
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDING, OnItemexpanding)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelchanged)
	ON_WM_RBUTTONDOWN()
	ON_WM_CAPTURECHANGED()
	ON_COMMAND(ID_FILE_RENAME, OnFileRename)
	ON_NOTIFY_REFLECT(TVN_BEGINLABELEDIT, OnBeginlabeledit)
	ON_NOTIFY_REFLECT(TVN_ENDLABELEDIT, OnEndlabeledit)
	ON_COMMAND(ID_FOLDER_NEW, OnFolderNew)
	ON_COMMAND(ID_FILE_DELETE, OnFileDelete)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CTreeView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeftView construction/destruction

CLeftView::CLeftView()
{
	// TODO: add construction code here
	m_bRButtonDown = FALSE;
}

CLeftView::~CLeftView()
{
}

BOOL CLeftView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CTreeView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLeftView drawing

void CLeftView::OnDraw(CDC* pDC)
{
	CExplorerTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}


/////////////////////////////////////////////////////////////////////////////
// CLeftView printing

BOOL CLeftView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLeftView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLeftView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CLeftView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO: You may populate your TreeView with items by directly accessing
	//  its tree control through a call to GetTreeCtrl().
	// 폴더 내용을 초기화 시킨다.
	CStringArray	driveNames;

	GetDriveNames(&driveNames);
	InitFolders(&driveNames);
}

/////////////////////////////////////////////////////////////////////////////
// CLeftView diagnostics

#ifdef _DEBUG
void CLeftView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CLeftView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CExplorerTestDoc* CLeftView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExplorerTestDoc)));
	return (CExplorerTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLeftView private functions

void CLeftView::GetDriveNames(CStringArray* driveArray)
{
	int		nIndex = 0, nTemp = 0;
	BOOL	bBreak = TRUE;
	char	driveNames[100] = {0, };
	char	driveTemp[100]  = {0, };

	// 드라이브의 이름을 알아낸다.
	::GetLogicalDriveStrings(sizeof(driveNames), driveNames);

	while(driveNames[nIndex] || bBreak)
	{
		if(driveNames[nIndex])
		{
			if ((driveNames[nIndex] != '\\') && (driveNames[nIndex] != '/'))
				driveTemp[nTemp++] = driveNames[nIndex];

			bBreak = TRUE;
		}
		else
		{
			driveTemp[nTemp] = '\0';
			driveArray->Add(driveTemp);
			bBreak = FALSE;
			nTemp = 0;
		}
		nIndex++;
	}
}

void CLeftView::InitFolders(CStringArray* driveNames)
{
	int			nType;
	HTREEITEM	hItem;
	CString		strDriveName;
	CTreeCtrl&	treeCtrl = GetTreeCtrl();

	for(int i = 0 ; i < driveNames->GetSize() ; i++)
	{
		strDriveName = driveNames->GetAt(i);
		nType = ::GetDriveType(strDriveName);

		switch(nType)
		{
		case DRIVE_REMOVABLE   :
			hItem = DisplayDrive(strDriveName, 4);
			InsertFolder('0', hItem);	// 반드시 쓰레기 폴더를 미리 하나 넣어 놔야만 한다.
			break;						// 나중에 Expanding 할때에 반드시 지워야 한다.

		case DRIVE_NO_ROOT_DIR :
		case DRIVE_REMOTE :
		case DRIVE_RAMDISK :
		case DRIVE_FIXED       :
			hItem = DisplayDrive(strDriveName, 5);
			InsertFolder('0', hItem);

			if (strDriveName.Compare("c:") == 0)	// C 드라이브를 먼저 선택해 놓는다.
			{
				treeCtrl.SelectItem(hItem);
				treeCtrl.Expand(hItem, TVE_EXPAND);
			}
			break;

		case DRIVE_CDROM       :
			hItem = DisplayDrive(strDriveName, 6);
			InsertFolder('0', hItem);
			break;
		}
	}
}

HTREEITEM CLeftView::DisplayDrive(CString strDriveName, int nImage)
{
	CTreeCtrl&	treeCtrl = GetTreeCtrl();

	TV_INSERTSTRUCT	tvStruct;

	tvStruct.hParent = NULL;
	tvStruct.hInsertAfter = TVI_SORT;
	tvStruct.item.iImage = nImage;
	tvStruct.item.iSelectedImage = nImage;
	tvStruct.item.cchTextMax = strDriveName.GetLength();
	tvStruct.item.pszText = (LPSTR)(LPCTSTR)strDriveName;
	tvStruct.item.mask = TVIF_TEXT|TVIF_IMAGE|TVIF_SELECTEDIMAGE;

	return	treeCtrl.InsertItem(&tvStruct);
}

HTREEITEM CLeftView::InsertFolder(CString strFolderName, HTREEITEM hParentItem)
{
	CTreeCtrl&	treeCtrl = GetTreeCtrl();

	TV_INSERTSTRUCT	tvStruct;

	tvStruct.hParent = hParentItem;
	tvStruct.hInsertAfter = TVI_SORT;
	tvStruct.item.iImage = 2;
	tvStruct.item.iSelectedImage = 3;
	tvStruct.item.cchTextMax = strFolderName.GetLength();
	tvStruct.item.pszText = (LPSTR)(LPCTSTR)strFolderName;
	tvStruct.item.mask = TVIF_TEXT|TVIF_IMAGE|TVIF_SELECTEDIMAGE;

	return	treeCtrl.InsertItem(&tvStruct);
}

CString CLeftView::GetFullPathName(HTREEITEM hItem)
{
	CString		strParentName;
	CString		strFullName;
	CTreeCtrl&	treeCtrl = GetTreeCtrl();

	strFullName = treeCtrl.GetItemText(hItem) + '\\';

	while((hItem = treeCtrl.GetParentItem(hItem)) != NULL)
	{
		strParentName = treeCtrl.GetItemText(hItem);
		strFullName = strParentName + '\\' + strFullName;
	}

	return	strFullName;
}

void CLeftView::DeleteChildItems(HTREEITEM hItem)
{
	CTreeCtrl&	treeCtrl = GetTreeCtrl();

	if (treeCtrl.ItemHasChildren(hItem) == FALSE)
		return;

	HTREEITEM	hNextItem;

	hItem = treeCtrl.GetChildItem(hItem);

	while((hNextItem = treeCtrl.GetNextSiblingItem(hItem)) != NULL)
	{
		treeCtrl.DeleteItem(hItem);
		hItem = hNextItem;
	}
	treeCtrl.DeleteItem(hItem);
}

BOOL CLeftView::IsDiskDrive(HTREEITEM hTreeItem)
{
	CTreeCtrl&	treeCtrl = GetTreeCtrl();

	hTreeItem = treeCtrl.GetParentItem(hTreeItem);

	if (hTreeItem == NULL)
		return	TRUE;
	else
		return	FALSE;
}

void CLeftView::ViewContextMenu(int nSubIndex, CPoint point)
{
	CMenu		menu;
	CMenu*		pSubMenu;

	menu.LoadMenu(IDR_CONTEXTMENU);

	pSubMenu = menu.GetSubMenu(nSubIndex);
	pSubMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
}

CString CLeftView::GetNewFolderName(HTREEITEM hTreeItem)
{
	CFileStatus		fs;
	int				nIndex = 0;
	BOOL			bFlag = TRUE;
	CString			strPathName, strTemp;
	CString			strFolderName = "새 폴더";
	
	strPathName = GetFullPathName(hTreeItem);

	while(bFlag)
	{
		strTemp = strPathName + strFolderName;

		// 같은 이름의 파일이 존재하면
		if (CFile::GetStatus(strTemp, fs))
		{
			strFolderName = "새 폴더";
			strTemp.Format("-%d", ++nIndex);
			strTemp = strFolderName + strTemp;
			strFolderName = strTemp;
		}
		else
		{
			bFlag = FALSE;
		}
	}

	return	strFolderName;
}

void CLeftView::CopyFilesToFolder(CString strFolderName)
{
	CObList*	pFileList;
	LIST_VIEW*	pListView;
	CString		strMessage, strTargetFile, strFileName;

	// 파일 복사중에 모래시계 커서로 바꾼다.
	CWaitCursor	waitCursor;

	pFileList = GetDocument()->GetCopyFileList();

	for(POSITION pos = pFileList->GetHeadPosition() ; pos != NULL ; )
	{
		pListView = (LIST_VIEW*)pFileList->GetNext(pos);

		strFileName = pListView->strName;
		strTargetFile = strFolderName + strFileName;

		if (::CopyFile(pListView->strPath, strTargetFile, TRUE) == FALSE)
		{
			DWORD		dwError = ::GetLastError();

			strMessage.Format("이 폴더에 이미 '%s' 파일이 있습니다.\n파일을 바꾸시겠습니까?", strFileName);
			if (MessageBox(strMessage, "파일 바꾸기 확인", MB_ICONQUESTION | MB_YESNO) == IDYES)
			{
				if (::CopyFile(pListView->strPath, strTargetFile, FALSE) == FALSE)
				{
					dwError = ::GetLastError();
					strMessage.Format("'%s' 파일을 복사하는데 실패하였습니다.", strFileName);
					MessageBox(strMessage, "파일 복사", MB_ICONSTOP);
				}
			}
		}
	}
}

BOOL CLeftView::DeleteDirectory(CString strFolderName, HTREEITEM hTreeItem)
{
	CFileFind		ff;
	CString			strDirectory = strFolderName;
	CStringArray	strFileArray;

	if (strFolderName.Right(1) != '\\')
	{
		strFolderName += '\\';
	}

	strFolderName += "*.*";

	if (ff.FindFile(strFolderName) == TRUE)
	{
		CString		strFileName;
		BOOL		bFlag = TRUE;

		while(bFlag == TRUE)
		{
			bFlag = ff.FindNextFile();
			strFileName = ff.GetFilePath();

			if (ff.IsDots())
			{
				continue;
			}

			if (ff.IsDirectory())
			{
				DeleteDirectory(strFileName, NULL);
				if (::RemoveDirectory(strFileName) == FALSE)
				{
					MessageBox("폴더를 삭제할 수가 없습니다.", "폴더 삭제", MB_ICONSTOP);
					return	FALSE;
				}
			}
			else
			{
				if (::DeleteFile(strFileName) == FALSE)
				{
					if (GetDocument()->DeleteReadOnlyFile(strFileName) == FALSE)
					{
						MessageBox("파일을 삭제할 수가 없습니다.", "파일 삭제", MB_ICONSTOP);
						return	FALSE;
					}
				}
			}
		}
	}
	ff.Close();

	if (hTreeItem != NULL)
	{
		CTreeCtrl&	treeCtrl = GetTreeCtrl();
		treeCtrl.DeleteItem(hTreeItem);
	}

	return	TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CLeftView message handlers

int CLeftView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	// style 을 설정한다.
	lpCreateStruct->style |= TVS_HASLINES | TVS_LINESATROOT
					| TVS_HASBUTTONS | TVS_EDITLABELS;

	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	CTreeCtrl&	treeCtrl = GetTreeCtrl();
	// drag & drop 을 할 수 있도록 설정해 놓는다.
	//LONG	exStyle = ::GetWindowLong(treeCtrl.m_hWnd, GWL_EXSTYLE);
	//exStyle |= WS_EX_ACCEPTFILES;
	//::SetWindowLong(treeCtrl.m_hWnd, GWL_EXSTYLE, exStyle);
	GetTreeCtrl().ModifyStyleEx(0, WS_EX_ACCEPTFILES);

	m_dropTarget.Register(this);
	m_cbFormat = (CLIPFORMAT)::RegisterClipboardFormat(FORMAT_FILECOPY);

	// 폴더 이미지를 초기화 시킨다.
	CBitmap		bitmap;
	bitmap.LoadBitmap(IDB_SHELL);

	m_imageList.Create(16, 16, ILC_COLOR8, 1, 1);
	m_imageList.Add(&bitmap, RGB(255, 0, 255));

	treeCtrl.SetImageList(&m_imageList, TVSIL_NORMAL);

	return 0;
}

void CLeftView::OnItemexpanding(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	if (pNMTreeView->action != TVE_EXPAND)
	{
		*pResult = 0;
		return;
	}

	HTREEITEM		hItem = pNMTreeView->itemNew.hItem;
	HTREEITEM		hChild;
	CString			strFullName;
	CStringArray	strFolderList;
	CTreeCtrl&		treeCtrl = GetTreeCtrl();

	strFullName = GetFullPathName(hItem);
	GetDocument()->GetChildFolders(&strFolderList, strFullName);

	DeleteChildItems(hItem);	// 모든 차일드 아이템들을 지운다.

	for(int i = 0 ; i < strFolderList.GetSize() ; i++)
	{
		hChild = InsertFolder(strFolderList.GetAt(i), hItem);
		InsertFolder('0', hChild);	// 임의의 폴더를 넣어 놓는다.
	}

	*pResult = 0;
}

void CLeftView::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	HTREEITEM	hItem = pNMTreeView->itemNew.hItem;

	GetDocument()->SelectTreeViewFolder(GetFullPathName(hItem));

	*pResult = 0;
}

void CLeftView::OnDragLeave() 
{
	// TODO: Add your specialized code here and/or call the base class
	CTreeCtrl&	treeCtrl = GetTreeCtrl();

	// 원래의 focus로 돌려놓는다.
	treeCtrl.SelectDropTarget(0);
	treeCtrl.SelectItem(treeCtrl.GetSelectedItem());

	CTreeView::OnDragLeave();
}

DROPEFFECT CLeftView::OnDragOver(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (!pDataObject->IsDataAvailable(m_cbFormat))
	{
		return	DROPEFFECT_NONE;
	}

	CTreeCtrl& treeCtrl = GetTreeCtrl();

	UINT	flags;
	HTREEITEM hHit, hDrop, hSelect;

	hHit = treeCtrl.HitTest(point, &flags);
	hDrop = treeCtrl.GetDropHilightItem();
	hSelect	= treeCtrl.GetSelectedItem();

	if( flags & TVHT_NOWHERE )
	{
		treeCtrl.SelectDropTarget(0);
		treeCtrl.SelectItem(hSelect);
		return DROPEFFECT_NONE;
	}
	else
	{
		treeCtrl.EnsureVisible(treeCtrl.GetPrevVisibleItem(hDrop));
		treeCtrl.EnsureVisible(treeCtrl.GetNextVisibleItem(hDrop));
		treeCtrl.SelectDropTarget(hHit);

		return	DROPEFFECT_COPY;
	}
}

BOOL CLeftView::OnDrop(COleDataObject* pDataObject, DROPEFFECT dropEffect, CPoint point) 
{
	// TODO: Add your specialized code here and/or call the base class
	CString				strFolderName;
	HTREEITEM			hTargetFolder;
	CTreeCtrl&			treeCtrl = GetTreeCtrl();
	CExplorerTestDoc*	pDoc = GetDocument();

	hTargetFolder = treeCtrl.GetDropHilightItem();
	strFolderName = GetFullPathName(hTargetFolder);

	if (dropEffect == DROPEFFECT_COPY)
	{
		HGLOBAL		globalMem;
		CSharedFile	sharedFile;

		globalMem = pDataObject->GetGlobalData(m_cbFormat);
		sharedFile.SetHandle(globalMem, FALSE);

		CArchive	ar(&sharedFile, CArchive::load);

		GetDocument()->SerializeCopyFiles(ar);
		ar.Close();

		CopyFilesToFolder(strFolderName);
	}

	// 원래의 focus로 돌려놓는다.
	treeCtrl.SelectDropTarget(0);
	treeCtrl.SelectItem(treeCtrl.GetSelectedItem());

	return	TRUE;
}

void CLeftView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_bRButtonDown = TRUE;
	m_ptRButton = point;

	CTreeView::OnRButtonDown(nFlags, point);
}

void CLeftView::OnCaptureChanged(CWnd *pWnd) 
{
	// TODO: Add your message handler code here
	if (m_bRButtonDown == TRUE)
	{
		UINT		uFlags;
		HTREEITEM	hTreeItem;
		CString		strFolder;
		CTreeCtrl&	treeCtrl = GetTreeCtrl();

		m_bRButtonDown = FALSE;
		hTreeItem = treeCtrl.HitTest(m_ptRButton, &uFlags);

		if (hTreeItem == NULL)
		{
			CTreeView::OnCaptureChanged(pWnd);
			return;
		}

		strFolder = treeCtrl.GetItemText(hTreeItem);

		if (strFolder.IsEmpty())
		{
			CTreeView::OnCaptureChanged(pWnd);
			return;
		}

		m_hContextItem = hTreeItem;
		ClientToScreen(&m_ptRButton);

		ViewContextMenu(2, m_ptRButton);
	}

	m_bRButtonDown = FALSE;

	CTreeView::OnCaptureChanged(pWnd);
}

void CLeftView::OnFileRename() 
{
	// TODO: Add your command handler code here
	CTreeCtrl&	treeCtrl = GetTreeCtrl();
	HTREEITEM	hTreeItem = m_hContextItem;

	treeCtrl.EditLabel(hTreeItem);
}

void CLeftView::OnBeginlabeledit(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;
	// TODO: Add your control notification handler code here
	HTREEITEM	hTreeItem = pTVDispInfo->item.hItem;

	// 디스크 드라이브이면
	if (IsDiskDrive(hTreeItem))
	{
		*pResult = 1;	// 이름 바꾸기를 중단한다.
		return;
	}

	*pResult = 0;
}

void CLeftView::OnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;
	// TODO: Add your control notification handler code here
	// 프로그램이 종료되는 경우
	if (((CMainFrame*)::AfxGetMainWnd())->IsProgramExit() == TRUE)
	{
		*pResult = 0;
		return;
	}

	CString		strOldFolder, strNewFolder;
	HTREEITEM	hTreeItem;
	CTreeCtrl&	treeCtrl = GetTreeCtrl();
	CEdit*		pEdit = treeCtrl.GetEditControl();

	hTreeItem = pTVDispInfo->item.hItem;
	strOldFolder = treeCtrl.GetItemText(hTreeItem);
	pEdit->GetWindowText(strNewFolder);	// 변경된 파일 이름을 가져온다.

	// 파일 이름이 바뀌지 않았으면
	if (strNewFolder == strOldFolder)
	{
		*pResult = 0;
		return;
	}

	// 파일 이름이 없으면
	if (strNewFolder.IsEmpty())
	{
		MessageBox("파일 이름을 입력해야 합니다.", "이름 바꾸기", MB_ICONSTOP);
		treeCtrl.EditLabel(hTreeItem);
		*pResult = 0;
		return;
	}

	CFileStatus		fs;
	CString			strOldPath, strNewPath;
	
	strOldPath = GetFullPathName(hTreeItem);

	if (strOldPath.Right(1) == '\\')
		strOldPath = strOldPath.Left(strOldPath.GetLength() - 1);

	strNewPath = strOldPath.Left(strOldPath.GetLength() - strOldFolder.GetLength());
	strNewPath += strNewFolder;

	// 같은 이름의 파일이 존재하면
	if (CFile::GetStatus(strNewPath, fs))
	{
		CString		str = strOldFolder + "의 이름을 바꿀수 없습니다.\n"
			+ "지정한 이름을 가진 파일이 이미 있습니다.\n"
			+ "다른 파일 이름을 지정하십시오.";
		MessageBox(str, "파일 이름 바꾸기 오류", MB_ICONSTOP);
		treeCtrl.EditLabel(hTreeItem);
		*pResult = 0;
		return;
	}

	// 새로이 바뀐 폴더로 Rename 시킨다.
	rename(strOldPath, strNewPath);	// 폴더를 실제로 바꾼다.
	treeCtrl.SetItemText(hTreeItem, strNewFolder);

	*pResult = 0;
}

void CLeftView::OnFolderNew() 
{
	// TODO: Add your command handler code here
	CString		strFolderName, strFullName;
	HTREEITEM	hTreeItem, hChildItem;
	CTreeCtrl&	treeCtrl = GetTreeCtrl();
	
	hTreeItem = m_hContextItem;
	strFolderName += GetNewFolderName(hTreeItem);
	strFullName = GetFullPathName(hTreeItem) + strFolderName;

	if (::CreateDirectory(strFullName, NULL) == FALSE)
	{
		MessageBox("폴더 만들기에 실패하였습니다.", "폴더 만들기", MB_ICONSTOP);
		return;
	}

	hChildItem = InsertFolder(strFolderName, hTreeItem);

	treeCtrl.Expand(hTreeItem, TVE_EXPAND);
	treeCtrl.EditLabel(hChildItem);
}

void CLeftView::OnFileDelete() 
{
	// TODO: Add your command handler code here
	CString		strFullPathName;
	HTREEITEM	hTreeItem;
	CTreeCtrl&	treeCtrl = GetTreeCtrl();
	
	hTreeItem = m_hContextItem;
	strFullPathName = GetFullPathName(hTreeItem);
	if (strFullPathName.Right(1) == '\\')
		strFullPathName = strFullPathName.Left(strFullPathName.GetLength() - 1);

	DeleteDirectory(strFullPathName, hTreeItem);
	if (::RemoveDirectory(strFullPathName) == FALSE)
	{
		MessageBox("폴더를 삭제할 수가 없습니다.", "폴더 삭제", MB_ICONSTOP);
	}
}
