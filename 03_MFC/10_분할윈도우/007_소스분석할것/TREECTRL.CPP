// MyTreeCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "Enroll.h"
#include "TreeCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyTreeCtrl

CMyTreeCtrl::CMyTreeCtrl()
{
	m_bDragging = FALSE;
}

CMyTreeCtrl::~CMyTreeCtrl()
{
}


BEGIN_MESSAGE_MAP(CMyTreeCtrl, CTreeCtrl)
	//{{AFX_MSG_MAP(CMyTreeCtrl)
	ON_NOTIFY_REFLECT(TVN_ENDLABELEDIT, OnEndlabeledit)
	ON_NOTIFY_REFLECT(TVN_BEGINDRAG, OnBegindrag)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyTreeCtrl message handlers
HTREEITEM CMyTreeCtrl::AddItem(HTREEITEM hParent, LPSTR szText, 
							   HTREEITEM hInsAfter, int image, int selImage)
{
	HTREEITEM hItem;
	TV_ITEM tvItem;
	TV_INSERTSTRUCT tvstruct;

	tvItem.mask = TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM;
	tvItem.pszText = szText;
	tvItem.cchTextMax = lstrlen(szText);
	tvItem.iImage = image;
	tvItem.iSelectedImage = selImage;
	
	tvstruct.item = tvItem;
	tvstruct.hInsertAfter = hInsAfter;
	tvstruct.hParent = hParent;

	hItem = InsertItem(&tvstruct);
	return hItem;
}

void CMyTreeCtrl::SetNewStyle(long lStyleMask, BOOL bSetBits)
{
	long lStyleOld;

	lStyleOld = GetWindowLong(m_hWnd, GWL_STYLE);
	lStyleOld &= ~lStyleMask;
	if (bSetBits)
		lStyleOld |= lStyleMask;

	SetWindowLong(m_hWnd, GWL_STYLE, lStyleOld);
	SetWindowPos(NULL, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER);
}

BOOL CMyTreeCtrl::IsChildNodeOf(HTREEITEM hItemChild, HTREEITEM hItemParent)
{
	do {
		if(hItemChild == hItemParent)
			break;
	} while((hItemChild = GetParentItem(hItemChild)) != NULL);
	return (hItemChild != NULL);
}

BOOL CMyTreeCtrl::TransferItem(HTREEITEM hItemDrag, HTREEITEM hItemDrop)
{
	TV_INSERTSTRUCT tvstruct;
	TCHAR szBuffer[50];
	HTREEITEM hNewItem, hFirstChild;

	// 무한 재귀적 호출을 피하기 위한 코드
	tvstruct.item.hItem = hItemDrag;
	tvstruct.item.cchTextMax = 49;
	tvstruct.item.pszText = szBuffer;
	tvstruct.item.mask = TVIF_CHILDREN|TVIF_HANDLE|TVIF_IMAGE|
						 TVIF_SELECTEDIMAGE|TVIF_TEXT;
	// ---
	GetItem(&tvstruct.item);
	tvstruct.hParent = hItemDrop;
	tvstruct.hInsertAfter = TVI_SORT;
	tvstruct.item.mask = TVIF_IMAGE|TVIF_SELECTEDIMAGE|TVIF_TEXT;
	hNewItem = InsertItem(&tvstruct);
	while((hFirstChild = GetChildItem(hItemDrag)) != NULL) {
		TransferItem(hFirstChild, hNewItem);
		DeleteItem(hFirstChild);
	}
	return TRUE;
}

void CMyTreeCtrl::OnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;
	// TODO: Add your control notification handler code here
	if (pTVDispInfo->item.pszText != NULL)
	{
		pTVDispInfo->item.mask = TVIF_TEXT;
		SetItem(&pTVDispInfo->item);
	}
	
	*pResult = 0;
}

void CMyTreeCtrl::OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	CPoint pt;
	UINT nFlags;

	GetCursorPos(&pt);
	ScreenToClient(&pt);
	ASSERT(!m_bDragging);
	m_bDragging =  TRUE;
	m_hItemDrag = HitTest(pt, &nFlags);
	m_hItemDrop = NULL;
	m_pDragImage = CreateDragImage(m_hItemDrag);
	m_pDragImage->DragShowNolock(TRUE);
	m_pDragImage->SetDragCursorImage(0, CPoint(0,0));
	m_pDragImage->BeginDrag(0, CPoint(0,0));
	m_pDragImage->DragMove(pt);
	m_pDragImage->DragEnter(this, pt);
	SetCapture();
	
	*pResult = 0;
}

void CMyTreeCtrl::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	HTREEITEM hItem;
	UINT nFlag;

	if(m_bDragging) {
		m_pDragImage->DragMove(point);
		if((hItem = HitTest(point, &nFlag)) != NULL) {
			m_pDragImage->DragLeave(this);
			SelectDropTarget(hItem);
			m_hItemDrop = hItem;
			m_pDragImage->DragEnter(this, point);
		}
	}
	
	CTreeCtrl::OnMouseMove(nFlags, point);
}

void CMyTreeCtrl::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bDragging) {
		m_pDragImage->DragLeave(this);
		m_pDragImage->EndDrag();
		if(m_hItemDrag != m_hItemDrop &&
		   !IsChildNodeOf(m_hItemDrop, m_hItemDrag) &&
		   GetParentItem(m_hItemDrag) != m_hItemDrop) {
			TransferItem(m_hItemDrag, m_hItemDrop);
			DeleteItem(m_hItemDrag);
		}
		else
			MessageBeep(0);
		ReleaseCapture();
		m_bDragging = FALSE;
		SelectDropTarget(NULL);
	}
	
	CTreeCtrl::OnLButtonUp(nFlags, point);
}
