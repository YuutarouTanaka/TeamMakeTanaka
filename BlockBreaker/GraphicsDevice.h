#pragma once
#include "main.h"
//グラフィック関係のデバイス管理クラス
class GraphicsDevice
{
private:
	IDirect3D9* m_pDirect3D;
	IDirect3DDevice9*  m_pD3Device;
	D3DDISPLAYMODE	   m_d3ddm;
	D3DPRESENT_PARAMETERS    m_d3dpp;
public:
	GraphicsDevice(HWND _hWnd, HINSTANCE _hIns);
	~GraphicsDevice(){ m_pDirect3D->Release(); m_pD3Device->Release(); };
	IDirect3DDevice9* Get_pD3Device(){ return m_pD3Device;};
};