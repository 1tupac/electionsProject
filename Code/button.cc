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



void Button::handleEvent( SDL_Event* e )
{
	//If mouse event happened
	//std::cout << "e->type: " << e->type << std::endl;
	if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );

		//Check if mouse is in button
		bool inside = true;

		//std::cout << "bx: " << _button_pos.get_x() << " by: " << _button_pos.get_y() << std::endl;
		//std::cout << "x: " << x << " y: " << y << std::endl;


		//Mouse is left of the button
		if( x < _button_pos.get_x() )
		{
			inside = false;
		}
		//Mouse is right of the button
		else if( x > _button_pos.get_x() + BUTTON_WIDTH )
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < _button_pos.get_y() )
		{
			inside = false;
		}
		//Mouse below the button
		else if( y > _button_pos.get_y() + BUTTON_HEIGHT )
		{
			inside = false;
		}

		//Mouse is outside button
		if( !inside )
		{
			_mouse_current_sprite = BUTTON_SPRITE_MOUSE_OUT;
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch( e->type )
			{
				case SDL_MOUSEMOTION:
					_mouse_current_sprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
					std::cout << "dd X: " << e->motion.x << ", Y: " << e->motion.y << std::endl;
					break;
			
				case SDL_MOUSEBUTTONDOWN:
					_mouse_current_sprite = BUTTON_SPRITE_MOUSE_DOWN;

					switch( e->button.button)
					{
						case SDL_BUTTON_LEFT:
							std::cout << "Coucou button mousemotion" << std::endl;
							break;
					}

					break;
			}
		}
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

