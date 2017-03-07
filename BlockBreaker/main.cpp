#include "main.h"
#include "Reader.h"
#include "GraphicsDevice.h"
#include "ManageTexturePointer.h"
#include "WindowCreate.h"
#include "ManageRender.h"
#include "InputDevice.h"
#include "Inputkey.h"
#include "ManageScene.h"
#include "LordGraph.h"
#include "LordVertex.h"
LRESULT CALLBACK WPC(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_DESTROY:														   //ウインドウが閉じられた時とか
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wp, lp);
}
int WINAPI WinMain                                                             //cで言うとこのメイン
(HINSTANCE hInstance, HINSTANCE hPrevInstance,
LPSTR lpCmdLine, int nCmdshow)
{
	MSG msg;

	WindowCreate Window(hInstance,WPC);
	GraphicsDevice DEVICE(Window.GethWnd(), hInstance);
	MnageRender RenderIns(DEVICE.Get_pD3Device());
	InputDevice Input(Window.GethWnd());
	InputKey Key(Input.GetInputDevice());
	ManageScene ManagerScene;
	GamePad Pad;
	DWORD SyncOld = timeGetTime();											   //システム時間を取得
	DWORD SyncNow;
	LordGraph(&RenderIns);
	LordVertex(&RenderIns);
	timeBeginPeriod(1);                                                        //マイクロ秒の分解を設定　#pragma comment(lib, "winmm.lib")要
	ZeroMemory(&msg, sizeof(msg));											   //メモリ初期化
	while (msg.message != WM_QUIT)
	{

		Sleep(1);															   //お休み
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))						   //メッセージの受け取り
		{
			TranslateMessage(&msg);											   //メッセージの変換
			DispatchMessage(&msg);											   
		}
		else
		{
			SyncNow = timeGetTime();
			if (SyncNow - SyncOld >= 1000 / 60)
			{   
				//60フレーム
				SyncOld = SyncNow;
				RenderIns.RenderSetup();
				ManagerScene.Colision();
				ManagerScene.Render(&RenderIns);
				ManagerScene.Input(&Key, &ManagerScene, &Pad);
				ManagerScene.Control(&ManagerScene);
				RenderIns.RenderTeardown();
			}
		}
	}
	timeEndPeriod(1);														   //マイクロ秒の分解を設定　#pragma comment(lib, "winmm.lib")が必要   

	return (int)msg.wParam;													   //なにこれ

}