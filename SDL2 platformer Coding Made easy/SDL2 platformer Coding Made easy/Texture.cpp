#include "Texture.h"



Texture::Texture()
{
	font = TTF_OpenFont("arial.ttf", 32);
	textTexture = NULL;
	textWidth = textHeight = 0;
}


Texture::~Texture()
{
	free();
}


void Texture::free()
{
	SDL_DestroyTexture(textTexture);
	textTexture = NULL;
	textWidth = textHeight = 0;
}

void Texture::renderText(int x, int y, SDL_Renderer *renderer)
{
	SDL_Rect rect = { x,y, textWidth, textHeight };

	SDL_RenderCopy(renderer, textTexture, NULL, &rect);
}

bool Texture::loadText(std::string text, SDL_Color color,SDL_Renderer *renderer )
{
	SDL_Surface *loadedText = TTF_RenderText_Solid(font, text.c_str(), color);

	textTexture = SDL_CreateTextureFromSurface(renderer, loadedText);

	textWidth = loadedText->w;
	textHeight = loadedText->h;

	SDL_FreeSurface(loadedText);

	return textTexture != 0;
}