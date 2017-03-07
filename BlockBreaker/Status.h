#pragma once
#include "Battle.h"
#include "Block.h"
#include "Ber.h"
class Status
{
private:
	int ItemNum;
	int BarrierTime;
	int PoisonTime;
	bool Barrier;
	bool Poison;
	int ItemVolumeCheack;
	bool ItemVolumeflag;
	bool OnceBreakFlag;
public:
	void	UpdateFlagTime();
	void	UpdateItemFlagTime();
	void    UpdateItemFlagSet();
	void	InitStatus();
	void	UseItem(Block Player[],Block Enemy[],Status* Enemeyber);
	void    StackItem(int ItemNum);
	void BarrierFlagOn();
	void PoisonFlagOn(Status* pEnemyStatus);
	int   GetItemNum();
	bool isBarrier();
	bool isPoison();
	void BreakFlagOn();
	void BreakFlagOff();
	bool OnceBreakFlagCheack();
};