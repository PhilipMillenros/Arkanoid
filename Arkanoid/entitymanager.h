#pragma once
#include <memory>
#include <vector>
#include "ECS.h"

class EntityManager
{
private:
	std::vector<std::unique_ptr<Entity>> entities;
public:
	void update();
	void refresh();
	size_t entityCount() const;
	template<typename T>
	T& addEntity()
	{
		T* entity = new T();
		std::unique_ptr<T> uPtr{ entity };
		entities.emplace_back(std::move(uPtr));
		entity->awake();
		return *entity;
	}
};
