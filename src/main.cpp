#include <tests.hpp>

int main( void )
{
	iteratorsTest();
	riteratorsTests();
	vectorsTest();

	std::map<int, int>	m;

	m.insert(std::make_pair(1,42));

	std::map<int, int>::iterator	it = m.begin();

	m.insert(it, std::make_pair(1, 24));

	std::cout << it->second << std::endl;
}