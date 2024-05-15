#pragma once

#ifndef TEXTURE_H
#define TEXTURE_H

#include "calculator.h"

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>

static class Texture {

	Texture();

	static SDL_Texture* loadTexture(const char* fileName);



};



#endif