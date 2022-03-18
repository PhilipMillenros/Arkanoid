#pragma once
#include "ECS.h"
#include "engine.h"
#include "movement.h"
#include "vector2.h"


class Rectangle;
class RectCollider;

class Player : public Entity 
{
public:
	HorizontalMovement* movement;
	Rectangle* rectangleSprite;
	RectCollider* rectCollider;

	Vector2 dimensions = { 250, 10 };
	Vector2 startPosition = Vector2(screenWidth / 2, screenHeight - 20 );

	void awake() override;
};
