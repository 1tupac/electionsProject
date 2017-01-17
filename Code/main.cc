#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "window.hh"
#include "database.hh"
#include "chart.hh"
#include "button.hh"

class Button;


int main( int argc, char* args[] )
{

	//Window window(65,36,21,21); //600*360

	Window window(25,40,21,21); //525 x 840

	// test database candidates
	Database db;
	db.create_candidates();
	db.statistic_candidates();

	// load images
 	//SDL_Texture* image = db.loadSurface(&window, "Images/rectangle.png");
 	SDL_Texture* button = db.loadSurface(&window, "Images/button.png");

 	Chart chart(&window, 100, 150, 500, 300);

 	Point p(10,10);
 	Point p1(0, 15);
 	Point p2(0,0);
 	std::string str ="YEah mane DASFJLKWFAASDFAsd";
 	//window.draw_text(str, p2);


 	Button bPie(750, 100);
 	Button bBar(750, 150);


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


 			//Handle button events
 			bPie.handleEvent( &e );
 			bBar.handleEvent( &e);
			
 		}

 		

 		
 		//window.draw_image(button, p1);

 		// Clear screen
 		SDL_SetRenderDrawColor(window._renderer, 230, 255, 255, SDL_ALPHA_OPAQUE);
 		SDL_RenderClear(window._renderer);

 		//window.draw_image(image, p);

 		SDL_SetRenderDrawColor(window._renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
 		SDL_RenderDrawLine(window._renderer, 320, 200, 300, 0);


		std::array<int, 5> votes = {14, 25, 37, 67, 23};
 		chart.plotBarChart(votes);


 		window.draw_text(str, p2);

 		// draw button
 		bPie.draw_button(&window, "Images/pieChart.png");
 		bBar.draw_button(&window, "Images/barChart.png");



 		//SDL_RenderPresent(window._renderer);
 		window.updateScreen();

 		//window.updateScreen();

		SDL_Delay( 1000 );
 	}
		

	//Free resources and close SDLs
	//SDL_DestroyTexture(image);
	//image = NULL;
	SDL_DestroyTexture(button);
	button = NULL;



	return 0;
}
