#include "CtrListView.h"

CtrListView::CtrListView( HWND _hList ) : hList( _hList ), headUsage(0)
{
	InitCommonControls();
	headList.mask = LVCF_FMT|LVCF_WIDTH|LVCF_TEXT|LVCF_SUBITEM;
	headList.fmt = LVCFMT_LEFT;
	headList.cx = 80;

	item.mask = LVIF_TEXT;
}

CtrListView::~CtrListView(void)
{
}
int CtrListView::GetHeadUsage()const
{
	return headUsage;
}

void CtrListView::AddHead(const char* hName)
{
	headList.pszText = (LPSTR)hName;
	headList.iSubItem = headUsage;
	SendMessage( hList, LVM_INSERTCOLUMN, headUsage,(LPARAM)&headList);
	headUsage++;
}

void CtrListView::ShowListView(int iItem, int subtem, const char* str)
{
	item.iItem = iItem;
	item.iSubItem = subtem;
	item.pszText = (LPSTR)str;

	if( subtem == 0 )
	{
		SendMessage( hList, LVM_INSERTITEM, 0, (LPARAM)&item );
	}
	else
	{
		SendMessage( hList, LVM_SETITEM, 0, (LPARAM)&item );
	}
}

void CtrListView::RmoveAllList()
{
 SendMessage( hList, LVM_DELETEALLITEMS, 0, 0 );
}