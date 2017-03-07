#pragma once
#include"main.h"
#include<map>
#include"Vertex.h"

//頂点管理
class ManageVertex
{
private:
	//頂点4つを持ってるベクターで管理
	std::vector <CUSTOMVERTEX4> Vertex;
public:
	//コンストラクタ
	ManageVertex(){};
	//デストラクタでベクターを初期化(クリア)
	~ManageVertex(){Vertex.clear();}
	//頂点を初期化する際に初期化
	CUSTOMVERTEX4 Initvertex();
	//頂点追加(横幅,立幅)
	void MakeVertex(FLOAT Vertex_X, FLOAT Vertex_Y);
	//頂点の呼び出し
	CUSTOMVERTEX4 GetVertex(int Texnum);
	void Setcolor(int texnum, DWORD col);
	bool FedeIn();
	bool FedeOut();
};
