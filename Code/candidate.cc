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
	int mode = ButtonMode::getMode();

	// if the function handleEventElectionEl returns one, the user clicked on the button
	if( _button_candidate.handleEvent( e ) == 1 )
	{
		switch(mode)
		{
			case 0:
				this->set_score(0);
				break;

			case 1:
				this->set_score(this->get_score()+1);
				break;

			case 2:
				this->set_score(this->get_score()+1);
				break;

			case 3:
				this->set_score(rand() % 10 + 1);
				break;
		}

	} else {
		switch(mode)
		{
			case 0:
				this->set_score(0);
				break;

			case 2:
				if (rand() % 100 < 8)
				{
					std::cout << "Enter random" << std::endl;
					this->set_score(this->get_score() + rand() % 3);
				}
				break;

			case 3:
				//this->set_score(rand() % 10 + 1);
				break;
		}
	}

}

