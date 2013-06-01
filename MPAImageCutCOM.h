

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Tue May 14 16:51:20 2013
 */
/* Compiler settings for .\MPAImageCutCOM.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
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

#ifndef __MPAImageCutCOM_h__
#define __MPAImageCutCOM_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMPAImageCut_FWD_DEFINED__
#define __IMPAImageCut_FWD_DEFINED__
typedef interface IMPAImageCut IMPAImageCut;
#endif 	/* __IMPAImageCut_FWD_DEFINED__ */


#ifndef __MPAImageCut_FWD_DEFINED__
#define __MPAImageCut_FWD_DEFINED__

#ifdef __cplusplus
typedef class MPAImageCut MPAImageCut;
#else
typedef struct MPAImageCut MPAImageCut;
#endif /* __cplusplus */

#endif 	/* __MPAImageCut_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IMPAImageCut_INTERFACE_DEFINED__
#define __IMPAImageCut_INTERFACE_DEFINED__

/* interface IMPAImageCut */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMPAImageCut;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("709011EE-41DC-4BFB-9143-5DC17CFB220C")
    IMPAImageCut : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Create( 
            /* [in] */ BSTR bsImage,
            /* [in] */ BSTR bsFaceTag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFaceCount( 
            /* [out] */ LONG *lCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetImage( 
            /* [in] */ LONG lIndex,
            /* [out] */ CHAR **pImg,
            /* [out] */ LONG *lSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMPAImageCutVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMPAImageCut * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMPAImageCut * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMPAImageCut * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMPAImageCut * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMPAImageCut * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMPAImageCut * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMPAImageCut * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Create )( 
            IMPAImageCut * This,
            /* [in] */ BSTR bsImage,
            /* [in] */ BSTR bsFaceTag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFaceCount )( 
            IMPAImageCut * This,
            /* [out] */ LONG *lCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetImage )( 
            IMPAImageCut * This,
            /* [in] */ LONG lIndex,
            /* [out] */ CHAR **pImg,
            /* [out] */ LONG *lSize);
        
        END_INTERFACE
    } IMPAImageCutVtbl;

    interface IMPAImageCut
    {
        CONST_VTBL struct IMPAImageCutVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMPAImageCut_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMPAImageCut_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMPAImageCut_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMPAImageCut_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IMPAImageCut_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IMPAImageCut_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IMPAImageCut_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IMPAImageCut_Create(This,bsImage,bsFaceTag)	\
    (This)->lpVtbl -> Create(This,bsImage,bsFaceTag)

#define IMPAImageCut_GetFaceCount(This,lCount)	\
    (This)->lpVtbl -> GetFaceCount(This,lCount)

#define IMPAImageCut_GetImage(This,lIndex,pImg,lSize)	\
    (This)->lpVtbl -> GetImage(This,lIndex,pImg,lSize)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMPAImageCut_Create_Proxy( 
    IMPAImageCut * This,
    /* [in] */ BSTR bsImage,
    /* [in] */ BSTR bsFaceTag);


void __RPC_STUB IMPAImageCut_Create_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMPAImageCut_GetFaceCount_Proxy( 
    IMPAImageCut * This,
    /* [out] */ LONG *lCount);


void __RPC_STUB IMPAImageCut_GetFaceCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMPAImageCut_GetImage_Proxy( 
    IMPAImageCut * This,
    /* [in] */ LONG lIndex,
    /* [out] */ CHAR **pImg,
    /* [out] */ LONG *lSize);


void __RPC_STUB IMPAImageCut_GetImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMPAImageCut_INTERFACE_DEFINED__ */



#ifndef __MPAImageCutCOMLib_LIBRARY_DEFINED__
#define __MPAImageCutCOMLib_LIBRARY_DEFINED__

/* library MPAImageCutCOMLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_MPAImageCutCOMLib;

EXTERN_C const CLSID CLSID_MPAImageCut;

#ifdef __cplusplus

class DECLSPEC_UUID("9CDCA6F4-A37D-4651-92B1-DE639DE2830E")
MPAImageCut;
#endif
#endif /* __MPAImageCutCOMLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


