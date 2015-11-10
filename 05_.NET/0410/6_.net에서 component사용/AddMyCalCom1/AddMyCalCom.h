/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue Oct 26 11:05:31 2010
 */
/* Compiler settings for C:\Documents and Settings\Administrator\바탕 화면\07_.net에서 component사용\AddMyCalCom\AddMyCalCom.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __AddMyCalCom_h__
#define __AddMyCalCom_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ICal_FWD_DEFINED__
#define __ICal_FWD_DEFINED__
typedef interface ICal ICal;
#endif 	/* __ICal_FWD_DEFINED__ */


#ifndef __ICalEvent_FWD_DEFINED__
#define __ICalEvent_FWD_DEFINED__
typedef interface ICalEvent ICalEvent;
#endif 	/* __ICalEvent_FWD_DEFINED__ */


#ifndef ___ICalEvent_FWD_DEFINED__
#define ___ICalEvent_FWD_DEFINED__
typedef interface _ICalEvent _ICalEvent;
#endif 	/* ___ICalEvent_FWD_DEFINED__ */


#ifndef __Cal_FWD_DEFINED__
#define __Cal_FWD_DEFINED__

#ifdef __cplusplus
typedef class Cal Cal;
#else
typedef struct Cal Cal;
#endif /* __cplusplus */

#endif 	/* __Cal_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __ICal_INTERFACE_DEFINED__
#define __ICal_INTERFACE_DEFINED__

/* interface ICal */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICal;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5BBBB248-1758-4D73-9233-DEA81E132491")
    ICal : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ int first,
            /* [in] */ int second) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Result( 
            /* [retval][out] */ int __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Result( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StringTest( 
            BSTR str) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICalVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ICal __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ICal __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ICal __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ICal __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ICal __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ICal __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ICal __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            ICal __RPC_FAR * This,
            /* [in] */ int first,
            /* [in] */ int second);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Result )( 
            ICal __RPC_FAR * This,
            /* [retval][out] */ int __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Result )( 
            ICal __RPC_FAR * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StringTest )( 
            ICal __RPC_FAR * This,
            BSTR str);
        
        END_INTERFACE
    } ICalVtbl;

    interface ICal
    {
        CONST_VTBL struct ICalVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICal_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICal_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICal_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICal_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICal_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICal_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICal_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICal_Add(This,first,second)	\
    (This)->lpVtbl -> Add(This,first,second)

#define ICal_get_Result(This,pVal)	\
    (This)->lpVtbl -> get_Result(This,pVal)

#define ICal_put_Result(This,newVal)	\
    (This)->lpVtbl -> put_Result(This,newVal)

#define ICal_StringTest(This,str)	\
    (This)->lpVtbl -> StringTest(This,str)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICal_Add_Proxy( 
    ICal __RPC_FAR * This,
    /* [in] */ int first,
    /* [in] */ int second);


void __RPC_STUB ICal_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICal_get_Result_Proxy( 
    ICal __RPC_FAR * This,
    /* [retval][out] */ int __RPC_FAR *pVal);


void __RPC_STUB ICal_get_Result_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ICal_put_Result_Proxy( 
    ICal __RPC_FAR * This,
    /* [in] */ int newVal);


void __RPC_STUB ICal_put_Result_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICal_StringTest_Proxy( 
    ICal __RPC_FAR * This,
    BSTR str);


void __RPC_STUB ICal_StringTest_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICal_INTERFACE_DEFINED__ */


#ifndef __ICalEvent_INTERFACE_DEFINED__
#define __ICalEvent_INTERFACE_DEFINED__

/* interface ICalEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICalEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("723BC6C1-8EC3-49ad-97E6-5446CE23AE19")
    ICalEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResltNumber( 
            int num) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Test( 
            BSTR str) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICalEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ICalEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ICalEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ICalEvent __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ICalEvent __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ICalEvent __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ICalEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ICalEvent __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ResltNumber )( 
            ICalEvent __RPC_FAR * This,
            int num);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Test )( 
            ICalEvent __RPC_FAR * This,
            BSTR str);
        
        END_INTERFACE
    } ICalEventVtbl;

    interface ICalEvent
    {
        CONST_VTBL struct ICalEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICalEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICalEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICalEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICalEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICalEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICalEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICalEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICalEvent_ResltNumber(This,num)	\
    (This)->lpVtbl -> ResltNumber(This,num)

#define ICalEvent_Test(This,str)	\
    (This)->lpVtbl -> Test(This,str)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICalEvent_ResltNumber_Proxy( 
    ICalEvent __RPC_FAR * This,
    int num);


void __RPC_STUB ICalEvent_ResltNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICalEvent_Test_Proxy( 
    ICalEvent __RPC_FAR * This,
    BSTR str);


void __RPC_STUB ICalEvent_Test_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICalEvent_INTERFACE_DEFINED__ */



#ifndef __ADDMYCALCOMLib_LIBRARY_DEFINED__
#define __ADDMYCALCOMLib_LIBRARY_DEFINED__

/* library ADDMYCALCOMLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ADDMYCALCOMLib;

#ifndef ___ICalEvent_DISPINTERFACE_DEFINED__
#define ___ICalEvent_DISPINTERFACE_DEFINED__

/* dispinterface _ICalEvent */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__ICalEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("7190E1C9-70F3-4493-A491-EB8F869AAA98")
    _ICalEvent : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ICalEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _ICalEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _ICalEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _ICalEvent __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _ICalEvent __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _ICalEvent __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _ICalEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _ICalEvent __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _ICalEventVtbl;

    interface _ICalEvent
    {
        CONST_VTBL struct _ICalEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ICalEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _ICalEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _ICalEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _ICalEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _ICalEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _ICalEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _ICalEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ICalEvent_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Cal;

#ifdef __cplusplus

class DECLSPEC_UUID("63CAE2B0-B4AD-4972-B188-2A644353125C")
Cal;
#endif
#endif /* __ADDMYCALCOMLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
