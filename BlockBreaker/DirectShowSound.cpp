//-----------------------------------------------------
//	DirectShow�ɂ�鉹���t�@�C���Đ��T���v��
//	2010.01.05 TMO
//-----------------------------------------------------
#include "DirectShowSound.h"

#pragma comment(lib,"strmiids.lib") 

//�t�@�C���̓ǂݍ���
void CSound::LoadFile( BSTR file )
{
	CoInitialize(NULL);
	CoCreateInstance( CLSID_FilterGraph, NULL, CLSCTX_INPROC, IID_IGraphBuilder, (LPVOID *)&pGraphBuilder);
	
	pGraphBuilder->QueryInterface(IID_IMediaControl, (LPVOID *)&pMediaControl );
	pGraphBuilder->QueryInterface(IID_IMediaPosition, (LPVOID *)&pMediaPosition );
	
	pMediaControl->RenderFile( file );
}

//�Đ�
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

//���[�v�Đ�
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
		
		//���̕��@�Ŗ߂��ƊJ�n�������r�؂�Ă��܂���
		//pMediaPosition->put_CurrentPosition(0);
		//pMediaControl->Run();
		
		//�����ł�������~�߂Ă���Đ�����
		Stop();
		PlayRoop();
	}
}

//�Đ����̏ꍇ�ł��擪�ɖ߂��čĐ�������
void CSound::PlayFromStart()
{
	pMediaPosition->put_CurrentPosition(0);
	pMediaControl->Run();
	
	isPlay = true;
}

//�ꎞ��~
void CSound::Pause() {
	pMediaControl->Pause();
	
	isPlay = false;
}

//��~
void CSound::Stop()
{
	pMediaControl->Stop();
	//Stop()�ł��Đ��ʒu���擪�ɖ߂�Ȃ��̂ŁA�����Ŗ߂�
	pMediaPosition->put_CurrentPosition(0);
	
	isPlay = false;
}

//�{�����[���_�E��&�A�b�v
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

//���\�[�X���
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