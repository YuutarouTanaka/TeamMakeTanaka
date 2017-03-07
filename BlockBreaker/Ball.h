#pragma once
#include "Battle.h"
#define BALL_SPEED			10.0f
#define RADIUSU				10.0f
#define START_SPEED			0.0f
#define DegtoRad  0.017453293f
#define RadtoDeg 57.295779514f
//ボールの構造体//1415926535
class Ball
{
private:
	float Radius;
	float Degree;
	float Speed;
	float VectorX;
	float VectorY;
	float PosX;
	float PosY;
public:
	//プレイヤー1のボール初期化
	void InitPlayerBall(float PosX, float PosY, float degree,Ball* pBall);
	//playerボールが動き出す
	void StartBall();
	//PosXを取得
	float GetPosX();
	//PosYを取得
	float GetPosY();
	//角度をセット
	void SetDegree(float degree);
	//角度を取得
	float GetDegree();
	//VectrXをセット
	void SetVectorX();
	//VectrYをセット
	void SetVectorY();
	//ベクターの分だけ動く
	void Move();
	//X座標をセット
	void SetX(float);
	//Y座標をセット
	void SetY(float);
	//ボールが止まる
	void StopBall();
};