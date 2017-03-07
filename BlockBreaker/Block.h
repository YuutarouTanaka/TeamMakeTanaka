#pragma once
#include "Battle.h"
#include <algorithm>
#include "Effect.h"
//�u���b�N�N���X
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
	//�v���C���[�̃u���b�N�̏�����
	void InitPlayerBlock(Block block[],int player);
	//�u���b�N�̃^�C�v���擾
	int GetBlockType();
	//�u���b�N��PosX�̎擾
	float GetBlockPosX();
	//�u���b�N��PosY�̎擾
	float GetBlockPosY();
	//�u���b�N��Use�̎擾
	bool GetBlockUse();
	//�Ԃ������useset
	void SetBlockUse(bool);
	//�u���b�N��use��ON
	void HitBlock(Block Player[], Block Enemy[] ,int blocknum,
		Status* pPlayerStatus, Status* pEnemyStatus,Effect* Effect, int player);
	//�u���b�N�z�u�̃p�^�[��������
	void InitBlockPattern(Block player1block[],Block player2block[]);
	//�A�C�e���̌��ʔ���
	void Useitem();
	//�A�C�e���̎�ރZ�b�g
	void SetType(int type);
};