#pragma once
#include <string>
#include <vector>

#include "config.h"
#include "TileSet.h"
#include "Tile.h"

using namespace std;
using namespace pugi;
class Map
{
private:
	int tileWidth;
	int tileHeight;

	int mapWidth;
	int mapHeight;
	vector<vector<int>> mapIndex;

	TileSet* tileSet;
public:
	vector<Tile*> tileList;

	Map();
	~Map();

	static Map* LoadFromFile(string path, LPTEXTURE tex, CSprites* sprites);
	static xml_attribute getAttributeValue(xml_node& node, string attributename);
	static void getElementMatrixIndex(xml_node& node, vector<vector<int>>& a);
};
typedef Map* LPMAP;
