#include "election.hh"



Election::Election():
	_window(25,40,21,21), //525 x 840
	_chart(&(_window), 170, 150, 500, 300),
	_bBar(Button(750, 150)),
	//_p_text(Point(0.0,0.0)),
	_textTuto(Text(&(_window), 800, 250, "Font/Roboto-Thin.ttf", 20)),
	_textMoving(Text(&_window, 900, 30, "Font/Roboto-Thin.ttf", 30))
{
	 
	std::cout << "Initialise program\n" << std::endl;

	// load image button on the right side
	_button = _db.loadSurface(&(_window), "Images/button.png");

	// define sample text
 	_text_string = "sample text YEAH!!!!!";
	
	_db.create_candidates();
	_db.statistic_candidates();
}

Election::~Election()
{
	//Free resources and close SDLs
	SDL_DestroyTexture(_button);
	_button = NULL;
	
}

// run program
void Election::run()
{
	std::cout << "Run program" << std::endl;


 	// quit flag
 	bool quit = false;
 	bool clic = false;

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
 			if (e.type == SDL_MOUSEBUTTONDOWN)
	 			clic = true;

 			//Handle button events
 			for(std::list<Candidate>::const_iterator iter = _db._list_candidates.begin(), end = _db._list_candidates.end(); iter != end; iter++)
			{
				// check if user clicks on a button of the candidats

				//(*iter)._button_candidate.handleEventElectionEl( &e, iter );
				//(*iter)._button_candidate.handleEventElectionEl( &e );
				(*iter).check_event_click( &e );
			}
			
 		}
		

 		SDL_SetRenderDrawColor(_window._renderer, 240, 240, 240, SDL_ALPHA_OPAQUE);
 		SDL_RenderClear(_window._renderer);


 		SDL_SetRenderDrawColor(_window._renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
 		//SDL_RenderDrawLine(_window._renderer, 320, 200, 300, 0);

 		// plot bar chart
		_chart.plotBarChart(&(_db));

		// print text
 		//_window.draw_text(_text_string, _p_text);

 		// draw buttons on the right side
  		//_db.draw_button(&(_window), "Images/pieChart.png", _bPie);
 		//_db.draw_button(&(_window), "Images/barChart.png", _bBar);
 		if (!clic)
 			_textTuto.displayText(700, 470, "< Clic to vote");
 		std::vector<std::string> movingMessages;
 		movingMessages.push_back("Princess Leila is doing a press conference");
 		movingMessages.push_back("Hercules is in Turkey to see the president");
 		movingMessages.push_back("Is Mr. Pink the new black?");
 		_textMoving.displayMovingText(2, movingMessages);

 		// update screen
 		_window.updateScreen();

		SDL_Delay( 20 );
 	}

}
