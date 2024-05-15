#include "Texture.h"

SDL_Texture* Texture::loadTexture(const char* fileName, SDL_Renderer* rend) {
	SDL_Surface* tempSurface = IMG_Load(fileName);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, tempSurface);
	SDL_FreeSurface(tempSurface);

	if (!tempSurface) {
		std::cout << "Texture not loaded!";
	}

	return tex;
}