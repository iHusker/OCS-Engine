#pragma once
#include "Resource.h"
#include "Component.h"

class Object
{
public:
	Object(std::type_index index) : index(index) {

	}

	~Object()
	{
		for (auto& component : components) delete component.second;
	}

	void Process(float deltaTime)
	{
		for (auto& component : components) component.second->Process(deltaTime);
	}

	void Render(SDL_Renderer* renderer)
	{
		for (auto& component : components) component.second->Render(renderer);
	}

	template <typename T, typename... A> void AddComponent(A&& ... a)
	{
		T* component = new T(std::forward<A>(a)...);
		component->object = this;

		if (component->Link())
		{

			std::cout << "(" << index.hash_code() << ") " << index.name() << " ADDED: " << typeid(T).name() << std::endl;

			components.insert(std::pair<std::type_index, Component*>(
				std::type_index(typeid(T)),
				std::move(component)
				));
		}
		else
		{
			std::cout << "(" << index.hash_code() << ") ERROR: " << component->Error() << std::endl;
			delete component;
		}
	}

	template <typename T> T& GetComponent()
	{
		return *dynamic_cast<T*>(components[typeid(T)]);
	}

	template <typename T> bool HasComponent() {
		std::map<std::type_index, Component*>::iterator it;
		it = components.find(typeid(T));
		return it != components.end();
	}

	std::type_index GetIndex() {
		return index;
	}

private:
	std::type_index index;
	std::map<std::type_index, Component*> components;
};