/*
�^�C�g���V�[��
*/
#include "TitleScene.h"

#include "../GameMain.h"
#include"../Framework/ResourceManager.h"
#include"../Effect/Effect.h"

/*--------------------------------------------------
�R���X�g���N�^
--------------------------------------------------*/
TitleScene::TitleScene()
	:mTest(0)
	,mpEffect(nullptr)
{
}

/*--------------------------------------------------
�f�X�g���N�^
--------------------------------------------------*/
TitleScene::~TitleScene()
{
}

/*--------------------------------------------------
������
--------------------------------------------------*/
void TitleScene::Initialize()
{
	ResourceManager* pRm = ResourceManager::GetInstance();

	mTest = pRm->GetResource("TridentLogo.png", TYPE::Textures);

	mpEffect = new Effect();
	mpEffect->Initialize();
}

/*--------------------------------------------------
�X�V
�߂�l	:���̃V�[���ԍ�
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
�`��
--------------------------------------------------*/
void TitleScene::Draw()
{
	DrawString(0, 0, "TitleScene", GetColor(100, 255, 100));
	DrawString(0, 20, "Input ZKey", GetColor(255, 0, 0));

	if (mpEffect != nullptr)
		mpEffect->Draw();

	DrawRectRotaGraph(
		SCREEN_CENTER_X,//X�̈ʒu
		SCREEN_CENTER_Y,//Y�̈ʒu
		0,//�؂���J�n�̈ʒu
		0,//�؂���J�n�̈ʒu
		2500,//�؂���I���̈ʒu
		1500,//�؂���I���̈ʒu
		0.655,//�g��
		0.0,//��]
		mTest,//�A�h���X
		TRUE
	);
}

/*--------------------------------------------------
�I������
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
