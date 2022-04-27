#pragma once
#include<math.h>

#define BUFFERLENGTH	800

class SoundWave
{
private:

	int SoundHandle;
	int SoftSoundHandle;
	float ParamList[BUFFERLENGTH];
	int SamplePos;

public:

	SoundWave();
	~SoundWave();

	void Initialize();

	void Update();

	void Draw();

	void Finalize();
};