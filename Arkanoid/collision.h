#pragma once

#include <map>
#include <SDL_pixels.h>

#include "ECS.h"
#include "vector2.h"

class RectCollider : public Component
{
public:
	Vector2 dimensions;
	Vector2 previousPosition;
	SDL_Color color = {50, 255, 0, 255};
	void update() override;
	std::map<int, bool> intersectingRectColliders;
	int id;
	bool operator <(const RectCollider& rhs) const;
	void awake() override;
	void onCollision(RectCollider& rectCollider);
	void onNoCollision(RectCollider& rectCollider);
};
