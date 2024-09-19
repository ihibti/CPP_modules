#include "Point.hpp"
#include "fixed.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	original;
	Fixed	PBC;
	Fixed	PAC;
	Fixed	PAB;

	if (a == b || b == c || c == a)
		return (std::cout << "error the points u entered are too close\n",
				false);
	if (a == point || c == point || b == point)
		return (false);
	original = get_are(a, b, c).abs();
	PBC = get_are(point, b, c).abs();
	PAC = get_are(point, a, c).abs();
	PAB = get_are(point, a, b).abs();
	return (original == (PBC + PAC + PAB));
}
