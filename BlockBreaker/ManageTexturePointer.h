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

	//vecterを作成
	ManegeTexturePointer(IDirect3DDevice9*);
	//画像データをリセット
	~ManegeTexturePointer();
	//vecterに画像データを追加
	void MakeTexture(LPCSTR);
	//vecterの画像データをリセット
	void InitTexture();
	//ポインタ獲得
	LPDIRECT3DTEXTURE9 GetTexturePointer(LPCSTR);
	};