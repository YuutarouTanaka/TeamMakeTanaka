//-----------------------------------------------------
//	DirectShowによる音声ファイル再生サンプル
//	2010.01.05 TMO
//-----------------------------------------------------
#include "DirectShowSound.h"

#pragma comment(lib,"strmiids.lib") 

//ファイルの読み込み
void CSound::LoadFile( BSTR file )
{
	CoInitialize(NULL);
	CoCreateInstance( CLSID_FilterGraph, NULL, CLSCTX_INPROC, IID_IGraphBuilder, (LPVOID *)&pGraphBuilder);
	
	pGraphBuilder->QueryInterface(IID_IMediaControl, (LPVOID *)&pMediaControl );
	pGraphBuilder->QueryInterface(IID_IMediaPosition, (LPVOID *)&pMediaPosition );
	
	pMediaControl->RenderFile( file );
}

//再生
void CSound::Play() {

	pMediaControl->Run();
	isPlay = true;
	isRoopMode = false;
}

bool CSound::ChkEnd() {
	if ( !isPlay ) return false;

	REFTIME pos, end;
	pMediaPosition->get_CurrentPosition(&pos);
	pMediaPosition->get_StopTime(&end);
	return pos >= end;	
}

//ループ再生
void CSound::PlayRoop()
{
	pMediaControl->Run();
	isPlay = true;
	isRoopMode = true;
}

void CSound::ChkRoop()
{
	if ( !isPlay || !isRoopMode ) {return;}
	
	REFTIME pos, end;
	pMediaPosition->get_CurrentPosition(&pos);
	pMediaPosition->get_StopTime(&end);
	if ( pos >= end ){	
		
		//この方法で戻すと開始が少し途切れてしまった
		//pMediaPosition->put_CurrentPosition(0);
		//pMediaControl->Run();
		
		//そこでいったん止めてから再生する
		Stop();
		PlayRoop();
	}
}

//再生中の場合でも先頭に戻して再生し直す
void CSound::PlayFromStart()
{
	pMediaPosition->put_CurrentPosition(0);
	pMediaControl->Run();
	
	isPlay = true;
}

//一時停止
void CSound::Pause() {
	pMediaControl->Pause();
	
	isPlay = false;
}

//停止
void CSound::Stop()
{
	pMediaControl->Stop();
	//Stop()でも再生位置が先頭に戻らないので、自分で戻す
	pMediaPosition->put_CurrentPosition(0);
	
	isPlay = false;
}

//ボリュームダウン&アップ
void CSound::VolChange(int _vol)
{
	IBasicAudio *pBasicAudio;
	pGraphBuilder->QueryInterface(IID_IBasicAudio, (LPVOID *)&pBasicAudio);

	long vol = 0;
	pBasicAudio->get_Volume(&vol);
	vol += _vol;
	if (vol < -5000) {
		vol = -5000;
	}
	if (vol > 0) {
		vol = 0;
	}
	pBasicAudio->put_Volume(vol);

	pBasicAudio->Release();
}

//リソース解放
void CSound::Release()
{
	if ( pMediaPosition ) {
		pMediaPosition->Release();
		pMediaPosition = NULL;
	}

	if ( pMediaControl ) {
		pMediaControl->Release();
		pMediaControl = NULL;
	}
	
	if ( pGraphBuilder ) {
		pGraphBuilder->Release();
		pGraphBuilder = NULL;

		CoUninitialize();
	}
}