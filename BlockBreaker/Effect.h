#pragma once
class Effect
{
private:
	bool tornado;
	bool Lightning;
	int TornadoTime;
	int Tornadeline;
	bool Twin;
	int LightningTime;
	int Lightningline;
public:
	Effect();
	void UseTornado(int,bool);
	void UseLightning(int);
	void UpDateTime();
	int GetTornado();
	int GetTornadoline();
	bool GetTwinflag();
	int GetLightning();
	int GetLightningline();
	bool GetTornadoflag();
	bool GetLightningflag();
};