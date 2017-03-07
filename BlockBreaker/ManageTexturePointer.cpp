#include "main.h"
#include "ManageTexturePointer.h"
#include <algorithm>
ManegeTexturePointer::ManegeTexturePointer(IDirect3DDevice9* p_3DDevice )
{
	m_3DDevice9 = p_3DDevice;
	UseArray = 0;
}
ManegeTexturePointer::~ManegeTexturePointer() 
{
}
void ManegeTexturePointer::InitTexture()
{

}
void ManegeTexturePointer::MakeTexture(LPCSTR  pSrcFile)
{
	LPDIRECT3DTEXTURE9 pTexture=nullptr;
	D3DXCreateTextureFromFileA(
		m_3DDevice9,
		pSrcFile,
		&pTexture);
	m_pTextureArray[UseArray] = pTexture;
	UseArray++;
	m_pTextureMap[pSrcFile] = UseArray-1;
}
LPDIRECT3DTEXTURE9 ManegeTexturePointer::GetTexturePointer(LPCSTR texname)
{
	return m_pTextureArray[m_pTextureMap.at(texname)];
}