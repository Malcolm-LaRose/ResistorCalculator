#include "Resistors.h"
#include "Settings.h"
#include "resistor.h"

#include <iostream>

Resistors::Resistors() : totalResistance(0), numParallelResistors(0), numSeriesResistors(0), settings(MySettings::getInstance()) {}

void Resistors::addParallelResistor(double res) {
	// Push Resistor to current vector
	if (numSeriesResistors == 0) {
		addSeriesResistor(res);
		return;
	}

	// Get the last column of resistors
	auto& lastColumn = setOfResistors[setOfResistors.size() - 1];

	Resistor resistor(res, true, ((numSeriesResistors - 1) * 200.0) + 25 * (numSeriesResistors - 1), 200 - settings.resistorTextureSize + ((numParallelResistors + 1) * 200.0));

	// setOfResistors[numSeriesResistors - 1].push_back(resistor);
	lastColumn.push_back(resistor);
	numParallelResistors++;
	calculateTotalResistance();
	// std::cout << "Added parallel resistor: " << resistor.getResistance() << std::endl; // Debugging output

}

void Resistors::addSeriesResistor(double res) {
	numParallelResistors = 0;
	// Add Resistor as first member of next vector
	std::vector<Resistor> resistorCol;
	Resistor resistor(res, false, (numSeriesResistors * 200.0) + 25 * (numSeriesResistors), 200 - settings.resistorTextureSize);
	resistorCol.push_back(resistor);

	setOfResistors.push_back(resistorCol);
	// std::cout << "Added series resistor: " << resistor.getResistance() << std::endl; // Debugging output
	numSeriesResistors++;
	calculateTotalResistance();
}

double Resistors::calculateTotalResistance() {
	// Sum of all resistances
	if (numParallelResistors == 0 || numSeriesResistors == 0) return 0;

	for (auto& resistorColumn : setOfResistors) {
		totalResistance += Resistors::calculateParallelResistance(resistorColumn);
	}

	// std::cout << "Total (Ohms): " << total << std::endl; --> Doesn't work?

	return totalResistance;
}

double Resistors::calculateParallelResistance(std::vector<Resistor> parallelResistorColumn) {
	double inverseSum = 0;
	for (auto& resistor : parallelResistorColumn) {
		if (resistor.getResistance() == 0) {
			return 0;
		}
		inverseSum += 1.0 / resistor.getResistance();
	}
	return 1.0 / inverseSum;
}

Resistor Resistors::getResistor(int col, int row) {
	return setOfResistors[col][row];
}

double Resistors::getTotalResistance() {
	return totalResistance;
}

int Resistors::getNumSeriesResistors() {
	return numSeriesResistors;
}

int Resistors::getNumParallelResistors() {
	return numSeriesResistors;
}

void Resistors::renderResistors(SDL_Renderer* renderer) {
	// Loop over all resistors and call their render functions

	for (auto& column : setOfResistors) {
		for (auto& resistor : column) {
			resistor.renderResistor(renderer);
		}
	}
}

