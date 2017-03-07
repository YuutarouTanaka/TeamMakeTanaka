#pragma once
#include "main.h"
//頂点データ
struct CUSTOMVERTEX
{
	FLOAT x, y, z, rhw;
	DWORD color;
	FLOAT tu, tv;
};
enum VertexName
{
	UPLEFT,
	UPRIGHT,
	DOWNRIGHT,
	DOWNLEFT
};
//4頂点(左上,右上,右下,左下)を持つ構造体
struct CUSTOMVERTEX4
{

	CUSTOMVERTEX CUSTOMVERTEX[4];
};

