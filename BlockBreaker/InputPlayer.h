#include "InputDevice.h"
#include "Inputkey.h"
class InputPlayer
{
	InputKey* inputKey;
	GamePad* gamePad;
	InputPlayer(LPDIRECTINPUTDEVICE8 device)
	{
		inputKey=new InputKey(device);
		gamePad = new GamePad;
	}
	~InputPlayer()
	{
		delete inputKey;
		delete gamePad;
	}
public:
	//�������������ꂽ�Ƃ�
	bool isLeft();
	//�E�����������ꂽ�Ƃ�
	bool isRight();
	//������������ꂽ�Ƃ�
	bool isUp();
	//�������������ꂽ�Ƃ�
	bool isDown();
	//����L�[�������ꂽ�Ƃ�
	bool isSelect();
	//�v���C���[1�̏�����������ꂽ�Ƃ�
	bool isPlayer1Up();
	//�v���C���[1�̉������������ꂽ�Ƃ�
	bool isPlayer1Down();
	//�v���C���[1�̍������������ꂽ�Ƃ�
	bool isPlayer1Left();
	//�v���C���[1�̉E�����������ꂽ�Ƃ�
	bool isPlayer1Right();
	//�v���C���[1�̌���L�[�������ꂽ�Ƃ�
	bool isPlayer1Select();
	//�v���C���[2�̏�����������ꂽ�Ƃ�
	bool isPlayer2Up();
	//�v���C���[2�̉������������ꂽ�Ƃ�
	bool isPlayer2Down();
	//�v���C���[2�̍������������ꂽ�Ƃ�
	bool isPlayer2Left();
	//�v���C���[2�̉E�����������ꂽ�Ƃ�
	bool isPlayer2Right();
	//�v���C���[2no����L�[�������ꂽ�Ƃ�
	bool isPlayer2Select();
};