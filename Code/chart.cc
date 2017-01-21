#include "chart.hh"

Chart::Chart(Window *window, int x, int y, int w, int h):
	Database(),
	_window(window),
	_x(x),
	_y(y),
	_w(w),
	_h(h),
	_margin(20)
{

}

Chart::~Chart()
{

}

//template<std::size_t SIZE>
void Chart::plotBarChart(Database* db)
{

	std::size_t size = db->get_number_candidats(); // size = number of candidates

	int max = db->get_highest_score();

	
	SDL_Rect barRect;
	//std::cout << "size: " << size << " max: " << max << std::endl;

	//Preliminary computation of sizes:
	int wOfBar = _w / size - _margin;

	int i = 0;
	float temp_x, temp_y;
	for(const auto& iter : db->_list_candidates)
	{
		//std::cout << "iter.get_score()" << iter.get_score() << std::endl;
		barRect.x = _x + i * (wOfBar + _margin);
		barRect.h = (iter.get_score() / (double)max) * _h;
		barRect.y = _y + _h - barRect.h;
		barRect.w = wOfBar;
		//std::cout << "i: " << i << "bar - x : " << barRect.x << " y : " << barRect.y << " w : " << barRect.w << " h : " << barRect.h << std::endl;
		SDL_RenderFillRect(_window->_renderer, &barRect);

		// create for each bar a button vote
		temp_x = barRect.x + barRect.w - 70 - BUTTON_WIDTH/2;
		temp_y = barRect.y + barRect.h + 30 - BUTTON_HEIGHT/2;
		//std::cout << "temp_x " << temp_x << " temp_y: " << temp_y << std::endl;

		// add personal button to each candidate
		iter.set_button_election( temp_x, temp_y);
		db->draw_button(_window, iter.get_image_button_filePath(), iter.get_button_candidate());
		//std::cout << "i:" << i << ", button x: " << iter._button_candidate.get_button_x() << " button y: " << iter._button_candidate.get_button_y() << std::endl;
		i++;
	}
}

Chart Chart::operator=(const Chart& chart) const // redirection equal
{
	_window = chart._window;
	_x = chart._x;
	_y = chart._y;
	_w = chart._w;
	_h = chart._h;
	_margin = chart._margin;

	return *this;
}


Window* Chart::get_window()// const
{
	return _window;
}

int Chart::get_x() //const
{
	return _x;
}

int Chart::get_y() //const
{
	return _y;
}

int Chart::get_w() //const
{
	return _w;
}

int Chart::get_h() //const
{
	return _h;
}

int Chart::get_margin() //const
{
	return _margin;
}

