// Cal.cpp : Implementation of CCal
#include "stdafx.h"
#include "AddMyCalCom.h"
#include "Cal.h"

/////////////////////////////////////////////////////////////////////////////
// CCal


STDMETHODIMP CCal::Add(int first, int second)
{
	// TODO: Add your implementation code here
	m_result = first + second;
	BSTR str = ::SysAllocString(L"TEST ¹®ÀÚ¿­");

	CProxy_ICalEvent<CCal>::Fire_ResultNumber(m_result);
	CProxyICalEvent<CCal>::Fire_ResltNumber(m_result);
	CProxyICalEvent<CCal>::Fire_Test(str);
	CProxy_ICalEvent<CCal>::Fire_Test(str);

	return S_OK;
}

STDMETHODIMP CCal::get_Result(int *pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_result;
	return S_OK;
}

STDMETHODIMP CCal::put_Result(int newVal)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CCal::StringTest(BSTR str)
{
	// TODO: Add your implementation code here
	CProxyICalEvent<CCal>::Fire_Test(str);
	CProxy_ICalEvent<CCal>::Fire_Test(str);

	return S_OK;
}
