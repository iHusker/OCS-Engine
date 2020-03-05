#pragma once

//Library Includes
#include "Resource.h"

//Local Includes
#include "Object.h"
#include "TransformComponent.h"

class SpriteComponent : public Component
{
public:
	SpriteComponent(SDL_Renderer* renderer, std::string imageFile) {
		texture = IMG_LoadTexture(renderer, imageFile.c_str());

		if (texture == nullptr) {
			std::cout << "Error: " << SDL_GetError() << std::endl;
		}
		else {
			source.x = source.y = 0;
			SDL_QueryTexture(texture, NULL, NULL, &source.w, &source.h);
		}
	}

	~SpriteComponent() {
		SDL_DestroyTexture(texture);
	}

	bool Link() override
	{
		if (object->HasComponent<TransformComponent>()) {
			transform = &object->GetComponent<TransformComponent>();
			return true;
		}
		return false;
	}

	void Render(SDL_Renderer* renderer) override {
		destination = {
					static_cast<int>(transform->GetPosition().x),
					static_cast<int>(transform->GetPosition().y),
					source.w,
					source.h
		};

		SDL_RenderCopyEx(renderer, texture, &source, &destination, angle, NULL, flip);
	}

private:
	TransformComponent* transform;
	SDL_Texture* texture;

	SDL_RendererFlip flip = SDL_FLIP_NONE;
	SDL_Rect source = {}, destination = {};

	float angle = 0.0f;
};