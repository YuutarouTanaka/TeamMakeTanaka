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
	//左方向が押されたとき
	bool isLeft();
	//右方向が押されたとき
	bool isRight();
	//上方向が押されたとき
	bool isUp();
	//下方向が押されたとき
	bool isDown();
	//決定キーが押されたとき
	bool isSelect();
	//プレイヤー1の上方向が押されたとき
	bool isPlayer1Up();
	//プレイヤー1の下方向が押されたとき
	bool isPlayer1Down();
	//プレイヤー1の左方向が押されたとき
	bool isPlayer1Left();
	//プレイヤー1の右方向が押されたとき
	bool isPlayer1Right();
	//プレイヤー1の決定キーが押されたとき
	bool isPlayer1Select();
	//プレイヤー2の上方向が押されたとき
	bool isPlayer2Up();
	//プレイヤー2の下方向が押されたとき
	bool isPlayer2Down();
	//プレイヤー2の左方向が押されたとき
	bool isPlayer2Left();
	//プレイヤー2の右方向が押されたとき
	bool isPlayer2Right();
	//プレイヤー2no決定キーが押されたとき
	bool isPlayer2Select();
};