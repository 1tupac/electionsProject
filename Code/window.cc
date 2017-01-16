
#include "window.hh"


Window::Window(int h, int w, int x, int y):
		_height(h),
		_width(w),
		_x_case(x),
		_y_case(y)
	{
		// initialise video
		std::cout << "SDL Initialisation" << std::endl;
		if( SDL_Init( SDL_INIT_VIDEO ) < 0)
		{
			std::cout << "Unable to set video mode: " << SDL_GetError() << std::endl;
			exit(-1);
		}


		//Create window
		std::cout << "Create Window" << std::endl;
		//_window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		_window = SDL_CreateWindow( "Fake election HAHA", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _width*_x_case, _height*_y_case, SDL_WINDOW_SHOWN  );

		if( _window == NULL )
		{
			std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << "\n" << std::endl;
		}
		else
		{
			//Get window surface
			//_windowSurface = SDL_GetWindowSurface( _window );

			//Create renderer for window
			_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
			if( _renderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
			} else {
				//Initialize renderer color
				SDL_SetRenderDrawColor( _renderer, 0xFF, 0xFF, 0xFF, 0xFF );

				printf( "Renderer OK\n" );


			}

		}

		// Initialise PNG loading
		int imgFlags = IMG_INIT_PNG; // returns the flags that loaded successfully
		if (!( IMG_Init( imgFlags ) & imgFlags ) )
		{
			std::cout << "SDL_image could not initialise! SDL_image Error: " << IMG_GetError() << "\n" << std::endl;
	 	}

	 	// Initialise text ttf
		if( TTF_Init() == -1 )
		{
			std::cout << "SDL_ttf could not initialise! Error: " << TTF_GetError() << std::endl;
			exit(-1);
		}
		
		// open font
		if( !(_font = TTF_OpenFont("Font/funnyFont.ttf",50)) ) {
			std::cout << "TTF_OpenFont could not initialise! Error: " << TTF_GetError() << std::endl;
			exit(-1);
		}
	

}


Window::~Window()
{

		//Destroy window
		//SDL_DestroyWindow( _window );
		//_window = NULL;

		SDL_DestroyRenderer(_renderer);
		_renderer = NULL;

		//Quit SDL subsystems
		SDL_Quit();
}


// draw image
void Window::draw_image(SDL_Texture* image, Point pos)
{
	SDL_Rect position;
	position.x = pos.get_x()*_x_case;
   	position.y = pos.get_y()*_y_case;
   	int w=0, h=0;
   	SDL_QueryTexture(image, NULL, NULL, &w, &h);
   	position.w = w;
   	position.h = h;//image->h;
	//SDL_BlitSurface(image, NULL , _windowSurface , &position);
	//SDL_BlitSurface(image, NULL , _windowSurface , NULL);

	SDL_RenderCopy(_renderer, image, NULL, &position);
}


// update screen
void Window::updateScreen()
{
 	//SDL_UpdateWindowSurface(_window);
 	SDL_RenderPresent(_renderer);


}

// draw text
void Window::draw_text(std::string text, Point pos) 
{
	SDL_Rect position;	
	position.x=55;//pos.get_x()*_x_case;		
	position.y=55;//pos.get_y()*_y_case;
	
	
	// colour
	SDL_Color foreground = { 0, 0, 0 };		// noir
	SDL_Color background = { 255, 255, 255 };	// blanc
	
	SDL_Surface* textSurface=TTF_RenderText_Shaded(_font,text.c_str(),foreground,background);
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(_renderer, textSurface);
	
	// ajout à l'écran
	//SDL_BlitSurface(textSurface, NULL, _windowSurface, &position);

	position.w = textSurface->w;
	position.h = textSurface->h;

	SDL_RenderCopy(_renderer, textTexture, NULL, &position);

	SDL_FreeSurface(textSurface);
}


std::size_t Window::get_height()
{
	return _height;
}

std::size_t Window::get_width()
{
	return _width;
}

std::size_t Window::get_x_case()
{
	return _x_case;
}

std::size_t Window::get_y_case()
{
	return _y_case;
}



