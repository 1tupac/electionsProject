#pragma once
//#include "window.hh"
#include <array>
#include <algorithm>
#include "database.hh"


class Chart: public Database
{
public:
	Chart(Window *window, int x, int y, int w, int h);
	~Chart();
	//template<std::size_t SIZE>
	//void plotBarChart(std::array<int, 5> &votes);
	void plotBarChart(Database* db);

private:
	Window* _window;
	int _x;
	int _y;
	int _w;
	int _h;
	int _margin;
	
};
