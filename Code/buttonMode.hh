#pragma once
#include "buttonElection.hh"

class ButtonMode: public ButtonElection
{
public:
	ButtonMode(float x0, float y0);
	ButtonMode(float x0, float y0, int w, int h, int id);
	~ButtonMode();

	void handleMode(SDL_Event* e);

	SDL_Texture* loadSurface(Window* screen, std::string filepath);
	void draw_button(Window* window, std::string filepath);

	static int getMode();

private:
	static int _mode;
	
};

