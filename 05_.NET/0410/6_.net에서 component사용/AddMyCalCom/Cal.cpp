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
