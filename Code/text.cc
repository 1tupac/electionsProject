#include "text.hh"

Text::Text(Window *window, int x, int y, std::string font, int fontSize):
	_window(window),
	_x(x),
	_y(y)
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
	// colour
	SDL_Color foreground = { 0, 0, 0 };		// noir
	SDL_Color background = { 255, 255, 255 };	// blanc

	SDL_Surface* textSurface=TTF_RenderText_Shaded(_font,text.c_str(),foreground,background);
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(_window->_renderer, textSurface);

	SDL_Rect position;
	position.w = textSurface->w;
	position.h = textSurface->h;
	position.x = (_window->get_width() - position.w)/2;
	position.y = y;
	
	SDL_RenderCopy(_window->_renderer, textTexture, NULL, &position);
	SDL_FreeSurface(textSurface);
}

void Text::displayMovingText(int speed, std::string text)
{
	// colour
	SDL_Color foreground = { 0, 0, 0 };		// noir
	SDL_Color background = { 255, 255, 255 };	// blanc

	SDL_Surface* textSurface=TTF_RenderText_Shaded(_font,text.c_str(),foreground,background);
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(_window->_renderer, textSurface);

	SDL_Rect position;
	position.w = textSurface->w;
	position.h = textSurface->h;
	position.x = _x - speed;
	_x = _x - speed;
	position.y = _y;

	SDL_RenderCopy(_window->_renderer, textTexture, NULL, &position);
	SDL_FreeSurface(textSurface);
}

