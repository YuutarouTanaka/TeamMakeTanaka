#pragma once
#include "main.h"
//���_�f�[�^
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
//4���_(����,�E��,�E��,����)�����\����
struct CUSTOMVERTEX4
{

	CUSTOMVERTEX CUSTOMVERTEX[4];
};

