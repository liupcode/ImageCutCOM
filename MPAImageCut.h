// MPAImageCut.h : Declaration of the CMPAImageCut

#pragma once
#include "resource.h"       // main symbols

#include "MPAImageCutCOM.h"
#include <vector>

// CMPAImageCut

class ATL_NO_VTABLE CMPAImageCut : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMPAImageCut, &CLSID_MPAImageCut>,
	public IDispatchImpl<IMPAImageCut, &IID_IMPAImageCut, &LIBID_MPAImageCutCOMLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CMPAImageCut()
	{
		//m_trg_bmp = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_MPAIMAGECUT)


BEGIN_COM_MAP(CMPAImageCut)
	COM_INTERFACE_ENTRY(IMPAImageCut)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
		std::vector<image_info>::iterator it = m_image_array.begin();
		for (;it!=m_image_array.end();it++)
		{
			delete it->img_buf_;
		}
	}
private:
	struct pos_rect
	{
		int X;
		int Y;
		int width;
		int height;
	};
	std::vector<pos_rect>		m_rt_array;

	struct image_info
	{
		int		img_size_;
		char*	img_buf_;
	};
	std::vector<image_info>			m_image_array;

	void CutImage(Gdiplus::Bitmap& obj);

public:
	STDMETHOD(GetFaceCount)(LONG* lCount);
	STDMETHOD(Create)(BSTR bsImage,BSTR bsFaceTag);
	STDMETHOD(GetImage)(LONG lIndex, CHAR** pImg, LONG* lSize);
public:
	int test(int t);
};

OBJECT_ENTRY_AUTO(__uuidof(MPAImageCut), CMPAImageCut)
