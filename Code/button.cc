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
	std::cout << "e->type: " << e->type << std::endl;
	if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );

		//Check if mouse is in button
		bool inside = true;

		std::cout << "bx: " << _button_pos.get_x() << " by: " << _button_pos.get_y() << std::endl;
		std::cout << "x: " << x << " y: " << y << std::endl;


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
float Button::get_button_x()
{
	return _button_pos.get_x();
}

// get button y
float Button::get_button_y()
{
	return _button_pos.get_y();
}



// draw button
//void Window::draw_button(SDL_Texture* image, Button b)
void Button::draw_button(Window* window, std::string filepath)
{

	// texture/image of button
	//_button_image = loadSurface(screen, filepath);
	//SDL_Texture* _button_image = load_button(&window, filepath);

	_button_image = loadSurface(window, filepath);

	SDL_Rect position;
	position.x = get_button_x();//*window->get_x_case();
   	position.y = get_button_y();//*window->get_y_case();
   	//int w=50, h=50;
   	//SDL_QueryTexture(image, NULL, NULL, &w, &h);
   	position.w = BUTTON_WIDTH;
   	position.h = BUTTON_HEIGHT;//image->h;

	SDL_RenderCopy(window->_renderer, _button_image, NULL, &position);
}


