#pragma once
#include "grid.h"
#include "engine.h"
#include "game.h"
Grid::Grid()
{
	grid.reserve(width);

	for (int i = 0; i < width; i++)
	{
		grid.emplace_back();
		grid[i].reserve(height);
		for (int y = 0; y < height; ++y)
		{
			grid[i].emplace_back();
		}
	}
	for (int i = 0; i < width; ++i)
	{
		for (int y = 0; y < height; ++y)
		{
			grid[i][y].x = i * (screenWidth / (width)) + blockWidth;
			grid[i][y].y = y * (screenHeight / (blockHeight)) + 2.5f * blockHeight;
		}
	}
}
int clamp(int value, int min, int max)
{
	return std::max(min, std::min(value, max));
}
Vector2 Grid::getPositionOfVertex(int x, int y)
{
	x = clamp(x, 0, width - 1);
	y = clamp(y, 0, height - 1);
	return grid[x][y];
}
