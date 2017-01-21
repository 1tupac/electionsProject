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

class Button;
class Window;
class Database;
class Chart;
class Text;

class Election
{
	private:
		Window _window;
		Database _db;
	 	SDL_Texture* _button; // button a droite

 		Chart _chart; // bar chart
	 	std::string _text_string;

	 	//Button _bPie;
 		Button _bBar;

 		//Point _p_text; // point for text print
 		Text _textTuto;
 		Text _textMoving;


	public:
		Election();
		~Election();
		void run();

};

