#pragma once
#include "Ball.h"
class CPenaltyTime
{
private:
	int m_playerPenaltyTime;
	bool FailBall;
public:
	void InitPenaltyTime();
	void UpdatePenaltyTime(Ball*);
	int  GetPenaltyTime();
	void CheckBall(Ball*,int);
	bool CheckFlag();
};