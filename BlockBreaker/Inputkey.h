#pragma once
#include "InputDevice.h"
#include <map>

//�Q�[���p�b�h�֘A

#include <Xinput.h>
#pragma comment (lib,"xinput.lib")

//�L�[�̎��
enum KEYKIND {
	ENTER,
	LEFT,
	RIGHT,
	UP,
	DOWN,
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	O,
	P,
	R,
	S,
	T,
	M,
	N,
	U,
	W,
	X,
	Y,
	Z,
	KEYMAX
};
//�L�[���̓N���X
class InputKey
{
private:
	//�L�[���͕⏕�̂��߂̃}�b�v�R���e�i
	std::map<int, int>KEYS;
	//���̓f�o�C�X�̃|�C���^
	LPDIRECTINPUTDEVICE8 m_pDIDevice;
	//�L�[��Ԃ̊Ǘ�
	INPUT_STATE Key[KEYMAX];
	//������Ă��邩
	int PreKey[KEYMAX];
	//��Ԋm�F�̂��ߕK�v�ȃr�b�g
	byte m_diks[256];
public:
	//�L�[���̓N���X�̃R���X�g���N�^
	InputKey(LPDIRECTINPUTDEVICE8);
	//�L�[���̓N���X�̃f�X�g���N�^
	~InputKey();
	//�L�[���̍X�V
	void KeyUpdate();
	//�L�[�̏�Ԋm�F
	void CheckState(BYTE* DIK,KEYKIND st);
	//�L�[�̏��`�F�b�N
	INPUT_STATE CheckKey(KEYKIND st);
};
//�Q�[���p�b�h�֘A
class GamePad
{
private:
#define MAX_CONTROLLERS 2	//�󂯕t����R���g���[���[�̍ő�l

	static const int XINPUT_KEY[];

	static const int XINPUT_KEY_LIST[];		// XInput�̃L�[���X�g
	static const int XINPUT_KEY_MAX;		// XInput�̃L�[�̍ő吔
	static const float INPUT_DEADZONE;		// �X�e�B�b�N���͂��󂯕t���Ȃ��̈�

	struct CONTROLER_STATE
	{
		XINPUT_STATE state;
		bool bConnected;
	};
	CONTROLER_STATE m_Controllers[MAX_CONTROLLERS];

	DWORD					GamePadState[2];		//�X�V���ɉ����Ă���ON
	int						GamePadAction[2][21];	//�����Ď���X�V����܂�ON
	

public:
	bool padCheck[2];
	enum KEY_STATE{
		KEY_RELEASE,
		KEY_PUSH,
		KEY_OFF,
		KEY_ON,
	};
	enum GamePadButton {
		GamePadBtn_UP,
		GamePadBtn_DOWN,
		GamePadBtn_LEFT,
		GamePadBtn_RIGHT,
		GamePadBtn_START,
		GamePadBtn_BACK,
		GamePadBtn_L3,
		GamePadBtn_R3,
		GamePadBtn_LB,
		GamePadBtn_RB,
		GamePadBtn_A,
		GamePadBtn_B,
		GamePadBtn_X,
		GamePadBtn_Y,
		GamePadLStick_UP,
		GamePadLStick_DOWN,
		GamePadLStick_LEFT,
		GamePadLStick_RIGHT,
	};
	void UpdateControllerState();
	int ChkGamePadAction(int playerNumber, int btn) { return GamePadAction[playerNumber][btn]; }
	bool ChkPadConect(int playerNumber){ return m_Controllers[playerNumber].bConnected; }
	void cheackPad();
};
