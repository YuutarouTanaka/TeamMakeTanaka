#pragma once
#include "main.h"
#include "ManageVertex.h"
#include "ManageAnimesction.h"
#include "Reader.h"
//描画処理全般の管理
class MnageRender
{
private:
	//メインデバイスの情報
	LPDIRECT3DDEVICE9				m_device;
	//頂点クラスのポインタ
	ManageVertex*				  m_pVERTEX4;
	//複数の頂点クラスのポインタ
	ManageAnimeVertex*            AnimectiomVertex;
	//テクスチャのポインタ
	ManegeTexturePointer*	m_pManageTexture;
	//描画クラスの管理
	Render*						 m_pRenderer;
public:
	//コンストラクタ 
	MnageRender(LPDIRECT3DDEVICE9 D3Ddevice) :m_device(D3Ddevice)
	{
		m_pVERTEX4 = new ManageVertex;
		AnimectiomVertex = new ManageAnimeVertex;
		m_pManageTexture = new ManegeTexturePointer(m_device);
		m_pRenderer = new Render(m_device);
	};
	//デストラクタ
	~MnageRender()
	{
	   delete	m_pVERTEX4;
	   delete   m_pManageTexture;
	   delete   m_pRenderer;
	   delete   AnimectiomVertex;
	};
	//描画の初期詳細設定
	void RenderSetup();
	//描画
	void RenderTeardown();
	//四角を描写
	void DrawBox(int Vertexnumber, LPCSTR Filename, float PosX, float PosY);
	//四角を描写（アニメーション）
	void DrawBox(int Vertexnumber,int koma, LPCSTR Filename, float PosX, float PosY);
	//拡大縮小できる四角を描写
	void DrawCustomBox(int Vertexnumber, LPCSTR Filename, float PosX, float PosY, double Scale);
	//中央に四角を描写
	void DrawCenterBox(int Vertexnumber, LPCSTR Filename, float PosX, float PosY);
	//中央に四角を描写(アニメーション)
	void DrawCenterBox(int Vertexnumber,int koma ,LPCSTR Filename, float PosX, float PosY);
	//頂点を作成してvectorに追加
	void MakeVertex(float X, float Y);
	//頂点を作成してAnimeVertexに追加
	void MakeAnimeVertex(float X, float Y, int Xnum, int Ynum);
	//画像データををarrayに追加
	void MakeTexture(LPCSTR FileName);
	//フェードイン・フェードアウト
	bool FedeIn();
	bool FedeOut();
};