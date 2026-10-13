#pragma once

#include "Headers/Struct.h"
#include "Headers/Includes.h"
#include "Headers/Logic.h"

void setUpEntities(vector<Entity>& entities);

Entity* getLocalPlayer(vector<Entity>& entities);

void listEntities(const vector<Entity>& entities, const Entity* pLocalPlayer);

Entity* findClosest(vector<Entity>& entities, Entity* pLocalPlayer);

void attackTarget(Entity* entity);

void healTarget(Entity* entity);

void targetOption(Entity* entity);

void killTarget(Entity* entity);

void changePosTarget(Entity* entity);

void clearTarget(Entity*& entity);