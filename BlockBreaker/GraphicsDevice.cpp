#include "GraphicsDevice.h"
GraphicsDevice::GraphicsDevice(HWND _hWnd, HINSTANCE _hIns)
{
	m_pDirect3D = Direct3DCreate9(D3D_SDK_VERSION);

	m_pDirect3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &m_d3ddm);
	ZeroMemory(&m_d3dpp, sizeof(D3DPRESENT_PARAMETERS));
	m_d3dpp.BackBufferFormat = m_d3ddm.Format;								 //最大色数
	m_d3dpp.BackBufferCount = 1;											 //裏面の数
	m_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;								 //一番効率がいい方法で転送(自動)
	m_d3dpp.Windowed = TRUE;												 //trueうぃんどう
	m_pDirect3D->CreateDevice(												 //デバイス作ります
		D3DADAPTER_DEFAULT,													 //ハードウェアによる処理
		D3DDEVTYPE_HAL,														 //デバイスによるハードウェア処理
		_hWnd,																 //フォーカスを設定するウィンドウハンドル
		D3DCREATE_HARDWARE_VERTEXPROCESSING,								 //ハードウェアによる頂点処理を指定
		&m_d3dpp,															 //デバイスを設定するD3DPRESENT_PARAMETERS構造体へのポインタ
		&m_pD3Device);
}