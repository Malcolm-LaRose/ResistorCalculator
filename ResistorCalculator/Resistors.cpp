#include "Resistors.h"

Resistors::Resistors() : totalResistance(0) {}

void Resistors::addParallelResistor() {
	// Push to current vector
}

void Resistors::addSeriesResistor() {
	// Add as first member of next vector
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
}



Resistor Resistors::getResistor(int col, int row) {
	return setOfResistors[col][row];
}

double Resistors::getTotalResistance() {
	return totalResistance;
}

