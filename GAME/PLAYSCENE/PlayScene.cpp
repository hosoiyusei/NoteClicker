/*
プレイシーン
*/
#include "PlayScene.h"
#include"../Framework/ResourceManager.h"
#include"Click/Click.h"
#include"CountUpManager/CountUpManager.h"
#include"Save/Save.h"
#include"SoundWave/SoundWave.h"

#include "../GameMain.h"

/*--------------------------------------------------
コンストラクタ
--------------------------------------------------*/
PlayScene::PlayScene()
	:mpClick(nullptr)
	, mpCountUpManager(nullptr)
	,mpSaveData(nullptr)
	,mpSoundWave(nullptr)
{
}

/*--------------------------------------------------
デストラクタ
--------------------------------------------------*/
PlayScene::~PlayScene()
{
}

/*--------------------------------------------------
初期化
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
更新
戻り値	:次のシーン番号
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
描画
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
終了処理
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
