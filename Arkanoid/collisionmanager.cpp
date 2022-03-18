#include "collisionmanager.h"
#include "transform.h"

void CollisionManager::addCollider(RectCollider& rectCollider)
{
	rectCollider.id = ++currentId;
	rectColliders.push_back(std::unique_ptr<RectCollider>(&rectCollider));
}

void CollisionManager::checkForCollisions(RectCollider& rectCollider)
{
	if(rectCollider.transform->position != rectCollider.previousPosition)
	{
		rectCollider.previousPosition = rectCollider.transform->position;
		for (int i = 0; i < rectColliders.size(); i++)
		{

			if(rectCollider.id == rectColliders[i]->id || rectCollider.entity->isWaitingForDestroy() || rectColliders[i]->entity->isWaitingForDestroy())
			{
				continue;
			}
			if(aabbCollision(rectCollider, *rectColliders[i]))
			{
				rectColliders[i]->onCollision(rectCollider);
				rectCollider.onCollision(*rectColliders[i]);
			}
			else
			{
				rectColliders[i]->onNoCollision(rectCollider);
				rectCollider.onNoCollision(*rectColliders[i]);
			}
		}
	}
}

bool CollisionManager::aabbCollision(RectCollider& r1, RectCollider& r2)
{
	return r1.transform->position.x - r1.dimensions.x / 2 < r2.transform->position.x - r2.dimensions.x / 2 + r2.dimensions.x &&
		r1.transform->position.x - r1.dimensions.x / 2 + r1.dimensions.x > r2.transform->position.x - r2.dimensions.x / 2 &&
		r1.transform->position.y - r1.dimensions.y / 2 < r2.transform->position.y - r2.dimensions.y / 2 + r2.dimensions.y &&
		r1.transform->position.y - r1.dimensions.y / 2 + r1.dimensions.y > r2.transform->position.y - r2.dimensions.y / 2;
}

