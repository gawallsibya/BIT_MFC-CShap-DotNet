/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue Oct 27 13:56:07 2009
 */
/* Compiler settings for C:\Documents and Settings\Administrator\πŸ≈¡ »≠∏È\AddMyCalCom\AddMyCalCom.idl:
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



#endif 	/* __ICal_INTERFACE_DEFINED__ */



#ifndef __ADDMYCALCOMLib_LIBRARY_DEFINED__
#define __ADDMYCALCOMLib_LIBRARY_DEFINED__

/* library ADDMYCALCOMLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ADDMYCALCOMLib;

EXTERN_C const CLSID CLSID_Cal;

#ifdef __cplusplus

class DECLSPEC_UUID("63CAE2B0-B4AD-4972-B188-2A644353125C")
Cal;
#endif
#endif /* __ADDMYCALCOMLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
