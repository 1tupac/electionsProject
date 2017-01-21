#include "election.hh"



Election::Election()
{
	//_window(25,40,21,21) //525 x 840

/*	_window = Window(25,40,21,21);
	_db.create_candidates();
	_db.statistic_candidates();
*/
}

Election::~Election()
{
	//Free resources and close SDLs
/*	SDL_DestroyTexture(_button);
	_button = NULL;
	*/
}

/*
// initialise Election
void Election::initialise()
{
	std::cout << "Initialise program" << std::endl;

	// load image button on the right side
	_button = _db.loadSurface(&(_window), "Images/button.png");

	// define window for bar chart
	_chart = Chart(&(_window), 100, 150, 500, 300);

	// define sample text
 	_text_string = "sample text YEAH!!!!!";

 	// define both buttons on the right side
 	_bPie = Button(750, 100);
 	_bBar = Button(750, 150);

 	// define text print
 	_p_text = Point(0.0,0.0);

}


// run program
void Election::run()
{
	std::cout << "Run program" << std::endl;


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
 			for(std::list<Candidate>::const_iterator iter = _db._list_candidates.begin(), end = _db._list_candidates.end(); iter != end; iter++)
			{
				// check if user clicks on a button of the candidats

				//(*iter)._button_candidate.handleEventElectionEl( &e, iter );
				//(*iter)._button_candidate.handleEventElectionEl( &e );
				(*iter).check_event_click( &e );
			}
			
 		}
		

 		SDL_SetRenderDrawColor(_window._renderer, 230, 255, 255, SDL_ALPHA_OPAQUE);
 		SDL_RenderClear(_window._renderer);


 		SDL_SetRenderDrawColor(_window._renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
 		SDL_RenderDrawLine(_window._renderer, 320, 200, 300, 0);

 		// plot bar chart
		_chart.plotBarChart(&(_db));

		// print text
 		_window.draw_text(_text_string, _p_text);

 		// draw buttons on the right side
  		_db.draw_button(&(_window), "Images/pieChart.png", _bPie);
 		_db.draw_button(&(_window), "Images/barChart.png", _bBar);

 		// update screen
 		_window.updateScreen();

		SDL_Delay( 1000 );
 	}

}

*/