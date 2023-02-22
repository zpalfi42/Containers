#include <vector>
#include  <iostream>
#include <typeinfo>
#include <map>
#include<unistd.h>
#include <vector.hpp>

#define RED 	"\033[1;31m"
#define	RESET	"\033[0m"
#define WHITE	"\033[1;37m"
#define GREEN	"\033[1;32m"

void	iterators_test( void )
{
	std::cout << RED << "  .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--." << RESET << std::endl;
	std::cout << RESET << ":::::." << RED << "\\" <<RESET << ":::::::." << RED << "\\" << RESET<< "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << std::endl;
	std::cout << RED << "'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `" << RESET << std::endl;

	std::cout << RED << "       _____ _                 _                   _            _   " << std::endl;
	std::cout << "      |_   _| |               | |                 | |          | |  " << std::endl;
	std::cout << "        | | | |_ ___ _ __ __ _| |_ ___  _ __ ___  | |_ ___  ___| |_ " << std::endl;
	std::cout << "        | | | __/ _ \\ '__/ _` | __/ _ \\| '__/ __| | __/ _ \\/ __| __|" << std::endl;
	std::cout << "       _| |_| ||  __/ | | (_| | || (_) | |  \\__ \\ | ||  __/\\__ \\ |_ " << std::endl;
	std::cout << "      |_____|\\__\\___|_|  \\__,_|\\__\\___/|_|  |___/  \\__\\___||___/\\__|" << RESET << std::endl << std::endl;

	std::cout << RED << "  .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--." << RESET << std::endl;
	std::cout << RESET << ":::::." << RED << "\\" <<RESET << ":::::::." << RED << "\\" << RESET<< "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << std::endl;
	std::cout << RED << "'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `" << RESET << std::endl;


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
		std::cout << WHITE << "Operator+ tests: ";
		usleep(424242);
		for (size_t i = 0; i < 100; i++)
		{
			if (*(it + i) != *(it1 + i))
			{
				std::cout << RED << "FAIL" << RESET << std::endl;
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "SUCCESS" << RESET << std::endl;
		usleep(424242);
		std::cout << WHITE << "+operator tests: ";
		usleep(424242);
		for (size_t i = 0; i < 100; i++)
		{
			if (*(it + i) != *(it1 + i))
			{
				std::cout << RED << "FAIL" << RESET << std::endl;
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "SUCCESS" << RESET << std::endl;
	}

	it = v.end();
	it1 = v1.end();

	b = true;
	usleep(424242);
	std::cout << WHITE << "operator- tests: ";
	usleep(424242);
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
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	it = v.begin();
	it1 = v1.begin();
	
	b = true;
	usleep(424242);
	std::cout << WHITE << "operator++ tests: ";
	usleep(424242);
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
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	b = true;
	usleep(424242);
	std::cout << WHITE << "operator-- tests: ";
	usleep(424242);
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
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	b = true;
	it = v.begin();
	it1 = v1.begin();
	usleep(424242);
	std::cout << WHITE << "++operator tests: ";
	usleep(424242);
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
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	b = true;
	usleep(424242);
	std::cout << WHITE << "--operator tests: ";
	usleep(424242);
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
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	it = v.begin();
	it1 = v1.begin();

	b = true;
	usleep(424242);
	std::cout << WHITE << "operator+= tests: ";
	usleep(424242);
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
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	it = v.end();
	it1 = v1.end();

	b = true;
	usleep(424242);
	std::cout << WHITE << "operator-= tests: ";
	usleep(424242);
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
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	std::vector<int>::iterator	itt = v.end();
	ft::vector<int>::iterator	itt1 = v1.end();

	usleep(424242);
	std::cout << WHITE << "operator-(it) tests: ";
	usleep(424242);
	if ((itt - it) != (itt1 - it1))
		std::cout << "FAIL ";
	else
		std::cout << GREEN << "SUCCESS " << RESET;

	itt--;
	itt1--;
	if ((itt - it) != (itt1 - it1))
		std::cout << "FAIL ";
	else
		std::cout << GREEN << "SUCCESS " << RESET;

	itt -= 42;
	itt1 -= 42;
	it += 42;
	it1 += 42;
	if ((itt - it) != (itt1 - it1))
		std::cout << RED << "FAIL" << RESET << std::endl;
	else
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	it = v.begin();
	it1 = v1.begin();

	b = true;
	usleep(424242);
	std::cout << WHITE << "operator[] tests: ";
	usleep(424242);
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
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	it = v.begin();
	it1 = v1.begin();

	b = true;
	usleep(424242);
	std::cout << WHITE << "operator* tests: ";
	usleep(424242);
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
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	it = v.begin();
	itt = v.end();
	std::vector<int>::iterator	ittt = v.begin();

	it1 = v1.begin();
	itt1 = v1.end();
	ft::vector<int>::iterator	ittt1 = v1.begin();

	usleep(424242);
	std::cout << WHITE << "operator== tests: ";
	usleep(424242);
	if (((it == itt) != (it1 == itt1)) || ((it == ittt) != (it1 == ittt1)) || ((++it == ittt) != (++it1 == ittt1)) || ((--it == ittt) != (--it1 == ittt1)) || ((it++ == ittt) != (it1++ == ittt1)) || ((it-- == ittt) != (it1-- == ittt1)))
		std::cout << RED << "FAIL" << RESET << std::endl;
	else
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	usleep(424242);
	std::cout << WHITE << "operator!= tests: ";
	usleep(424242);
	if (((it != itt) != (it1 != itt1)) || ((it != ittt) != (it1 != ittt1)) || ((++it != ittt) != (++it1 != ittt1)) || ((--it != ittt) != (--it1 != ittt1)) || ((it++ != ittt) != (it1++ != ittt1)) || ((it-- != ittt) != (it1-- != ittt1)))
		std::cout << RED << "FAIL" << RESET << std::endl;
	else
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	usleep(424242);
	std::cout << WHITE << "operator< tests: ";
	usleep(424242);
	if (((it < itt) != (it1 < itt1)) || ((it < ittt) != (it1 < ittt1)) || ((++it < ittt) != (++it1 < ittt1)) || ((--it < ittt) != (--it1 < ittt1)) || ((it++ < ittt) != (it1++ < ittt1)) || ((it-- < ittt) != (it1-- < ittt1)))
		std::cout << RED << "FAIL" << RESET << std::endl;
	else
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	usleep(424242);
	std::cout << WHITE << "operator<= tests: ";
	usleep(424242);
	if (((it <= itt) != (it1 <= itt1)) || ((it <= ittt) != (it1 <= ittt1)) || ((++it <= ittt) != (++it1 <= ittt1)) || ((--it <= ittt) != (--it1 <= ittt1)) || ((it++ <= ittt) != (it1++ <= ittt1)) || ((it-- <= ittt) != (it1-- <= ittt1)))
		std::cout << RED << "FAIL" << RESET << std::endl;
	else
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;
	
	usleep(424242);
	std::cout << WHITE << "operator> tests: ";
	usleep(424242);
	if (((it > itt) != (it1 > itt1)) || ((it > ittt) != (it1 > ittt1)) || ((++it > ittt) != (++it1 > ittt1)) || ((--it > ittt) != (--it1 > ittt1)) || ((it++ > ittt) != (it1++ > ittt1)) || ((it-- > ittt) != (it1-- > ittt1)))
		std::cout << RED << "FAIL" << RESET << std::endl;
	else
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	usleep(424242);
	std::cout << WHITE << "operator>= tests: ";
	usleep(424242);
	if (((it >= itt) != (it1 >= itt1)) || ((it >= ittt) != (it1 >= ittt1)) || ((++it >= ittt) != (++it1 >= ittt1)) || ((--it >= ittt) != (--it1 >= ittt1)) || ((it++ >= ittt) != (it1++ >= ittt1)) || ((it-- >= ittt) != (it1-- >= ittt1)))
		std::cout << RED << "FAIL" << RESET << std::endl;
	else
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	std::vector<int>::iterator	aux;
	ft::vector<int>::iterator	aux1;

	aux = v.begin();
	aux1 = v1.begin();

	usleep(424242);
	std::cout << WHITE << "operator= tests: ";
	usleep(424242);
	if ((aux == it) != (aux1 == it1))
		std::cout << RED << "FAIL" << RESET << std::endl;
	else
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;
	
	std::cout << std::endl << std::endl;
}

void	reverse_iterator_tests( void )
{
	std::cout << RED << "  .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--." << RESET << std::endl;
	std::cout << RESET << ":::::." << RED << "\\" <<RESET << ":::::::." << RED << "\\" << RESET<< "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << std::endl;
	std::cout << RED << "'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `" << RESET << std::endl;

	std::cout << RED << "       _____ _                 _                   _            _   " << std::endl;
	std::cout << "      |_   _| |               | |                 | |          | |  " << std::endl;
	std::cout << "        | | | |_ ___ _ __ __ _| |_ ___  _ __ ___  | |_ ___  ___| |_ " << std::endl;
	std::cout << "        | | | __/ _ \\ '__/ _` | __/ _ \\| '__/ __| | __/ _ \\/ __| __|" << std::endl;
	std::cout << "       _| |_| ||  __/ | | (_| | || (_) | |  \\__ \\ | ||  __/\\__ \\ |_ " << std::endl;
	std::cout << "      |_____|\\__\\___|_|  \\__,_|\\__\\___/|_|  |___/  \\__\\___||___/\\__|" << RESET << std::endl << std::endl;

	std::cout << RED << "  .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--." << RESET << std::endl;
	std::cout << RESET << ":::::." << RED << "\\" <<RESET << ":::::::." << RED << "\\" << RESET<< "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << std::endl;
	std::cout << RED << "'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `" << RESET << std::endl;


	std::vector<int>	v;
	ft::vector<int>		v1;

	for (size_t i = 0; i < 100; i++)
	{
		v.push_back(i);
		v1.push_back(i);
	}
	
	std::vector<int>::reverse_iterator	it = v.rbegin();
	ft::vector<int>::reverse_iterator	it1 = v1.rbegin();

	bool b = true;

	usleep(424242);
	std::cout << WHITE << "Operator+ tests: ";
	usleep(424242);
	for (size_t i = 0; i < 100; i++)
	{
		if (*(it + i) != *(it1 + i))
		{
			std::cout << RED << "FAIL" << RESET << std::endl;
			b = false;
		}
	}
	if (b)
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;
	
	usleep(424242);
	std::cout << WHITE << "+operator tests: ";
	usleep(424242);
	for (size_t i = 0; i < 100; i++)
	{
		if (*(it + i) != *(it1 + i))
		{
			std::cout << RED << "FAIL" << RESET << std::endl;
			b = false;
		}
	}
	if (b)
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	it = v.rend();
	it1 = v1.rend();

	b = true;
	usleep(424242);
	std::cout << WHITE << "operator- tests: ";
	usleep(424242);
	for (size_t i = 1; i < 100; i++)
	{
		if (*(it - i) != *(it1 - i))
		{
			std::cout << "FAIL " << *it << " != " << *it1 << std::endl;
			b = false;
			break ;
		}
	}
	if (b)
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	it = v.rbegin();
	it1 = v1.rbegin();
	
	b = true;
	usleep(424242);
	std::cout << WHITE << "operator++ tests: ";
	usleep(424242);
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
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;
	it--;
	it1--;
	b = true;
	usleep(424242);
	std::cout << WHITE << "operator-- tests: ";
	usleep(424242);
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
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	b = true;
	it = v.rbegin();
	it1 = v1.rbegin();
	usleep(424242);
	std::cout << WHITE << "++operator tests: ";
	usleep(424242);
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
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	it--;
	it1--;
	b = true;
	usleep(424242);
	std::cout << WHITE << "--operator tests: ";
	usleep(424242);
	for (size_t i = 1; i < 100; i++)
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
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	it = v.rbegin();
	it1 = v1.rbegin();

	b = true;
	usleep(424242);
	std::cout << WHITE << "operator+= tests: ";
	usleep(424242);
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
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	it = v.rend();
	it1 = v1.rend();

	b = true;
	it--;
	it1--;
	usleep(424242);
	std::cout << WHITE << "operator-= tests: ";
	usleep(424242);
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
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	std::vector<int>::reverse_iterator	itt = v.rbegin();
	ft::vector<int>::reverse_iterator	itt1 = v1.rbegin();

	usleep(424242);
	std::cout << WHITE << "operator-(it) tests: ";
	usleep(424242);
	if ((itt - it) != (itt1 - it1))
		std::cout << "FAIL ";
	else
		std::cout << GREEN << "SUCCESS " << RESET;

	itt--;
	itt1--;

	if ((itt - it) != (itt1 - it1))
		std::cout << "FAIL ";
	else
		std::cout << GREEN << "SUCCESS " << RESET;

	itt -= 42;
	itt1 -= 42;
	it += 42;
	it1 += 42;

	if ((itt - it) != (itt1 - it1))
		std::cout << RED << "FAIL" << RESET << std::endl;
	else
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	it = v.rbegin();
	it1 = v1.rbegin();

	b = true;
	usleep(424242);
	std::cout << WHITE << "operator[] tests: ";
	usleep(424242);
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
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	it = v.rbegin();
	it1 = v1.rbegin();

	b = true;
	usleep(424242);
	std::cout << WHITE << "operator* tests: ";
	usleep(424242);
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
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	it = v.rbegin();
	itt = v.rend();
	std::vector<int>::reverse_iterator	ittt = v.rbegin();

	it1 = v1.rbegin();
	itt1 = v1.rend();
	ft::vector<int>::reverse_iterator	ittt1 = v1.rbegin();

	usleep(424242);
	std::cout << WHITE << "operator== tests: ";
	usleep(424242);
	if (((it == itt) != (it1 == itt1)) || ((it == ittt) != (it1 == ittt1)) || ((++it == ittt) != (++it1 == ittt1)) || ((--it == ittt) != (--it1 == ittt1)) || ((it++ == ittt) != (it1++ == ittt1)) || ((it-- == ittt) != (it1-- == ittt1)))
		std::cout << RED << "FAIL" << RESET << std::endl;
	else
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	usleep(424242);
	std::cout << WHITE << "operator!= tests: ";
	usleep(424242);
	if (((it != itt) != (it1 != itt1)) || ((it != ittt) != (it1 != ittt1)) || ((++it != ittt) != (++it1 != ittt1)) || ((--it != ittt) != (--it1 != ittt1)) || ((it++ != ittt) != (it1++ != ittt1)) || ((it-- != ittt) != (it1-- != ittt1)))
		std::cout << RED << "FAIL" << RESET << std::endl;
	else
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	usleep(424242);
	std::cout << WHITE << "operator< tests: ";
	usleep(424242);
	if (((it < itt) != (it1 < itt1)) || ((it < ittt) != (it1 < ittt1)) || ((++it < ittt) != (++it1 < ittt1)) || ((--it < ittt) != (--it1 < ittt1)) || ((it++ < ittt) != (it1++ < ittt1)) || ((it-- < ittt) != (it1-- < ittt1)))
		std::cout << RED << "FAIL" << RESET << std::endl;
	else
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	usleep(424242);
	std::cout << WHITE << "operator<= tests: ";
	usleep(424242);
	if (((it <= itt) != (it1 <= itt1)) || ((it <= ittt) != (it1 <= ittt1)) || ((++it <= ittt) != (++it1 <= ittt1)) || ((--it <= ittt) != (--it1 <= ittt1)) || ((it++ <= ittt) != (it1++ <= ittt1)) || ((it-- <= ittt) != (it1-- <= ittt1)))
		std::cout << RED << "FAIL" << RESET << std::endl;
	else
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;
	
	usleep(424242);
	std::cout << WHITE << "operator> tests: ";
	usleep(424242);
	if (((it > itt) != (it1 > itt1)) || ((it > ittt) != (it1 > ittt1)) || ((++it > ittt) != (++it1 > ittt1)) || ((--it > ittt) != (--it1 > ittt1)) || ((it++ > ittt) != (it1++ > ittt1)) || ((it-- > ittt) != (it1-- > ittt1)))
		std::cout << RED << "FAIL" << RESET << std::endl;
	else
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	usleep(424242);
	std::cout << WHITE << "operator>= tests: ";
	usleep(424242);
	if (((it >= itt) != (it1 >= itt1)) || ((it >= ittt) != (it1 >= ittt1)) || ((++it >= ittt) != (++it1 >= ittt1)) || ((--it >= ittt) != (--it1 >= ittt1)) || ((it++ >= ittt) != (it1++ >= ittt1)) || ((it-- >= ittt) != (it1-- >= ittt1)))
		std::cout << RED << "FAIL" << RESET << std::endl;
	else
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;

	std::vector<int>::reverse_iterator	aux;
	ft::vector<int>::reverse_iterator	aux1;

	aux = v.rbegin();
	aux1 = v1.rbegin();

	usleep(424242);
	std::cout << WHITE << "operator= tests: ";
	usleep(424242);
	if ((aux == it) != (aux1 == it1))
		std::cout << RED << "FAIL" << RESET << std::endl;
	else
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;
	
	std::cout << std::endl << std::endl;
}

void	printCase( std::string s, bool b , bool endl)
{
	usleep(424242);
	std::cout << s;
	if (b)
		std::cout << GREEN << "SUCCESS" << RESET;
	else
		std::cout << RED << "FAIL" << RESET;

	if (endl)
		std::cout << std::endl;
	else
		std::cout << " ";
}

void	vectors_test( void )
{
	std::cout << RED << "  .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--." << RESET << std::endl;
	std::cout << RESET << ":::::." << RED << "\\" <<RESET << ":::::::." << RED << "\\" << RESET<< "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << std::endl;
	std::cout << RED << "'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `" << RESET << std::endl;

	std::cout << RED << " __      __       _               _            _   " << std::endl;
	std::cout << " \\ \\    / /      | |             | |          | |  " << std::endl;
	std::cout << "  \\ \\  / /__  ___| |_ ___  _ __  | |_ ___  ___| |_ " << std::endl;
	std::cout << "   \\ \\/ / _ \\/ __| __/ _ \\| '__| | __/ _ \\/ __| __|" << std::endl;
	std::cout << "    \\  /  __/ (__| || (_) | |    | ||  __/\\__ \\ |_ " << std::endl;
	std::cout << "     \\/ \\___|\\___|\\__\\___/|_|     \\__\\___||___/\\__|" << RESET << std::endl << std::endl;

	std::cout << RED << "  .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--." << RESET << std::endl;
	std::cout << RESET << ":::::." << RED << "\\" <<RESET << ":::::::." << RED << "\\" << RESET<< "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << std::endl;
	std::cout << RED << "'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `" << RESET << std::endl;

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
	reverse_iterator_tests();
	vectors_test();
}