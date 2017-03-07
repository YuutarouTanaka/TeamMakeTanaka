#pragma once
#include"ManageVertex.h"
#include "ManageAnimesction.h"
#include"ManageTexturePointer.h"
#include"main.h"
#include "Battle.h"
class Render
{
private:
	//�`��f�o�C�X�̏�����
	IDirect3DDevice9* p_device;
	//���_�Ǘ��N���X
	ManageVertex m_Vertex;
	//�e�N�X�`���̊Ǘ�
	ManegeTexturePointer m_TexturePointer();
public:
	//�R���X�g���N�^�@�f�o�C�X��n���ď�����
	Render(IDirect3DDevice9* device){ p_device = device;};
	//�f�X�g���N�^
	~Render(){};
	//�A���t�@�u�����f�B���O�̂ƃe�N�X�`���u�����f�B���O�̐ݒ�
	void SetRenderState();
	//��ʂ̃N���A�@�`��̐ݒ�@���_�̐錾
	void RenderStart();
	//�`��̏I���@�`��̕\��
	void RenderEnd();
	//��`�̕`��
	void DrawBox(CUSTOMVERTEX4 Vertex, LPDIRECT3DTEXTURE9 p_texture,float x,float y);
	//��`�̕`��
	void DrawBox(AnimeVertex AnimeVertex,int koma, LPDIRECT3DTEXTURE9 p_texture, float x, float y);
	//�g��k���ł����`�̕`��
	void DrawCustomBox(
		CUSTOMVERTEX4 Vertex,
		LPDIRECT3DTEXTURE9 p_texture,
		float x,
		float y,
		FLOAT ScaleFactor);
	//���W�̒����ɋ�`�̕`��
	void DrawCenterBox(
		CUSTOMVERTEX4 Vertex,
		LPDIRECT3DTEXTURE9 p_texture,
		float x,
		float y);
};