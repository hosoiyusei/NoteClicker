#include"CountUp.h"

CountUp::CountUp()
	:mX(0)
	,mY(0)
	,mCount(0)
	, mActive(true)
	, mUpCount(0)
{

}

CountUp::~CountUp()
{

}

void  CountUp::Initialize(int x, int y, int i)
{
	mX = x;
	mY = y;
	mUpCount = i;
}

void CountUp::Update()
{
	mY -= 1;
	mCount += 1;

	if (mCount == 50)
		mActive = false;
}

void CountUp::Draw()
{
		DrawFormatString(mX, mY, GetColor(200, 200, 200), "+%d", mUpCount);
}

void CountUp::Finalize()
{

}