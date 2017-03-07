#pragma once
//ƒoƒgƒ‹‚ÌŠÔŠÇ—
class CTime
{
private:
	int m_CountDownTime;
	int m_BattleTime;
	int m_Timing;
	bool m_EndFlag;
public:
	void InitTime();
	void EndBattle();
	void UpdateTime();
	void EndFlagON();
	bool GetEndFlag();
	int GetTiming();
	int GetBattleTime();
	int GetCountDownTime();
};