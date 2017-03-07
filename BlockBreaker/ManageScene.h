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
//シーンの抽象クラス
class Scene
{
	friend class ManageScene;
public:
	//シーンデータを初期化する純粋仮想関数
	virtual void InitData() = 0;
	//キー入力の純粋仮想関数
	virtual void Input(InputKey**, ManageScene**, GamePad**) = 0;
	//描画の純粋仮想関数
	virtual void Render(MnageRender**) = 0;
	//衝突の判定
	virtual void Colison() = 0;
	//コントロール
	virtual void Control(ManageScene**) = 0;
	//シーン切り替えの純粋仮想関数
	virtual Scene* ChangeScene(int) = 0;
protected:
	//タイトルへの切り替え
	static Scene* GO_Title();
	//バトルシーンへの切り替え
	static Scene* GO_Battle();
	//遊び方説明シーンへの切り替え
	static Scene* GO_HowTo();
	//結果シーンへの切り替え
	static Scene* GO_Result();
	//終了処理
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
//タイトルシーン
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
//メインシーン
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
//遊び方シーン
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
//シーン切り替えクラス
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
