#pragma once

#include "Object.h"
#include "Player.h"

class Scene {

public:

	Scene(SDL_Renderer* renderer, std::type_index index) {
		b2Vec2 gravity(0.0f, -9.3f);
		world = new b2World(gravity);

		objects.push_back(new Player(renderer));
	}

	void Render(SDL_Renderer* renderer) {

		SDL_RenderClear(renderer);

		for (auto& object : objects) object->Render(renderer);

		SDL_RenderPresent(renderer);
	}


	void Process(float deltaTime)
	{

		for (auto& object : objects) object->Process(deltaTime);

		world->Step(deltaTime, velocityIterations, positionIterations);
	};

private:
	std::vector<Object*> objects;
	b2World* world;

	int32 velocityIterations = 6;
	int32 positionIterations = 2;
};