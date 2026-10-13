#include "Headers/Includes.h"
#include "Headers/Logic.h"
#include "Headers/Struct.h"

#include "Entities/Entities.h"
#include "Targeting/Targeting.h"

auto main() -> int
{
	initConsole();
	SetConsoleTitleA("Target Manager V2");

	vector<Entity> entities;
	setUpEntities(entities);

	Entity* pLocalPlayer = getLocalPlayer(entities);
	Entity* currentTarget = nullptr;

	int mainOption;

	while (true)
	{
		clear();
		printInfo(currentTarget);

		cout << "[1] List Entities" << endl;
		cout << "[2] Find Closest Target" << endl;
		cout << "[3] Target Options" << endl;
		cout << "[4] Clear Target" << endl;
		cout << "[5] Exit" << endl;

		space();
		cout << "> ";
		cin >> mainOption;

		if (input())
		{
			continue;
		}

		switch (mainOption)
		{

		case ListOpt:
			listEntities(entities, pLocalPlayer);
			break;

		case FindOpt:
			currentTarget = findClosest(entities, pLocalPlayer);
			break;

		case TargetOpt:
			targetOption(currentTarget);
			break;

		case ClearOpt:
			clearTarget(currentTarget);
			break;

		case Exit:
			return 0;
			break;

		
		default:
			invalid();
			break;
		}
	}
}