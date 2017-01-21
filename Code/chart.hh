#pragma once
//#include "window.hh"
#include <array>
#include <algorithm>
#include "database.hh"
//#include "buttonElection.hh"


class Chart: public Database
{
public:
	Chart(Window *window, int x, int y, int w, int h);
	~Chart();
	//template<std::size_t SIZE>
	//void plotBarChart(std::array<int, 5> &votes);
	void plotBarChart(Database* db);

	Chart operator=(const Chart& chart) const; // redirection equal

	// getters
	Window* get_window();// const;
	int get_x();// const;
	int get_y();// const;
	int get_w();// const;
	int get_h();// const;
	int get_margin();// const;



private:
	mutable Window* _window;
	mutable int _x;
	mutable int _y;
	mutable int _w;
	mutable int _h;
	mutable int _margin;
	
};
