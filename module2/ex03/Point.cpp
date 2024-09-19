#include "Point.hpp"

Point::Point()
	: m_x(), m_y(){};

Point::Point(const float x, const float y)
	: m_x(x), m_y(y){};

Point::Point(const Point &other)
	: m_x(other.m_x), m_y(other.m_y){};

Point::~Point()
{
	std::cout << "destructeurs point\n";
}

Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
		this->m_x = other.m_x;
		this->m_y = other.m_y;
	}
	return (*this);
}

Fixed &Point::getx()
{
	return (this->m_x);
}
Fixed &Point::gety()
{
	return (this->m_y);
}
bool Point::operator==(const Point &other) const
{
	if (this->m_x.getRawBits() == other.m_x.getRawBits())
		if (this->m_y.getRawBits() == other.m_y.getRawBits())
			return (true);
	return (false);
}

Fixed	get_are(const Point &a, const Point &b, const Point &c)
{
	Fixed	surf1;
	Fixed	surf2;
	Fixed	surf3;
	Fixed	total;

	surf1 = a.m_x * (b.m_y - c.m_y);
	surf2 = b.m_x * (c.m_y - a.m_y);
	surf3 = c.m_x * (a.m_y - b.m_y);
	total = surf1 + surf2 + surf3;
	return (total);
}
