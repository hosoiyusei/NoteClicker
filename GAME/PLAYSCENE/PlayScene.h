/*
�v���C�V�[��
*/
#pragma once

#include "../IScene.h"

class Click;
class CountUpManager;
class SaveData;
class SoundWave;

class PlayScene : public IScene
{
private:

	Click* mpClick;

	CountUpManager* mpCountUpManager;

	SaveData* mpSaveData;

	SoundWave* mpSoundWave;

public:

	// �R���X�g���N�^
	PlayScene();

	// �f�X�g���N�^
	~PlayScene();

	// ������
	void Initialize() override;

	// �X�V
	GAME_SCENE Update() override;

	// �`��
	void Draw() override;

	// �I������
	void Finalize() override;
};