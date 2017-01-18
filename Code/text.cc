#include "text.hh"

Text::Text(Window *window, int x, int y, int w, int h, std::string font, int fontSize):
	_window(window),
	_x(x),
	_y(y),
	_w(w),
	_h(h)
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
	SDL_Rect position;	
	position.x=55;
	position.y=55;
	
	
	// colour
	SDL_Color foreground = { 0, 0, 0 };		// noir
	SDL_Color background = { 255, 255, 255 };	// blanc
	
	SDL_Surface* textSurface=TTF_RenderText_Shaded(_font,text.c_str(),foreground,background);
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(_window->_renderer, textSurface);
	

	position.w = textSurface->w;
	position.h = textSurface->h;

	SDL_RenderCopy(_window->_renderer, textTexture, NULL, &position);

	SDL_FreeSurface(textSurface);
}

