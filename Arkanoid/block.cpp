#include "block.h"

#include "collision.h"

void Block::awake()
{
	sprite = &addComponent<Rectangle>();
	sprite->dimensions = Vector2(50, 50);
	
	
	collider = &addComponent<RectCollider>();
	blockBehaviour = &addComponent<BlockBehaviour>();
	collider->dimensions = sprite->dimensions;
}
