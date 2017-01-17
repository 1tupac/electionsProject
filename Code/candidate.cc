#include "candidate.hh"


Candidate::Candidate(string name):
	_name(name),
	_score(0)
{}

Candidate::~Candidate(){};

string Candidate::get_name()
{
	return _name;
}

int Candidate::get_score() const
{
	return _score;
}

void Candidate::set_score(int s)
{
	_score = s;
}
