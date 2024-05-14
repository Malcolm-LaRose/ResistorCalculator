#include "calculator.h"
#include "Settings.h"
#include "Resistors.h"
#include "resistor.h"

#include <iostream>


Calculator::Calculator() : settings(MySettings::getInstance()), screenWidth(settings.initScreenWidth), screenHeight(settings.initScreenHeight) {
	initAll();
}

void Calculator::initAll() {
	Calculator::initSDL();
	Calculator::initObjects();
}

void Calculator::initSDL() {
	running = true;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		running = false;
	}
	else
	{

		// Create window
		window = SDL_CreateWindow("SDL Playground", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			running = false;
		}
		else
		{
			// Create renderer for window
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				running = false;
			}

			// Initialize SDL_ttf
			else if (TTF_Init() != 0) {
				printf("SDL_ttf initialization failed");
				running = false;
			}

			// Init background
			SDL_SetRenderDrawColor(renderer, settings.bgColor.r, settings.bgColor.g, settings.bgColor.b, settings.bgColor.a);



		}
	}

	if (!running)
	{
		SDL_Quit();
		renderer = nullptr;
		window = nullptr;
	}
}

void Calculator::initObjects() {

	// init objects here

}

void Calculator::handleEvents() {

	SDL_Event event;
	SDL_PollEvent(&event); // Pointer to event

	while (SDL_PollEvent(&event) != 0) {

		// Log event type
		// printf("Event type: %d\n", event.type);

		if (event.type == SDL_QUIT) {
			clean();
		}

		else if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
			switch (event.key.keysym.sym) {
			case SDLK_PLUS:
				// Add series resistor

				break;
			case SDLK_ASTERISK:
				// Add parallel resistor

				break;
			}
		}
	}


}

void Calculator::update() {

}

void Calculator::render() {
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}

void Calculator::clean() {

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	system("cls");
	std::cout << "Cleanup complete!";

}

bool Calculator::isRunning() {
	return running;
}

