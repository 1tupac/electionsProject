#include "point.hh"
#include <iostream>

Point::Point( float x, float y) : 
	_x(x),
	_y(y)
{;}

float Point::get_x() const {
	return _x;
}

float Point::get_y() const {
	return _y;
}

Point Point::operator=(const Point& p) {
	_x = p.get_x();
	_y = p.get_y();
	return *this;
}

Point Point::operator+(const Point& p) {
	Point p_new( _x+p.get_x(), _y+p.get_y() );
	return p_new;
}
Point Point::operator-(const Point& p) {
	Point p_new( _x-p.get_x(), _y-p.get_y() );
	return p_new;
}

bool Point::operator==(const Point& p)  {
	return ( _x==p.get_x() ) && ( _y==p.get_y() );
}

bool Point::operator!=(const Point& p) {
	return ( _x!=p.get_x() ) || ( _y!=p.get_y() );
}
