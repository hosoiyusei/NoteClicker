/*
タイトルシーン
*/
#include "TitleScene.h"

#include "../GameMain.h"
#include"../Framework/ResourceManager.h"
#include"../Effect/Effect.h"

/*--------------------------------------------------
コンストラクタ
--------------------------------------------------*/
TitleScene::TitleScene()
	:mTest(0)
	,mpEffect(nullptr)
{
}

/*--------------------------------------------------
デストラクタ
--------------------------------------------------*/
TitleScene::~TitleScene()
{
}

/*--------------------------------------------------
初期化
--------------------------------------------------*/
void TitleScene::Initialize()
{
	ResourceManager* pRm = ResourceManager::GetInstance();

	mTest = pRm->GetResource("TridentLogo.png", TYPE::Textures);

	mpEffect = new Effect();
	mpEffect->Initialize();
}

/*--------------------------------------------------
更新
戻り値	:次のシーン番号
--------------------------------------------------*/
GAME_SCENE TitleScene::Update()
{
	if (mpEffect != nullptr)
		mpEffect->Update();

	if (IsButtonPressed(PAD_INPUT_10) == TRUE)
	{
		mpEffect->Play(SCREEN_CENTER_X+100, SCREEN_CENTER_Y+100, EFFECT_NUM::EFFECT_1);
	}

	if (IsButtonPressed(PAD_INPUT_1))
	{
		return GAME_SCENE::PLAY;
	}

	return GAME_SCENE::NONE;
}

/*--------------------------------------------------
描画
--------------------------------------------------*/
void TitleScene::Draw()
{
	DrawString(0, 0, "TitleScene", GetColor(100, 255, 100));
	DrawString(0, 20, "Input ZKey", GetColor(255, 0, 0));

	if (mpEffect != nullptr)
		mpEffect->Draw();

	DrawRectRotaGraph(
		SCREEN_CENTER_X,//Xの位置
		SCREEN_CENTER_Y,//Yの位置
		0,//切り取り開始の位置
		0,//切り取り開始の位置
		2500,//切り取り終わりの位置
		1500,//切り取り終わりの位置
		0.655,//拡大
		0.0,//回転
		mTest,//アドレス
		TRUE
	);
}

/*--------------------------------------------------
終了処理
--------------------------------------------------*/
void TitleScene::Finalize()
{
	if (mpEffect != nullptr)
	{
		mpEffect->Finalize();
		delete mpEffect;
		mpEffect = nullptr;
	}

	ResourceManager* pRm = ResourceManager::GetInstance();
	pRm->DeleteResource();
}
