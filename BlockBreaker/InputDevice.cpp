#include "main.h"
#include "InputDevice.h"
#include "GraphicsDevice.h"
InputDevice::InputDevice(HWND _hWnd)
{
	hInst = (HINSTANCE)GetWindowLong(_hWnd, GWL_HINSTANCE);
	 DirectInput8Create(
		hInst,
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(VOID**)&pDinput,
		NULL);
     pDinput->CreateDevice(
		GUID_SysKeyboard,
		&m_pDIDevice,
		NULL);
	m_pDIDevice->SetDataFormat(&c_dfDIKeyboard);

	m_pDIDevice->SetCooperativeLevel(
		_hWnd,
		DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
	if (m_pDIDevice) m_pDIDevice->Acquire();
}

LPDIRECTINPUTDEVICE8 InputDevice::GetInputDevice()
{
	return m_pDIDevice;
}