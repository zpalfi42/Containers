#include <vector>
#include  <iostream>
#include <typeinfo>
#include <map>
#include <vector.hpp>

int main( void )
{
	std::vector<int>	v(4, 42);

	std::vector<int>::iterator	it = v.begin();
	std::vector<int>::iterator	end = v.end();


	typedef	ft::iterator_traits<ft::iterator<ft::random_access_iterator_tag, ft::random_access_iterator_tag, ft::random_access_iterator_tag, ft::random_access_iterator_tag, ft::random_access_iterator_tag> > aa;
	
	if (aa::iterator_category == ft::random_access_iterator_tag)
    std::cout << "int* is a random-access iterator";
	while (it != end)
	{
		std::cout << *it << std::endl;
		std::advance(it, 1);
	}
}