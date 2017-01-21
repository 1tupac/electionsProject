#include "button.hh"

// constructor
Button::Button(float x0, float y0):
	_button_pos(x0, y0)
{
	_mouse_current_sprite = BUTTON_SPRITE_MOUSE_OUT;
	_button_image = NULL;
}

// deconstructor
Button::~Button()
{
	// Free loaded images
	//gButtonSpriteSheetTexture.free();

	// free texture if it exists
	if ( _button_image != NULL )
	{
		SDL_DestroyTexture( _button_image );
		_button_image = NULL;
	}
}

	

// get button x
float Button::get_button_x() const
{
	return _button_pos.get_x();
}

// get button y
float Button::get_button_y() const
{
	return _button_pos.get_y();
}


Point Button::get_button_pos() const
{
	return _button_pos;
}


ButtonSprite Button::get_mouse_current_sprite() const
{
	return _mouse_current_sprite;
}



void Button::set_button_image(SDL_Texture* image) const
{
	_button_image = image;
}


SDL_Texture* Button::get_button_image() const
{
	return _button_image;
}


Button Button::operator=(const Button& button) const
{
	_button_pos = button.get_button_pos();
	_mouse_current_sprite = button.get_mouse_current_sprite();
	_button_image = button.get_button_image();
	return *this;
}

