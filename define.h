#pragma once
#include <d3d10.h>		// d3d9.lib
#include <d3dx10.h>		// d3dx9.lib
#include <dinput.h>		// dinput8.lib, dxguid.lib
#include <dsound.h>		// dsound.lib

#include <vector>
#include <math.h>
#include <string>
#include <map>

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
	SoldierID = 2,
	AircraftID = 3,//
	CannonID = 4,//
	RiflemanID = 5,//
	FalconID = 6,//
	WallTurretID = 7,//
	ScubaSoldierID = 8,// newly created 5-25-2023 2:25PM

	WATER = 11,
	LAND = 12,
	BRIDGE = 14,
	BOSS1SHIELD = 18,
	BOSS1GUN = 19,

	RockFlyID = 21,
	FireID = 25,
	RockFallID = 26,
	BOSS3MOUTH = 20,
	BOSS3ARM = 22,

	TriggerBoxID = 200,

	generator = 23,
};

enum eLandType
{
	GRASS,
	BRIDGELAND
};

enum eMapType
{
	VERTICAL = 0,
	HORIZONTAL = 1
};

enum eAirCraftType
{
	B,
	F,
	L,
	M,
	R,
	S,
	I,
};

typedef D3DXVECTOR3 GVector3;
typedef D3DXVECTOR2 GVector2;

