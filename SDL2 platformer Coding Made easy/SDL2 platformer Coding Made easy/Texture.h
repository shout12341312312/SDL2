#pragma once
#include "header.h"
class Texture
{
public:
	Texture();
	~Texture();
	bool loadText(std::string text, SDL_Color, SDL_Renderer *renderer);
	void renderText(int x, int y, SDL_Renderer *renderer);
	void free();
private:
	SDL_Texture *textTexture;
	TTF_Font *font;

	int textWidth, textHeight;
};

