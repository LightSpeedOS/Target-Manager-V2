#pragma once

#include "Entities.h"

void setUpEntities(vector<Entity>& entities)
{
	Entity localPlayer("Jamaal", returnHealth(), true, Team::Falcon, returnPos(), returnPos());
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

void listEntities(vector<Entity>& entities)
{
	clear();

	cout << left << setw(16) << "NAME" << setw(10) << "HEALTH" << "POS" << endl;
	cout << "------------------------------------------" << endl;
	
	for (const Entity& e : entities)
	{
		cout << left << setw(16) << e.name
			<< healthColor(&e) << "  " << setw(8) << e.health << reset <<
			"(" << e.positions.x << "," << e.positions.y << ")" << endl;
	}

	getKey();
}

Entity* findClosest(vector<Entity>& entities)
{
	Entity* closest = nullptr;
}