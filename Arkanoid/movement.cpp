#pragma once
#include "movement.h"
#include "engine.h"
#include "transform.h"

void HorizontalMovement::awake()
{
	
}
void HorizontalMovement::update()
{
	if (keys[SDL_SCANCODE_D])
		transform->position.x += 200 * deltaTime;
	if (keys[SDL_SCANCODE_A])
		transform->position.x -= 200 * deltaTime;
}

