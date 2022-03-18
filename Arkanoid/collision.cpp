#include "collision.h"

#include "game.h"
#include "transform.h"

const float PI = 3.1415;

void RectCollider::update()
{
	collisionManager.checkForCollisions(*this);
	SDL_SetRenderDrawColor(render, color.r, color.g, color.b, 255);
	SDL_Rect rect = { static_cast<int>(transform->position.x - dimensions.x / 2), static_cast<int>(transform->position.y - dimensions.y / 2), (int)dimensions.x, (int)dimensions.y };
	SDL_RenderDrawRect(render, &rect);
}

bool RectCollider::operator<(const RectCollider& rhs) const
{
	return id < rhs.id;
}

void RectCollider::awake()
{
	transform = entity->transform;
	collisionManager.addCollider(*this);
}

void RectCollider::onCollision(RectCollider& rectCollider)
{
	if (!intersectingRectColliders[rectCollider.id])
	{
		entity->onCollisionEnter(rectCollider);
		intersectingRectColliders[rectCollider.id] = true;
		this->color = { 255, 100, 0, 255 };
	}
	
	entity->onCollisionStay(rectCollider);
}

void RectCollider::onNoCollision(RectCollider& rectCollider)
{
	if (intersectingRectColliders[rectCollider.id])
	{
		entity->onCollisionExit(rectCollider);
		rectCollider.color = { 50, 255, 0, 255 };
	}
	intersectingRectColliders[rectCollider.id] = false;
}

