//-----------------------------------------------------
//	DirectShowによる音声ファイル再生サンプル
//	2010.01.05 TMO
//-----------------------------------------------------

#include <dshow.h>

class CSound
{
	IGraphBuilder	*pGraphBuilder;
	IMediaControl	*pMediaControl;		//ファイルの読み込み、再生停止などを行う。
	IMediaPosition	*pMediaPosition;	//再生位置を指定するのに使う。
	
	bool isPlay;
	bool isRoopMode;

public:
	CSound()
	{
		pGraphBuilder = NULL;
		pMediaControl = NULL;
		pMediaPosition = NULL;

		isPlay = false;
		isRoopMode = false;
	}
	~CSound() { Release(); }

	//ファイルの読み込み
	void LoadFile( BSTR file );
	
	//再生 or 一時停止からの再開
	void Play();
	bool ChkEnd();
	
	//ループ再生
	void PlayRoop();
	void ChkRoop();

	//再生中の場合でも先頭に戻して再生し直す
	void PlayFromStart();

	//一時停止
	void Pause();

	//停止
	void Stop();

	//ボリュームダウン&アップ
	void VolChange(int _vol);


	//リソース解放
	void Release();
};