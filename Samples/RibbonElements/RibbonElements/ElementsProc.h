#pragma once
class CElementsProc
{
public:
	CElementsProc(void);
	~CElementsProc(void);

	static void OnSliderExecuteProc(void* clientData);
	static FS_BOOL OnSliderMarkedProc(void* clientData);
	static FS_BOOL OnSliderEnabledProc(void* clientData);

	static void OnButtonFreeData(void* clientDate);
	static void OnButtonExecuteProc(void* clientDate);
	static void OnQRGetInfoButtonProc(void * clientDate);
	static FS_BOOL OnButtonMarkedProc(void* clientDate);
	static FS_BOOL OnButtonEnableProc(void* clientDate);

	static HWND FRRibbonBackstageCreateProc(HWND hParentWnd, void* clientData);
	static void FRRibbonBackstageDestoryProc(void* pDialog, void* clientData);
	
};

