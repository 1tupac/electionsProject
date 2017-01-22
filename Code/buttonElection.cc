#include "buttonElection.hh"

ButtonElection::ButtonElection(float x0, float y0):
	Button(x0, y0)
{;}

ButtonElection::ButtonElection(float x0, float y0, int w, int h, int id):
	Button(x0, y0, w, h, id)
{;}

ButtonElection::~ButtonElection()
{;}



int ButtonElection::handleEvent(SDL_Event* e, int bW, int bH) const
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
		else if( x > _button_pos.get_x() + bW )
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < _button_pos.get_y() )
		{
			inside = false;
		}
		//Mouse below the button
		else if( y > _button_pos.get_y() + bH )
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
					//std::cout << "dd X: " << e->motion.x << ", Y: " << e->motion.y << std::endl;
					break;
			
				case SDL_MOUSEBUTTONDOWN:
					_mouse_current_sprite = BUTTON_SPRITE_MOUSE_DOWN;

					switch( e->button.button)
					{
						case SDL_BUTTON_LEFT:
							//std::cout << "Coucou buttonEl mousemotion" << std::endl;

							//voteJoke();
							return 1;
							break;
					}

					break;
			}
		}
	}

	return 0;
}



ButtonElection ButtonElection::operator=(const ButtonElection& button) const
{
	_button_pos = button.get_button_pos();
	_mouse_current_sprite = button.get_mouse_current_sprite();
	_button_image = button.get_button_image();
	return *this;
}
