#include "stdafx.h"
#include "ElementsProc.h"
#include "resource.h"
#include "PropertySheetPageDlg.h"

CElementsProc::CElementsProc(void)
{
}


CElementsProc::~CElementsProc(void)
{
}



void CElementsProc::OnButtonFreeData(void* clientDate)
{
	FS_WideString fsButtonData = (FS_WideString)clientDate;
	FS_LPCWSTR str = FSWideStringCastToLPCWSTR(fsButtonData);
	FSWideStringDestroy(fsButtonData);
}

//Event occurs when user select "SelectQR"
void CElementsProc::OnButtonExecuteProc(void* clientDate)
{

	FS_WideString fsButtonData = (FS_WideString)clientDate;	
	FR_Tool frTool = FRAppGetToolByName(FR_NAME_SNAPSHOT);
	if (frTool != NULL) {
		FRAppSetActiveTool(frTool, false);
	}
	else {
		FRSysShowMessageBox((FS_LPCWSTR)L"Tool not found!", MB_OK | MB_ICONINFORMATION, NULL, NULL, FRAppGetMainFrameWnd());
	}

	///FRDocViewGetCurrentSnapshot
}


unsigned char* Bitmap2BMP(unsigned char* bitmap, int width, int height, long* len)
{
	int i = 0;
	int j = 0;
	int pitch = width * 3;
	int stride24 = width * 3;
	int stride32 = width * 4;
	if (bitmap == NULL || height == 0 || width == 0)
	{
		return NULL;
	}
	if (pitch % 4 != 0)
	{
		stride24 += 4 - pitch % 4;
	}

	unsigned char* bmpbuf = (unsigned char*)malloc(stride24 * height + 54);
	unsigned char *header = bmpbuf;

	if (NULL == bmpbuf)

		return NULL;

	// write BMP header

	unsigned short bftype;

	unsigned long  bfsize;

	unsigned short bfreserved1;

	unsigned short bfreserved2;

	unsigned long  bfoffbits;


	unsigned long  bisize;

	unsigned long  biwidth;

	unsigned long  biheight;

	unsigned short biplanes;

	unsigned short bibitcount;

	unsigned long  bicompression;

	unsigned long  bisizeimage;

	unsigned long  bixpelspermeter;

	unsigned long  biypelspermeter;

	unsigned long  biclrused;

	unsigned long  biclrimportant;


	bftype = 0x4d42;

	bfsize = stride24 * height + 54;
	bfreserved1 = 0;

	bfreserved2 = 0;

	bfoffbits = 54;


	bisize = 40;

	biwidth = width;

	biheight = height;

	biplanes = 1;

	bibitcount = 24;

	bicompression = 0;

	bisizeimage = stride24 * height;

	bixpelspermeter = 0;

	biypelspermeter = 0;

	biclrused = 0;

	biclrimportant = 0;


	memcpy(bmpbuf, &bftype, 2);
	bmpbuf += 2;

	memcpy(bmpbuf, &bfsize, 4);
	bmpbuf += 4;

	memcpy(bmpbuf, &bfreserved1, 2);
	bmpbuf += 2;

	memcpy(bmpbuf, &bfreserved2, 2);
	bmpbuf += 2;

	memcpy(bmpbuf, &bfoffbits, 4);
	bmpbuf += 4;


	memcpy(bmpbuf, &bisize, 4);
	bmpbuf += 4;

	memcpy(bmpbuf, &biwidth, 4);
	bmpbuf += 4;

	memcpy(bmpbuf, &biheight, 4);
	bmpbuf += 4;

	memcpy(bmpbuf, &biplanes, 2);
	bmpbuf += 2;

	memcpy(bmpbuf, &bibitcount, 2);
	bmpbuf += 2;

	memcpy(bmpbuf, &bicompression, 4);
	bmpbuf += 4;

	memcpy(bmpbuf, &bisizeimage, 4);
	bmpbuf += 4;

	memcpy(bmpbuf, &bixpelspermeter, 4);
	bmpbuf += 4;

	memcpy(bmpbuf, &biypelspermeter, 4);
	bmpbuf += 4;

	memcpy(bmpbuf, &biclrused, 4);
	bmpbuf += 4;

	memcpy(bmpbuf, &biclrimportant, 4);
	bmpbuf += 4;

	//trans

	for (i = height - 1; i >= 0; i--)
	{
		for (j = 0; j < width; j++)
		{
			bmpbuf[(height - 1 - i)*stride24 + j * 3] = bitmap[i*stride32 + j * 4];
			bmpbuf[(height - 1 - i)*stride24 + j * 3 + 1] = bitmap[i*stride32 + j * 4 + 1];
			bmpbuf[(height - 1 - i)*stride24 + j * 3 + 2] = bitmap[i*stride32 + j * 4 + 2];
		}
	}

	*len = stride24 * height + 54;
	return header;
}

//Event occurs when user select "ShowQRInfo"
void CElementsProc::OnQRGetInfoButtonProc(void* clientDate)
{

	FS_WideString fsButtonData = (FS_WideString)clientDate;
	FR_Document frDocument = FRAppGetActiveDocOfPDDoc();
	FR_DocView docView = FRDocGetCurrentDocView(frDocument);

	FS_DIBitmap bitmap = FRDocViewGetCurrentSnapshot(docView);
	if (bitmap != NULL) {
		//void* pBuf = FS_Bitmap_GetBuffer(dib);
		FS_LPBYTE pBuf= FSDIBitmapGetBuffer(bitmap);
		//get length of bitmap buffer
		FS_INT32 nDIBWidth =FSDIBitmapGetHeight(bitmap);
		FS_INT32 nDIBHeight = FSDIBitmapGetWidth(bitmap);
		//start to output buffer to a bmp
		long len;
		//create the head of a bmp file
		unsigned char* pData = Bitmap2BMP((unsigned char*)pBuf, nDIBHeight, nDIBWidth, &len);
		//open file
		FILE* pFile = fopen("./test.bmp", "wb");
		//write the data of bitmap
		fwrite((void*)pData, sizeof(char), len, pFile);
		//close file
		fclose(pFile);
	}
	//ToDo:  reader the test.bmp into a QRCode Reader and get the text output of the QR Code and display the message to the user.
	FRSysShowMessageBox((FS_LPCWSTR)L"This part of the code needs work.", MB_OK | MB_ICONINFORMATION, NULL, NULL, FRAppGetMainFrameWnd());
}
FS_BOOL CElementsProc::OnButtonMarkedProc(void* clientDate)
{
	return FALSE;
}
FS_BOOL CElementsProc::OnButtonEnableProc(void* clientDate)
{
	return TRUE;
}

HWND CElementsProc::FRRibbonBackstageCreateProc(HWND hParentWnd, void* clientData)
{
	PropertySheetPageDlg *pPage = new PropertySheetPageDlg();
	if (pPage)
	{
		BOOL bCreate = pPage->Create(IDD_DLG_PROPERTYSHEETPAGE, CWnd::FromHandle(hParentWnd));
		if (bCreate)
		{
			return pPage->GetSafeHwnd();
		}
	}	
	return NULL;

}

void CElementsProc::FRRibbonBackstageDestoryProc(void* pDialog, void* clientData)
{
	PropertySheetPageDlg* pPage = (PropertySheetPageDlg*)clientData;
	if (NULL != pPage)
	{
		delete pPage;
		pPage = NULL;
	}
}