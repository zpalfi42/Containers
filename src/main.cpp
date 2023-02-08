#include <vector>
#include  <iostream>
#include <typeinfo>
#include <map>
#include <vector.hpp>

int main( void )
{
	std::vector<int>	v(4, 42);
	v.push_back(1);

	std::vector<int>::iterator	it = v.begin();
	std::vector<int>::iterator	end = v.end();

	std::map<int, std::string> numbers;
	numbers.insert (std::make_pair(1, "one"));

	std::reverse_iterator<std::map<int, std::string>::iterator>	rev(numbers.end());

	ft::vector<int>	ftv(it, end);

	while (it != end)
	{
		std::cout << *it << std::endl;
		std::advance(it, 1);
	}
}