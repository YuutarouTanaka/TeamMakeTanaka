#include "main.h"
//�E�B���h�E�쐬�̃N���X
class WindowCreate
{
public:
	//�R���X�g���N�^
		WindowCreate(HINSTANCE h_Ins, WNDPROC WPC);
	//�f�X�g���N�^
	~WindowCreate(){};
	//�E�B���h�E�n���h�E�擾
	HWND GethWnd();
private:
	//�E�B���h�E�N���X�̃����o
	WNDCLASS m_winc;
	//�E�B���h�E�n���h���̃����o
	HWND m_hWnd;
};