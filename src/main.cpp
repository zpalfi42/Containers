#include <vector>
#include  <iostream>
#include <typeinfo>
#include <map>
#include <vector.hpp>

int main( void )
{
	std::vector<int>	v(1, 42);
	std::vector<int>	v2(4, 666);
	v.push_back(1);
	v2.push_back(1);
	
	std::vector<int>::iterator	it = v.begin();
	std::vector<int>::iterator	end = v.end();

	std::vector<int>::iterator	it2 = v2.begin();
	std::vector<int>::iterator	end2 = v2.end();

	ft::vector<int>	ftv(it, end);
	ft::vector<int>	ftv2;

	ftv2.assign(it2, end2);

	int	*	p = ftv.data();

	std::cout << *p << " " << *(p + 1) << std::endl;

	// std::cout << ftv.capacity() << std::endl;
	// std::cout << ftv2.capacity() << std::endl;

	ftv2 = ftv;

	// std::cout << ftv.capacity() << std::endl;
	// std::cout << ftv2.capacity() << std::endl;
}