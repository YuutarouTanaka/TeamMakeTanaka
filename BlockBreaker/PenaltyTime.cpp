#include "Battle.h"
#include "PenaltyTime.h"
void CPenaltyTime::InitPenaltyTime()
{
	m_playerPenaltyTime = 0;
	FailBall = false;
}
void CPenaltyTime::CheckBall(Ball* pBall,int player)
{
	if (player == 1)
	{
		if (pBall->GetPosY() > SCREEN_HEIGHT || pBall->GetPosY() < 0 || pBall->GetPosX() > 1280.0f || pBall->GetPosX() <0.0f)
		{
			FailBall = true;
			m_playerPenaltyTime = 180;
			pBall->InitPlayerBall(START_X_PLAYER1_BALL, START_Y_PLAYER_BALL, 90.0f, pBall);
		}
	}
	if (player == 2)
	{
		if (pBall->GetPosY() > SCREEN_HEIGHT || pBall->GetPosY() < 0 || pBall->GetPosX() > 1280.0f || pBall->GetPosX() <0.0f)
		{
			FailBall = true;
			m_playerPenaltyTime = 180;
			pBall->InitPlayerBall(START_X_PLAYER2_BALL, START_Y_PLAYER_BALL, 90.0f, pBall);
		}
	}
}
void CPenaltyTime::UpdatePenaltyTime(Ball* pBall)
{
	if (m_playerPenaltyTime > 0)
	{
		m_playerPenaltyTime--;
	}
	if ((m_playerPenaltyTime == 0)&&(FailBall==true))
	{
		pBall->StartBall();
		FailBall = false;
	}
}
int CPenaltyTime::GetPenaltyTime()
{
	return m_playerPenaltyTime;
}
bool CPenaltyTime::CheckFlag()
{
	return FailBall;
}