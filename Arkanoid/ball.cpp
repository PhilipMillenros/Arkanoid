#include "ball.h"


void Ball::awake()
{
	sprite = &addComponent<Rectangle>();
	collider = &addComponent<RectCollider>();
	ballBehaviour = &addComponent<BallBehaviour>();
	sprite->dimensions = dimensions;
	collider->dimensions = dimensions;
}
