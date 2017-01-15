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
#include "database.hh"
#include "chart.hh"




SDL_Texture* loadSurface(Window* screen, std::string filepath)
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
		// Convert image/surface to screen format
		//imageSurface = screen->convert_surface(loadedImage);
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


int main( int argc, char* args[] )
{

	//Window window(65,36,21,21); //600*360

	Window window(25,40,21,21); //600*360

	Database database;

	database.statistic_candidates();

 	SDL_Texture* image = loadSurface(&window, "rectangle.png");

 	SDL_Texture* button = loadSurface(&window, "button.png");

 	Chart chart(&window, 40, 40, 300, 200);

 	Point p(10,10);
 	Point p1(0, 15);
 	Point p2(0,0);
 	std::string str ="YEah mane DASFJLKWFAASDFAsd";
 	//window.draw_text(str, p2);

 	// quit flag
 	bool quit = false;

 	// event handler
 	SDL_Event e;

 	// while application is running
 	while ( !quit )
 	{
 		// handle events on queue
 		while ( SDL_PollEvent( &e ) != 0 )
 		{
 			// user requests quit
 			if ( e.type == SDL_QUIT )
 				quit = true;
 		}

 		
 		//window.draw_image(button, p1);

 		SDL_SetRenderDrawColor(window._renderer, 230, 255, 255, SDL_ALPHA_OPAQUE);


 		SDL_RenderClear(window._renderer);
 		window.draw_image(image, p);
 		//SDL_RenderCopy(window._renderer, image, NULL, NULL);
 		//SDL_RenderCopy(window._renderer, button, NULL, NULL);
 		SDL_SetRenderDrawColor(window._renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
 		SDL_RenderDrawLine(window._renderer, 320, 200, 300, 0);


		std::array<int, 5> votes = {14, 25, 37, 67, 23};
 		chart.plotBarChart(votes);

 		window.draw_text(str, p2);

 		//SDL_RenderPresent(window._renderer);
 		window.updateScreen();

 		//window.updateScreen();

		SDL_Delay( 1000 );
 	}
		

	//Free resources and close SDLs
	SDL_DestroyTexture(image);
	image = NULL;
	SDL_DestroyTexture(button);
	button = NULL;



	return 0;
}
