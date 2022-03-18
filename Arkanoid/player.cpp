#include "player.h"
#include "collision.h"
#include "shape.h"

void Player::awake()
{
	rectangleSprite = &addComponent<Rectangle>();
	movement = &addComponent<HorizontalMovement>();
	rectCollider = &addComponent<RectCollider>();
	rectCollider->dimensions = dimensions;
	rectangleSprite->dimensions = dimensions;
	transform->position = startPosition;
	tag = "player";
}


