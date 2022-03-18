#pragma once
#include "collision.h"


class BallBehaviour : public Component
{
public:
	Vector2 velocity = {250, 250};
	RectCollider* collider;
	void update() override;
	void awake() override;
	void bounce(const RectCollider& objectHit);
	void getHit(RectCollider& player);
	void onCollisionEnter(RectCollider& collider) override;
};
