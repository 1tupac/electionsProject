#include "database.hh"

// constructor
Database::Database()
{
	// define candidats and add them to list
	Candidate cand1("Mr. Pink");
	Candidate cand2("Princess Leia");
	Candidate cand3("Hercules");

	_list_candidates.push_back(cand1);
	_list_candidates.push_back(cand2);
	_list_candidates.push_back(cand3);


	/*
	// load images
	if ( dir != "")
	{
		// chart
		if( !(_image_chart = IMG_Load((filename + "/chart.png").c_str())) )
			std::cout "Could not load " << (filename + "/chart.png").c_str() << "Error: " << IMG_GetError << "\n" << std::endl;

		// button update
		if( !(_image_button_update = IMG_Load((filename + "/buttonUpdate.png").c_str())) )
			std::cout "Could not load " << (filename + "/buttonUpdate.png").c_str() << "Error: " << IMG_GetError << "\n" << std::endl;	

		// button reset
		if( !(_image_button_reset = IMG_Load((filename + "/buttonReset.png").c_str())) )
			std::cout "Could not load " << (filename + "/buttonReset.png").c_str() << "Error: " << IMG_GetError << "\n" << std::endl;	

		// text start
		if( !(_image_text_start = IMG_Load((filename + "/textStart.png").c_str())) )
			std::cout "Could not load " << (filename + "/textStart.png").c_str() << "Error: " << IMG_GetError << "\n" << std::endl;

	}
	else
	{
		std::cout << "Could not load images. Save them in an extra directory! \n" << std::endl;
	}
	*/
}


// destructor
Database::~Database()
{
	/*
	SDL_FreeSurface(_image_chart);
	SDL_FreeSurface(_image_button_update);
	SDL_FreeSurface(_image_button_reset);
	SDL_FreeSurface(_image_text_start);
	*/
}

// print names of candidates
void Database::statistic_candidates()
{
	list<Candidate>::iterator i;

	std::cout << "---- Statistic candidates ----" << std::endl;
	for(i=_list_candidates.begin(); i!= _list_candidates.end(); ++i)
	{
		std::cout << "Name: " << (*i).get_name() << ", Score: " << (*i).get_score() << std::endl;
	}
}
