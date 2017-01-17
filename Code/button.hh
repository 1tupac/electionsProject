#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "database.hh"
#include "window.hh"


class Window;

// button constants
const int BUTTON_WIDTH = 30;
const int BUTTON_HEIGHT = 30;

// constants defining if mouse moved over, up, down,...
enum ButtonSprite
{
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
	BUTTON_SPRITE_TOTAL = 4
};

class Button: public Database
{
	public:

		Button(float x0, float y0);
		~Button();


		// Handles mouse event
		void handleEvent( SDL_Event* e );
	

		float get_button_x();
		float get_button_y();
		
		// vote for candidat
		virtual void vote();

		//void draw_button(Window*, SDL_Texture* image);
		void draw_button(Window* window, std::string filepath);

	private:
		//Top left position
		Point _button_pos;

		//Current used sprite
		ButtonSprite _mouse_current_sprite;
	
		// texture/image of button
		SDL_Texture* _button_image;
};






