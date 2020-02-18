#pragma once

#include <iostream>

class Object;

class Component
{
public:
	Object* object = nullptr;

	virtual void Render() {}
	virtual void Process(float deltaTime) {}
	virtual bool Link() { return false; }
	virtual std::string Error() { return "NULL"; };
};
