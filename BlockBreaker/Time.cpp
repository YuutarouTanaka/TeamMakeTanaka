#include "Battle.h"
#include "Time.h"
void CTime::InitTime()
{
	m_Timing = CountDown;
	m_CountDownTime=180;
	m_BattleTime = 5940;
	m_EndFlag = false;
}
void CTime::EndBattle()
{
	m_Timing = Result;
}
void CTime::UpdateTime()
{
	if (m_EndFlag==false)
	{
		switch (m_Timing)
		{
		case CountDown:
			m_CountDownTime--;
			break;
		case Battle:
			m_BattleTime--;
			break;
		}
	}
	if (m_CountDownTime == 0)
	{
		m_Timing = Battle;
	}
   if (m_BattleTime==0&&m_CountDownTime==0)
	{
		m_Timing = Result;
	}
}
void CTime::EndFlagON()
{
	m_EndFlag = true;
	m_Timing = Result;
}
bool CTime::GetEndFlag()
{
	return m_EndFlag;
}
int CTime::GetTiming()
{
	return m_Timing;
}
int CTime::GetBattleTime()
{
	return 	m_BattleTime;
}
int CTime::GetCountDownTime()
{
	return 	m_CountDownTime;
}