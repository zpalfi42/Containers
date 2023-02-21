#include <vector>
#include  <iostream>
#include <typeinfo>
#include <map>
#include <vector.hpp>

void	iterators_test( void )
{
	std::cout << "\033[1;31m  .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--.\033[0m" << std::endl;
	std::cout << "\033[0m:::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m" << std::endl;
	std::cout << "\033[1;31m'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `\033[0m" << std::endl;

	std::cout << "\033[1;31m       _____ _                 _                   _            _   " << std::endl;
	std::cout << "      |_   _| |               | |                 | |          | |  " << std::endl;
	std::cout << "        | | | |_ ___ _ __ __ _| |_ ___  _ __ ___  | |_ ___  ___| |_ " << std::endl;
	std::cout << "        | | | __/ _ \\ '__/ _` | __/ _ \\| '__/ __| | __/ _ \\/ __| __|" << std::endl;
	std::cout << "       _| |_| ||  __/ | | (_| | || (_) | |  \\__ \\ | ||  __/\\__ \\ |_ " << std::endl;
	std::cout << "      |_____|\\__\\___|_|  \\__,_|\\__\\___/|_|  |___/  \\__\\___||___/\\__|\033[0m" << std::endl << std::endl;

	std::cout << "\033[1;31m  .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--.\033[0m" << std::endl;
	std::cout << "\033[0m:::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m" << std::endl;
	std::cout << "\033[1;31m'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `\033[0m" << std::endl << std::endl;


	std::vector<int>	v;
	ft::vector<int>		v1;

	for (size_t i = 0; i < 100; i++)
	{
		v.push_back(i);
		v1.push_back(i);
	}
	
	std::vector<int>::iterator	it = v.begin();
	ft::vector<int>::iterator	it1 = v1.begin();

	bool b = true;

	{
		std::cout << "\033[1;37mOperator+ tests: ";
		for (size_t i = 0; i < 100; i++)
		{
			if (*(it + i) != *(it1 + i))
			{
				std::cout << "\033[1;31mFAIL\033[0m" << std::endl;
				b = false;
			}
		}
		if (b)
			std::cout << "\033[1;32mSUCCESS\033[0m" << std::endl;
		
		std::cout << "\033[1;37m+operator tests: ";
		for (size_t i = 0; i < 100; i++)
		{
			if (*(it + i) != *(it1 + i))
			{
				std::cout << "\033[1;31mFAIL\033[0m" << std::endl;
				b = false;
			}
		}
		if (b)
			std::cout << "\033[1;32mSUCCESS\033[0m" << std::endl;
	}

	it = v.end();
	it1 = v1.end();

	b = true;
	std::cout << "\033[1;37moperator- tests: ";
	for (size_t i = 0; i < 100; i++)
	{
		if (*(it - i) != *(it1 - i))
		{
			std::cout << "FAIL " << *it << " != " << *it1 << std::endl;
			b = false;
			break ;
		}
	}
	if (b)
		std::cout << "\033[1;32mSUCCESS\033[0m" << std::endl;

	it = v.begin();
	it1 = v1.begin();
	
	b = true;
	std::cout << "\033[1;37moperator++ tests: ";
	for (size_t i = 0; i < 100; i++)
	{
		if (*it != *it1)
		{
			std::cout << "FAIL " << *it << " != " << *it1 << std::endl;
			b = false;
			break ;
		}
		it++;
		it1++;
	}
	if (b)
		std::cout << "\033[1;32mSUCCESS\033[0m" << std::endl;

	b = true;
	std::cout << "\033[1;37moperator-- tests: ";
	for (size_t i = 0; i < 100; i++)
	{
		if (*it != *it1)
		{
			std::cout << "FAIL " << *it << " != " << *it1 << std::endl;
			b = false;
			break ;
		}
		it--;
		it1--;
	}
	if (b)
		std::cout << "\033[1;32mSUCCESS\033[0m" << std::endl;

	b = true;
	it = v.begin();
	it1 = v1.begin();
	std::cout << "\033[1;37m++operator tests: ";
	for (size_t i = 0; i < 100; i++)
	{
		if (*it != *it1)
		{
			std::cout << "FAIL " << *it << " != " << *it1 << std::endl;
			b = false;
			break ;
		}
		++it;
		++it1;
	}
	if (b)
		std::cout << "\033[1;32mSUCCESS\033[0m" << std::endl;

	b = true;
	std::cout << "\033[1;37m--operator tests: ";
	for (size_t i = 0; i < 100; i++)
	{
		if (*it != *it1)
		{
			std::cout << "FAIL " << *it << " != " << *it1 << std::endl;
			b = false;
			break ;
		}
		--it;
		--it1;
	}
	if (b)
		std::cout << "\033[1;32mSUCCESS\033[0m" << std::endl;

	it = v.begin();
	it1 = v1.begin();

	b = true;
	std::cout << "\033[1;37moperator+= tests: ";
	for (size_t i = 0; i < 100; i++)
	{
		if (*it != *it1)
		{
			std::cout << "FAIL " << *it << " != " << *it1 << std::endl;
			b = false;
			break ;
		}
		it += 1;
		it1 += 1;
	}
	if (b)
		std::cout << "\033[1;32mSUCCESS\033[0m" << std::endl;

	it = v.end();
	it1 = v1.end();

	b = true;
	std::cout << "\033[1;37moperator-= tests: ";
	for (size_t i = 0; i < 100; i++)
	{
		if (*it != *it1)
		{
			std::cout << "FAIL " << *it << " != " << *it1 << std::endl;
			b = false;
			break ;
		}
		it -= 1;
		it1 -= 1;
	}
	if (b)
		std::cout << "\033[1;32mSUCCESS\033[0m" << std::endl;

	std::vector<int>::iterator	itt = v.end();
	ft::vector<int>::iterator	itt1 = v1.end();

	std::cout << "\033[1;37moperator-(it) tests: ";
	if ((itt - it) != (itt1 - it1))
		std::cout << "FAIL ";
	else
		std::cout << "\033[1;32mSUCCESS \033[0m";

	itt--;
	itt1--;

	if ((itt - it) != (itt1 - it1))
		std::cout << "FAIL ";
	else
		std::cout << "\033[1;32mSUCCESS \033[0m";

	itt -= 42;
	itt1 -= 42;
	it += 42;
	it1 += 42;

	if ((itt - it) != (itt1 - it1))
		std::cout << "\033[1;31mFAIL\033[0m" << std::endl;
	else
		std::cout << "\033[1;32mSUCCESS\033[0m" << std::endl;

	it = v.begin();
	it1 = v1.begin();

	b = true;
	std::cout << "\033[1;37moperator[] tests: ";
	for (size_t i = 0; i < 100; i++)
	{
		if (it[i] != it1[i])
		{
			std::cout << "FAIL " << *it << " != " << *it1 << std::endl;
			b = false;
			break ;
		}
	}
	if (b)
		std::cout << "\033[1;32mSUCCESS\033[0m" << std::endl;

	it = v.begin();
	it1 = v1.begin();

	b = true;
	std::cout << "\033[1;37moperator* tests: ";
	for (size_t i = 0; i < 100; i++)
	{
		if (*it != *it1)
		{
			std::cout << "FAIL " << *it << " != " << *it1 << std::endl;
			b = false;
			break ;
		}
		it++;
		it1++;
	}
	if (b)
		std::cout << "\033[1;32mSUCCESS\033[0m" << std::endl;

	it = v.begin();
	itt = v.end();
	std::vector<int>::iterator	ittt = v.begin();

	it1 = v1.begin();
	itt1 = v1.end();
	ft::vector<int>::iterator	ittt1 = v1.begin();

	std::cout << "\033[1;37moperator== tests: ";
	if (((it == itt) != (it1 == itt1)) || ((it == ittt) != (it1 == ittt1)) || ((++it == ittt) != (++it1 == ittt1)) || ((--it == ittt) != (--it1 == ittt1)) || ((it++ == ittt) != (it1++ == ittt1)) || ((it-- == ittt) != (it1-- == ittt1)))
		std::cout << "\033[1;31mFAIL\033[0m" << std::endl;
	else
		std::cout << "\033[1;32mSUCCESS\033[0m" << std::endl;

	std::cout << "\033[1;37moperator!= tests: ";
	if (((it != itt) != (it1 != itt1)) || ((it != ittt) != (it1 != ittt1)) || ((++it != ittt) != (++it1 != ittt1)) || ((--it != ittt) != (--it1 != ittt1)) || ((it++ != ittt) != (it1++ != ittt1)) || ((it-- != ittt) != (it1-- != ittt1)))
		std::cout << "\033[1;31mFAIL\033[0m" << std::endl;
	else
		std::cout << "\033[1;32mSUCCESS\033[0m" << std::endl;

	std::cout << "\033[1;37moperator< tests: ";
	if (((it < itt) != (it1 < itt1)) || ((it < ittt) != (it1 < ittt1)) || ((++it < ittt) != (++it1 < ittt1)) || ((--it < ittt) != (--it1 < ittt1)) || ((it++ < ittt) != (it1++ < ittt1)) || ((it-- < ittt) != (it1-- < ittt1)))
		std::cout << "\033[1;31mFAIL\033[0m" << std::endl;
	else
		std::cout << "\033[1;32mSUCCESS\033[0m" << std::endl;

	std::cout << "\033[1;37moperator<= tests: ";
	if (((it <= itt) != (it1 <= itt1)) || ((it <= ittt) != (it1 <= ittt1)) || ((++it <= ittt) != (++it1 <= ittt1)) || ((--it <= ittt) != (--it1 <= ittt1)) || ((it++ <= ittt) != (it1++ <= ittt1)) || ((it-- <= ittt) != (it1-- <= ittt1)))
		std::cout << "\033[1;31mFAIL\033[0m" << std::endl;
	else
		std::cout << "\033[1;32mSUCCESS\033[0m" << std::endl;
	
	std::cout << "\033[1;37moperator> tests: ";
	if (((it > itt) != (it1 > itt1)) || ((it > ittt) != (it1 > ittt1)) || ((++it > ittt) != (++it1 > ittt1)) || ((--it > ittt) != (--it1 > ittt1)) || ((it++ > ittt) != (it1++ > ittt1)) || ((it-- > ittt) != (it1-- > ittt1)))
		std::cout << "\033[1;31mFAIL\033[0m" << std::endl;
	else
		std::cout << "\033[1;32mSUCCESS\033[0m" << std::endl;

	std::cout << "\033[1;37moperator>= tests: ";
	if (((it >= itt) != (it1 >= itt1)) || ((it >= ittt) != (it1 >= ittt1)) || ((++it >= ittt) != (++it1 >= ittt1)) || ((--it >= ittt) != (--it1 >= ittt1)) || ((it++ >= ittt) != (it1++ >= ittt1)) || ((it-- >= ittt) != (it1-- >= ittt1)))
		std::cout << "\033[1;31mFAIL\033[0m" << std::endl;
	else
		std::cout << "\033[1;32mSUCCESS\033[0m" << std::endl;

	std::vector<int>::iterator	aux;
	ft::vector<int>::iterator	aux1;

	aux = v.begin();
	aux1 = v1.begin();

	std::cout << "\033[1;37moperator= tests: ";
	if ((aux == it) != (aux1 == it1))
		std::cout << "\033[1;31mFAIL\033[0m" << std::endl;
	else
		std::cout << "\033[1;32mSUCCESS\033[0m" << std::endl;
	
	std::cout << std::endl << std::endl;
}

void	printCase( std::string s, bool b , bool endl)
{
	std::cout << s;
	if (b)
		std::cout << "\033[1;32mSUCCESS\033[0m";
	else
		std::cout << "\033[1;31mFAIL\033[0m";

	if (endl)
		std::cout << std::endl;
	else
		std::cout << " ";
}

void	vectors_test( void )
{
	std::cout << "\033[1;31m  .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--.\033[0m" << std::endl;
	std::cout << "\033[0m:::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m" << std::endl;
	std::cout << "\033[1;31m'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `\033[0m" << std::endl;

	std::cout << "\033[1;31m __      __       _               _            _   " << std::endl;
	std::cout << " \\ \\    / /      | |             | |          | |  " << std::endl;
	std::cout << "  \\ \\  / /__  ___| |_ ___  _ __  | |_ ___  ___| |_ " << std::endl;
	std::cout << "   \\ \\/ / _ \\/ __| __/ _ \\| '__| | __/ _ \\/ __| __|" << std::endl;
	std::cout << "    \\  /  __/ (__| || (_) | |    | ||  __/\\__ \\ |_ " << std::endl;
	std::cout << "     \\/ \\___|\\___|\\__\\___/|_|     \\__\\___||___/\\__|\033[0m" << std::endl << std::endl;

	std::cout << "\033[1;31m  .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--.\033[0m" << std::endl;
	std::cout << "\033[0m:::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m::::::::.\033[1;31m\\\033[0m" << std::endl;
	std::cout << "\033[1;31m'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `\033[0m" << std::endl << std::endl;

	bool res;

	std::vector<int> v1(10, 42);
	ft::vector<int> v(10 , 42);

	res = (v.size() == v1.size());
	printCase("\033[1;37mconstructor(int, int) tests: ", res, false);
	res = (v.capacity() == v1.capacity());
	printCase("", res, false);
	res = (v.front() == v1.front());
	printCase("", res, false);
	res = (v.back() == v1.back());
	printCase("", res, false);
	res = (v[9] == v1[9]);
	printCase("", res, true);

	// std::cout << v.size() << " " << v.capacity() << " " << v.front() << " " << v.back() << " " << v[9] << std::endl;
	// std::cout << v1.size() << " " << v1.capacity() << " " << v1.front() << " " << v1.back() << " " << v1[9] << std::endl;

	v.resize(8, 0);
	v1.resize(8, 0);

	res = (v.size() == v1.size());
	printCase("\033[1;37mResize tests: ", res, false);
	res = (v.capacity() == v1.capacity());
	printCase("", res, false);
	res = (v.front() == v1.front());
	printCase("", res, false);
	res = (v.back() == v1.back());
	printCase("", res, false);
	res = (v[9] == v1[9]);
	printCase("", res, true);

	v.assign(50, 0);
	v1.assign(50, 0);

	res = (v.size() == v1.size());
	printCase("\033[1;37mAssign tests: ", res, false);
	res = (v.capacity() == v1.capacity());
	printCase("", res, false);
	res = (v.front() == v1.front());
	printCase("", res, false);
	res = (v.back() == v1.back());
	printCase("", res, false);
	res = (v[9] == v1[9]);
	printCase("", res, true);

	v.resize(80, 60);
	v1.resize(80, 60);

	v.push_back(42);
	v1.push_back(42);

	res = (v.size() == v1.size());
	printCase("\033[1;37mPush_back tests: ", res, false);
	res = (v.capacity() == v1.capacity());
	printCase("", res, false);
	res = (v.front() == v1.front());
	printCase("", res, false);
	res = (v.back() == v1.back());
	printCase("", res, false);
	res = (v[9] == v1[9]);
	printCase("", res, true);

	std::cout << std::endl;
}

int main( void )
{
	iterators_test();
	vectors_test();

	ft::vector<int>	v;

	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	ft::vector<int> vv(10, 42);

	v.insert((v.begin() + 3), vv.begin(), vv.end());

	for (long i = 0; i < (v.end() - v.begin()); i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
	
}