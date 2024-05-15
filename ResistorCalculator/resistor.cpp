#include "resistor.h"
#include "Texture.h"
#include "calculator.h"

Resistor::Resistor(double res, bool trueForParallel, float x, float y) : resistance(res), parallel(trueForParallel), xPos(x), yPos(y) {

	resistorTexture = Texture::loadTexture("Resistor.png", Calculator::renderer);

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

void Resistor::renderResistor() {
	SDL_RenderDrawRect(Calculator::renderer, &textRect);
}
