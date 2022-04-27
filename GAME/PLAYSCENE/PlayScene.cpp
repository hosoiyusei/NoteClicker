/*
�v���C�V�[��
*/
#include "PlayScene.h"
#include"../Framework/ResourceManager.h"
#include"Click/Click.h"
#include"CountUpManager/CountUpManager.h"
#include"Save/Save.h"
#include"SoundWave/SoundWave.h"

#include "../GameMain.h"

/*--------------------------------------------------
�R���X�g���N�^
--------------------------------------------------*/
PlayScene::PlayScene()
	:mpClick(nullptr)
	, mpCountUpManager(nullptr)
	,mpSaveData(nullptr)
	,mpSoundWave(nullptr)
{
}

/*--------------------------------------------------
�f�X�g���N�^
--------------------------------------------------*/
PlayScene::~PlayScene()
{
}

/*--------------------------------------------------
������
--------------------------------------------------*/
void PlayScene::Initialize()
{
	mpClick = new Click();
	mpCountUpManager = new CountUpManager();
	mpSaveData = new SaveData();
	mpSoundWave = new SoundWave();

	if (mpClick != nullptr)
		mpClick->Initialize(mpCountUpManager,mpSaveData);

	if (mpCountUpManager != nullptr)
		mpCountUpManager->Initialize();

	if (mpSoundWave != nullptr)
		mpSoundWave->Initialize();
}

/*--------------------------------------------------
�X�V
�߂�l	:���̃V�[���ԍ�
--------------------------------------------------*/
GAME_SCENE PlayScene::Update()
{
	if (mpClick != nullptr)
		mpClick->Update();
	if (mpCountUpManager != nullptr)
		mpCountUpManager->Update();
	if (mpSoundWave != nullptr)
		mpSoundWave->Update();

	/*if (IsButtonPressed(PAD_INPUT_1))
	{
		return GAME_SCENE::RESULT;
	}*/

	return GAME_SCENE::NONE;
}

/*--------------------------------------------------
�`��
--------------------------------------------------*/
void PlayScene::Draw()
{
	DrawString(0, 0, "PlayScene", GetColor(100, 255, 100));
	DrawString(0, 20, "Input ZKey", GetColor(0, 255, 0));

	DrawBox(0, 0, SCREEN_RIGHT, SCREEN_BOTTOM, GetColor(255, 255, 255), TRUE);

	
	if (mpSoundWave != nullptr)
		mpSoundWave->Draw();
	if (mpClick != nullptr)
		mpClick->Draw();
	if (mpCountUpManager != nullptr)
		mpCountUpManager->Draw();
}

/*--------------------------------------------------
�I������
--------------------------------------------------*/
void PlayScene::Finalize()
{
	if (mpClick != nullptr)
		mpClick->Finalize();
	delete mpClick;
	if (mpCountUpManager != nullptr)
		mpCountUpManager->Finalize();
	delete mpCountUpManager;
	if (mpSoundWave != nullptr)
		mpSoundWave->Finalize();
}
