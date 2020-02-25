#pragma once

#include "Object.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"

class Player : public Object {

public: 
	Player(SDL_Renderer* renderer) : Object(typeid(Player)) {

		AddComponent<TransformComponent>(Vector2{ 0.0f });
		AddComponent<SpriteComponent>(renderer, "Resources/Sprites/Test.png");

		TransformComponent* transform = &GetComponent<TransformComponent>();
		transform->SetSpeed(1.0f);
		transform->SetVelocity(Vector2{ 1.0f, 0.0f });
	}
};