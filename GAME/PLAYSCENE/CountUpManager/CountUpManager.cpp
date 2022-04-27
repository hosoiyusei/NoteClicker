#include"CountUpManager.h"
#include"CountUp/CountUp.h"

CountUpManager::CountUpManager()
	:mpCountUp()
{

}

CountUpManager::~CountUpManager()
{

}

void CountUpManager::Initialize()
{

}

void CountUpManager::Update()
{
	for (std::list<CountUp*>::iterator itr = mpCountUp.begin(); itr != mpCountUp.end(); itr++)
	{
		if ((*itr) != nullptr)
			(*itr)->Update();
	}

	Delete();
}

void CountUpManager::Draw()
{
	for (std::list<CountUp*>::iterator itr = mpCountUp.begin(); itr != mpCountUp.end(); itr++)
	{
		if ((*itr) != nullptr)
			(*itr)->Draw();
	}
}

void CountUpManager::Finalize()
{
	for (std::list<CountUp*>::iterator itr = mpCountUp.begin(); itr != mpCountUp.end(); itr++)
	{
		if ((*itr) == nullptr)
			continue;
		(*itr)->Finalize();
		delete (*itr);
	}
	mpCountUp.clear();
}

void CountUpManager::Spain(int x,int y,int i)
{
	mpCountUp.push_back(new CountUp());
	std::list<CountUp*>::iterator itr = mpCountUp.end();
	itr--; (*itr)->Initialize(x, y, i);
}

void CountUpManager::Delete()
{
	for (std::list<CountUp*>::iterator itr = mpCountUp.begin(); itr != mpCountUp.end();)
	{
		if ((*itr) == nullptr)
		{
			itr++;
			continue;
		}
		if ((*itr)->IsActive()==false)
		{
			if ((*itr) != nullptr)
				(*itr)->Finalize();
			delete (*itr);
			(*itr) = nullptr;
			itr = mpCountUp.erase(itr);
			continue;
		}
		itr++;
	}
}