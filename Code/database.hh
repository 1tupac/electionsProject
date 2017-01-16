#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "window.hh"
#include <list>
#include "candidate.hh"


class Candidate;

class Database
{
	protected:
		//SDL_Surface* _image_chart;
		//SDL_Surface* _image_button_update;
		//SDL_Surface* _image_button_reset;
		//SDL_Surface* _image_text_start;

		std::list<Candidate> _list_candidates; // list of all candidates

		std::list<string> list_textOutput;


	public:
		Database();
		~Database();
		void create_candidates();

		void statistic_candidates();

		SDL_Texture* loadSurface(Window* screen, std::string filepath);

};