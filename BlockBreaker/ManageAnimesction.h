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
	//�R���X�g���N�^
	ManageAnimeVertex(){};
	//�f�X�g���N�^�Ńx�N�^�[��������(�N���A)
	~ManageAnimeVertex(){ AnimeCtion.clear(); }
	//���_��ǉ�����ۂɏ�����
	CUSTOMVERTEX4 InitAnimevertex();
	//���_�ǉ�(����,����,���v�f��,�c�v�f��)
	void MakeAnimeVertex(FLOAT Vertex_X, FLOAT Vertex_Y,int Xnum,int Ynum);
	//���_�̌Ăяo��
	 CUSTOMVERTEX4 GetAnimeVertex(int Texnum,int koma);
};