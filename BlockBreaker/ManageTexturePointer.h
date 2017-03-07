#pragma once
#include"main.h" 
#include <map>
class ManegeTexturePointer
{
private:
	std::map<LPCSTR,int> m_pTextureMap;
	int UseArray;
	LPDIRECT3DTEXTURE9  m_pTextureArray[60];
	IDirect3DDevice9* m_3DDevice9;
public:

	//vecter���쐬
	ManegeTexturePointer(IDirect3DDevice9*);
	//�摜�f�[�^�����Z�b�g
	~ManegeTexturePointer();
	//vecter�ɉ摜�f�[�^��ǉ�
	void MakeTexture(LPCSTR);
	//vecter�̉摜�f�[�^�����Z�b�g
	void InitTexture();
	//�|�C���^�l��
	LPDIRECT3DTEXTURE9 GetTexturePointer(LPCSTR);
	};