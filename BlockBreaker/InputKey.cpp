#include "Inputkey.h"
InputKey::InputKey(LPDIRECTINPUTDEVICE8 device)
{
	m_pDIDevice = device;
	KEYS[ENTER] = DIK_RETURN;
	KEYS[LEFT] =  DIK_LEFT;
	KEYS[RIGHT] = DIK_RIGHT;
	KEYS[UP] =    DIK_UP;
	KEYS[DOWN] =  DIK_DOWN;
	KEYS[A] = DIK_A;
	KEYS[B] = DIK_B;
	KEYS[C] = DIK_C;
	KEYS[D] = DIK_D;
	KEYS[E] = DIK_E;
	KEYS[F] = DIK_F;
	KEYS[G] = DIK_G;
	KEYS[H] = DIK_H;
	KEYS[I] = DIK_I;
	KEYS[J] = DIK_J;
	KEYS[K] = DIK_K;
	KEYS[L] = DIK_L;
	KEYS[O] = DIK_O;
	KEYS[P] = DIK_P;
	KEYS[N] = DIK_N;
	KEYS[M] = DIK_M;
	KEYS[R] = DIK_R;
	KEYS[S] = DIK_S;
	KEYS[T] = DIK_T;
	KEYS[U] = DIK_U;
	KEYS[W] = DIK_W;
	KEYS[X] = DIK_X;
	KEYS[Y] = DIK_Y;
	KEYS[Z] = DIK_Z;
}
InputKey::~InputKey()
{
	m_pDIDevice->Release();
}
INPUT_STATE InputKey::CheckKey(KEYKIND st)
{
	CheckState(&m_diks[KEYS.at(st)], st);
	return Key[st];
}
void InputKey::CheckState(BYTE* diks, KEYKIND st)
{

	if ((*diks) & 0x80) {
		if (PreKey[st] == 0) {
			Key[st] = PUSH;
		}
		else {
			Key[st] = ON;
		}
		PreKey[st] = 1;
	}
	else {
		if (PreKey[st] == 0) {
			Key[st] = OFF;
		}
		else {
			Key[st] = RELEASE;
		}
		PreKey[st] = 0;
	}
}
void InputKey::KeyUpdate()
{
	m_pDIDevice->GetDeviceState(256, m_diks);
	m_pDIDevice->Acquire();
}
//�Q�[���p�b�h�֘A
const int GamePad::XINPUT_KEY_LIST[] = {
	XINPUT_GAMEPAD_DPAD_UP,
	XINPUT_GAMEPAD_DPAD_DOWN,
	XINPUT_GAMEPAD_DPAD_LEFT,
	XINPUT_GAMEPAD_DPAD_RIGHT,
	XINPUT_GAMEPAD_START,
	XINPUT_GAMEPAD_BACK,
	XINPUT_GAMEPAD_LEFT_THUMB,
	XINPUT_GAMEPAD_RIGHT_THUMB,
	XINPUT_GAMEPAD_LEFT_SHOULDER,
	XINPUT_GAMEPAD_RIGHT_SHOULDER,
	XINPUT_GAMEPAD_A,
	XINPUT_GAMEPAD_B,
	XINPUT_GAMEPAD_X,
	XINPUT_GAMEPAD_Y,
};

const int GamePad::XINPUT_KEY_MAX = sizeof(XINPUT_KEY_LIST) / sizeof(int);

const float GamePad::INPUT_DEADZONE = (0.24f * FLOAT(0x7FFF));

void GamePad::UpdateControllerState()
{
	DWORD dwResult;
	for (DWORD i = 0; i < MAX_CONTROLLERS; i++)
	{
		// Simply get the state of the controller from XInput.
		dwResult = XInputGetState(i, &m_Controllers[i].state);

		if (dwResult == ERROR_SUCCESS)
			m_Controllers[i].bConnected = true;
		else
			m_Controllers[i].bConnected = false;

		// �Ȃ����ĂȂ��Ƃ��̓`�F�b�N���Ȃ�
		if (!m_Controllers[i].bConnected) continue;

		// �X�e�B�b�N�̏�Ԃ��擾(�����̈��OFF,�L���̈��ON)
		// ��
		bool stick = m_Controllers[i].state.Gamepad.sThumbLX < -INPUT_DEADZONE;

		if (stick && ((GamePadState[i] & 0x10000) != 0)) {
			GamePadAction[i][GamePadLStick_LEFT] = KEY_ON;
		}
		if (stick && ((GamePadState[i] & 0x10000) == 0)) GamePadAction[i][GamePadLStick_LEFT] = KEY_PUSH;
		if (!stick && ((GamePadState[i] & 0x10000) == 0)) GamePadAction[i][GamePadLStick_LEFT] = KEY_OFF;
		if (!stick && ((GamePadState[i] & 0x10000) != 0)) GamePadAction[i][GamePadLStick_LEFT] = KEY_RELEASE;

		// �O��̃L�[�̏�ԂƂ��ĕۑ�
		if (stick)	GamePadState[i] |= 0x10000;
		else		GamePadState[i] &= ~0x10000;

		// �E
		stick = m_Controllers[i].state.Gamepad.sThumbLX > INPUT_DEADZONE;
		if (stick && ((GamePadState[i] & 0x20000) != 0))	{
			GamePadAction[i][GamePadLStick_RIGHT] = KEY_ON;
		}
		if (stick && ((GamePadState[i] & 0x20000) == 0))  GamePadAction[i][GamePadLStick_RIGHT] = KEY_PUSH;
		if (!stick && ((GamePadState[i] & 0x20000) == 0)) GamePadAction[i][GamePadLStick_RIGHT] = KEY_OFF;
		if (!stick && ((GamePadState[i] & 0x20000) != 0)) GamePadAction[i][GamePadLStick_RIGHT] = KEY_RELEASE;

		// �O��̃L�[�̏�ԂƂ��ĕۑ�
		if (stick) GamePadState[i] |= 0x20000;
		else		GamePadState[i] &= ~0x20000;

		// ��
		stick = m_Controllers[i].state.Gamepad.sThumbLY > INPUT_DEADZONE;

		if (stick && ((GamePadState[i] & 0x40000) != 0)) GamePadAction[i][GamePadLStick_UP] = KEY_ON;
		if (stick && ((GamePadState[i] & 0x40000) == 0)) GamePadAction[i][GamePadLStick_UP] = KEY_PUSH;
		if (!stick && ((GamePadState[i] & 0x40000) == 0)) GamePadAction[i][GamePadLStick_UP] = KEY_OFF;
		if (!stick && ((GamePadState[i] & 0x40000) != 0)) GamePadAction[i][GamePadLStick_UP] = KEY_RELEASE;

		// �O��̃L�[�̏�ԂƂ��ĕۑ�
		if (stick)	GamePadState[i] |= 0x40000;
		else		GamePadState[i] &= ~0x40000;

		// ��
		stick = m_Controllers[i].state.Gamepad.sThumbLY < -INPUT_DEADZONE;
		if (stick && ((GamePadState[i] & 0x80000) != 0))	GamePadAction[i][GamePadLStick_DOWN] = KEY_ON;
		if (stick && ((GamePadState[i] & 0x80000) == 0))  GamePadAction[i][GamePadLStick_DOWN] = KEY_PUSH;
		if (!stick && ((GamePadState[i] & 0x80000) == 0)) GamePadAction[i][GamePadLStick_DOWN] = KEY_OFF;
		if (!stick && ((GamePadState[i] & 0x80000) != 0)) GamePadAction[i][GamePadLStick_DOWN] = KEY_RELEASE;

		// �O��̃L�[�̏�ԂƂ��ĕۑ�
		if (stick) GamePadState[i] |= 0x80000;
		else		GamePadState[i] &= ~0x80000;

		for (int j = 0; j < MAX_CONTROLLERS; j++){
			// �e�L�[�̏�Ԃ��擾
			for (int i = 0; i < XINPUT_KEY_MAX; i++) {
				// �{�^���̏�Ԃ��`�F�b�N
				bool now = (m_Controllers[j].state.Gamepad.wButtons & XINPUT_KEY_LIST[i]) != 0;

				// �O�񉟂���Ăč��񉟂���Ă�Ƃ�
				if (now && ((GamePadState[j] & XINPUT_KEY_LIST[i]) != 0)) {
					GamePadAction[j][i] = KEY_ON;
				}
				// �O�񉟂���ĂȂ��č��񉟂���Ă�Ƃ�
				if (now && ((GamePadState[j] & XINPUT_KEY_LIST[i]) == 0)) {
					GamePadAction[j][i] = KEY_PUSH;
				}
				// �O�񉟂���ĂȂ��č��񉟂���Ă��Ȃ��Ƃ�
				if (!now && ((GamePadState[j] & XINPUT_KEY_LIST[i]) == 0)) {
					GamePadAction[j][i] = KEY_OFF;
				}
				// �O�񉟂���Ă��č��񉟂���Ă��Ȃ���
				if (!now && ((GamePadState[j] & XINPUT_KEY_LIST[i]) != 0)) {
					GamePadAction[j][i] = KEY_RELEASE;
				}

				// �O��̃L�[�̏�ԂƂ��ĕۑ�
				if (now) GamePadState[j] |= XINPUT_KEY_LIST[i];
				else	  GamePadState[j] &= ~XINPUT_KEY_LIST[i];
			}
		}

	}
}
void GamePad::cheackPad()
{
	for (int i = 0; i < 2; i++)
	{
		if (ChkPadConect(i)) padCheck[i] = TRUE;
		else
		{
			padCheck[i] = FALSE;
		}
	}
}