#pragma once

#include "player.h"
#include "entitymanager.h"
#include "collisionmanager.h"
#include "grid.h"
#define blockWidth 40
#define blockHeight 20
#define ballsPerBlock 4
extern int blocksDestroyed;
extern Player player;
extern EntityManager entityManager;
extern CollisionManager collisionManager;
extern Grid grid;

