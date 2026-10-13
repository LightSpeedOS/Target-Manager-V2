#pragma once
#include "Struct.h"

inline bool targetCheck(const Entity* e)
{
	return e == nullptr;
}

inline void checkMessage()
{
	clear();
	cout << "[!] No Target Has Been Selected" << endl;
	pause();
}

inline int returnHealth()
{
	return rand() % 100 + 0;
}

inline int returnDamage()
{
	return rand() % 100 + 1;
}

inline float returnPos()
{
	return rand() % 1250 + 10;
}

inline const char* healthColor(const Entity* e)
{
	if (e->health > 50) return green;
	if (e->health > 20) return yellow;
	else return red;
}

inline void printInfo(const Entity* e)
{
	cout << "========= TARGET MANAGER V2 ==========" << endl;
	space();

	if (e == nullptr)
	{
		cout << "Current Target: None" << endl;
		space();
	}

	else
	{
		cout << "Current Target: " << e->name << endl;
		space();
	}
}

inline void printSubInfo(const Entity* e)
{
	cout << "========= Sub Menu ==========" << endl;
	space();

		cout << "Current Target: " << e->name << " | " << e->health << "/" << e->maxHealth << " HP" << endl;
		space();
}

inline float getDistance(const Vec2& local, const Vec2& entity)
{

	constexpr float unitsPerMeter = 100.0f;

	float dx = entity.x - local.x;
	float dy = entity.y - local.y;

	float distance = sqrt((dx * dx) + (dy * dy));
	float distanceMeter = distance / unitsPerMeter;

	return distanceMeter;
	
}