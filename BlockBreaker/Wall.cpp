#include "Wall.h"
#include "Battle.h"
void Wall::InitPlayer1Wall(Wall* pwall)
{
	pwall->WallColider[TOP_LEFT].x = 0.0f;
	pwall->WallColider[TOP_LEFT].y = 160.0f;
	pwall->WallColider[TOP_RIGHT].x = 640.0f;
	pwall->WallColider[TOP_RIGHT].y = 160.0f;
	pwall->WallColider[BOTTOM_RIGHT].x = 640.0f;
	pwall->WallColider[BOTTOM_RIGHT].y = 960.0f;
	pwall->WallColider[BOTTOM_LEFT].x = 0.0f;
	pwall->WallColider[BOTTOM_LEFT].y = 960.0f;
}
void Wall::InitPlayer2Wall(Wall* pwall)
{
	pwall->WallColider[TOP_LEFT].x = 0.0f+PLAYER2_X_GAP;
	pwall->WallColider[TOP_LEFT].y = 160.0f;
	pwall->WallColider[TOP_RIGHT].x = 640.0f+PLAYER2_X_GAP;
	pwall->WallColider[TOP_RIGHT].y = 160.0f;
	pwall->WallColider[BOTTOM_RIGHT].x = 640.0f+PLAYER2_X_GAP;
	pwall->WallColider[BOTTOM_RIGHT].y = 960.0f;
	pwall->WallColider[BOTTOM_LEFT].x = 0.0f + PLAYER2_X_GAP;
	pwall->WallColider[BOTTOM_LEFT].y = 960.0f;
}