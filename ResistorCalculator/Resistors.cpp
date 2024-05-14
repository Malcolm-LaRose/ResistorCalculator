#include "Resistors.h"
#include "resistor.h"

Resistors::Resistors() : totalResistance(0), numResistors(0) {}

void Resistors::addParallelResistor(int res) {
	// Push to current vector

	numResistors++;
	if (colNum == 0) colNum++;
}

void Resistors::addSeriesResistor(int res) {
	// Add as first member of next vector

	numResistors++;
	colNum++;
}

double Resistors::calculateTotalResistance() {
	// Sum of all resistances
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

int Resistors::getNumResistors() {
	return numResistors;
}

