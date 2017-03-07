#include "Status.h"
#include "Battle.h"

#include"DirectShowSound.h"
CSound poison_break;
CSound barrier_break;
CSound change_break;
CSound block_break;
CSound lightning_break;
CSound tornado_break;

extern CSound battle_sound;

void Status::InitStatus()
{
	block_break.LoadFile(TEXT("BlockBreakersBGM\\block_break.mp3"));
	lightning_break.LoadFile(TEXT("BlockBreakersBGM\\lightning_break.mp3"));
	tornado_break.LoadFile(TEXT("BlockBreakersBGM\\tornado_break.mp3"));
	poison_break.LoadFile(TEXT("BlockBreakersBGM\\poison_break.mp3"));
	barrier_break.LoadFile(TEXT("BlockBreakersBGM\\barrier_break.mp3"));
	change_break.LoadFile(TEXT("BlockBreakersBGM\\change_break.mp3"));
	ItemNum = 0;
	BarrierTime = 600;
	PoisonTime = 600;
	Barrier = false;
	Poison = false;
	ItemVolumeCheack = 0;
	ItemVolumeflag = false;
	bool OnceBreakFlag=false;
}
void Status::UpdateFlagTime()
{
	if (Barrier == true)
	{
		BarrierTime--;
	}
	if (Poison == true)
	{
		PoisonTime--;
	}

	if (PoisonTime == 0)
	{

		Poison = false;
		PoisonTime = 600;
	}
	if (BarrierTime == 0)
	{
		Barrier = false;
		BarrierTime = 600;
	}
}
void Status::UseItem(Block Player[], Block pEnemy[],Status* pEnemyStatus)
{
	switch (ItemNum)
	{
	case POISON:
		battle_sound.VolChange(-10000);
		UpdateItemFlagSet();
		poison_break.PlayFromStart();
		PoisonFlagOn(pEnemyStatus);
		ItemNum = 0;
		break;
	case BARRIER:
		battle_sound.VolChange(-10000);
		UpdateItemFlagSet();
		barrier_break.PlayFromStart();
		BarrierFlagOn();
		ItemNum = 0;
		break;
	case CHANGE:
		battle_sound.VolChange(-10000);
		UpdateItemFlagSet();
		change_break.PlayFromStart();
		if (pEnemyStatus->isBarrier() == false)
		{
			Block temp[36];
			for (int i = 0; i < 36; i++)
			{
				temp[i].SetType(Player[i].GetBlockType());
				temp[i].SetBlockUse(Player[i].GetBlockUse());
				Player[i].SetType(pEnemy[i].GetBlockType());
				Player[i].SetBlockUse(pEnemy[i].GetBlockUse());
				pEnemy[i].SetType(temp[i].GetBlockType());
				pEnemy[i].SetBlockUse(temp[i].GetBlockUse());
			}
		}
		ItemNum = 0;
		break;
	default:
		break;
	}
}
void Status::BarrierFlagOn()
{
	Barrier = true;
}
void Status::PoisonFlagOn(Status* pEnemyStatus)
{
	if ((pEnemyStatus)->Barrier == false)
	{
		(pEnemyStatus)->Poison = true;
	}
}
void Status::StackItem(int Item)
{
	ItemNum = Item;
}
int Status::GetItemNum()
{
	return ItemNum;
}
bool Status::isPoison()
{
	return Poison;
}
bool Status::isBarrier()
{
	return Barrier;
}
void Status::UpdateItemFlagSet()
{
	ItemVolumeCheack = 100;
	ItemVolumeflag = true;
}
void Status::UpdateItemFlagTime()
{
	if (ItemVolumeCheack > 0)
	{
		battle_sound.VolChange(+100);
		ItemVolumeCheack--;
	}
	if (ItemVolumeCheack == 0 && ItemVolumeflag == true)
	{
		
		ItemVolumeflag = false;
	}

}
void Status::BreakFlagOn()
{
	if(OnceBreakFlag ==false )
	{
		OnceBreakFlag = true;
	}
}
void Status::BreakFlagOff()
{
	if (OnceBreakFlag == true)
	{
		OnceBreakFlag = false;
	}
}
bool Status::OnceBreakFlagCheack()
{
	return OnceBreakFlag;
}