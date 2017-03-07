#include "ManageRender.h"
#include "ManageTexturePointer.h"
#include "ManageVertex.h"
#include "Battle.h"
void MnageRender::RenderSetup()
{
	m_pRenderer->SetRenderState();
	m_pRenderer->RenderStart();
}
void MnageRender::RenderTeardown()
{
	m_pRenderer->RenderEnd();
}
void MnageRender::DrawBox(int Vertexnum, LPCSTR Filename, float Posx, float Posy)
{
	m_pRenderer->DrawBox(
		m_pVERTEX4->GetVertex(Vertexnum),
		m_pManageTexture->GetTexturePointer(Filename),
		Posx,
		Posy);
}
void MnageRender::DrawBox(int Vertexnum,int koma, LPCSTR Filename, float Posx, float Posy)
{
	m_pRenderer->DrawBox(
		AnimectiomVertex->GetAnimeVertex(Vertexnum,koma),
		m_pManageTexture->GetTexturePointer(Filename),
		Posx,
		Posy);
}
void MnageRender::DrawCustomBox(int Vertexnumber,LPCSTR Filename,float Posx,float Posy,double Scale)
{
	m_pRenderer->DrawCustomBox(
		m_pVERTEX4->GetVertex(Vertexnumber),
		m_pManageTexture->GetTexturePointer(Filename),
		Posx,
		Posy,
		(float)Scale);
}
void MnageRender::DrawCenterBox(int Vertexnumber, LPCSTR Filename, float PosX, float PosY)
{
	m_pRenderer->DrawCenterBox(
		m_pVERTEX4->GetVertex(Vertexnumber),
		m_pManageTexture->GetTexturePointer(Filename),
		PosX,
		PosY
		);
}
void MnageRender::MakeVertex(FLOAT Posx, FLOAT Posy)
{
	m_pVERTEX4->MakeVertex(Posx, Posy);
}
void MnageRender::MakeAnimeVertex(FLOAT Posx, FLOAT Posy, int Xnum, int Ynum)
{
	AnimectiomVertex->MakeAnimeVertex(Posx, Posy, Xnum, Ynum);
}
void MnageRender::MakeTexture(LPCSTR Texnum)
{
	m_pManageTexture->MakeTexture(Texnum);
}
bool MnageRender::FedeIn(){
	return m_pVERTEX4->FedeIn();
}
bool MnageRender::FedeOut(){
	return m_pVERTEX4->FedeOut();
}
