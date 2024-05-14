#include "resistor.h"
#include "Settings.h"

Resistor::Resistor(double res, bool trueForParallel) : resistance(res), parallel(trueForParallel) {}

double Resistor::getResistance() {
	return resistance;
}

bool Resistor::isParallel() {
	return parallel;
}

bool Resistor::isSeries() {
	return !parallel;
}

