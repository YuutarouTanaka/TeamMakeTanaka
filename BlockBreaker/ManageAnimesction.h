              #pragma once
#include"main.h"
#include "Vertex.h"
struct AnimeVertex
{
	std::vector<CUSTOMVERTEX4>ITIKOMA;
};
class ManageAnimeVertex
{
private:
	std::vector<AnimeVertex>AnimeCtion;
public:
	//コンストラクタ
	ManageAnimeVertex(){};
	//デストラクタでベクターを初期化(クリア)
	~ManageAnimeVertex(){ AnimeCtion.clear(); }
	//頂点を追加する際に初期化
	CUSTOMVERTEX4 InitAnimevertex();
	//頂点追加(立幅,横幅,横要素数,縦要素数)
	void MakeAnimeVertex(FLOAT Vertex_X, FLOAT Vertex_Y,int Xnum,int Ynum);
	//頂点の呼び出し
	 CUSTOMVERTEX4 GetAnimeVertex(int Texnum,int koma);
};