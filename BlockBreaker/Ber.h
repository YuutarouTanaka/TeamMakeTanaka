#pragma once
#include "Battle.h"
#define BER_WITDH 150.0f
#define BER_HEIGHT 30.0f
class Ber
{
public:
	float PosX;
	float PosY;
	Colider BerColider[4];
	void InitPlayer1Ber(float posx, float posy);
	void InitPlayer2Ber(float posx, float posy);
	void moveBerRight(bool);
	void moveBerLeft(bool);
	float GetPosX();
	float GetPosY();
};
