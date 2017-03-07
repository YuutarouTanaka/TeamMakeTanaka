#pragma once
#include "main.h"
#include "GraphicsDevice.h"
//入力状況
enum INPUT_STATE {
	//押されたとき
	PUSH,
	//離されたとき
	RELEASE,
	//押しているとき
	ON,
	//離されているとき
	OFF
};
//入力デバイス
class InputDevice
{
public:
	HINSTANCE hInst;
	LPDIRECTINPUT8 pDinput;
	LPDIRECTINPUTDEVICE8		m_pDIDevice = NULL;
	InputDevice(HWND _hWnd);
	LPDIRECTINPUTDEVICE8 GetInputDevice();
};