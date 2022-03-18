#pragma once
#include "blockbehaviour.h"
#include "collision.h"
#include "ECS.h"
#include "shape.h"

class Block : public Entity
{
public:
	int hitPoints = 5;
	void awake() override;
	BlockBehaviour* blockBehaviour;
	Rectangle* sprite;
	RectCollider* collider;

};
