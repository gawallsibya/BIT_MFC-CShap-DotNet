// CntrItem.h : interface of the CExplorerTestCntrItem class
//

#if !defined(AFX_CNTRITEM_H__4798FD71_3B8A_11D2_A360_D86A33074DD9__INCLUDED_)
#define AFX_CNTRITEM_H__4798FD71_3B8A_11D2_A360_D86A33074DD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CExplorerTestDoc;
class CExplorerTestView;

class CExplorerTestCntrItem : public COleClientItem
{
	DECLARE_SERIAL(CExplorerTestCntrItem)

// Constructors
public:
	CExplorerTestCntrItem(CExplorerTestDoc* pContainer = NULL);
		// Note: pContainer is allowed to be NULL to enable IMPLEMENT_SERIALIZE.
		//  IMPLEMENT_SERIALIZE requires the class have a constructor with
		//  zero arguments.  Normally, OLE items are constructed with a
		//  non-NULL document pointer.

// Attributes
public:
	CExplorerTestDoc* GetDocument()
		{ return (CExplorerTestDoc*)COleClientItem::GetDocument(); }
	CExplorerTestView* GetActiveView()
		{ return (CExplorerTestView*)COleClientItem::GetActiveView(); }

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExplorerTestCntrItem)
	public:
	virtual void OnChange(OLE_NOTIFICATION wNotification, DWORD dwParam);
	virtual void OnActivate();
	protected:
	virtual void OnGetItemPosition(CRect& rPosition);
	virtual void OnDeactivateUI(BOOL bUndoable);
	virtual BOOL OnChangeItemPosition(const CRect& rectPos);
	//}}AFX_VIRTUAL

// Implementation
public:
	~CExplorerTestCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void Serialize(CArchive& ar);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CNTRITEM_H__4798FD71_3B8A_11D2_A360_D86A33074DD9__INCLUDED_)
