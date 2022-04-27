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

	// ソフトサウンドハンドルからサウンドハンドルを作成( もう一度ファイルから読み込んでも同じです )
	SoundHandle = LoadSoundMemFromSoftSound(SoftSoundHandle);

	PlaySoundMem(SoundHandle, DX_PLAYTYPE_LOOP);
}

void SoundWave::Update()
{
	// 現在の再生位置を取得
	SamplePos = GetCurrentPositionSoundMem(SoundHandle);

	// 現在の再生位置から 4096 サンプルを使用して周波数分布を得る
	GetFFTVibrationSoftSound(SoftSoundHandle, -1, SamplePos, 4096, ParamList, BUFFERLENGTH);
	ChangeVolumeSoundMem(50, SoundHandle);
}

void SoundWave::Draw()
{
	// 周波数分布を画面に描画する
	for (int i = 0; i < 80; i++)
	{
		float Param;

		// 関数から取得できる値を描画に適した値に調整
		Param = pow(ParamList[i], 0.5f) * 4.0f;

		// 縦線を描画
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

		// 縦線を描画
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