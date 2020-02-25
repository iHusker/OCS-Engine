#include "Engine.h"

int main(int argc, char* argv[]) {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) 
	{
		std::cout << "Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	Uint32 startFrame, timeFrame;

	Engine* engine = new Engine("2DEngine");

	while (true)
	{
		startFrame = SDL_GetTicks();

		engine->Render();
		engine->Process();
		engine->Listen();

		timeFrame = SDL_GetTicks() - startFrame;

		if (FRAME_DELAY > timeFrame) SDL_Delay(FRAME_DELAY - timeFrame);
	}

	engine->Clean();
	delete engine;

	return 0;
}