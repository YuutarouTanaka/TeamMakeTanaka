#pragma once
#include "main.h"
#include "GraphicsDevice.h"
//���͏�
enum INPUT_STATE {
	//�����ꂽ�Ƃ�
	PUSH,
	//�����ꂽ�Ƃ�
	RELEASE,
	//�����Ă���Ƃ�
	ON,
	//������Ă���Ƃ�
	OFF
};
//���̓f�o�C�X
class InputDevice
{
public:
	HINSTANCE hInst;
	LPDIRECTINPUT8 pDinput;
	LPDIRECTINPUTDEVICE8		m_pDIDevice = NULL;
	InputDevice(HWND _hWnd);
	LPDIRECTINPUTDEVICE8 GetInputDevice();
};