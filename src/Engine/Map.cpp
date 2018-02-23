#include "Map.h"

Map::Map() = default;

void Map::AddWall(Wall wall) {
	_walls.push_back(wall);
}

std::vector<Wall> Map::GetWalls() const {
	return _walls;
}
