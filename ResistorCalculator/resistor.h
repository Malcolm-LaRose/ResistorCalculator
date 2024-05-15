#pragma once

#ifndef RESISTOR_H
#define RESISTOR_H

// #include "Texture.h"


#include <SDL.h>

class Resistor {
public:

	Resistor(double res, bool trueForParallel, float x, float y);

	double getResistance();

	bool isParallel();

	bool isSeries();

	void renderResistor();

private:
	double resistance;
	bool parallel; // May not be necessary

	float xPos; // Position
	float yPos;

	SDL_Texture* resistorTexture;
	SDL_Rect textRect;

	



};


#endif