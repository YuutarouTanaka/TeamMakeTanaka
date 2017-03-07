#pragma once
#include "ManageRender.h"
#include "Inputkey.h"
#include "DataTitle.h"
#include "Battle.h"
#include "Howto.h"
#include "Block.h"
#include "Ball.h"
#include "Wall.h"
#include "Ber.h" 
#include "PenaltyTime.h"
#include "Time.h"
#include "Status.h"
#include "EndFlag.h"
#include "Effect.h"
//�V�[���̒��ۃN���X
class Scene
{
	friend class ManageScene;
public:
	//�V�[���f�[�^�����������鏃�����z�֐�
	virtual void InitData() = 0;
	//�L�[���͂̏������z�֐�
	virtual void Input(InputKey**, ManageScene**, GamePad**) = 0;
	//�`��̏������z�֐�
	virtual void Render(MnageRender**) = 0;
	//�Փ˂̔���
	virtual void Colison() = 0;
	//�R���g���[��
	virtual void Control(ManageScene**) = 0;
	//�V�[���؂�ւ��̏������z�֐�
	virtual Scene* ChangeScene(int) = 0;
protected:
	//�^�C�g���ւ̐؂�ւ�
	static Scene* GO_Title();
	//�o�g���V�[���ւ̐؂�ւ�
	static Scene* GO_Battle();
	//�V�ѕ������V�[���ւ̐؂�ւ�
	static Scene* GO_HowTo();
	//���ʃV�[���ւ̐؂�ւ�
	static Scene* GO_Result();
	//�I������
	static Scene* GO_End();

	enum FadeStep
	{
		free,
		InMidstream,
		InEnd,
		OutMidstream,
		OutEnd

	};

	FadeStep fadestep;
};
//�^�C�g���V�[��
class TitleScene :public Scene
{
public:
	DataTitle Data;
	void InitData()override;
	void Input(InputKey**, ManageScene**, GamePad**)override;
	void Render(MnageRender**)override;
	void Colison()override;
	void Control(ManageScene**)override;
	Scene* ChangeScene(int)override;
};
//���C���V�[��
class MainScene :public Scene
{
	DataBattle Data;
	Block BlockTypeSelect[36];
	Block Player1Block[36];
	Block Player2Block[36];
	Wall Player1Wall;
	Wall Player2Wall;
	Ball Player1Ball;
	Ball Player2Ball;
	Ber Player1Ber;
	Ber Player2Ber;
	CTime BattleTimer;
	CPenaltyTime  Player1flag;
	CPenaltyTime  Player2flag;
	Status Player1Status;
	Status Player2Status;
	Effect Player1Effect;
	Effect Player2Effect;
	CEndFlag EndFlag;
	
	

public:
	void InitData()override;
	void Input(InputKey**, ManageScene**, GamePad**)override;
	void Render(MnageRender**)override;
	void Colison()override;
	void Control(ManageScene**)override;
	void PenaltyCountRender(MnageRender*** pppRender,
		CPenaltyTime* pFlagPenalty,int Player);
	void CountRender(MnageRender*** pppRender);
	void TimeRender(MnageRender*** pppRender, CTime* ptime);
	void BlockRender(MnageRender*** pppRender,
		Block block[], int GraphNum, float x, float y, int player);
	void EffectRender(MnageRender*** pppRender, Effect*,int player);
	void ItemRender(MnageRender*** pppRender,Status* pstatus,int player);
	void StatusRender(MnageRender*** pppRender, Status* pstatus, int player);
	void ResultRender(MnageRender*** pppRender, CTime* pEndflag);
	void ManageColisonPlayerWall(Wall*,Ball*);
	void ManageColisonPlayerBer(Ber*,Ball*);
	void ManageColisonPlayerBlock(Block*, Block*, Ball*, Status*, Status*,Effect*,int);
	float ManageColisonPlayerBlockBounde(Block*,Ball*,int);
	Scene* ChangeScene(int)override;
};
//�V�ѕ��V�[��
class HowToScene :public Scene
{
public:
	DataHowto Data;
	void InitData()override;
	void Input(InputKey**, ManageScene**, GamePad**)override;
	void Colison()override;
	void Control(ManageScene**)override;
	void Render(MnageRender**)override;
	Scene* ChangeScene(int)override;

};
//�V�[���؂�ւ��N���X
class ManageScene
{
public:
	ManageScene()
	{
		Scene_ = (Scene::GO_Title());
		Scene_->InitData();
	}
	void ChangeScene(int SceneNum)
	{
		Scene_ = Scene_->ChangeScene(SceneNum);
		Scene_->InitData();
	}
	void InitData()
	{
		Scene_->InitData();
	}
	void Render(MnageRender* pRender)
	{
		Scene_->Render(&pRender);
	}
	void Control(ManageScene* pManageScene)
	{
		Scene_->Control(&pManageScene);
	}
	void Colision()
	{
		Scene_->Colison();
	}
	void Input(InputKey* pInput, ManageScene* pManageScene, GamePad* pGamePad)
	{
		Scene_->Input(&pInput, &pManageScene, &pGamePad);
	}
private:
	Scene* Scene_;
};
