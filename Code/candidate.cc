#include "candidate.hh"


Candidate::Candidate(std::string name):
	_name(name),
	_score(0),
	_button_candidate(0.0,0.0)
{
	//button_candidate=NULL;
}

Candidate::~Candidate(){};

std::string Candidate::get_name() const
{
	return _name;
}

int Candidate::get_score() const
{
	return _score;
}


void Candidate::set_score(int s) const
{
	this->_score = s;
}



// create for a button to vote for candidat
void Candidate::set_button_election( float x, float y) const
{
	_button_candidate = ButtonElection(x,y);
}

ButtonElection Candidate::get_button_candidate() const
{
	return _button_candidate;
}


void Candidate::set_image_button_filePath(std::string filePath)
{
	_image_button_filePath = filePath;
}

std::string Candidate::get_image_button_filePath() const
{
	return _image_button_filePath;
}


int Candidate::check_event_click(SDL_Event* e) const
{
	// if the function handleEventElectionEl returns one, the user clicked on the button
	if( _button_candidate.handleEvent( e ) == 1 )
	{
		int randomNumber = rand() % 3 + 1; // random number between 1,2,3
		std::cout << "cluck: " << randomNumber << std::endl;

		// TO DO: DECIDE WHAT TO DO WHEN USERS CLICK ON BUTTON
		switch(randomNumber)
		{
			case 1:	this->set_score(this->get_score()*2);
					std::cout << "double score" << std::endl;
					break;

			case 2: this->set_score(this->get_score()-1);
					std::cout << "score minus 1" << std::endl;
					break;

			case 3: this->set_score(rand() % 10 - 1);
					std::cout << "score is a random number between 0 and 10" << std::endl;
					break;
		}
	}

}

