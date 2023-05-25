#include "Map.h"
#include <string>
#include <sstream>
Map::Map() {

}
Map::~Map() {

}
xml_attribute Map::getAttributeValue(xml_node& node, string attributename) {
	return node.find_attribute(
		[&](xml_attribute att) -> bool
		{
			if (string(att.name()).compare(attributename) == 0)
				return true;
			return false;
		});
}
void Map::getElementMatrixIndex(xml_node& node, vector<vector<int>>& a) {
	/*
		Hàm này thực hiện duyệt tất cả Row của MatrixIndex
		Cấu trúc có dạng:
		<MatrixIndex>
			<Row id="0">1	1	1	6	66	..	3	3	3	3	3	3	3	3</Row>
			<Row id="1">67	63	69	72	69	..	69	72	75	76	3	3	3	3</Row>
			<Row id="2">64	60	64	60	64	..	64	60	64	60	64	60	64	60</Row>
		</MatrixIndex>
		Sau khi kết thúc hàm này ta sẽ có ma trận index đầy đủ của một tiled map.
	*/
	xml_node child = node.first_child();

	 string indexStr;

	int i = 0, j = 0;
	while (child != nullptr) {

		indexStr = child.text().as_string();
		//get 1st dimension index
		i = child.attribute("id").as_int();
		//split string by \t
		vector<string> t;
		stringstream ss(indexStr);
		string item;
		while (getline(ss, item, '\t')) {
			t.push_back(item);
		}
		int j = 0;
			vector<int>temp;
		for (string tmp : t) {
			temp.push_back(atoi(tmp.c_str()));
			j++;
		}
		a.push_back(temp);
		child = child.next_sibling();
		indexStr.clear();
		temp.clear();
	}
}
Map* Map::LoadFromFile(string path, LPTEXTURE tex, CSprites* sprites) {
	pugi::xml_document doc;

	// Mở file và đọc
	xml_parse_result result = doc.load_file(path.data(), pugi::parse_default | pugi::parse_pi);
	if (result == false)
	{
		return nullptr;
	}
	Map* map = new Map();
	/*
		Đọc dữ liệu từ element Tilesmap
		cấu trúc:
		<Tilesmap columns="1" rows="2">
			....
		</Tilesmap>
	*/
	xml_node tilemap = doc.child("Tilesmap");
	if (tilemap == NULL)
		return nullptr;
	map->mapWidth = getAttributeValue(tilemap, "columns").as_int();
	map->mapHeight = getAttributeValue(tilemap, "rows").as_int();
	xml_node matrixindex = tilemap.child("MatrixIndex");
	if (matrixindex == NULL)
		return nullptr;
	getElementMatrixIndex(matrixindex, map->mapIndex);
	xml_node tileset = tilemap.child("TileSet");
	map->tileSet = new TileSet(tex);
	map->tileSet->loadListTiles(tileset, sprites);

	map->tileWidth = 32;
	map->tileHeight = 32;
	for (int i = 0; i < map->mapIndex.size(); i++) {
		for (int j = 0; j < map->mapIndex[i].size(); j++) {
			map->tileList.push_back(new Tile(map->mapIndex[i][j], j * 32, (map->mapIndex.size() - i) * 32));
		}
	}
	return map;
}