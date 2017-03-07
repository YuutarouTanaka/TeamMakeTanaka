#pragma once
#include "main.h"
#include "ManageVertex.h"
#include "ManageAnimesction.h"
#include "Reader.h"
//�`�揈���S�ʂ̊Ǘ�
class MnageRender
{
private:
	//���C���f�o�C�X�̏��
	LPDIRECT3DDEVICE9				m_device;
	//���_�N���X�̃|�C���^
	ManageVertex*				  m_pVERTEX4;
	//�����̒��_�N���X�̃|�C���^
	ManageAnimeVertex*            AnimectiomVertex;
	//�e�N�X�`���̃|�C���^
	ManegeTexturePointer*	m_pManageTexture;
	//�`��N���X�̊Ǘ�
	Render*						 m_pRenderer;
public:
	//�R���X�g���N�^ 
	MnageRender(LPDIRECT3DDEVICE9 D3Ddevice) :m_device(D3Ddevice)
	{
		m_pVERTEX4 = new ManageVertex;
		AnimectiomVertex = new ManageAnimeVertex;
		m_pManageTexture = new ManegeTexturePointer(m_device);
		m_pRenderer = new Render(m_device);
	};
	//�f�X�g���N�^
	~MnageRender()
	{
	   delete	m_pVERTEX4;
	   delete   m_pManageTexture;
	   delete   m_pRenderer;
	   delete   AnimectiomVertex;
	};
	//�`��̏����ڍאݒ�
	void RenderSetup();
	//�`��
	void RenderTeardown();
	//�l�p��`��
	void DrawBox(int Vertexnumber, LPCSTR Filename, float PosX, float PosY);
	//�l�p��`�ʁi�A�j���[�V�����j
	void DrawBox(int Vertexnumber,int koma, LPCSTR Filename, float PosX, float PosY);
	//�g��k���ł���l�p��`��
	void DrawCustomBox(int Vertexnumber, LPCSTR Filename, float PosX, float PosY, double Scale);
	//�����Ɏl�p��`��
	void DrawCenterBox(int Vertexnumber, LPCSTR Filename, float PosX, float PosY);
	//�����Ɏl�p��`��(�A�j���[�V����)
	void DrawCenterBox(int Vertexnumber,int koma ,LPCSTR Filename, float PosX, float PosY);
	//���_���쐬����vector�ɒǉ�
	void MakeVertex(float X, float Y);
	//���_���쐬����AnimeVertex�ɒǉ�
	void MakeAnimeVertex(float X, float Y, int Xnum, int Ynum);
	//�摜�f�[�^����array�ɒǉ�
	void MakeTexture(LPCSTR FileName);
	//�t�F�[�h�C���E�t�F�[�h�A�E�g
	bool FedeIn();
	bool FedeOut();
};