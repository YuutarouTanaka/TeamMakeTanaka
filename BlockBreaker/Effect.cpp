#include "Effect.h"
Effect::Effect()
{
	TornadoTime = 0;
	LightningTime = 0;
	Tornadeline = 0;
	Lightningline = 0;
	bool IsTwin = false;
	tornado = false;
	Lightning = false;
}
void Effect::UseTornado(int line,bool twin)
{
	tornado = true;
	TornadoTime = 42;
	Tornadeline = line;
	Twin = twin;
}
void Effect::UseLightning(int line)
{
	Lightning = true;
	LightningTime = 56;
	Lightningline = line;
}
void Effect::UpDateTime()
{
	if (TornadoTime>0)
	{
		TornadoTime--;
	}
	if (tornado == true && TornadoTime==0)
	{
		tornado = false;
	}
	if (LightningTime>0)
	{
		LightningTime--;
	}
	if (Lightning == true&&LightningTime==0)
	{
		Lightning = false;
	}
}
int Effect::GetLightningline()
{
	return Lightningline;
}
int Effect::GetLightning()
{
	return LightningTime;
}
int Effect::GetTornadoline()
{
	return Tornadeline;
}
int Effect::GetTornado()
{
	return TornadoTime;
}
bool Effect::GetTwinflag()
{
	return Twin;
}
bool Effect::GetTornadoflag()
{
	return tornado;
}
bool Effect::GetLightningflag()
{
	return Lightning;
}