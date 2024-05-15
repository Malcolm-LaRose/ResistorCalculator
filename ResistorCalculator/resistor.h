#pragma once

#ifndef RESISTOR_H
#define RESISTOR_H

// #include "Texture.h"

#include <iostream>
#include <SDL.h>

class Resistor {
public:

	Resistor(double res, bool trueForParallel, float x, float y);

	double getResistance();

	bool isParallel();

	bool isSeries();

	void renderResistor(SDL_Renderer* renderer);

	static SDL_Texture* resistorTexture;

private:
	double resistance;
	bool parallel; // May not be necessary

	float xPos; // Position
	float yPos;

	SDL_FRect textRect;

	



};


#endif