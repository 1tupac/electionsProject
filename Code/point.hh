#pragma once

class Point {
  private:
	float _x;
	float _y;
  public:
	Point(float x, float y);
	~Point() {}
	float get_x() const;
	float get_y() const;
	Point operator=(const Point& p); // affectation
	Point operator+(const Point& p); // addition
	Point operator-(const Point& p); // substraction
	bool operator==(const Point& p); // equality
	bool operator!=(const Point& p); // not equal
};
