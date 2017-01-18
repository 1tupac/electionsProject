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


		std::list<string> list_textOutput;
		int _number_candidats;


	public:
		Database();
		~Database();
		void create_candidates();

		void statistic_candidates();

		int get_highest_score() const; // returns highest score of all candidats

		SDL_Texture* loadSurface(Window* screen, std::string filepath);

		std::list<Candidate> _list_candidates; // list of all candidates
		int get_number_candidats();

};