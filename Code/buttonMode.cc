#include "buttonMode.hh"

int ButtonMode::_mode = 1;

ButtonMode::ButtonMode(float x0, float y0):
	ButtonElection(x0, y0)
{

}

ButtonMode::ButtonMode(float x0, float y0, int w, int h, int id):
	ButtonElection(x0, y0, w, h, id)
{

}

ButtonMode::~ButtonMode()
{

}

void ButtonMode::handleMode(SDL_Event* e)
{
	if (handleEvent(e, _wB, _hB) == 1)
	{
		_mode = _id;
		std::cout << "Mode " << _mode << std::endl;
	}
}


SDL_Texture* ButtonMode::loadSurface(Window* screen, std::string filepath)
{
	// define the returned surface image
	//SDL_Surface* imageSurface = NULL;
	SDL_Texture* imageSurface = NULL;

	// Load image
	SDL_Surface* loadedImage = IMG_Load(filepath.c_str());
	if( loadedImage == NULL )
	{
		std::cout << "Unable to load image " << filepath.c_str() << "SDL_image ERROR: "<< IMG_GetError() << "\n" << std::endl;
	}
	else
	{
		// create texture from surface object
		imageSurface = SDL_CreateTextureFromSurface(screen->_renderer, loadedImage);


		if ( imageSurface == NULL)
		{
			std::cout << "Unable to adjust image to screen " << filepath.c_str() << "! SDL_Error: " << SDL_GetError << "\n" << std::endl;
		}

		// free old surface
		SDL_FreeSurface(loadedImage);
	}

	return imageSurface;
}

void ButtonMode::draw_button(Window* window, std::string filepath)
{

	set_button_image( loadSurface(window, filepath) );

	SDL_Rect position;
	int selected = 0;

	if (_mode == _id)
	{
		selected = 50;
	}
	if (_mode == 0)
	{
		_mode = 1;
	}

	position.x = get_button_x()+selected;
   	position.y = get_button_y();
	position.w = get_button_w();
	position.h = get_button_h();

	SDL_RenderCopy(window->_renderer, get_button_image(), NULL, &position);
}

int ButtonMode::getMode()
{
	return _mode;
}

