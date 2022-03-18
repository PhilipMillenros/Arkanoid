#pragma once
#include <vector>
#include "collision.h"
class RectCollider;
class CollisionManager
{
private:
	std::vector<std::unique_ptr<RectCollider>> rectColliders;
	int currentId;
public:

	void addCollider(RectCollider& rectCollider);
	void checkForCollisions(RectCollider& rectCollider);
	bool aabbCollision(RectCollider& r1, RectCollider& r2);
};
