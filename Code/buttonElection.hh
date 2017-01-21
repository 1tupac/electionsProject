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

		~ButtonElection();

		// handle event of buttonElection
		int handleEvent( SDL_Event* e) const;


		void handleEventMode(SDL_Event* e);
		
		// redirection of equal
		ButtonElection operator=(const ButtonElection& button) const; 

};

