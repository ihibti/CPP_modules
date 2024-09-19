#ifndef POINT_HPP
# define POINT_HPP

# include "fixed.hpp"

class Point
{
  private:
	Fixed m_x;
	Fixed m_y;

  public:
	Point();
	~Point();
	Point(const float x, const float y);
	Point(const Point &other);
	Point &operator=(const Point &other);
	Fixed &getx();
	Fixed &gety();
	bool operator==(const Point &other) const;
	friend Fixed get_are(const Point &a, const Point &b, const Point &c);
};
bool	bsp(Point const a, Point const b, Point const c, Point const point);
#endif