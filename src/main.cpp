#include <tests.hpp>

int main( void )
{
	// iteratorsTest();
	// riteratorsTests();
	// vectorsTest();
	std::map<int, int>	m;
	ft::map<int, int>	f;

	m.insert(std::pair<int, int>(1, 1));
	m.insert(std::pair<int, int>(0, 0));
	m.insert(std::pair<int, int>(2, 2));

	std::map<int, int>::iterator	it = m.begin();

	while(it != m.end())
	{
		std::cout << it->first << " " << it->second << std::endl;
		it++;
	}
}