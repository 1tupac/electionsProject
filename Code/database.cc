#include "database.hh"

// constructor
Database::Database()
{;}


// destructor
Database::~Database()
{;}

void Database::create_candidates()
{
	// define candidats and add them to list
	Candidate cand1("Mr. Pink");
	Candidate cand2("Princess Leia");
	Candidate cand3("Hercules");

	_list_candidates.push_back(cand1);
	_list_candidates.push_back(cand2);
	_list_candidates.push_back(cand3);

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



