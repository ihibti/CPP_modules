#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

# include "Base.hpp"
# include <cstdlib> // For rand()
# include <ctime>
# include <iostream>

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif
