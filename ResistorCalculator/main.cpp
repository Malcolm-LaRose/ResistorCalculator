#include "Settings.h"
#include "color.h"
#include "timer.h"

#include "calculator.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


// Globals
SDL_Renderer* Calculator::renderer = nullptr;

int main(int argc, char* argv[]) {

	Uint32 frameStart = 0;
	int frameTime = 0;
	Uint32 count = 0;

	const MySettings& settings = MySettings::getInstance();

	Calculator* calc = nullptr;
	calc = new Calculator;

	MyTimer_us* timer = nullptr;
	timer = new MyTimer_us;


	// Main Loop
	while (calc->isRunning()) {
		// timer->markFrameBeginTime();

		frameStart = SDL_GetTicks();

		calc->handleEvents(); // Event handling
		calc->update(frameTime); // Game logic
		calc->render(frameTime); // Rendering

		// timer->markFrameEndTime(); 
		// timer->logFPS();
		// system("cls");
		// std::cout << "\rAVG SDL FPS: " << (wrapper->getCount() * 1000) / SDL_GetTicks() << std::endl; --> Agrees with below
		std::cout << "\rAVG FPS: " << (count * 1000000) / timer->getTotalTimeElapsed().count() << std::flush;

		frameTime = SDL_GetTicks() - frameStart;

		if ((1000 / settings.frameRateCap) > frameTime) {
			SDL_Delay((1000 / settings.frameRateCap) - frameTime);
		}

		count++;

	}

	// Quit
	calc->clean();
	timer = nullptr;
	calc = nullptr;

	return 0;
}