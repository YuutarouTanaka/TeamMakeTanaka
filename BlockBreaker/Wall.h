#pragma once
#include "Battle.h"
class Wall
{
	int Position;
public:
	Colider WallColider[4];

	void InitPlayer1Wall(Wall* pwall);
	void InitPlayer2Wall(Wall* pwall);
};
