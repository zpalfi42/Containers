#ifndef	TEST_HPP
#	define	TEST_HPP

#	include <vector>
#	include  <iostream>
#	include <typeinfo>
#	include <map>
#	include<unistd.h>
#	include <vector.hpp>
#	include <time.h>

#	define RED 	"\033[1;31m"
#	define	RESET	"\033[0m"
#	define WHITE	"\033[21;37m"
#	define GREEN	"\033[1;32m"
#	define BLUE 	"\033[1;34m"

#	include <sstream>

#	define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

void	iteratorsTest( void );
void	riteratorTests( void );

#endif