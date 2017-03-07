#pragma once
#include"ManageVertex.h"
#include "ManageAnimesction.h"
#include"ManageTexturePointer.h"
#include"main.h"
#include "Battle.h"
class Render
{
private:
	//描画デバイスの初期化
	IDirect3DDevice9* p_device;
	//頂点管理クラス
	ManageVertex m_Vertex;
	//テクスチャの管理
	ManegeTexturePointer m_TexturePointer();
public:
	//コンストラクタ　デバイスを渡して初期化
	Render(IDirect3DDevice9* device){ p_device = device;};
	//デストラクタ
	~Render(){};
	//アルファブレンディングのとテクスチャブレンディングの設定
	void SetRenderState();
	//画面のクリア　描画の設定　頂点の宣言
	void RenderStart();
	//描画の終了　描画の表示
	void RenderEnd();
	//矩形の描画
	void DrawBox(CUSTOMVERTEX4 Vertex, LPDIRECT3DTEXTURE9 p_texture,float x,float y);
	//矩形の描画
	void DrawBox(AnimeVertex AnimeVertex,int koma, LPDIRECT3DTEXTURE9 p_texture, float x, float y);
	//拡大縮小できる矩形の描画
	void DrawCustomBox(
		CUSTOMVERTEX4 Vertex,
		LPDIRECT3DTEXTURE9 p_texture,
		float x,
		float y,
		FLOAT ScaleFactor);
	//座標の中央に矩形の描画
	void DrawCenterBox(
		CUSTOMVERTEX4 Vertex,
		LPDIRECT3DTEXTURE9 p_texture,
		float x,
		float y);
};