#pragma once
#include "button.hh"
#include <stdlib.h>
//#include "candidate.hh"

//class Candidate;
//class Database;


class ButtonElection: public Button
{
	public:
		ButtonElection(float x0, float y0);
		ButtonElection(float x0, float y0, int w, int h, int id);

		~ButtonElection();

		// handle event of buttonElection
		int handleEvent(SDL_Event* e, int bW=BUTTON_WIDTH, int bH=BUTTON_HEIGHT) const;

		
		// redirection of equal
		ButtonElection operator=(const ButtonElection& button) const; 

};

