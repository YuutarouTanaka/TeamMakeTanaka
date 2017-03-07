//-----------------------------------------------------
//	DirectShow�ɂ�鉹���t�@�C���Đ��T���v��
//	2010.01.05 TMO
//-----------------------------------------------------

#include <dshow.h>

class CSound
{
	IGraphBuilder	*pGraphBuilder;
	IMediaControl	*pMediaControl;		//�t�@�C���̓ǂݍ��݁A�Đ���~�Ȃǂ��s���B
	IMediaPosition	*pMediaPosition;	//�Đ��ʒu���w�肷��̂Ɏg���B
	
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

	//�t�@�C���̓ǂݍ���
	void LoadFile( BSTR file );
	
	//�Đ� or �ꎞ��~����̍ĊJ
	void Play();
	bool ChkEnd();
	
	//���[�v�Đ�
	void PlayRoop();
	void ChkRoop();

	//�Đ����̏ꍇ�ł��擪�ɖ߂��čĐ�������
	void PlayFromStart();

	//�ꎞ��~
	void Pause();

	//��~
	void Stop();

	//�{�����[���_�E��&�A�b�v
	void VolChange(int _vol);


	//���\�[�X���
	void Release();
};