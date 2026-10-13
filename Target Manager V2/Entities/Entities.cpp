#pragma once

#include "Entities.h"

void setUpEntities(vector<Entity>& entities)
{
	Entity localPlayer("Jamaal", 100, true, Team::Falcon, 2000, 1473);
	entities.push_back(localPlayer);

	Entity ghost("Ghost Gamer", returnHealth(), false, Team::Falcon, returnPos(), returnPos());
	entities.push_back(ghost);

	Entity astro("Astro World", returnHealth(), false, Team::Falcon, returnPos(), returnPos());
	entities.push_back(astro);

	Entity dodo("Dodo Expert", returnHealth(), false, Team::Toad, returnPos(), returnPos());
	entities.push_back(dodo);

	Entity buzz("Buzz Light", returnHealth(), false, Team::Toad, returnPos(), returnPos());
	entities.push_back(buzz);

	Entity captian("Captain Jack", returnHealth(), false, Team::Toad, returnPos(), returnPos());
	entities.push_back(captian);
}

Entity* getLocalPlayer(vector<Entity>& entities)
{
	Entity* pLocalPlayer = nullptr;

	for (Entity& e : entities)
	{
		if (e.isLocal == true)
		{
			pLocalPlayer = &e;
		}
	}
	return pLocalPlayer;
}

void listEntities(const vector<Entity>& entities, const Entity* pLocalPlayer)
{
	clear();

	cout << left << setw(16) << "NAME" << setw(10) << "HEALTH" << "DIST" << endl;
	cout << "------------------------------------------" << endl;
	
	for (const Entity& e : entities)
	{

		float distanceMeters = getDistance(pLocalPlayer->positions, e.positions);

		cout << left << setw(16) << e.name
			<< healthColor(&e) << "  " << setw(8) << e.health << reset;

		if (e.isLocal == true)
		{
			cout << " [LocalPlayer]" << endl;
		}
		
		else
		{
			cout << " | " << fixed << setprecision(2) << distanceMeters << "[m]";

			if (e.team == Team::Falcon) cout << " [TEAM]" << endl;
			else cout << " [Enemy]" << endl;
		}

	}

	getKey();
}

Entity* findClosest(vector<Entity>& entities, Entity* pLocalPlayer)
{
	clear();

	Entity* closest = nullptr;

	float closestDistance = FLT_MAX;
	constexpr float unitsPerMeter = 100.0f;

	for (Entity& e : entities)
	{
		if (e.team == Team::Falcon) continue;

		float distanceMeters = getDistance(pLocalPlayer->positions, e.positions);


		if (closestDistance > distanceMeters)
		{
			closestDistance = distanceMeters;
			closest = &e;
		}
	}

	if (closest == nullptr)
	{
		cout << "[!] No Targets Within Range" << endl;
		pause();
		return nullptr;
	}
	else
	{
		cout << "Closest: " << closest->name << " | " << fixed << setprecision(2) << closestDistance << "[m]" << endl;
		getKey();
		return closest;
	}
}

void attackTarget(Entity* entity)
{
	clear();

	const int damage = returnDamage();
	const int healthSnapshot = entity->health;
	entity->health -= damage;

	if (entity->health <= 0) entity->health = 0;

	cout << "[+] You Attackd " << entity->name << "!" << endl;
	cout << entity->name << "'s Health: " << healthSnapshot << " -> " << entity->health
		<< " (" << red << "-" << damage << reset << ")" << endl;

	getKey();
}

void healTarget(Entity* entity)
{
	clear();

	const int healthSnapshot = entity->health;
	entity->health = entity->maxHealth;

	cout << "[+] " << green << "Successfully " << reset << "Replenished " << entity->name << "'s Health!" << endl;
	cout << entity->name << " Health: " << healthSnapshot << " -> " << entity->health
		<< " (" << green << "+" << entity->health - healthSnapshot << reset << ")" << endl;


	getKey();
}

void killTarget(Entity* entity)
{
	clear();
	entity->health = 0;

	cout << "[+] " << green << "Successfully " << red << "Killed " << reset << entity->name << "!" << endl;
	getKey();
}

void changePosTarget(Entity* entity)
{
	float x, y;

	x = returnPos();
	y = returnPos();

	entity->positions.x = x;
	entity->positions.y = y;

	cout << entity->name << "'s New Coords (" << entity->positions.x << ", " << entity->positions.y << ")" << endl;

	getKey();
}

void targetOption(Entity* entity)
{
	clear();

	if (targetCheck(entity))
	{
		checkMessage();
		return;
	}

	int subOption;

	while (true)
	{
		clear();

		printSubInfo(entity);

		cout << "[1] Attack" << endl;
		cout << "[2] Heal" << endl;
		cout << "[3] Kill" << endl;
		cout << "[4] Change Position" << endl;
		cout << "[5] Return" << endl;

		space();
		cout << "> ";
		cin >> subOption;

		if (input())
		{
			continue;
		}

		switch (subOption)
		{

		case AttackOpt:
			attackTarget(entity);
			break;

		case HealOpt:
			healTarget(entity);
			break;

		case KillOpt:
			killTarget(entity);
			break;

		case ChangePosOpt:
			changePosTarget(entity);
			break;

		case Return:

			return;

		default:
			invalid();
			break;
		}
	}

}

void clearTarget(Entity*& entity)
{
	clear();

	if (targetCheck(entity))
	{
		cout << "[!] No Target To Clear" << endl;
		pause();
		return;
	}

	cout << "[+] " << green << "Successfully " << reset << "Removed Target" << endl;
	entity = nullptr;

	getKey();
}