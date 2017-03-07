#include "Ball.h"
#include "Battle.h"
#include <cmath>
void Ball::InitPlayerBall(float posX,float posY,float degree,Ball* pBall)
{
	Radius = RADIUSU;
	Degree = degree;
	Speed = START_SPEED;
	PosX = posX;
	PosY = posY;
	SetVectorX();
	SetVectorY();
}
void Ball::StopBall()
{
	Speed = START_SPEED;
}
void Ball::StartBall()
{
	Speed = BALL_SPEED;
}
float Ball::GetDegree()
{
	return Degree;
}
void Ball::SetDegree(float degree)
{
	Degree = degree;
}
float Ball::GetPosX()
{
	return PosX;
}
float Ball::GetPosY()
{
	return PosY;

}
void Ball::SetVectorX()
{
	VectorX = Speed*cosf(Degree*DegtoRad);
}
void Ball::SetVectorY()
{
	VectorY = Speed*sinf(Degree*DegtoRad);
}
void Ball::SetX(float x)
{
	PosX = x;
}
void Ball::SetY(float y)
{
	PosY = y;
}
void Ball::Move()
{
	PosX += VectorX;
	PosY += VectorY;
}