#pragma once

#ifdef MAC
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#endif
#include <array>
#include <algorithm>
#include "window.hh"

class Text
{
public:
	Text(Window *window, int x, int y, std::string font, int fontSize);
	Text(Window *window, std::string font, int fontSize);
	~Text();
	void displayCenteredText(int y, std::string text);
	void displayMovingText(int speed, std::string text);

private:
	Window* _window;
	int _x;
	int _y;
	int _w;
	int _h;
	TTF_Font* _font;
	
};

