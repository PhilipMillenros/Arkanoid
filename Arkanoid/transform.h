#pragma once

#include "ECS.h"
#include "vector2.h"

class Transform : public Component
{

public:
	Vector2 position;
	Transform()
	{
		position.x = 5;
		position.y = 10;
	}
};
