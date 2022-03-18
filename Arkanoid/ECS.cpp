#include "ECS.h"

#include "collision.h"
#include "transform.h"




Component::~Component() = default;

void Entity::update()
{
	for (std::unique_ptr<Component>& component : components)
	{
		component->update();
	}
}

Entity::~Entity() = default;

void Entity::onCollisionEnter(RectCollider& collider)
{
	for (std::unique_ptr<Component>& component : components)
	{
		component->onCollisionEnter(collider);
	}
	
}
void Entity::onCollisionStay(RectCollider& collider)
{
	for (std::unique_ptr<Component>& component : components)
	{
		component->onCollisionStay(collider);
	}
}
void Entity::onCollisionExit(RectCollider& collider)
{
	for (std::unique_ptr<Component>& component : components)
	{
		component->onCollisionExit(collider);
	}
}

Entity::Entity() : transform(&addComponent<Transform>())
{
	Entity::awake();
}

void Entity::awake()
{
	
}


bool Entity::isWaitingForDestroy() const
{
	return isDestroyed;
}

template <typename T>
bool Entity::hasComponent() const
{
	return componentBitSet[getComponentID<T>];
}



