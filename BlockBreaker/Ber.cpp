#include "Ber.h" 
#include "Battle.h"
void Ber::InitPlayer1Ber(float posx, float posy)
{
	PosX = posx;
	PosY = posy;
	BerColider[TOP_LEFT].x = posx - (BER_WITDH/2);
	BerColider[TOP_LEFT].y = posy - (BER_HEIGHT / 2);
	BerColider[TOP_RIGHT].x = posx + (BER_WITDH / 2);
	BerColider[TOP_RIGHT].y = posy - (BER_HEIGHT / 2);
	BerColider[BOTTOM_RIGHT].x = posx + (BER_WITDH / 2);
	BerColider[BOTTOM_RIGHT].y = posy +(BER_HEIGHT/2);
	BerColider[BOTTOM_LEFT].x = posx - (BER_WITDH / 2);
	BerColider[BOTTOM_LEFT].y = posy + (BER_HEIGHT / 2);
}
void Ber::InitPlayer2Ber(float posx, float posy)
{
	PosX = posx;
	PosY = posy;

	BerColider[TOP_LEFT].x = (posx - (BER_WITDH / 2))+PLAYER2_X_GAP;
	BerColider[TOP_LEFT].y = posy - (BER_HEIGHT / 2);
	BerColider[TOP_RIGHT].x = posx + ((BER_WITDH / 2)+PLAYER2_X_GAP);
	BerColider[TOP_RIGHT].y = posy - (BER_HEIGHT / 2);
	BerColider[BOTTOM_RIGHT].x = posx + ((BER_WITDH / 2)+PLAYER2_X_GAP);
	BerColider[BOTTOM_RIGHT].y = posy + (BER_HEIGHT / 2);
	BerColider[BOTTOM_LEFT].x = (posx - (BER_WITDH / 2))+PLAYER2_X_GAP;
	BerColider[BOTTOM_LEFT].y = posy + (BER_HEIGHT / 2);
}
void Ber::moveBerRight(bool isPoison)
{
	for (int i = 0; i < 4; i++)
	{
		BerColider[i].x = PosX;
	}
	isPoison == true ? PosX += (MOVE_BER)/2.0f : PosX += (MOVE_BER);
}
void Ber::moveBerLeft(bool isPoison)
{
	for (int i = 0; i < 4; i++)
	{
		BerColider[i].x = PosX;
	}
	isPoison == true ? PosX -= (MOVE_BER)/2.0f : PosX -= (MOVE_BER);
}
float Ber::GetPosX()
{
	return PosX;
}
float Ber::GetPosY()
{
	return PosY;
}