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
//void Chart::plotBarChart(std::array<int, 5> &votes)
void Chart::plotBarChart(Database* db)
{

	//std::size_t size = 5;//votes->size();
	std::size_t size = db->get_number_candidats(); // size = number of candidates


	//int max = *(std::max_element(votes.begin(), votes.end()));
	int max = db->get_highest_score();

	/*if (size > 6)
	{
		;//std::cout << "Big votes array" << std::endl;
	}*/
	
	SDL_Rect barRect;
	std::cout << "size: " << size << " max: " << max << std::endl;

	//Preliminary computation of sizes:
	int wOfBar = _w / size - _margin;
	/*for(int i = 0; i < size; i++)
	{
		barRect.x = _x + i * (wOfBar + _margin);
		barRect.h = (votes[i] / (double)max) * _h;
		barRect.y = _y + _h - barRect.h;
		barRect.w = wOfBar;
		std::cout << i << " - x : " << barRect.x << " y : " << barRect.y << " w : " << barRect.w << " h : " << barRect.h << std::endl;
		SDL_RenderFillRect(_window->_renderer, &barRect);
	}*/
	int i = 0;
	for(const auto& iter : db->_list_candidates)
	{
		std::cout << "iter.get_score()" << iter.get_score() << std::endl;
		barRect.x = _x + i * (wOfBar + _margin);
		barRect.h = (iter.get_score() / (double)max) * _h;
		barRect.y = _y + _h - barRect.h;
		barRect.w = wOfBar;
		std::cout << i << " - x : " << barRect.x << " y : " << barRect.y << " w : " << barRect.w << " h : " << barRect.h << std::endl;
		SDL_RenderFillRect(_window->_renderer, &barRect);
		i++;
	}

}
