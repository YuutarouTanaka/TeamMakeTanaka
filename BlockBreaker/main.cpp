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
	case WM_DESTROY:														   //�E�C���h�E������ꂽ���Ƃ�
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wp, lp);
}
int WINAPI WinMain                                                             //c�Ō����Ƃ��̃��C��
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
	DWORD SyncOld = timeGetTime();											   //�V�X�e�����Ԃ��擾
	DWORD SyncNow;
	LordGraph(&RenderIns);
	LordVertex(&RenderIns);
	timeBeginPeriod(1);                                                        //�}�C�N���b�̕�����ݒ�@#pragma comment(lib, "winmm.lib")�v
	ZeroMemory(&msg, sizeof(msg));											   //������������
	while (msg.message != WM_QUIT)
	{

		Sleep(1);															   //���x��
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))						   //���b�Z�[�W�̎󂯎��
		{
			TranslateMessage(&msg);											   //���b�Z�[�W�̕ϊ�
			DispatchMessage(&msg);											   
		}
		else
		{
			SyncNow = timeGetTime();
			if (SyncNow - SyncOld >= 1000 / 60)
			{   
				//60�t���[��
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
	timeEndPeriod(1);														   //�}�C�N���b�̕�����ݒ�@#pragma comment(lib, "winmm.lib")���K�v   

	return (int)msg.wParam;													   //�Ȃɂ���

}