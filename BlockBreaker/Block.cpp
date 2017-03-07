#include "Block.h"
#include "Battle.h"
#include <random>
#include<time.h>
#include "Status.h"
#include<algorithm>
#define TYPE_MAX  5
#include"DirectShowSound.h"
#include <queue>
#include <time.h>


extern CSound block_break;
extern CSound lightning_break;
extern CSound tornado_break;
extern CSound battle_sound;

void Block::InitPlayerBlock(Block block[] ,int player)
{
	int num = 0;
	for (int y = 0; y < 6; y++)
	{
		for (int x = 0; x < 6; x++)
		{
			block[num].PosX = ((float)x*BLOCK_WITDH) + PLAYER2_X_GAP*player+  STAGE_SIDE + CENTER_GAP + WALL_WITDH;
			block[num].PosY = ((float)y*BLOCK_HEIGHT) + STATUS_SPASE + CENTER_GAP;
			block[num].BlockColider[TOP_LEFT].x = block[num].GetBlockPosX() - (BLOCK_WITDH / 2);
			block[num].BlockColider[TOP_LEFT].y = block[num].GetBlockPosY() - (BLOCK_HEIGHT / 2);

			block[num].BlockColider[TOP_RIGHT].x = block[num].GetBlockPosX() + (BLOCK_WITDH / 2);
			block[num].BlockColider[TOP_RIGHT].y = block[num].GetBlockPosY() - (BLOCK_HEIGHT / 2);

			block[num].BlockColider[BOTTOM_RIGHT].x = block[num].GetBlockPosX() + (BLOCK_WITDH / 2);
			block[num].BlockColider[BOTTOM_RIGHT].y = block[num].GetBlockPosY() + (BLOCK_HEIGHT / 2);

			block[num].BlockColider[BOTTOM_LEFT].x = block[num].GetBlockPosX() - (BLOCK_WITDH / 2);
			block[num].BlockColider[BOTTOM_LEFT].y = block[num].GetBlockPosY() + (BLOCK_HEIGHT / 2);

			block[num].Use = true;
			block[num].BlockType = NORMAL;
			num++;
		}
	}

}
int Block::GetBlockType()
{
	return BlockType;
}
float Block::GetBlockPosX()
{
	return PosX;
}
float Block::GetBlockPosY()
{
	return PosY;
}
bool Block::GetBlockUse()
{
	return Use;
}
void Block::SetBlockUse(bool usetype)
{
	Use = usetype;
}
void Block::HitBlock(Block pPlayerblock[], Block pEnemyblock[], int blocknum,
	Status* pPlayerStatus, Status* pEnemyStatus, Effect* Effect,int player)
{
	
	switch (pPlayerblock[blocknum].BlockType)
	{
	case NORMAL:
		block_break.PlayFromStart();

		break;
	case LIGHTNING:
		battle_sound.VolChange(-20000);
		lightning_break.PlayFromStart();
		pPlayerStatus->UpdateItemFlagSet();
		Effect->UseLightning(blocknum);
		break;
	case TORNADO:
		battle_sound.VolChange(-20000);
		tornado_break.PlayFromStart();
		pPlayerStatus->UpdateItemFlagSet();
		if (pEnemyStatus->isBarrier() == true)
		{
			Effect->UseTornado(blocknum, false);
		}
		else
		{
			Effect->UseTornado(blocknum, true);
		}
		break;

	}
	if (pPlayerblock[blocknum].BlockType == POISON ||
		pPlayerblock[blocknum].BlockType == CHANGE ||
		pPlayerblock[blocknum].BlockType == BARRIER)
	{
		
		pPlayerStatus->StackItem(pPlayerblock[blocknum].BlockType);
	}
	if (pPlayerblock[blocknum].BlockType == LIGHTNING)
	{
		int block[5];
		if (blocknum < 6)
		{
			block[0] = blocknum + 6;
			block[1] = blocknum + 12;
			block[2] = blocknum + 18;
			block[3] = blocknum + 24;
			block[4] = blocknum + 30;
		}
		else if (blocknum>=6&&blocknum<12)
		{
			block[0] = blocknum - 6;
			block[1] = blocknum + 6;
			block[2] = blocknum + 12;
			block[3] = blocknum + 18;
			block[4] = blocknum + 24;

		}
		else if (blocknum >= 12 && blocknum < 18)
		{
			block[0] = blocknum - 12;
			block[1] = blocknum - 6;
			block[2] = blocknum + 6;
			block[3] = blocknum + 12;
			block[4] = blocknum + 18;
		}
		else if (blocknum >= 18 && blocknum < 24)
		{
			block[0] = blocknum - 18;
			block[1] = blocknum - 12;
			block[2] = blocknum - 6;
			block[3] = blocknum + 6;
			block[4] = blocknum + 12;
		}
		else if (blocknum >= 24 && blocknum < 30)
		{
			block[0] = blocknum - 24;
			block[1] = blocknum - 18;
			block[2] = blocknum - 12;
			block[3] = blocknum - 6;
			block[4] = blocknum + 6;
		}
		else if (blocknum >= 30 && blocknum < 36)
		{
			block[0] = blocknum - 30;
			block[1] = blocknum - 24;
			block[2] = blocknum - 18;
			block[3] = blocknum - 12;
			block[4] = blocknum - 6;
		}
		for (int i = 0; i < 5;i++)
		{
			pPlayerblock[block[i]].SetBlockUse(false);
		}
	}
	if (pPlayerblock[blocknum].BlockType == TORNADO)
	{
		int temp = blocknum / 6;
		int block[6] = { temp * 6, temp * 6 + 1, temp * 6 + 2, temp * 6 + 3, temp * 6 + 4, temp * 6 + 5 };
		for (int i = 0; i < 6; i++)
		{
			pPlayerblock[block[i]].SetBlockUse(false);
		}
		if (pEnemyStatus->isBarrier() == false)
		{
			for (int i = 0; i < 6; i++)
			{
				pEnemyblock[block[i]].SetBlockUse(false);
			}
		}
	}
	pPlayerblock[blocknum].Use = false;
}
void Block::SetType(int type)
{
	BlockType = type;
}
void Block::InitBlockPattern(Block player1block[], Block player2block[])
{   //ƒ‰ƒ“ƒ_ƒ€
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::deque<int> item;
	std::uniform_int_distribution<> rand1(0, 4);
	std::uniform_int_distribution<> rand2(0, 4);
	item.push_front(1);
	item.push_front(2);
	item.push_front(3);
	item.push_front(4);
	item.push_front(5);
	std::random_shuffle(item.begin(), item.end());
	int itembox[6][6][6] = 
	{ { { 0, 1, 0, 0, 0, 1 }, { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0 }, { 1, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 1, 0 }, { 0, 0, 1, 0, 0, 0 } },
	{ { 0, 0, 0, 0, 1, 0 }, { 0, 0, 0, 0, 0, 0 }, { 1, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 1 }, { 0, 1, 0, 0, 0, 0 }, { 0, 0, 0, 1, 0, 0 } },
	{ { 0, 0, 1, 0, 0, 0 }, { 0, 0, 0, 0, 1, 0 }, { 0, 0, 0, 0, 0, 1 }, { 1, 0, 0, 0, 0, 0 }, { 0, 0, 0, 1, 0, 0 }, { 0, 0, 0, 0, 0, 0 } },
	{ { 1, 0, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0, 0 }, { 0, 0, 0, 0, 0, 1 }, { 0, 0, 0, 0, 0, 0 }, { 0, 1, 0, 0, 0, 0 }, { 0, 0, 0, 1, 0, 0 } },
	{ { 0, 0, 0, 0, 0, 0 }, { 0, 1, 0, 1, 0, 0 }, { 0, 0, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0, 0 }, { 1, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 1, 0 } } };
	
	int patarn1 = rand1(mt);
	int num = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (itembox[patarn1][i][j] == 1)
			{
				player1block[num].BlockType = item.back();
				item.pop_back();
			}
			num++;
		}
	}
	item.push_front(1);
	item.push_front(2);
	item.push_front(3);
	item.push_front(4);
	item.push_front(5);
	std::random_shuffle(item.begin(), item.end());

	int patarn2 = rand2(mt);
	num = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (itembox[patarn2][i][j] == 1)
			{
				player2block[num].BlockType = item.back();
				item.pop_back();
			}
			num++;
		}
	}
	


}