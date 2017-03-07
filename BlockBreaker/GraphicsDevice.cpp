#include "GraphicsDevice.h"
GraphicsDevice::GraphicsDevice(HWND _hWnd, HINSTANCE _hIns)
{
	m_pDirect3D = Direct3DCreate9(D3D_SDK_VERSION);

	m_pDirect3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &m_d3ddm);
	ZeroMemory(&m_d3dpp, sizeof(D3DPRESENT_PARAMETERS));
	m_d3dpp.BackBufferFormat = m_d3ddm.Format;								 //�ő�F��
	m_d3dpp.BackBufferCount = 1;											 //���ʂ̐�
	m_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;								 //��Ԍ������������@�œ]��(����)
	m_d3dpp.Windowed = TRUE;												 //true������ǂ�
	m_pDirect3D->CreateDevice(												 //�f�o�C�X���܂�
		D3DADAPTER_DEFAULT,													 //�n�[�h�E�F�A�ɂ�鏈��
		D3DDEVTYPE_HAL,														 //�f�o�C�X�ɂ��n�[�h�E�F�A����
		_hWnd,																 //�t�H�[�J�X��ݒ肷��E�B���h�E�n���h��
		D3DCREATE_HARDWARE_VERTEXPROCESSING,								 //�n�[�h�E�F�A�ɂ�钸�_�������w��
		&m_d3dpp,															 //�f�o�C�X��ݒ肷��D3DPRESENT_PARAMETERS�\���̂ւ̃|�C���^
		&m_pD3Device);
}