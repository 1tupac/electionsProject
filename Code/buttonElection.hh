#pragma once
#include "button.hh"


class ButtonElection: public Button
{
	public:
		ButtonElection(float x0, float y0);

		~ButtonElection();

		// vote for candidat
		void vote();

};