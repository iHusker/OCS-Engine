#pragma once

#include "Resource.h"
#include "Player.h"


//Components
#include "TransformComponent.h"
#include "SpriteComponent.h"

class Engine 
{

public:
	Engine(std::string name) {
		Uint32 flags = SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI;

		SDL_DisplayMode displayMode;
		SDL_GetCurrentDisplayMode(0, &displayMode);

		window = SDL_CreateWindow(name.c_str(), (displayMode.w - WINDOW_WIDTH) / 2, (displayMode.h - WINDOW_HEIGHT) / 2, WINDOW_WIDTH, WINDOW_HEIGHT, flags);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		surface = SDL_GetWindowSurface(window);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_UpdateWindowSurface(window);
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

		objects.push_back(new Player(renderer));
	}

	void Render() {

		SDL_RenderClear(renderer);

		for (auto& object : objects) object->Render(renderer);

		SDL_RenderPresent(renderer);
	}
	
	void Process() {
		lastFrame = currentFrame;
		currentFrame = SDL_GetPerformanceCounter();

		for (auto& object : objects) object->Process((currentFrame - lastFrame) / (float)SDL_GetPerformanceFrequency());
	}

	void Listen() {
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT: {
			break;
		}
		default:
			break;
		}
	}

	void Clean()
	{
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		exit(0);
	}

private:

	Uint64 currentFrame = 0;
	Uint64 lastFrame = 0;

	std::vector<Object*> objects;

	SDL_Renderer* renderer = nullptr;
	SDL_Window* window = nullptr;
	SDL_Surface* surface = nullptr;

	SDL_Event event;
};