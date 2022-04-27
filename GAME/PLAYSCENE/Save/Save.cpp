#include"Save.h"

SaveData::SaveData()
	:mData{}
{

}

SaveData::~SaveData()
{

}

void SaveData::Save(int Score, int l1, int l2, int l3, int l4, int l5, int l6, int u1, int u2, int u3, int u4, int u5, int u6,int save)
{
	mSave = fopen("RESOURCES/SaveData/SaveData.txt", "w");
	fprintf(mSave, "%d\n", Score);
	fprintf(mSave, "%d\n", l1);
	fprintf(mSave, "%d\n", l2);
	fprintf(mSave, "%d\n", l3);
	fprintf(mSave, "%d\n", l4);
	fprintf(mSave, "%d\n", l5);
	fprintf(mSave, "%d\n", l6);
	fprintf(mSave, "%d\n", u1);
	fprintf(mSave, "%d\n", u2);
	fprintf(mSave, "%d\n", u3);
	fprintf(mSave, "%d\n", u4);
	fprintf(mSave, "%d\n", u5);
	fprintf(mSave, "%d\n", u6);
	fprintf(mSave, "%d", save);

	fclose(mSave);
}

int SaveData::Road(int i)
{
	mRoad = fopen("RESOURCES/SaveData/SaveData.txt", "r");

	for (int i = 0; i < 100; i++)
	{
		fgets(line, 256, mRoad);
		sscanf(line, "%d", &mData[i]);
	}

	for (int Z = 0; Z < 100; Z++)
	{
		if (Z == i)
		{
			return mData[Z];
			break;
		}
	}

	fclose(mRoad);
}