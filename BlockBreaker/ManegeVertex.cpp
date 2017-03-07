#include "main.h"
#include "ManageVertex.h"
CUSTOMVERTEX4  ManageVertex::Initvertex()
{
	CUSTOMVERTEX4 Vertex = {};
	for (int i = 0; i < 4; i++)
	{
		Vertex.CUSTOMVERTEX[i].x = 0.0f;
		Vertex.CUSTOMVERTEX[i].y = 0.0f;
		Vertex.CUSTOMVERTEX[i].z = 0.5f;
		Vertex.CUSTOMVERTEX[i].rhw = 1.0f;
		Vertex.CUSTOMVERTEX[i].color = 0x00FFFFFF;
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
void ManageVertex::MakeVertex(FLOAT Vertex_X, FLOAT Vertex_Y)
{
	CUSTOMVERTEX4 VERTEX = {};
	VERTEX = Initvertex();
	VERTEX.CUSTOMVERTEX[UPRIGHT].x = Vertex_X;
	VERTEX.CUSTOMVERTEX[DOWNRIGHT].x = Vertex_X;
	VERTEX.CUSTOMVERTEX[DOWNRIGHT].y = Vertex_Y;
	VERTEX.CUSTOMVERTEX[DOWNLEFT].y = Vertex_Y;
	Vertex.push_back(VERTEX);
}

CUSTOMVERTEX4 ManageVertex::GetVertex(int texnum)
{
	return Vertex.at(texnum);
}
void ManageVertex::Setcolor(int texnum, DWORD clo){
	for (int i = 0; i < 4; i++)
	{
		Vertex[texnum].CUSTOMVERTEX[i].color = clo;
	}
}
bool ManageVertex::FedeIn(){

	bool check = true;
	for (int i = 0; i < int(Vertex.size()); i++){

		// 1つでも終わってなければcheckをfalseに
		if (GetVertex(i).CUSTOMVERTEX[0].color != D3DCOLOR_ARGB(255, 255, 255, 255)){
			check = false;
		}

	}
	if (check == true) return true;

	DWORD c;


	for (int i = 0; i < int(Vertex.size()); i++){
		c = GetVertex(i).CUSTOMVERTEX[0].color;

		c += D3DCOLOR_ARGB(5, 0, 0, 0);

		Setcolor(i, c);
	}

	if (c == D3DCOLOR_ARGB(255, 255, 255, 255)){

		return true;
	}

	return false;

}
bool ManageVertex::FedeOut(){
	// フェード終わってるかチェック
	bool check = true;
	for (int i = 0; i < int(Vertex.size()); i++){

		// 1つでも終わってなければcheckをfalseに
		if (GetVertex(i).CUSTOMVERTEX[0].color != D3DCOLOR_ARGB(0, 255, 255, 255)){
			check = false;
		}

	}
	if (check == true) return true;

	DWORD c;


	for (int i = 0; i < int(Vertex.size()); i++){
		c = GetVertex(i).CUSTOMVERTEX[0].color;

		c -= D3DCOLOR_ARGB(5, 0, 0, 0);

		Setcolor(i, c);
	}



	return false;
}