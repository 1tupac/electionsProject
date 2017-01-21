#include "text.hh"

Text::Text(Window *window, int x, int y, std::string font, int fontSize):
	_window(window),
	_x(x),
	_y(y),
	_index(0)
{
	if( !(_font = TTF_OpenFont(font.c_str(),fontSize)) ) {
		std::cout << "TTF_OpenFont could not initialise! Error: " << TTF_GetError() << std::endl;
		exit(-1);
	}
}

Text::Text(Window *window, std::string font, int fontSize):
	_window(window)
{
	if( !(_font = TTF_OpenFont(font.c_str(),fontSize)) ) {
		std::cout << "TTF_OpenFont could not initialise! Error: " << TTF_GetError() << std::endl;
		exit(-1);
	}
}

Text::~Text()
{

}

void Text::displayCenteredText(int y, std::string text)
{
	SDL_Color foreground = { 20, 20, 20 };

	SDL_Surface* textSurface=TTF_RenderText_Blended(_font,text.c_str(),foreground);
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(_window->_renderer, textSurface);

	SDL_Rect position;
	position.w = textSurface->w;
	position.h = textSurface->h;
	position.x = (_window->get_width() - position.w)/2;
	position.y = y;
	
	SDL_RenderCopy(_window->_renderer, textTexture, NULL, &position);
	SDL_FreeSurface(textSurface);
}

void Text::displayText(int x, int y, std::string text)
{
	SDL_Color foreground = { 20, 20, 20 };

	SDL_Surface* textSurface=TTF_RenderText_Blended(_font,text.c_str(),foreground);
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(_window->_renderer, textSurface);

	SDL_Rect position;
	position.w = textSurface->w;
	position.h = textSurface->h;
	position.x = x;
	position.y = y;
	
	SDL_RenderCopy(_window->_renderer, textTexture, NULL, &position);
	SDL_FreeSurface(textSurface);
}

void Text::displayMovingText(int speed, std::vector<std::string> textVector)
{
	SDL_Color foreground = { 20, 20, 20 };
	
	std::string text;
	
	text = textVector[_index];

	SDL_Surface* textSurface=TTF_RenderText_Blended(_font,text.c_str(),foreground);
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(_window->_renderer, textSurface);

	SDL_Rect position;
	position.w = textSurface->w;
	position.h = textSurface->h;
	position.x = _x - speed;
	_x = _x - speed;
	position.y = _y;

	if (_x + position.w < 0)
	{
		_x = _window->get_width();
		_index = rand()%textVector.size();
	}

	SDL_RenderCopy(_window->_renderer, textTexture, NULL, &position);
	SDL_FreeSurface(textSurface);
}

