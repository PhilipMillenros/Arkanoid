#pragma once
#include <SDL_render.h>

#include "ECS.h"
#include "engine.h"
#include "transform.h"

class Shape : public Component
{

public:

	void awake() override
	{
		transform = &entity->getComponent<Transform>();
	}

	void update() override
	{

	}
	int getScale()
	{
		
	}
};

class Rectangle : public Shape
{
public:
	Vector2 dimensions = {0 , 0};
	SDL_Color color;
	Rectangle()
	{
		color = { 25, 50, 50, 0, };
	}
	void drawShape() const
	{
		SDL_SetRenderDrawColor(render, color.r,  color.g, color.b, 255);
		SDL_Rect rect = { static_cast<int>(transform->position.x - dimensions.x / 2), static_cast<int>(transform->position.y - dimensions.y / 2), (int)dimensions.x, (int)dimensions.y};
		SDL_RenderFillRect(render, &rect);
	}
	void update() override
	{
		drawShape();
	}
};