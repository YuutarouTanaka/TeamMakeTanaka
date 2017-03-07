#pragma once
#include "InputDevice.h"
#include <map>

//ゲームパッド関連

#include <Xinput.h>
#pragma comment (lib,"xinput.lib")

//キーの種類
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
//キー入力クラス
class InputKey
{
private:
	//キー入力補助のためのマップコンテナ
	std::map<int, int>KEYS;
	//入力デバイスのポインタ
	LPDIRECTINPUTDEVICE8 m_pDIDevice;
	//キー状態の管理
	INPUT_STATE Key[KEYMAX];
	//押されているか
	int PreKey[KEYMAX];
	//状態確認のため必要なビット
	byte m_diks[256];
public:
	//キー入力クラスのコンストラクタ
	InputKey(LPDIRECTINPUTDEVICE8);
	//キー入力クラスのデストラクタ
	~InputKey();
	//キー情報の更新
	void KeyUpdate();
	//キーの状態確認
	void CheckState(BYTE* DIK,KEYKIND st);
	//キーの情報チェック
	INPUT_STATE CheckKey(KEYKIND st);
};
//ゲームパッド関連
class GamePad
{
private:
#define MAX_CONTROLLERS 2	//受け付けるコントローラーの最大値

	static const int XINPUT_KEY[];

	static const int XINPUT_KEY_LIST[];		// XInputのキーリスト
	static const int XINPUT_KEY_MAX;		// XInputのキーの最大数
	static const float INPUT_DEADZONE;		// スティック入力を受け付けない領域

	struct CONTROLER_STATE
	{
		XINPUT_STATE state;
		bool bConnected;
	};
	CONTROLER_STATE m_Controllers[MAX_CONTROLLERS];

	DWORD					GamePadState[2];		//更新時に押してたらON
	int						GamePadAction[2][21];	//押して次回更新するまでON
	

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
