#pragma once

#include "Includes.h"

enum mainMenu
{
	ListOpt = 1,
	FindOpt,
	TargetOpt,
	ClearOpt,
	Exit,
};

enum subMenu
{
	AttackOpt = 1,
	HealOpt,
	ChangePosOpt,
};

struct Vec2
{
	float x, y;
};

enum struct Team
{
	Falcon,
	Toad
};

struct Entity
{
	string name;
	int health;
	bool isLocal = false; 
	Team team;
	Vec2 positions;

	Entity(string n, int h, bool l, Team t, float posX, float posY)
	{
		name = n;
		health = h;
		isLocal = l;
		team = t;
		positions.x = posX;
		positions.y = posY;
	}
};