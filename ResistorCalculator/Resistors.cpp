#include "Resistors.h"
#include "resistor.h"

Resistors::Resistors() : totalResistance(0), numResistors(0), colNum(0) {}

void Resistors::addParallelResistor(double res) {
	// Push Resistor to current vector
	if (numResistors == 0) {
		addSeriesResistor(res);
	}
	else {
		Resistor resistor(res, true);

		setOfResistors[colNum].push_back(resistor);
	}
	numResistors++;
}

void Resistors::addSeriesResistor(double res) {
	// Add Resistor as first member of next vector
	std::vector<Resistor> resistorCol;
	Resistor resistor(res, false);
	resistorCol.push_back(resistor);

	setOfResistors.push_back(resistorCol);

	numResistors++;
	colNum++;
}

double Resistors::calculateTotalResistance() {
	// Sum of all resistances

	if (colNum == 0) return 0;

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

