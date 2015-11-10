// Cal.h : Declaration of the CCal

#ifndef __CAL_H_
#define __CAL_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCal
class ATL_NO_VTABLE CCal : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCal, &CLSID_Cal>,
	public IDispatchImpl<ICal, &IID_ICal, &LIBID_ADDMYCALCOMLib>
{
private:
	int m_result;
public:
	CCal()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CAL)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CCal)
	COM_INTERFACE_ENTRY(ICal)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// ICal
public:
	STDMETHOD(get_Result)(/*[out, retval]*/ int *pVal);
	STDMETHOD(put_Result)(/*[in]*/ int newVal);
	STDMETHOD(Add)(/*[in]*/ int first, /*[in]*/ int second);
};

#endif //__CAL_H_
