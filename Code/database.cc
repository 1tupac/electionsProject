#include "database.hh"

// constructor
Database::Database()
{
	_number_candidats=0;
}


// destructor
Database::~Database()
{;}

void Database::create_candidates()
{
	// define candidats and add them to list
	Candidate cand1("Mr. Pink");
	Candidate cand2("Princess Leia");
	Candidate cand3("Hercules");

	// only to test
	cand1.set_score(3);
	cand2.set_score(5);
	cand3.set_score(8);

	_list_candidates.push_back(cand1);
	_number_candidats++;
	_list_candidates.push_back(cand2);
	_number_candidats++;

	_list_candidates.push_back(cand3);
	_number_candidats++;

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


// returns highest score of all candidates
int Database::get_highest_score() const
{
	std::size_t i; 
	int highest_score = 0;
	int current_score;

	//for(const auto& iter : _list_candidates)
	for(std::list<Candidate>::const_iterator iter = _list_candidates.begin(), end = _list_candidates.end(); iter != end; iter++)
	{
		current_score = (*iter).get_score();
		if (current_score > highest_score)
			highest_score = current_score;
	}

	return highest_score;
}

// load surface
SDL_Texture* Database::loadSurface(Window* screen, std::string filepath)
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


int Database::get_number_candidats()
{
	return _number_candidats;
}



