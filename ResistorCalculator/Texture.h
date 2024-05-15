#pragma once

#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>

static class Texture {
public:
	static SDL_Texture* loadTexture(const char* fileName, SDL_Renderer* rend);



};



#endif