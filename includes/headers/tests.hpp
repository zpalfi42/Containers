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
# include <map.hpp>

# define RED 	"\033[1;31m"
# define RESET	"\033[0m"
# define WHITE	"\033[0;37m"
# define GREEN	"\033[1;32m"
# define BLUE 	"\033[1;34m" 

#define BLK "\e[0;30m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

//Regular underline text
# define UBLK "\e[4;30m"
# define URED "\e[4;31m"
# define UGRN "\e[4;32m"
# define UYEL "\e[4;33m"
# define UBLU "\e[4;34m"
# define UMAG "\e[4;35m"
# define UCYN "\e[4;36m"
# define UWHT "\e[4;37m"

#define MAX_RAM 429496729
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

# define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

void	iteratorsTest( void );
void	riteratorsTests( void );
void	vectorsTest( void );
void mapTest();
void testOk();
void testKo();
void	printCase( std::string s, bool b , bool endl);

#endif