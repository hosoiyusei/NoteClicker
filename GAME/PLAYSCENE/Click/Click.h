#pragma once
#include"../Collision/Collision.h"

class CountUpManager;
class SaveData;

class Click
{
private:

	int mImage;

	int mNoteImage[5];

	int mMousePos_X;
	int mMousePos_Y;

	int mClickTime, mClickTime2, mClickTime3, mClickTime4, mClickTime5, mClickTime6, mClickTime7;

	int mLevel, mLevel2, mLevel3, mLevel4, mLevel5, mLevel6;

	int mNoteCount;

	int mSize1;
	float mSize2;

	int mClickUpCount;

	int mUpScore,mUpScore2,mUpScore3, mUpScore4, mUpScore5, mUpScore6;

	int mCountUpTime, mCountUpTime2, mCountUpTime3, mCountUpTime4, mCountUpTime5;

	CircleCollider mCircleCollider, mCircleCollider2, mCircleCollider3, mCircleCollider4, mCircleCollider5, mCircleCollider6, mCircleCollider7, mCircleCollider8;

	CountUpManager* mpCountUpManager;

	SaveData* mpSaveData;

public:

	Click();
	~Click();

	void Initialize(CountUpManager* pCountUpManager,SaveData* pSaveData);

	void Update();

	void Draw();

	void Finalize();

	void DrawNotes();

private:

	void ClickEvent_1();

	void ClickEvent_2();

	void ClickEvent_3();

	void ClickEvent_4();

	void ClickEvent_5();

	void ClickEvent_6();

	void Save();
};