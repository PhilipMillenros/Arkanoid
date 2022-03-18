#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>


class RectCollider;
typedef std::size_t ComponentID;

class Transform;
class Component;
class Entity;


inline ComponentID getComponentID()
{
	static ComponentID previousID = 0;
	return previousID++;
}

template <typename T> ComponentID getComponentID() noexcept
{
	static ComponentID typeID = getComponentID();
	return typeID;
}
constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component
{
	
public:
	Entity* entity;
	Transform* transform;
	
	virtual void awake() {}
	virtual void update() {}

	virtual ~Component();
	virtual void onCollisionEnter(RectCollider& collider) {}
	virtual void onCollisionStay(RectCollider& collider) {}
	virtual void onCollisionExit(RectCollider& collider) {}
};
class Entity
{
private:
	bool isDestroyed{};
	std::vector<std::unique_ptr<Component>> components;
	ComponentArray componentArray{};
	ComponentBitSet componentBitSet;
public:
	std::string tag;
	virtual ~Entity();
	Transform* transform{};
	void onCollisionEnter(RectCollider& collider);
	void onCollisionStay(RectCollider& collider);
	void onCollisionExit(RectCollider& collider);
	Entity();
	virtual void awake();
	virtual void update();
	bool isWaitingForDestroy() const;
	void destroy() { isDestroyed = true; }
	
	template<typename T>
	bool hasComponent() const;
	
	template <typename T, typename ... TArgs>
	T& addComponent(TArgs&&... mArgs)
	{
		T* component(new T(std::forward<TArgs>(mArgs)...));
		component->entity = this;
		std::unique_ptr<Component> uPtr{ component };
		components.emplace_back(std::move(uPtr));
		componentArray[getComponentID<T>()] = component;
		componentBitSet[getComponentID<T>()] = true;
		component->awake();
		component->transform = &getComponent<Transform>();
		return *component;
	}
	template <typename T>
	T& getComponent() const
	{
		auto ptr(componentArray[getComponentID<T>()]);
		return *static_cast<T*>(ptr);
	}
	
};
