#include "main.h"
#include "Reader.h"
void Render::SetRenderState()
{
	p_device->SetRenderState							//SetRenderState：色々描画設定できる
		(D3DRS_ALPHABLENDENABLE, true);					//ピクセルごとのアルファ テストを有効にする
	p_device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	//D3DRS_SRCBLEND  D3DBLEND 列挙型のいずれかのメンバーです
	//D3DBLEND_SRCALPHA//	ブレンディング係数は(As, As, As, As) なる。
	p_device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	//D3DRS_SRCBLEND  D3DBLEND 列挙型のいずれかのメンバーです
	//ブレンディング係数は(1 - Rs, 1 - Gs, 1 - Bs, 1 - As) となる
	p_device->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1);
	//ライティング計算に使われるディフューズ色のソース
	//D3DMCS_COLOR1:ディフューズ頂点色を使う。


	p_device->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE); //テクスチャブレンディング
	//D3DTSS_COLORARG1:テクスチャ ステージ ステートは、そのステージに対する最初の色引数であり、
	//D3DTA のいずれかにより示される。デフォルトの引数は D3DTA_TEXTURE である。


	p_device->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
	//D3DTSS_COLORARG2:テクスチャ ステージ ステートは、そのステージに対する 2 番目の色引数であり、
	//D3DTA_DIFFUSE:テクスチャ引数フラグにより識別される。デフォルト引数は D3DTA_CURRENT である。
	//グーロー シェーディング処理中に頂点成分から補間して得られたディフューズ カラー
	p_device->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	//D3DTSS_COLOROP:このテクスチャーステートはＤ３ＤＴＡで認識されるステージの2番目のＡ因数です
	//D3DTOP_MODULATE:因数の成分を乗算する

	//透明度の設定
	p_device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	p_device->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	p_device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
}
void Render::RenderStart()
{
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)
	p_device->Clear(									//画面のクリア
		0,												//stencilステンシルバッファをクリアする
		NULL,                                           // Targetレンタリング先をクリア
		D3DCLEAR_TARGET,								//Targetレンタリング先をクリア
		D3DCOLOR_XRGB(0x00, 0x00, 0x00),				//ZBUffer深度バッファをクリア
		1.0,											//？？？
		0												//？？？
		);
	p_device->BeginScene();							//描画の設定

	p_device->SetFVF(									//固定頂点機能の宣言を取得
		D3DFVF_CUSTOMVERTEX);
}
void Render::RenderEnd()
{
	p_device->EndScene();								//描画の終了


	p_device ->Present(NULL, NULL, NULL, NULL);			//描画の表示(pSouseRect, pDestRect,hDestWindowOverride)
	//pSouseRect:転送先の矩形領域をあらわすRECT構造体へのポインタ
	//hDestWindowOverride:転送先のウィンドウのハンドル
	//pDirtyRegion:ＮＵＬＬ
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
	p_device->DrawPrimitiveUP(							//実際に描画してる関数　(引数4個)
		D3DPT_TRIANGLEFAN,								//頂点をどうつなげるかの設定
		2,												//面の数
		TEMP.CUSTOMVERTEX,										//頂点ストリーム0に使うための頂点データユーザーメモリポインタ
													//（頂点を入れた所をポインタでしてい）10
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
	p_device->DrawPrimitiveUP(							//実際に描画してる関数　(引数4個)
		D3DPT_TRIANGLEFAN,								//頂点をどうつなげるかの設定
		2,												//面の数
		TEMP.CUSTOMVERTEX,										//頂点ストリーム0に使うための頂点データユーザーメモリポインタ
		//（頂点を入れた所をポインタでしてい）10
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
	p_device->DrawPrimitiveUP(							//実際に描画してる関数　(引数4個)
		D3DPT_TRIANGLEFAN,								//頂点をどうつなげるかの設定
		2,												//面の数
		TEMP.CUSTOMVERTEX,										//頂点ストリーム0に使うための頂点データユーザーメモリポインタ
		//（頂点を入れた所をポインタでしてい）10
		sizeof(CUSTOMVERTEX));
}