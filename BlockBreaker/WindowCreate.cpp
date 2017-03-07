#include "WindowCreate.h"
#include "main.h"
//�E�B���h�E�����N���X
WindowCreate::WindowCreate(HINSTANCE h_Ins, WNDPROC WPC)
{
	
	m_winc.style = CS_HREDRAW | CS_VREDRAW;									   //�E�B���h�E�X�^�C�� HREDRAW:�c�T�C�Y���ς������ĕ`��
																			   //�E�B���h�E�X�^�C�� VREDRAW:���T�C�Y���ς������ĕ`��
	m_winc.lpfnWndProc = WPC;									               //�R�[���o�b�N�֐��i�E�B���h�v���V�[�W��WPC�j�ւ̃|�C���^
	m_winc.cbClsExtra = m_winc.cbWndExtra = 0;								   //�E�B���h�N���X�\���̂Ƃ��E�B���h�E�C���X�^���X�̌��Ɋ��蓖�Ă�⑫�o�C�g��
	m_winc.hInstance = h_Ins;     //���̃N���X�̂��߂̃E�B���h�E�v���V�[�W��������C���X�^���h�n���h��
	m_winc.hIcon = LoadIcon(h_Ins,TEXT("ICON")); 
	//�A�C�R���ݒ�@NULL:�V�X�e����`�̃A�C�R�� IDI_APPLICATION:�K��̃A�v���A�C�R��
	m_winc.hCursor = LoadCursor(NULL, IDC_ARROW);                              //�J�[�\���ݒ�  NULL:�V�X�e����`�̃A�C�R�� IDC_ARROW�W���̖��J�[�\��
	m_winc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);                //�E�B���h�E�̔w�i��ݒ�
	m_winc.lpszMenuName = NULL;                                                //�f�t�H���g���j���[�Ȃ񂩓�����Ƃ��ł���
	m_winc.lpszClassName = TEXT("TEST"); //���̃E�B���h�E�N���X�ɂ���
	RegisterClass(&m_winc);
	int dH = GetSystemMetrics(SM_CYCAPTION) + GetSystemMetrics(SM_CYFRAME) * 2;//�c��(�^�C�g���o�[�ƃt���[���Q���̕�)��
	//GetsystemMetrics�ł��Ƃ߂Ă�
	int dW = GetSystemMetrics(SM_CXFRAME);                                 //����(�t���[������̕�)��
	//GetSystemMetrics�ł��Ƃ߂Ă�
	m_hWnd = CreateWindow(                                                     //Createwindow:�E�B���h�E�����֐�
		TEXT("TEST"),                                                          //�E�B�����h�E�N���X�̖��O���w��
		TEXT("BlockBreakers"),														   //�E�B���h�E�̃^�C�g��
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,                                      //VISIBLE:�ŏ��ɐ��������E�B���h�EOVERLAPPEDWINDOW:��������Ő���オ����
		CW_USEDEFAULT,                                                         //�E�B���h�E�̉������̏����ʒux
		CW_USEDEFAULT,                                                         //�E�B���h�E�̏c�����̏����ʒuy
		1280+dW ,                                                              //�g�����킹������
		960+dH ,                                                              //�g�����킹���c��
		NULL,																       //�I�[�i�[�E�B���h�E�̃n���h��
		NULL,															       //�q���E�B���h�E�̂h�c
		h_Ins,															   //�A�v���P�[�V�����C���X�^���X�̃n���h��
		NULL
		);
}

HWND WindowCreate::GethWnd()
{
	return m_hWnd;
}