#include "Texture.h"

Texture::Texture()  {}

SDL_Texture* Texture::loadTexture(const char* fileName) {
	SDL_Surface* tempSurface = IMG_Load(fileName);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Calculator::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	if (!tempSurface) {
		std::cout << "Texture not loaded!";
	}

	return tex;
}