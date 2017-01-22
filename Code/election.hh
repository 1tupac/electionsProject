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
#include <iostream>
#include <vector>

#include "window.hh"
#include "database.hh"
#include "chart.hh"
#include "button.hh"
#include "text.hh"
#include "buttonElection.hh"
#include "buttonMode.hh"

class Button;
class Window;
class Database;
class Chart;
class Text;
class ButtonMode;

class Election
{
	private:
		Window _window;
		Database _db;
	 	SDL_Texture* _button; // button a droite

 		Chart _chart; // bar chart
	 	std::string _text_string;

 		ButtonMode _reset;
 		ButtonMode _regular;
 		ButtonMode _watch;
 		ButtonMode _random;

 		Text _textTuto;
 		Text _textMoving;


	public:
		Election();
		~Election();
		void run();

};

