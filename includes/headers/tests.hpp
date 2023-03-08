#ifndef	TEST_HPP
# define	TEST_HPP

# include <map>
# include <vector>
# include <time.h>
# include <sstream>
# include <iostream>
# include <typeinfo>
# include <unistd.h>
# include <vector.hpp>

# define RED 	"\033[1;31m"
# define RESET	"\033[0m"
# define WHITE	"\033[0;37m"
# define GREEN	"\033[1;32m"
# define BLUE 	"\033[1;34m" 

# define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

void	iteratorsTest( void );
void	riteratorsTests( void );
void	vectorsTest( void );

#endif