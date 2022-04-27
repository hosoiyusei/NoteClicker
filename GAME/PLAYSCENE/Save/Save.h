#pragma once
#include <string>    // useful for reading and writing

class SaveData
{
private:

	int mData[100];

	char line[256];

	FILE* mRoad;
	FILE* mSave;

public:

	SaveData();
	~SaveData();

	void Save(int Score, int l1, int l2,int l3,int l4,int l5,int l6,int u1,int u2,int u3,int u4,int u5,int u6,int save);

	int Road(int i);
};