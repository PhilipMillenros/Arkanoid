#pragma once
#include "ECS.h"

class BlockBehaviour : public Component
{
	int health = 2;
	void onCollisionEnter(RectCollider& collider) override;
	void getHit();
};
