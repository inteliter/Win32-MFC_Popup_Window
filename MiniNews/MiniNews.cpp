// MiniNews.cpp : ����Ӧ�ó������ڵ㡣
// Download by http://www.codefans.net

#include "stdafx.h"
#include "MiniNews.h"
#include "NewsWindow.h"

CNewsWindow NewsWindow;
BOOL InitNews();

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{

	if (!InitNews())
		return 0;


	// ����Ϣѭ��:
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}
BOOL InitNews()
{
	//int nScreenWidth, nScreenHeight;
	//nScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	//nScreenHeight = GetSystemMetrics(SM_CYSCREEN);
	//printf("��ǰ��Ļ�ķֱ���Ϊ��%d��%d", nScreenWidth, nScreenHeight);
	//return 0;

	/*LPCTSTR lpNewsTitle		= _T("�������ű���");
	LPCTSTR lpNewsContent	= _T("������������,���ǿƼ���չ���޹�˾(��������)���Ŷ�����վ����������������飬���о���ḻ�Ŀ����Ŷӡ�Ϊ���ṩרҵ����վ���衢��������ȷ���");*/
	LPCTSTR lpNewsTitle = _T("ShotgunTimeLog֪ͨ");
	LPCTSTR lpNewsContent = _T("�����ڸø���ShogunTimelog��~~~~~\n\n����ô��ڣ�ֱ������Timelog���򣡣����һ�μ��ɣ���������Σ�\n\n�����򽫲���ǿ������������\n\n�����ѽ�������½Timelog���Զ��˳�~~~~");
	LPCTSTR lpNewsURL = _T("C:\\ShotgunDesktop\\TimelogAutoRun.bat");
	//LPCTSTR lpNewsURL = _T("www.baidu.com");

	//NewsWindow.SetSkin(MAKEINTRESOURCE(IDB_SKIN_QQ));
	//NewsWindow.SetSkin(MAKEINTRESOURCE(IDB_SKIN_WANGWANG));
	NewsWindow.SetSkin(MAKEINTRESOURCE(IDB_SKIN_XUNLEI),0xFFFFFF);
	if (!NewsWindow.Create(_T("֪ͨ")))
		return FALSE;

	NewsWindow.SetNews(lpNewsTitle, lpNewsContent, lpNewsURL);
	NewsWindow.Show();
	NewsWindow.SetMainWindow();
	//NewsWindow.SetAutoClose(TRUE);
	//NewsWindow.HideTaskbar();
	//NewsWindow.ShowTaskbar();
	//ShowWindow(NewsWindow.m_hWnd, SW_MAXIMIZE);//��� hwnd ������Ĵ���
	return TRUE;
}