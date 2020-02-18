#pragma once

#include "Component.h"

class TransformComponent : public Component
{
public:
	void Process(float deltaTime) override {
		std::cout << "Processing Transform" << std::endl;
	}

	void Render() override {
		std::cout << "Rendering Transform" << std::endl;
	}

	bool Link() override { return true; }
};