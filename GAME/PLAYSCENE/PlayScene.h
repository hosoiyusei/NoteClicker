/*
プレイシーン
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

	// コンストラクタ
	PlayScene();

	// デストラクタ
	~PlayScene();

	// 初期化
	void Initialize() override;

	// 更新
	GAME_SCENE Update() override;

	// 描画
	void Draw() override;

	// 終了処理
	void Finalize() override;
};