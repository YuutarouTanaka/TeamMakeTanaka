#include "main.h"
#include "ManageAnimesction.h"
CUSTOMVERTEX4 ManageAnimeVertex::InitAnimevertex()
{
	CUSTOMVERTEX4 Vertex = {};
	for (int i = 0; i < 4; i++)
	{
		Vertex.CUSTOMVERTEX[i].x = 0.0f;
		Vertex.CUSTOMVERTEX[i].y = 0.0f;
		Vertex.CUSTOMVERTEX[i].z = 0.5f;
		Vertex.CUSTOMVERTEX[i].rhw = 1.0f;
		Vertex.CUSTOMVERTEX[i].color = 0xFFFFFFFF;
	}
	Vertex.CUSTOMVERTEX[UPLEFT].tu = 0.0f;
	Vertex.CUSTOMVERTEX[UPLEFT].tv = 0.0f;
	Vertex.CUSTOMVERTEX[UPRIGHT].tu = 1.0f;
	Vertex.CUSTOMVERTEX[UPRIGHT].tv = 0.0f;
	Vertex.CUSTOMVERTEX[DOWNRIGHT].tu = 1.0f;
	Vertex.CUSTOMVERTEX[DOWNRIGHT].tv = 1.0f;
	Vertex.CUSTOMVERTEX[DOWNLEFT].tu = 0.0f;
	Vertex.CUSTOMVERTEX[DOWNLEFT].tv = 1.0f;

	return Vertex;
}
void ManageAnimeVertex::MakeAnimeVertex(FLOAT Vertex_X, FLOAT Vertex_Y,int Xnum, int Ynum)
{
	AnimeVertex TempAnime = {};
	CUSTOMVERTEX4 TempVertex = {};
	for (int j = 0; j < Ynum; j++)
	{
		for (int i = 0; i < Xnum; i++)
		{
			TempVertex = InitAnimevertex();
			TempVertex.CUSTOMVERTEX[UPRIGHT].x = Vertex_X;
			TempVertex.CUSTOMVERTEX[DOWNRIGHT].x = Vertex_X;
			TempVertex.CUSTOMVERTEX[DOWNRIGHT].y = Vertex_Y;
			TempVertex.CUSTOMVERTEX[DOWNLEFT].y = Vertex_Y;

			TempVertex.CUSTOMVERTEX[UPLEFT].tu = (FLOAT)i/Xnum;
			TempVertex.CUSTOMVERTEX[UPLEFT].tv = (FLOAT)j/Ynum;
			TempVertex.CUSTOMVERTEX[UPRIGHT].tu = (FLOAT)(i + 1) / Xnum;
			TempVertex.CUSTOMVERTEX[UPRIGHT].tv = (FLOAT)j/ Ynum;
			TempVertex.CUSTOMVERTEX[DOWNRIGHT].tu = (FLOAT)(i + 1) / Xnum;
			TempVertex.CUSTOMVERTEX[DOWNRIGHT].tv = (FLOAT)(j + 1) / Ynum;
			TempVertex.CUSTOMVERTEX[DOWNLEFT].tu = (FLOAT) i/ Xnum;
			TempVertex.CUSTOMVERTEX[DOWNLEFT].tv = (FLOAT)(j + 1) / Ynum;
			TempAnime.ITIKOMA.push_back(TempVertex);
		}
	}
	AnimeCtion.push_back(TempAnime);
}
CUSTOMVERTEX4 ManageAnimeVertex::GetAnimeVertex(int Texnum, int koma)
{
	return AnimeCtion.at(Texnum).ITIKOMA.at(koma);
}