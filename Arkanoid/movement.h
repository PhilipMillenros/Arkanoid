#pragma once
#include "ECS.h"

class HorizontalMovement : public Component
{
public:
	void awake() override;
	void update() override;
};
