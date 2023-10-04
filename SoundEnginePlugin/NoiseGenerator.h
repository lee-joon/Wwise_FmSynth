#pragma once
#pragma once
#include <AK/SoundEngine/Common/IAkPlugin.h>
class NoiseGenerator
{
public:
	NoiseGenerator()
	{
		AkReal32 fRandom = (rand() / ((AkReal32)RAND_MAX));
		SetSeed(*(AkReal32*)&fRandom);
	}

	void SetSeed(AkUInt32 Seed)
	{
		noiseSeed = Seed;
	}

	AkUInt32 BoolValue()
	{
		AkUInt32 fRandom = rand() / ((AkReal32)RAND_MAX);
		

		return fRandom % 2;
	}

	AkUInt32 BSnextValue(AkUInt32 BufferSize, AkUInt32 Granularlength)
	{
		/*noiseSeed = noiseSeed * 19631241656 + 9076343515;
		AkUInt32 r = (noiseSeed & 0xFFFFFF);*/
		AkReal32 fRandom = rand() / ((AkReal32)RAND_MAX);
		AkUInt32 Rvalue = (AkUInt32)(fRandom * ((BufferSize - Granularlength) - 1) + 1.f);
		return Rvalue;
	}

	AkReal32 nextValue()
	{
		// Generate the next integer pseudorandom number.
		noiseSeed = noiseSeed * 196314165 + 907633515;

		// Convert the integer to a float, to get a number between 2 and 4.
		AkUInt32 r = (noiseSeed & 0x7FFFFF) + 0x40000000;
		AkReal32 noise = *(AkReal32*)&r;

		// Subtract 3 to get the float into the range [-1, 1].
		return noise - 3.0f;
	}

	AkReal32 floatValue(AkReal32 MaxValue)
	{
		noiseSeed = noiseSeed * 196314165 + 907633515;
		// Convert the integer to a float, to get a number between 2 and 4.
		AkInt32 r = (noiseSeed & 0x47FFFFFF) | ((1 << 22) + (1 << 30));
		AkReal32 noise = *(AkReal32*)&r;

		return fmodf(noise, MaxValue);
	}


private:
	AkUInt32 noiseSeed = 0;
};