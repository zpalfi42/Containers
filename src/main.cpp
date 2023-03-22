#include <tests.hpp>

int main( void )
{
	// iteratorsTest();
	// riteratorsTests();
	// vectorsTest();

	ft::map<int, int>	m;
	m.insert(ft::make_pair(1, 1));
	std::cout << m.size() << std::endl;
}