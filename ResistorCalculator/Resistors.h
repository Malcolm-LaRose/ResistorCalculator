#pragma once

#ifndef RESISTORS_H
#define RESISTORS_H

#include "resistor.h"

#include <vector>

// For storing an arbitrary set of Resistor objects
class Resistors {
public:

	Resistors();

	void addParallelResistor();

	void addSeriesResistor();

	double calculateTotalResistance();

	double calculateParallelResistance(std::vector<Resistor> parallelResistors);

	Resistor getResistor(int col, int row);

	double getTotalResistance();


private:
	std::vector<std::vector<Resistor>> setOfResistors;
	double totalResistance;


};

#endif
