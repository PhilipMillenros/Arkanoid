#include "blockbehaviour.h"

#include "ball.h"
#include "game.h"

void BlockBehaviour::onCollisionEnter(RectCollider& collider)
{
	getHit();
}

void BlockBehaviour::getHit()
{
	health--;
	if(health < 1)
	{
		entity->destroy();
		blocksDestroyed++;
		if (blocksDestroyed % ballsPerBlock == 0)
		{
			entityManager.addEntity<Ball>();
		}
	}
}
