#pragma once
#include <vector>

#include "vector2.h"

class Grid
{
private:
	
	std::vector<std::vector<Vector2>> grid;
	
public:
	int width = 20, height = 3;
	Vector2 getPositionOfVertex(int x, int y);
	Grid();
};
