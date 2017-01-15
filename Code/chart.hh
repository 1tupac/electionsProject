#pragma once
#include "window.hh"
#include <array>
#include <algorithm>


class Chart
{
public:
	Chart(Window *window, int x, int y, int w, int h);
	~Chart();
	//template<std::size_t SIZE>
	void plotBarChart(std::array<int, 5> &votes);

private:
	Window* _window;
	int _x;
	int _y;
	int _w;
	int _h;
	int _margin;
	
};
