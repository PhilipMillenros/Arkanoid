#include "game.h"




void EntityManager::refresh()
{
	entities.erase(std::remove_if(std::begin(entities), std::end(entities), [](const std::unique_ptr<Entity>& mEntity)
	{
		return mEntity->isWaitingForDestroy();
	}),
		std::end(entities));
}
void EntityManager::update()
{
	
	for (const std::unique_ptr<Entity>& entity : entities)
	{
		if(!entity->isWaitingForDestroy())
			entity->update();
	}
	
}

size_t EntityManager::entityCount() const
{
	return entities.size();
}

