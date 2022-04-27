#include"SoundWave.h"
#include"../../Framework/ResourceManager.h"

SoundWave::SoundWave()
	:SoundHandle(0)
	,SoftSoundHandle(0)
{

}

SoundWave::~SoundWave()
{

}

void SoundWave::Initialize()
{
	ResourceManager* pRm = ResourceManager::GetInstance();

	SoftSoundHandle = pRm->GetResource("BGM.mp3", TYPE::Audio);

	// �\�t�g�T�E���h�n���h������T�E���h�n���h�����쐬( ������x�t�@�C������ǂݍ���ł������ł� )
	SoundHandle = LoadSoundMemFromSoftSound(SoftSoundHandle);

	PlaySoundMem(SoundHandle, DX_PLAYTYPE_LOOP);
}

void SoundWave::Update()
{
	// ���݂̍Đ��ʒu���擾
	SamplePos = GetCurrentPositionSoundMem(SoundHandle);

	// ���݂̍Đ��ʒu���� 4096 �T���v�����g�p���Ď��g�����z�𓾂�
	GetFFTVibrationSoftSound(SoftSoundHandle, -1, SamplePos, 4096, ParamList, BUFFERLENGTH);
	ChangeVolumeSoundMem(50, SoundHandle);
}

void SoundWave::Draw()
{
	// ���g�����z����ʂɕ`�悷��
	for (int i = 0; i < 80; i++)
	{
		float Param;

		// �֐�����擾�ł���l��`��ɓK�����l�ɒ���
		Param = pow(ParamList[i], 0.5f) * 4.0f;

		// �c����`��
		DrawBox(
			i * 3,
			240 - (int)(Param * 200),
			i * 3 + 3,
			240,
			GetColor(0, 0, 0), FALSE);

		DrawBox(
			i * 3,
			240 + (int)(Param * 200),
			i * 3 + 3,
			241,
			GetColor(0, 0, 0), FALSE);

		// �c����`��
		DrawBox(
			640+i * -3,
			240 - (int)(Param * 200),
			640+i * -3 - 3,
			240,
			GetColor(0, 0, 0), FALSE);

		DrawBox(
			640 + i * -3,
			240 + (int)(Param * 200),
			640 + i * -3 - 3,
			242,
			GetColor(0, 0, 0), FALSE);
	}
}

void SoundWave::Finalize()
{
	StopSoundMem(SoundHandle);
	ResourceManager* pRm = ResourceManager::GetInstance();
	pRm->DeleteResource();
}