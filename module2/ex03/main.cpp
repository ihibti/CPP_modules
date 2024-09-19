#include "Point.hpp"

int	main(void)
{
	Point a(0.0f, 0.0f);
	Point b(20.0f,0.0f);
    Point c(10.0f,30.0f);
    Point p(10.0f,15.0f);

	if (bsp(a,b,c,p))
		std::cout << "point is inside the triangle\n";
	else
		std::cout << "no he s not  \n";
}