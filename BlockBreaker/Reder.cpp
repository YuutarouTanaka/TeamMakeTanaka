#include "main.h"
#include "Reader.h"
void Render::SetRenderState()
{
	p_device->SetRenderState							//SetRenderState�F�F�X�`��ݒ�ł���
		(D3DRS_ALPHABLENDENABLE, true);					//�s�N�Z�����Ƃ̃A���t�@ �e�X�g��L���ɂ���
	p_device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	//D3DRS_SRCBLEND  D3DBLEND �񋓌^�̂����ꂩ�̃����o�[�ł�
	//D3DBLEND_SRCALPHA//	�u�����f�B���O�W����(As, As, As, As) �Ȃ�B
	p_device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	//D3DRS_SRCBLEND  D3DBLEND �񋓌^�̂����ꂩ�̃����o�[�ł�
	//�u�����f�B���O�W����(1 - Rs, 1 - Gs, 1 - Bs, 1 - As) �ƂȂ�
	p_device->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1);
	//���C�e�B���O�v�Z�Ɏg����f�B�t���[�Y�F�̃\�[�X
	//D3DMCS_COLOR1:�f�B�t���[�Y���_�F���g���B


	p_device->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE); //�e�N�X�`���u�����f�B���O
	//D3DTSS_COLORARG1:�e�N�X�`�� �X�e�[�W �X�e�[�g�́A���̃X�e�[�W�ɑ΂���ŏ��̐F�����ł���A
	//D3DTA �̂����ꂩ�ɂ�莦�����B�f�t�H���g�̈����� D3DTA_TEXTURE �ł���B


	p_device->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
	//D3DTSS_COLORARG2:�e�N�X�`�� �X�e�[�W �X�e�[�g�́A���̃X�e�[�W�ɑ΂��� 2 �Ԗڂ̐F�����ł���A
	//D3DTA_DIFFUSE:�e�N�X�`�������t���O�ɂ�莯�ʂ����B�f�t�H���g������ D3DTA_CURRENT �ł���B
	//�O�[���[ �V�F�[�f�B���O�������ɒ��_���������Ԃ��ē���ꂽ�f�B�t���[�Y �J���[
	p_device->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	//D3DTSS_COLOROP:���̃e�N�X�`���[�X�e�[�g�͂c�R�c�s�`�ŔF�������X�e�[�W��2�Ԗڂ̂`�����ł�
	//D3DTOP_MODULATE:�����̐�������Z����

	//�����x�̐ݒ�
	p_device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	p_device->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	p_device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
}
void Render::RenderStart()
{
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)
	p_device->Clear(									//��ʂ̃N���A
		0,												//stencil�X�e���V���o�b�t�@���N���A����
		NULL,                                           // Target�����^�����O����N���A
		D3DCLEAR_TARGET,								//Target�����^�����O����N���A
		D3DCOLOR_XRGB(0x00, 0x00, 0x00),				//ZBUffer�[�x�o�b�t�@���N���A
		1.0,											//�H�H�H
		0												//�H�H�H
		);
	p_device->BeginScene();							//�`��̐ݒ�

	p_device->SetFVF(									//�Œ蒸�_�@�\�̐錾���擾
		D3DFVF_CUSTOMVERTEX);
}
void Render::RenderEnd()
{
	p_device->EndScene();								//�`��̏I��


	p_device ->Present(NULL, NULL, NULL, NULL);			//�`��̕\��(pSouseRect, pDestRect,hDestWindowOverride)
	//pSouseRect:�]����̋�`�̈������킷RECT�\���̂ւ̃|�C���^
	//hDestWindowOverride:�]����̃E�B���h�E�̃n���h��
	//pDirtyRegion:�m�t�k�k
}
void Render::DrawBox(CUSTOMVERTEX4 Vertex, LPDIRECT3DTEXTURE9 p_texture,float PosX,float PosY)
{
	int i;
	CUSTOMVERTEX4   TEMP;
	for (i = 0; i < 4; i++)
	{
		TEMP.CUSTOMVERTEX[i] = Vertex.CUSTOMVERTEX[i];
	}
	for (i = 0; i < 4; i++)
	{
		TEMP.CUSTOMVERTEX[i].x+=PosX;
		TEMP.CUSTOMVERTEX[i].y+=PosY;
	}
	p_device->SetTexture(0, p_texture);
	p_device->DrawPrimitiveUP(							//���ۂɕ`�悵�Ă�֐��@(����4��)
		D3DPT_TRIANGLEFAN,								//���_���ǂ��Ȃ��邩�̐ݒ�
		2,												//�ʂ̐�
		TEMP.CUSTOMVERTEX,										//���_�X�g���[��0�Ɏg�����߂̒��_�f�[�^���[�U�[�������|�C���^
													//�i���_����ꂽ�����|�C���^�ł��Ă��j10
		sizeof(CUSTOMVERTEX));
}
void Render::DrawCustomBox(
	CUSTOMVERTEX4 Vertex,
	LPDIRECT3DTEXTURE9 p_texture,
	float PosX, float PosY,
	FLOAT ScaleFactor)
{
	int i;
	CUSTOMVERTEX4   TEMP;
	for (i = 0; i < 4; i++)
	{
		TEMP.CUSTOMVERTEX[i] = Vertex.CUSTOMVERTEX[i];
	}
	for (i = 0; i < 4; i++)
	{
		TEMP.CUSTOMVERTEX[i].x *=ScaleFactor;
		TEMP.CUSTOMVERTEX[i].y *=ScaleFactor;
	}
	for (i = 0; i < 4; i++)
	{
		TEMP.CUSTOMVERTEX[i].x +=PosX;
		TEMP.CUSTOMVERTEX[i].y +=PosY;
	}
	p_device->SetTexture(0, p_texture);
	p_device->DrawPrimitiveUP(							//���ۂɕ`�悵�Ă�֐��@(����4��)
		D3DPT_TRIANGLEFAN,								//���_���ǂ��Ȃ��邩�̐ݒ�
		2,												//�ʂ̐�
		TEMP.CUSTOMVERTEX,										//���_�X�g���[��0�Ɏg�����߂̒��_�f�[�^���[�U�[�������|�C���^
		//�i���_����ꂽ�����|�C���^�ł��Ă��j10
		sizeof(CUSTOMVERTEX));
}
void Render::DrawCenterBox(
	CUSTOMVERTEX4 Vertex,
	LPDIRECT3DTEXTURE9 p_texture,
	float PosX,
	float PosY)
{
	CUSTOMVERTEX4   TEMP;
	int i;
	for (i = 0; i < 4; i++)
	{
		TEMP.CUSTOMVERTEX[i] = Vertex.CUSTOMVERTEX[i];
	}
	FLOAT CenterX = TEMP.CUSTOMVERTEX[1].x / 2.0f;
	FLOAT CenterY = TEMP.CUSTOMVERTEX[3].y / 2.0f;
	for (i = 0; i < 4; i++)
	{
		TEMP.CUSTOMVERTEX[i].x -= CenterX;
		TEMP.CUSTOMVERTEX[i].x += PosX;
	}
	for (i = 0; i < 4; i++)
	{
		TEMP.CUSTOMVERTEX[i].y -= CenterY;
		TEMP.CUSTOMVERTEX[i].y += PosY;
	}

	p_device->SetTexture(0, p_texture);
	p_device->DrawPrimitiveUP(							//���ۂɕ`�悵�Ă�֐��@(����4��)
		D3DPT_TRIANGLEFAN,								//���_���ǂ��Ȃ��邩�̐ݒ�
		2,												//�ʂ̐�
		TEMP.CUSTOMVERTEX,										//���_�X�g���[��0�Ɏg�����߂̒��_�f�[�^���[�U�[�������|�C���^
		//�i���_����ꂽ�����|�C���^�ł��Ă��j10
		sizeof(CUSTOMVERTEX));
}