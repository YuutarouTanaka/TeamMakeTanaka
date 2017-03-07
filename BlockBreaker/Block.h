#pragma once
#include "Battle.h"
#include <algorithm>
#include "Effect.h"
//ブロッククラス
class Status;
class Block
{
private:
	float PosX;
	float PosY;

	bool Use;
	int BlockType;
public:
	Colider BlockColider[4];
	//プレイヤーのブロックの初期化
	void InitPlayerBlock(Block block[],int player);
	//ブロックのタイプを取得
	int GetBlockType();
	//ブロックのPosXの取得
	float GetBlockPosX();
	//ブロックのPosYの取得
	float GetBlockPosY();
	//ブロックのUseの取得
	bool GetBlockUse();
	//ぶろっくのuseset
	void SetBlockUse(bool);
	//ブロックのuseをON
	void HitBlock(Block Player[], Block Enemy[] ,int blocknum,
		Status* pPlayerStatus, Status* pEnemyStatus,Effect* Effect, int player);
	//ブロック配置のパターン初期化
	void InitBlockPattern(Block player1block[],Block player2block[]);
	//アイテムの効果発動
	void Useitem();
	//アイテムの種類セット
	void SetType(int type);
};