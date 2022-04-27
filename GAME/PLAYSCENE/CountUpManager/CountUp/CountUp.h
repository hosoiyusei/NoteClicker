#pragma once

class CountUp
{
private:

	int mX;
	int mY;

	int mCount;

	int mUpCount;

	bool mActive;

public:

	CountUp();
	~CountUp();

	void Initialize(int x,int y,int i);

	void Update();

	void Draw();

	void Finalize();

	bool IsActive()
	{
		return mActive;
	}
};