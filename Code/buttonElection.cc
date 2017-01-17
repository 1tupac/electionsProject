#include "buttonElection.hh"

ButtonElection::ButtonElection(float x0, float y0):
	Button(x0, y0)
{}

ButtonElection::~ButtonElection()
{}

void ButtonElection::vote()
{
	std::cout << "cluck" << std::endl;
}