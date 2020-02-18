#pragma once

#include "Object.h"
#include "TransformComponent.h"

class SpriteComponent : public Component
{
public:
	bool Link() override
	{
		if (object->HasComponent<TransformComponent>()) {
			return true;
		}
		return false;
	}

	std::string Error() override {
		return "Object Requires TransformComponent to add SpriteComponent.";
	}
};