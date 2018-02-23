#pragma once

#include <vector>

#include "Wall.h"

class Map {
	public:
	Map();

	void AddWall(Wall wall);

	std::vector<Wall> GetWalls() const;

	private:
	std::vector<Wall> _walls;
};


