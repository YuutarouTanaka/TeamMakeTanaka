#pragma once
#include"main.h"
#include<map>
#include"Vertex.h"

//���_�Ǘ�
class ManageVertex
{
private:
	//���_4�������Ă�x�N�^�[�ŊǗ�
	std::vector <CUSTOMVERTEX4> Vertex;
public:
	//�R���X�g���N�^
	ManageVertex(){};
	//�f�X�g���N�^�Ńx�N�^�[��������(�N���A)
	~ManageVertex(){Vertex.clear();}
	//���_������������ۂɏ�����
	CUSTOMVERTEX4 Initvertex();
	//���_�ǉ�(����,����)
	void MakeVertex(FLOAT Vertex_X, FLOAT Vertex_Y);
	//���_�̌Ăяo��
	CUSTOMVERTEX4 GetVertex(int Texnum);
	void Setcolor(int texnum, DWORD col);
	bool FedeIn();
	bool FedeOut();
};
