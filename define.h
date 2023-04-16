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
	//Missing: Boss, Explosions,...
	SoldierID = 2,
	AircraftID = 3,
	CannonID = 4,
	RiflemanID = 5,
	FalconID = 6,
	WallTurretID = 7,
	
};
