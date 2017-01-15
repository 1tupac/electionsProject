#pragma once

#include <stdio.h>
#include <iostream>
#include "point.hh"
#ifdef MAC
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#endif

//Screen dimension constants
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;


class Window 
{
  private:
	std::size_t _height;	// height
	std::size_t _width;		// length
	std::size_t _x_case;	// subdivise window in smaller parts
	std::size_t _y_case;	// subdivise window in smaller parts like a matrix
	TTF_Font* _font;
	

  public:
	//SDL_Surface*_window;	// Window
	
	//The window we'll be rendering to
	SDL_Window* _window; //gWindow;
	
	//The surface contained by the window
	SDL_Surface* _windowSurface;

	//The window renderer for graphics
	SDL_Renderer* _renderer;

	Window(int h, int w, int x, int y);
	~Window();
	void draw_image(SDL_Texture*, Point pos);
	void updateScreen();
	void draw_text(std::string text, Point pos);
};

