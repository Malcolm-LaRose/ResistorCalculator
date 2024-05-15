#include "resistor.h"
#include "calculator.h"

Resistor::Resistor(double res, bool trueForParallel, float x, float y) : resistance(res), parallel(trueForParallel), xPos(x), yPos(y) {

	textRect.h = 200;
	textRect.w = 200;
	textRect.x = xPos;
	textRect.y = yPos;

}

double Resistor::getResistance() {
	return resistance;
}

bool Resistor::isParallel() {
	return parallel;
}

bool Resistor::isSeries() {
	return !parallel;
}

void Resistor::renderResistor(SDL_Renderer* renderer) {
	SDL_RenderCopyF(renderer, resistorTexture, nullptr, &textRect);
}
