#include "election.hh"



Election::Election():
	_window(25,40,21,21), //525 x 840
	_chart(&(_window), 170, 150, 500, 300),
	_reset(ButtonMode(20, 100, 70, 70, 0)),
	_regular(ButtonMode(20, 200, 70, 70, 1)),
	_watch(ButtonMode(20, 300, 70, 70, 2)),
	_random(ButtonMode(20, 400, 70, 70, 3)),
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
				(*iter).check_event_click( &e );
			}
			_reset.handleMode(&e);
			_regular.handleMode(&e);
			_watch.handleMode(&e);
			_random.handleMode(&e);
			
 		}
 		_window.windowBackground(ButtonMode::getMode());
 		
 		// plot bar chart
		_chart.plotBarChart(&(_db));

 		// draw buttons on the right side
 		_reset.draw_button(&(_window), "Images/graph.png");
 		_regular.draw_button(&(_window), "Images/clock.png");
 		_watch.draw_button(&(_window), "Images/rocket.png");
 		_random.draw_button(&(_window), "Images/brain.png");
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
