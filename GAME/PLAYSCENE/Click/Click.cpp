#include"Click.h"

#include"../../GameMain.h"
#include"../../Framework/ResourceManager.h"
#include<random>
#include"../CountUpManager/CountUpManager.h"
#include"../Save/Save.h"

Click::Click()
	:mImage(0)
	, mMousePos_X(0)
	, mMousePos_Y(0)
	, mClickTime(0)
	, mNoteCount(0)
	, mCircleCollider()
	, mCircleCollider2()
	, mCircleCollider3()
	, mCircleCollider4()
	, mCircleCollider5()
	, mCircleCollider6()
	, mCircleCollider7()
	, mCircleCollider8()
	, mSize1(100)
	, mSize2(0.7)
	, mNoteImage{}
	, mClickUpCount(1)
	, mClickTime2(0)
	, mClickTime3(0)
	, mClickTime4(0)
	, mClickTime5(0)
	, mClickTime6(0)
	, mClickTime7(0)
	, mLevel(1)
	, mLevel2(0)
	,mLevel3(0)
	, mLevel4(0)
	, mLevel5(0)
	, mLevel6(0)
	, mUpScore(10)
	, mUpScore2(50)
	,mUpScore3(100)
	, mUpScore4(300)
	, mUpScore5(3000)
	, mUpScore6(10000)
	, mCountUpTime(0)
	, mCountUpTime2(0)
	, mCountUpTime3(0)
	, mCountUpTime4(0)
	, mCountUpTime5(0)
{

}

Click::~Click()
{

}

void Click::Initialize(CountUpManager* pCountUpManager,SaveData* pSaveData)
{
	mpCountUpManager = pCountUpManager;
	mpSaveData = pSaveData;

	if (mpSaveData->Road(13)==1)
	{
		mNoteCount = mpSaveData->Road(0);
		mLevel = mpSaveData->Road(1);
		mLevel2 = mpSaveData->Road(2);
		mLevel3 = mpSaveData->Road(3);
		mLevel4 = mpSaveData->Road(4);
		mLevel5 = mpSaveData->Road(5);
		mLevel6 = mpSaveData->Road(6);
		mUpScore = mpSaveData->Road(7);
		mUpScore2 = mpSaveData->Road(8);
		mUpScore3 = mpSaveData->Road(9);
		mUpScore4 = mpSaveData->Road(10);
		mUpScore5 = mpSaveData->Road(11);
		mUpScore6 = mpSaveData->Road(12);
	}
	
	ResourceManager* pRm = ResourceManager::GetInstance();

	mImage = pRm->GetResource("Note.png", TYPE::Textures);

	mNoteImage[0]= pRm->GetResource("Note1.png", TYPE::Textures);
	mNoteImage[1] = pRm->GetResource("Note2.png", TYPE::Textures);
	mNoteImage[2] = pRm->GetResource("Note3.png", TYPE::Textures);
	mNoteImage[3] = pRm->GetResource("Note4.png", TYPE::Textures);
	mNoteImage[4] = pRm->GetResource("Note5.png", TYPE::Textures);

	mCircleCollider2.mPos.mX = SCREEN_CENTER_X;
	mCircleCollider2.mPos.mY = SCREEN_CENTER_Y;
	mCircleCollider2.mRadius = 100;

	mCircleCollider3.mPos.mX = 70;
	mCircleCollider3.mPos.mY = 400;
	mCircleCollider3.mRadius = 30.0f;

	mCircleCollider4.mPos.mX = 170;
	mCircleCollider4.mPos.mY = 400;
	mCircleCollider4.mRadius = 30.0f;

	mCircleCollider5.mPos.mX = 270;
	mCircleCollider5.mPos.mY = 400;
	mCircleCollider5.mRadius = 30.0f;

	mCircleCollider6.mPos.mX = 370;
	mCircleCollider6.mPos.mY = 400;
	mCircleCollider6.mRadius = 30.0f;

	mCircleCollider7.mPos.mX = 470;
	mCircleCollider7.mPos.mY = 400;
	mCircleCollider7.mRadius = 30.0f;

	mCircleCollider8.mPos.mX = 570;
	mCircleCollider8.mPos.mY = 400;
	mCircleCollider8.mRadius = 30.0f;
}

void Click::Update()
{
	GetMousePoint(&mMousePos_X, &mMousePos_Y);

	if (mCircleCollider.CheckHit(mCircleCollider2) == true)
	{
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			if (mClickTime != 2)
			{
				mClickTime++;
				if (mSize1 != 95)
					mSize1 = 95;
				if (mSize2 != 0.65)
					mSize2 = 0.65;
			}
			else
			{
				if (mSize1 != 105)
					mSize1 += 1;
				if (mSize2 <= 0.75)
					mSize2 += 0.01;
			}
		}
		else
		{
			mClickTime = 0;
			if (mSize1 != 105)
				mSize1 += 1;
			if (mSize2 <= 0.75)
				mSize2 += 0.01;
		}
	}
	else
	{
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			mClickTime = 2;
		}
		else
		{
			mClickTime = 0;
		}
		if (mSize1 >= 100)
			mSize1 -= 1;
		if (mSize1 <= 100)
			mSize1 += 1;
		if(mSize2>=0.7)
			mSize2 -= 0.01;
		if (mSize2 <= 0.7)
			mSize2 += 0.01;
	}


	if (mClickTime == 1)
	{
		mNoteCount += mClickUpCount;
		std::mt19937 mt{ std::random_device{}() };
		std::uniform_int_distribution<int> dist(-10, 10);
		mpCountUpManager->Spain(mMousePos_X + dist(mt), mMousePos_Y, mClickUpCount);
	}

	ClickEvent_1();
	ClickEvent_2();
	ClickEvent_3();
	ClickEvent_4();
	ClickEvent_5();
	ClickEvent_6();

	Save();

	if (mNoteCount > 9999999999)
		mNoteCount = 9999999999;

	mCircleCollider.mPos.mX = mMousePos_X;
	mCircleCollider.mPos.mY = mMousePos_Y;
	mCircleCollider.mRadius = 1;
}

void Click::Draw()
{
	DrawCircle(SCREEN_CENTER_X, SCREEN_CENTER_Y, mSize1, GetColor(255, 255, 255), TRUE);
	DrawRectRotaGraph(
		SCREEN_CENTER_X,//Xの位置
		SCREEN_CENTER_Y,//Yの位置
		0,//切り取り開始の位置
		0,//切り取り開始の位置
		2500,//切り取り終わりの位置
		1500,//切り取り終わりの位置
		mSize2,//拡大
		0.0,//回転
		mImage,//アドレス
		TRUE
	);

	DrawCircle(SCREEN_CENTER_X, SCREEN_CENTER_Y, mSize1, GetColor(0, 0, 0), FALSE);

	SetFontSize(30);
	DrawFormatString(SCREEN_CENTER_X, 0, GetColor(0, 0, 0), "%d",mNoteCount);
	SetFontSize(16);

	DrawNotes();

	DrawRectRotaGraph(
		mMousePos_X,//Xの位置
		mMousePos_Y,//Yの位置
		0,//切り取り開始の位置
		0,//切り取り開始の位置
		2500,//切り取り終わりの位置
		1500,//切り取り終わりの位置
		0.1,//拡大
		0.0,//回転
		mImage,//アドレス
		TRUE
	);
}

void Click::Finalize()
{

}

void Click::DrawNotes()
{
	DrawRectRotaGraph(
		70,//Xの位置
		400,//Yの位置
		0,//切り取り開始の位置
		0,//切り取り開始の位置
		2500,//切り取り終わりの位置
		1500,//切り取り終わりの位置
		0.2,//拡大
		0.0,//回転
		mImage,//アドレス
		TRUE
	);
	DrawRectRotaGraph(
		170,//Xの位置
		400,//Yの位置
		0,//切り取り開始の位置
		0,//切り取り開始の位置
		2500,//切り取り終わりの位置
		1500,//切り取り終わりの位置
		0.18,//拡大
		0.0,//回転
		mNoteImage[0],//アドレス
		TRUE
	);
	DrawRectRotaGraph(
		270,//Xの位置
		400,//Yの位置
		0,//切り取り開始の位置
		0,//切り取り開始の位置
		2500,//切り取り終わりの位置
		1500,//切り取り終わりの位置
		0.12,//拡大
		0.0,//回転
		mNoteImage[1],//アドレス
		TRUE
	);
	DrawRectRotaGraph(
		370,//Xの位置
		400,//Yの位置
		0,//切り取り開始の位置
		0,//切り取り開始の位置
		2500,//切り取り終わりの位置
		1500,//切り取り終わりの位置
		0.1,//拡大
		0.0,//回転
		mNoteImage[2],//アドレス
		TRUE
	);
	DrawRectRotaGraph(
		470,//Xの位置
		400,//Yの位置
		0,//切り取り開始の位置
		0,//切り取り開始の位置
		2500,//切り取り終わりの位置
		1500,//切り取り終わりの位置
		0.17,//拡大
		0.0,//回転
		mNoteImage[3],//アドレス
		TRUE
	);
	DrawRectRotaGraph(
		570,//Xの位置
		400,//Yの位置
		0,//切り取り開始の位置
		0,//切り取り開始の位置
		2500,//切り取り終わりの位置
		1500,//切り取り終わりの位置
		0.05,//拡大
		0.0,//回転
		mNoteImage[4],//アドレス
		TRUE
	);

	DrawFormatString(70 - 20, 350, GetColor(0, 0, 0), "Lv:%d", mLevel);
	DrawFormatString(70 - 10, 430, GetColor(0, 0, 0), "%d", mLevel * mUpScore);

	DrawFormatString(170 - 20, 350, GetColor(0, 0, 0), "Lv:%d", mLevel2);
	if(mLevel2!=0)
	DrawFormatString(170 - 10, 430, GetColor(0, 0, 0), "%d", mLevel2 * mUpScore2);
	if(mLevel2==0)
		DrawFormatString(170 - 10, 430, GetColor(0, 0, 0), "%d", mUpScore2);

	DrawFormatString(270 - 20, 350, GetColor(0, 0, 0), "Lv:%d", mLevel3);
	if (mLevel3 != 0)
		DrawFormatString(270 - 10, 430, GetColor(0, 0, 0), "%d", mLevel3 * mUpScore3);
	if (mLevel3 == 0)
		DrawFormatString(270 - 10, 430, GetColor(0, 0, 0), "%d", mUpScore3);

	DrawFormatString(370 - 20, 350, GetColor(0, 0, 0), "Lv:%d", mLevel4);
	if (mLevel4 != 0)
		DrawFormatString(370 - 10, 430, GetColor(0, 0, 0), "%d", mLevel4 * mUpScore4);
	if (mLevel4 == 0)
		DrawFormatString(370 - 10, 430, GetColor(0, 0, 0), "%d", mUpScore4);

	DrawFormatString(470 - 20, 350, GetColor(0, 0, 0), "Lv:%d", mLevel5);
	if (mLevel5 != 0)
		DrawFormatString(470 - 10, 430, GetColor(0, 0, 0), "%d", mLevel5 * mUpScore5);
	if (mLevel5 == 0)
		DrawFormatString(470 - 10, 430, GetColor(0, 0, 0), "%d", mUpScore5);

	DrawFormatString(570 - 20, 350, GetColor(0, 0, 0), "Lv:%d", mLevel6);
	if (mLevel6 != 0)
		DrawFormatString(570 - 10, 430, GetColor(0, 0, 0), "%d", mLevel6 * mUpScore6);
	if (mLevel6 == 0)
		DrawFormatString(570 - 10, 430, GetColor(0, 0, 0), "%d", mUpScore6);

	DrawCircle(70, 400, 30, GetColor(0, 0, 0), FALSE);
	DrawCircle(170, 400, 30, GetColor(0, 0, 0), FALSE);
	DrawCircle(270, 400, 30, GetColor(0, 0, 0), FALSE);
	DrawCircle(370, 400, 30, GetColor(0, 0, 0), FALSE);
	DrawCircle(470, 400, 30, GetColor(0, 0, 0), FALSE);
	DrawCircle(570, 400, 30, GetColor(0, 0, 0), FALSE);


	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	if (mLevel * mUpScore > mNoteCount)
		DrawCircle(70, 400, 30, GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_GRAPH_BLEND_NORMAL, 0);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	if (mLevel2 * mUpScore2 > mNoteCount)
		DrawCircle(170, 400, 30, GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	if(mLevel2==0&&mNoteCount< mUpScore2)
		DrawCircle(170, 400, 30, GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_GRAPH_BLEND_NORMAL, 0);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	if (mLevel3 * mUpScore3 > mNoteCount)
		DrawCircle(270, 400, 30, GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	if (mLevel3 == 0 && mNoteCount < mUpScore3)
		DrawCircle(270, 400, 30, GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_GRAPH_BLEND_NORMAL, 0);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	if (mLevel4 * mUpScore4 > mNoteCount)
		DrawCircle(370, 400, 30, GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	if (mLevel4 == 0 && mNoteCount < mUpScore4)
		DrawCircle(370, 400, 30, GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_GRAPH_BLEND_NORMAL, 0);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	if (mLevel5 * mUpScore5 > mNoteCount)
		DrawCircle(470, 400, 30, GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	if (mLevel5 == 0 && mNoteCount < mUpScore5)
		DrawCircle(470, 400, 30, GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_GRAPH_BLEND_NORMAL, 0);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	if (mLevel6 * mUpScore6 > mNoteCount)
		DrawCircle(570, 400, 30, GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	if (mLevel6 == 0 && mNoteCount < mUpScore6)
		DrawCircle(570, 400, 30, GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_GRAPH_BLEND_NORMAL, 0);
}

void Click::ClickEvent_1()
{
	if (mCircleCollider.CheckHit(mCircleCollider3))
	{
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			if (mClickTime2 != 2)
				mClickTime2++;

			if (mClickTime2 == 1 && mLevel * mUpScore - 1 < mNoteCount&&mLevel!=100)
			{
				mNoteCount -= mLevel * mUpScore;
				mUpScore += 10;
				mLevel++;
			}
				
		}
		else
			mClickTime2 = 0;
	}
	else
		mClickTime2 = 0;

	mClickUpCount = mLevel;
}

void Click::ClickEvent_2()
{
	if (mCircleCollider.CheckHit(mCircleCollider4))
	{
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			if (mClickTime3 != 2)
				mClickTime3++;
			if (mLevel2 == 0)
			{
				if (mClickTime3 == 1 && mUpScore2 - 1 < mNoteCount)
				{
					mNoteCount -= mUpScore2;
					mUpScore2 += 100;
					mLevel2++;
				}
			}
			else if (mClickTime3 == 1 && mLevel2 * mUpScore2 - 1 < mNoteCount&&mLevel2!=100)
			{
				mNoteCount -= mLevel2 * mUpScore2;
				mUpScore2 += 100;
				mLevel2++;
			}

		}
		else
			mClickTime3 = 0;
	}
	else
		mClickTime3 = 0;

	if (mLevel2 != 0)
	{
		++mCountUpTime %= 10;
		if (mCountUpTime == 0)
		{
			mNoteCount += mLevel2;
			mpCountUpManager->Spain(170, 400, mLevel2);
		}
	}
}

void Click::ClickEvent_3()
{
	if (mCircleCollider.CheckHit(mCircleCollider5))
	{
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			if (mClickTime4 != 2)
				mClickTime4++;
			if (mLevel3 == 0)
			{
				if (mClickTime4 == 1 && mUpScore3 - 1 < mNoteCount)
				{
					mNoteCount -= mUpScore3;
					mUpScore3 += 200;
					mLevel3++;
				}
			}
			else if (mClickTime4 == 1 && mLevel3 * mUpScore3 - 1 < mNoteCount&&mLevel3!=100)
			{
				mNoteCount -= mLevel3 * mUpScore3;
				mUpScore3 += 200;
				mLevel3++;
			}

		}
		else
			mClickTime4 = 0;
	}
	else
		mClickTime4 = 0;

	if (mLevel3 != 0)
	{
		++mCountUpTime2 %= 20;
		if (mCountUpTime2 == 0)
		{
			mNoteCount += mLevel3 * 5;
			mpCountUpManager->Spain(270, 400, mLevel3 * 5);
		}
	}
}

void Click::ClickEvent_4()
{
	if (mCircleCollider.CheckHit(mCircleCollider6))
	{
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			if (mClickTime5 != 2)
				mClickTime5++;
			if (mLevel4 == 0)
			{
				if (mClickTime5 == 1 && mUpScore4 - 1 < mNoteCount)
				{
					mNoteCount -= mUpScore4;
					mUpScore4 += 400;
					mLevel4++;
				}
			}
			else if (mClickTime5 == 1 && mLevel4 * mUpScore4 - 1 < mNoteCount && mLevel4 != 100)
			{
				mNoteCount -= mLevel4 * mUpScore4;
				mUpScore4 += 400;
				mLevel4++;
			}

		}
		else
			mClickTime5 = 0;
	}
	else
		mClickTime5 = 0;

	if (mLevel4 != 0)
	{
		++mCountUpTime3 %= 60;
		if (mCountUpTime3 == 0)
		{
			mNoteCount += mLevel4 * 30;
			mpCountUpManager->Spain(370, 400, mLevel4 * 30);
		}
	}
}

void Click::ClickEvent_5()
{
	if (mCircleCollider.CheckHit(mCircleCollider7))
	{
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			if (mClickTime6 != 2)
				mClickTime6++;
			if (mLevel5 == 0)
			{
				if (mClickTime6 == 1 && mUpScore5 - 1 < mNoteCount)
				{
					mNoteCount -= mUpScore5;
					mUpScore5 += 800;
					mLevel5++;
				}
			}
			else if (mClickTime6 == 1 && mLevel5 * mUpScore5 - 1 < mNoteCount&&mLevel5!=100)
			{
				mNoteCount -= mLevel5 * mUpScore5;
				mUpScore5 += 800;
				mLevel5++;
			}

		}
		else
			mClickTime6 = 0;
	}
	else
		mClickTime6 = 0;

	if (mLevel5 != 0)
	{
		++mCountUpTime4 %= 180;
		if (mCountUpTime4 == 0)
		{
			mNoteCount += mLevel5 * 100;
			mpCountUpManager->Spain(470, 400, mLevel5 * 100);
		}
	}
}

void Click::ClickEvent_6()
{
	if (mCircleCollider.CheckHit(mCircleCollider8))
	{
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			if (mClickTime7 != 2)
				mClickTime7++;
			if (mLevel6 == 0)
			{
				if (mClickTime7 == 1 && mUpScore6 - 1 < mNoteCount)
				{
					mNoteCount -= mUpScore6;
					mUpScore6 += 1600;
					mLevel6++;
				}
			}
			else if (mClickTime7 == 1 && mLevel6 * mUpScore6 - 1 < mNoteCount&&mLevel6!=100)
			{
				mNoteCount -= mLevel6 * mUpScore6;
				mUpScore6 += 1600;
				mLevel6++;
			}

		}
		else
			mClickTime7 = 0;
	}
	else
		mClickTime7 = 0;

	if (mLevel6 != 0)
	{
		++mCountUpTime5 %= 500;
		if (mCountUpTime5 == 0)
		{
			mNoteCount += mLevel6 * 1000;
			mpCountUpManager->Spain(570, 400, mLevel6 * 1000);
		}
	}
}

void Click::Save()
{
	mpSaveData->Save(mNoteCount, mLevel, mLevel2, mLevel3, mLevel4, mLevel5, mLevel6, mUpScore, mUpScore2, mUpScore3, mUpScore4, mUpScore5, mUpScore6,1);
}