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
#include <string>
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

class Button
{
	public:

		Button(float x0, float y0);
		Button(float x0, float y0, int w, int h, int id);
		~Button();


		// Handles mouse event	
		virtual int handleEvent( SDL_Event* e ) const {};

	
		// getters
		float get_button_x() const;
		float get_button_y() const;
		int get_button_w() const;
		int get_button_h() const;
		Point get_button_pos() const;
		SDL_Texture* get_button_image() const;
		ButtonSprite get_mouse_current_sprite() const;


		// setters
		void set_button_image(SDL_Texture*) const;

		// vote for candidat
		//virtual void vote();

		Button operator=(const Button& button) const; // redirection equal



	protected:
		//Top left position
		Point _button_pos;

		int _wB;
		int _hB;
		int _id;

		//Current used sprite
		mutable ButtonSprite _mouse_current_sprite;
	
		// texture/image of button
		mutable SDL_Texture* _button_image;


};






