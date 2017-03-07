#pragma once
#include "Block.h"
#include "Time.h"
#include "Ball.h"
enum judgement
{
	none,
	Player1win,
	Player2win,
	Draw

};
class CEndFlag
{
private:
	bool EndFlag;
	int judgement;
public:
	void InitEndFlag();
	void CheakEnd(Block player[], Block enemy[],CTime* Time
		, Ball* Player1, Ball* Player2);
	bool GetEndFlag();
	int Getjudgement();
};