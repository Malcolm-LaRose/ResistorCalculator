#pragma once


#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Settings.h"

#include <SDL.h>
#include <SDL_ttf.h>

class Calculator {
public:

	Calculator();

	void initAll();

	void initSDL();

	void initObjects();

	void handleEvents();

	void update();

	void render();

	void clean();

	bool isRunning();

	static SDL_Renderer* renderer;


private:

	const MySettings& settings;
	bool running;
	SDL_Window* window;
	int screenWidth;
	int screenHeight;





};

#endif