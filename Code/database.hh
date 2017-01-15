#pragma once

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
#include <list>
#include "window.hh"
#include "point.hh"
#include "candidate.hh"

using namespace std;

class Candidate;

class Database
{
	protected:
		//SDL_Surface* _image_chart;
		//SDL_Surface* _image_button_update;
		//SDL_Surface* _image_button_reset;
		//SDL_Surface* _image_text_start;

		list<Candidate> _list_candidates; // list of all candidates

		list<string> list_textOutput;



	public:
		//Database(std::string directory = "" );
		Database();
		~Database();
		void statistic_candidates();
};