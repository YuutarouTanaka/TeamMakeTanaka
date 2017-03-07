#include "EndFlag.h"
#include "Block.h"
#include "Time.h" 
#include "Ball.h"
void CEndFlag::InitEndFlag()
{
	EndFlag = false;
	judgement = none;
}
void CEndFlag::CheakEnd(Block pplayer1block[],Block pplayer2block[],
	CTime* time,Ball* Player1ball,Ball* Player2ball)
{
	if (time->GetTiming()== Result)
	{
		Player1ball->StopBall();
		Player2ball->StopBall();
		time->EndFlagON();
		int CountDeletePlayer1Block = 0;
		int CountDeletePlayer2Block = 0;

		for (int i = 0; i < 36; i++)
		{
			if (pplayer1block[i].GetBlockUse()==false)
			{
				CountDeletePlayer1Block++;
			}
			if (pplayer2block[i].GetBlockUse() == false)
			{
				CountDeletePlayer2Block++;
			}
		}
		if (CountDeletePlayer1Block>CountDeletePlayer2Block)
		{
			judgement = Player1win;
		}
		if (CountDeletePlayer1Block<CountDeletePlayer2Block)
		{
			judgement = Player2win;
		}
		if (CountDeletePlayer1Block == CountDeletePlayer2Block)
		{
			judgement = Draw;
		}
	}
	bool Player1winflag = false;
	bool Player2winflag = false;
	for (int i = 0; i < BLOCK_MAX; i++)
	{
		
		if (pplayer1block[i].GetBlockUse() == true)
		{
			Player2winflag = true;
		}
		if (pplayer2block[i].GetBlockUse() == true)
		{
			Player1winflag = true;
		}

	}
	if (Player1winflag == true && Player2winflag == false)
	{
		Player1ball->StopBall();
		Player2ball->StopBall();
		time->EndFlagON();
		judgement = Player1win;
	}
	else if (Player1winflag == false && Player2winflag == true)
	{
		Player1ball->StopBall();
		Player2ball->StopBall();
		time->EndFlagON();
		judgement = Player2win;
	}
	else if (Player1winflag == false && Player2winflag == false)
	{
		Player1ball->StopBall();
		Player2ball->StopBall();
		time->EndFlagON();
		judgement = Draw;
	}

	
}
int CEndFlag::Getjudgement()
{
	return judgement;
}
bool CEndFlag::GetEndFlag()
{
	return EndFlag;
}