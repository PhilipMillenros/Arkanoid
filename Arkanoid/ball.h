#pragma once
#include "ECS.h"
#include "shape.h"
#include "ballbehaviour.h"
class Ball : public Entity
{
public:
	Rectangle* sprite;
	RectCollider* collider;
	BallBehaviour* ballBehaviour;
	Vector2 dimensions { 20, 20};
	void awake() override;
};
