#pragma once

#include "Resource.h"

class Object;

class Component
{
public:
	Object* object = nullptr;

	virtual void Render(SDL_Renderer * renderer) {}
	virtual void Process(float deltaTime) {}
	virtual bool Link() { return false; }
};
