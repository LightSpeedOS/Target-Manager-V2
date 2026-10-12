#pragma once

#include "Headers/Struct.h"
#include "Headers/Includes.h"
#include "Headers/Logic.h"

void setUpEntities(vector<Entity>& entities);

void listEntities(vector<Entity>& entities);

Entity* findClosest(vector<Entity>& entities);