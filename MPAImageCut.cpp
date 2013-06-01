// MPAImageCut.cpp : Implementation of CMPAImageCut

#include "stdafx.h"
#include "MPAImageCut.h"
#include ".\mpaimagecut.h"

#include <comutil.h>
#include <string>

#include "json/json.h"

#ifdef _DEBUG
#pragma comment(lib, "libjson_mdd.lib")
#else
#pragma comment(lib, "libjson_md.lib")
#endif
// CMPAImageCut

using namespace std;
static bool stream_to_mem( IStream *stream, void **outbuf, size_t *size )
{
	ULARGE_INTEGER ulnSize;
	LARGE_INTEGER lnOffset;
	lnOffset.QuadPart = 0;
	/* get the stream size */
	if( stream->Seek( lnOffset, STREAM_SEEK_END, &ulnSize ) != S_OK )
	{
		return false;
	}
	if( stream->Seek( lnOffset, STREAM_SEEK_SET, NULL ) != S_OK )
	{
		return false;
	}

	/* read it */
	*outbuf = malloc( (size_t)ulnSize.QuadPart );
	*size = (size_t) ulnSize.QuadPart;
	ULONG bytesRead;
	if( stream->Read( *outbuf, (ULONG)ulnSize.QuadPart, &bytesRead ) != S_OK )
	{
		free( *outbuf );
		return false;
	}

	return true;
}

int GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
	UINT  num = 0;          // number of image encoders
	UINT  size = 0;         // size of the image encoder array in bytes
	ImageCodecInfo* pImageCodecInfo = NULL;
	GetImageEncodersSize(&num, &size);
	if(size == 0)
		return -1;  // Failure
	pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
	if(pImageCodecInfo == NULL)
		return -1;  // Failure
	GetImageEncoders(num, size, pImageCodecInfo);
	for(UINT j = 0; j < num; ++j)
	{
		if( wcscmp(pImageCodecInfo[j].MimeType, format) == 0 )
		{
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;  // Success
		}   
	}
	free(pImageCodecInfo);
	return -1;  // Failure
}

void *mi_to_memory( Gdiplus::Image *image, void **outbuf, size_t *size )
{
	IStream *stream = NULL;
	if( ::CreateStreamOnHGlobal( NULL, TRUE, &stream ) != S_OK )
	{
		return NULL;
	}
	/* get the jpg encoder */
	::CLSID jpgClsid;
	GetEncoderClsid( L"image/jpeg", &jpgClsid );

	/* save the image to stream */
	Gdiplus::Status save_s = image->Save( stream, &jpgClsid );
	if( save_s != Gdiplus::Ok )
	{
		stream->Release();
		return NULL;
	}

	/* read the stream to buffer */
	if( !stream_to_mem( stream, outbuf, size ) )
	{
		stream->Release();
		return NULL;
	}
	return *outbuf;
}

void CMPAImageCut::CutImage(Gdiplus::Bitmap& obj)
{
	std::vector<pos_rect>::iterator it		= m_rt_array.begin();
	std::vector<pos_rect>::iterator it_e	= m_rt_array.end();
	for (int i=0;it!=it_e;it++)
	{
		image_info img;
		size_t len		= 0;
		pos_rect& rt	= *it;

		Gdiplus::Bitmap* trg_bmp	= new Gdiplus::Bitmap(rt.width,rt.height);;
		Gdiplus::Graphics* pMemTrg	= Graphics::FromImage(trg_bmp);
		pMemTrg->DrawImage(&obj,0,0,rt.X,rt.Y,rt.width,rt.height,UnitPixel);
		
		img.img_buf_ = (char*)mi_to_memory(trg_bmp,(void**)&img.img_buf_,&len);
		img.img_size_ = (int)len;

		delete pMemTrg;
		delete trg_bmp;

		m_image_array.push_back(img);
	}
}

STDMETHODIMP CMPAImageCut::GetFaceCount(LONG* lCount)
{
	*lCount = (LONG)m_image_array.size();

	return S_OK;
}

STDMETHODIMP CMPAImageCut::Create(BSTR bsImage,BSTR bsFaceTag)
{
	Json::Value root;   
	Json::Reader reader;
	Json::FastWriter w;

	std::string faceTag = _bstr_t(bsFaceTag);

	bool bRet = reader.parse(faceTag.c_str(), root);
	if (!bRet)
		return E_FAIL;

	int cnt = root.get("result_face_info","").size();
	for(int i=0;i<cnt;i++)
	{
		pos_rect rt;

		rt.X		= root["result_face_info"][i].get("details.Face.Rectangle.X","").asInt();
		rt.Y		= root["result_face_info"][i].get("details.Face.Rectangle.Y","").asInt();
		rt.width	= root["result_face_info"][i].get("details.Face.Rectangle.Width","").asInt();
		rt.height	= root["result_face_info"][i].get("details.Face.Rectangle.Height","").asInt();

		m_rt_array.push_back(rt);
	}
	//
	std::wstring filePath = _bstr_t(bsImage);
	Gdiplus::Bitmap bmp(filePath.c_str());
	//
	CutImage(bmp);

	return S_OK;
}


STDMETHODIMP CMPAImageCut::GetImage(LONG lIndex, CHAR** pImg, LONG* lSize)
{
	// TODO: Add your implementation code here
	if (lIndex >= (LONG)m_image_array.size()||lIndex<0)
		return E_FAIL;
	
	LONG len = m_image_array[lIndex].img_size_;

	*pImg = m_image_array[lIndex].img_buf_;

	*lSize = len;
	
	return S_OK;
}

