#pragma once

#ifndef RESISTORS_H
#define RESISTORS_H

#include "Settings.h"
#include "resistor.h"

#include <SDL.h>

#include <vector>

// For storing an arbitrary set of Resistor objects
class Resistors {
public:

	Resistors();

	void addParallelResistor(double res);

	void addSeriesResistor(double res);

	double calculateTotalResistance();

	double calculateParallelResistance(std::vector<Resistor> parallelResistors);

	Resistor getResistor(int col, int row);

	double getTotalResistance();

	int getNumSeriesResistors();

	int getNumParallelResistors();

	void renderResistors(SDL_Renderer* renderer); // Tells resistors where to be rendered


private:
	std::vector<std::vector<Resistor>> setOfResistors;
	double totalResistance;

	int numParallelResistors;
	int numSeriesResistors;

	SDL_Texture* totalResistanceTexture;

	const MySettings& settings;


};

#endif
