#pragma once
#include<list>
#include<iostream>

class CountUp;

class CountUpManager
{
private:

	std::list<CountUp*>mpCountUp;

public:

	CountUpManager();
	~CountUpManager();

	void Initialize();

	void Update();

	void Draw();

	void Finalize();

	void Spain(int x, int y, int i);

private:

	void Delete();
};