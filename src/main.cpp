#include <vector>
#include  <iostream>
#include <typeinfo>
#include <map>
#include <vector.hpp>

int main( void )
{
	std::vector<int> v2(10, 42);
	ft::vector<int>	ftv2(10, 42);

	std::vector<int> v1(v2);
	ft::vector<int> v(ftv2);

	std::cout << v.size() << " " << v.capacity() << " " << v.front() << " " << v.back() << " " << v[10] << std::endl;
	std::cout << v1.size() << " " << v1.capacity() << " " << v1.front() << " " << v1.back() << " " << v1[10] << std::endl;

	v.resize(8, 0);
	v1.resize(8, 0);

	std::cout << v.size() << " " << v.capacity() << " " << v.front() << " " << v.back() << std::endl;
	std::cout << v1.size() << " " << v1.capacity() << " " << v1.front() << " " << v1.back() << std::endl;

	v.assign(50, 0);
	v1.assign(50, 0);

	v.resize(80, 60);
	v1.resize(80, 60);

	v.push_back(42);
	v1.push_back(42);

	std::cout << v.size() << " " << v.capacity() << " " << v.front() << " " << v.back() << std::endl;
	std::cout << v1.size() << " " << v1.capacity() << " " << v1.front() << " " << v1.back() << std::endl;

	std::vector<int>::iterator	it = v1.begin();
	ft::vector<int>::iterator	it2 = v.begin();

	std::cout << *it2 << " " << *(it2++) << " " << *(it2 + 30) << std::endl;
	std::cout << *it << " " << *(it2++) << " " << *(it + 30) << std::endl;

	// std::vector<int>	v1(10, 42);
	// ft::vector<int>		v(10, 42);

	// std::cout << v.size() << " " << v.capacity() << " " << v.front() << " " << v.back() << " " << v[10] << std::endl;
	// std::cout << v1.size() << " " << v1.capacity() << " " << v1.front() << " " << v1.back() << " " << v1[10] << std::endl;

	// std::cout << std::endl;

	// ft::vector<int>::iterator	it = v.begin();
	// ft::vector<int>::iterator	end = v.end();

	// std::vector<int>::iterator	it1 = v1.begin();
	// std::vector<int>::iterator	end1 = v1.end();

	// std::cout << v.size() << " " << v.capacity() << " " << v.front() << " " << v.back() << " " << v[10] << std::endl;
	// std::cout << v1.size() << " " << v1.capacity() << " " << v1.front() << " " << v1.back() << " " << v1[10] << std::endl;

	// std::cout << std::endl;

	// std::vector<int>	v2(it1, end1);
	// ft::vector<int>		vv(it, end);

	// std::cout << vv.size() << " " << vv.capacity() << " " << vv.front() << " " << vv.back() << " " << vv[10] << std::endl;
	// std::cout << v2.size() << " " << v2.capacity() << " " << v2.front() << " " << v2.back() << " " << v2[10] << std::endl;
}