#pragma once
#include <math.h>
#include <string>
#include <map>
#include <vector>

#include "pugixml.hpp"

using namespace std;
using namespace pugi;


#define __NS_FRAMEWORK__
#define _USE_MATH_DEFINES


using namespace std;

enum eID
{
	BillID = 0,			// Main character.
	BulletID = 1,
	//
	//stage 1 characters
	//Missing: Boss, Explosions, Bridge,...
	SoldierID = 2,		//Dunno cause hohoanhtung got soldierCreator - research later
	AircraftID = 3,		//done
	CannonID = 4,		//done
	RiflemanID = 5,		//done
	FalconID = 6,		//done
	WallTurretID = 7,	//done
	
};
