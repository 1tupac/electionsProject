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

//#include <string>
#include "window.hh"
#include <list>
#include "candidate.hh"
#include "buttonMode.hh"


class Candidate;

class Database
{
	protected:

		std::list<std::string> _list_button_file; // list of all button .png which will be loaded

		int _number_candidats;


	public:
		Database();
		~Database();
		void create_candidates();

		void statistic_candidates();

		// getters
		int get_highest_score() const; // returns highest score of all candidats
		int get_number_candidats();


		void draw_button(Window* window, std::string filepath, const Button &button);

		SDL_Texture* loadSurface(Window* screen, std::string filepath);

		std::list<Candidate> _list_candidates; // list of all candidates



};