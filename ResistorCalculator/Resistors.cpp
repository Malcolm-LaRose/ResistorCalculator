#include "Resistors.h"
#include "Settings.h"
#include "resistor.h"

Resistors::Resistors() : totalResistance(0), numParallelResistors(0), numSeriesResistors(0), settings(MySettings::getInstance()) {
	// Call resistor texture init
}

void Resistors::addParallelResistor(double res) {
	// Push Resistor to current vector
	if (numParallelResistors == 0 && numSeriesResistors == 0) {
		addSeriesResistor(res);
	}
	else {
		Resistor resistor(res, true, numSeriesResistors * 200.0, settings.screenCenter.y - settings.resistorTextureSize + (numParallelResistors * 200.0));

		setOfResistors[numSeriesResistors - 1].push_back(resistor);
	}
	numParallelResistors++;
}

void Resistors::addSeriesResistor(double res) {
	// Add Resistor as first member of next vector
	std::vector<Resistor> resistorCol;
	Resistor resistor(res, false, numSeriesResistors * 200.0, settings.screenCenter.y - settings.resistorTextureSize);
	resistorCol.push_back(resistor);

	setOfResistors.push_back(resistorCol);

	numSeriesResistors++;
}

double Resistors::calculateTotalResistance() {
	// Sum of all resistances

	if (numParallelResistors == 0 || numSeriesResistors == 0) return 0;

	for (auto& resistorColumn : setOfResistors) {
		return Resistors::calculateParallelResistance(resistorColumn);
	}
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
	for (int i = 0; i < numSeriesResistors; i++) {
		for (int j = 0; j < numParallelResistors; j++) {
			setOfResistors[i][j].renderResistor();
		}
	}
}

