#pragma once


#ifndef RESISTOR_H
#define RESISTOR_H

class Resistor {
public:

	Resistor(double res, bool trueForParallel);

	Resistor getResistor();

	double getResistance();

	bool isParallel();

	bool isSeries();

private:
	double resistance;
	bool parallel;



};


#endif