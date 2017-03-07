#pragma once
#include "Battle.h"
#define BALL_SPEED			10.0f
#define RADIUSU				10.0f
#define START_SPEED			0.0f
#define DegtoRad  0.017453293f
#define RadtoDeg 57.295779514f
//�{�[���̍\����//1415926535
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
	//�v���C���[1�̃{�[��������
	void InitPlayerBall(float PosX, float PosY, float degree,Ball* pBall);
	//player�{�[���������o��
	void StartBall();
	//PosX���擾
	float GetPosX();
	//PosY���擾
	float GetPosY();
	//�p�x���Z�b�g
	void SetDegree(float degree);
	//�p�x���擾
	float GetDegree();
	//VectrX���Z�b�g
	void SetVectorX();
	//VectrY���Z�b�g
	void SetVectorY();
	//�x�N�^�[�̕���������
	void Move();
	//X���W���Z�b�g
	void SetX(float);
	//Y���W���Z�b�g
	void SetY(float);
	//�{�[�����~�܂�
	void StopBall();
};