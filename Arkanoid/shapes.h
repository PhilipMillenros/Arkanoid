#pragma once
#include <SDL_render.h>

#include "ECS.h"
#include "engine.h"
#include "transform.h"

class Shape : public Component
{
	
public:
	Transform* transform;

	void awake() override
	{
		transform = &entity->getComponent<Transform>();
	}
	
	void update() override
	{
		
	}
};

class Rectangle : public Shape
{
public:
	void drawS() const
	{
		SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
		SDL_Rect rect = { static_cast<int>(transform->position.x) - 25, static_cast<int>(transform->position.y) - 25, 50, 50 };

		SDL_RenderFillRect(render, &rect);
	}
	void update() override
	{
		drawS();
	}
	
};