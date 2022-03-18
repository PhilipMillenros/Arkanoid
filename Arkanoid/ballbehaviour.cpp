#include "BallBehaviour.h"
#include "engine.h"
#include "transform.h"

void BallBehaviour::awake()
{
	collider = &entity->getComponent<RectCollider>();
}

void BallBehaviour::bounce(const RectCollider& objectHit)
{
	if(transform->position.y > objectHit.transform->position.y + objectHit.dimensions.y / 2)
	{
		velocity.y *= -1.0f;
	}
	if (transform->position.y < objectHit.transform->position.y - objectHit.dimensions.y / 2)
	{
		velocity.y *= -1.0f;
	}
	if (transform->position.x > objectHit.transform->position.x + objectHit.dimensions.x / 2)
	{
		velocity.x *= -1.0f;
	}
	if (transform->position.x < objectHit.transform->position.x - objectHit.dimensions.x / 2)
	{
		velocity.x *= -1.0f;
	}
}

void BallBehaviour::getHit(RectCollider& player)
{
	velocity = (transform->position - player.transform->position).normalize() * velocity.magnitude();
}

void BallBehaviour::onCollisionEnter(RectCollider& collider)
{
	//if(collider.entity->tag == "player")
	//{
		//getHit(collider);
	//}
	//else
	//{
	bounce(collider);
	//}
}

void BallBehaviour::update()
{
	if (deltaTime < 10)
	{
		transform->position += velocity * deltaTime;
	}
	if(transform->position.x > screenWidth)
	{
		velocity.x = -abs(velocity.x);
	}
	if (transform->position.x < 0)
	{
		velocity.x = abs(velocity.x);
	}
	if (transform->position.y < 0)
	{
		velocity.y = abs(velocity.x);
	}
	if (transform->position.y > screenHeight)
	{
		//Destroy
	}
	
}

