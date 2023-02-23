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

#include <sstream>

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()


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

	bool b;
	size_t	n;

	/**
	 * Defined one std::vector and one ft::vector that will be filled with 100 ints.
	 */
	std::vector<int>	v;
	ft::vector<int>		v1;

	/**
	 * Defined one std::vector and one ft::vector that will be filled with 100 strings.
	 */
	std::vector<std::string>	s;
	ft::vector<std::string>		s1;

	/**
	 * Defined one std::vector and one ft::vector that will be empty.
	 */
	std::vector<int>	ev;
	ft::vector<int>		ev1;

	/**
	 * Defined one std::vector and one ft::vector that will have only one int.
	 */
	std::vector<int>	ov;
	ft::vector<int>		ov1;

	for (size_t i = 0; i < 100; i++)
	{
		v.push_back(i);
		v1.push_back(i);

		s.push_back( SSTR( i ) );
		s1.push_back( SSTR( i ) );
	}

	ov.push_back(42);
	ov1.push_back(42);
	
	std::vector<int>::iterator	it = v.begin();
	std::vector<int>::iterator	end = v.end();
	ft::vector<int>::iterator	it1 = v1.begin();
	ft::vector<int>::iterator	end1 = v1.end();

	std::vector<std::string>::iterator	sit = s.begin();
	std::vector<std::string>::iterator	send = s.end();
	ft::vector<std::string>::iterator	sit1 = s1.begin();
	ft::vector<std::string>::iterator	send1 = s1.end();

	std::vector<int>::iterator	oit = ov.begin();
	std::vector<int>::iterator	oend = ov.end();
	ft::vector<int>::iterator	oit1 = ov1.begin();
	ft::vector<int>::iterator	oend1 = ov1.end();

	std::vector<int>::iterator	eit = ev.begin();
	std::vector<int>::iterator	eend = ev.end();
	ft::vector<int>::iterator	eit1 = ev1.begin();
	ft::vector<int>::iterator	eend1 = ev1.end();

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator+ works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "Operator+ tests: ";
		usleep(244242);

		/**
		 * Test operator+ with vectors full of ints.
		 */
		b = true;
		for (size_t i = 0; (it + i) != end; i++)
		{
			if (*(it + i) != *(it1 + i) || (it1 + i) == end1)
			{
				std::cout << RED << "FAIL " << std::endl;
				b = false;

			}
		}
		if (b && (end - it) == (end1 - it1))
			std::cout << GREEN << "✅ ";

		/**
		 * Test operator+ with vectors full of std::string
		 */
		b = true;
		for (size_t i = 0; (sit + i) != send; i++)
		{
			if (*(sit + i) != *(sit1 + i) || (sit1 + i) == send1)
			{
				std::cout << RED << "FAIL ";
				b = false;
			}
		}
		if (b && (send - sit) == (send1 - sit1))
			std::cout << GREEN << "✅ ";

		/**
		 * Test operator+ with vectors with only one int.
		 */
		b = true;
		for (size_t i = 0; (oit + i) != oend; i++)
		{
			if (*(oit + i) != *(oit1 + i) || (oit1 + i) == oend1)
			{
				std::cout << RED << "FAIL ";
				b = false;
			}
		}
		if (b && (oend - oit) == (oend1 - oit1))
			std::cout << GREEN << "✅ ";

		/**
		 * Test operator+ with empty vectors.
		 */
		b = true;
		for (size_t i = 0; (eit + i) != eend; i++)
		{
			if (*(eit + i) != *(eit1 + i) || (eit1 + i) == end1)
			{
				std::cout << RED << "FAIL " << RESET << std::endl;
				b = false;

			}
		}
		if (b && (eend - eit) == (eend1 - eit1))
			std::cout << GREEN << "✅ " << std::endl;
	}

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator+(size_t + iter) works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator+(size_t + iter) tests: ";
		usleep(244242);

		/**
		 * Test operator+ with vectors full of ints.
		 */
		b = true;
		for (size_t i = 0; (i + it) != end; i++)
		{
			if (*(i + it) != *(i + it1) || (i + it1) == end1)
			{
				std::cout << RED << "FAIL ";
				b = false;
			}
		}
		if (b && (end - it) == (end1 - it1))
			std::cout << GREEN << "✅ ";

		/**
		 * Test operator+ with vectors full of std::strings.
		 */
		b = true;
		for (size_t i = 0; (i + sit) != send; i++)
		{
			if (*(i + sit) != *(i + sit1) || (i + sit1) == send1)
			{
				std::cout << RED << "FAIL ";
				b = false;
			}
		}
		if (b && (send - sit) == (send1 - sit1))
			std::cout << GREEN << "✅ ";

		/**
		 * Test operator+ with vectors with only one int.
		 */
		b = true;
		for (size_t i = 0; (i + oit) != oend; i++)
		{
			if (*(i + oit) != *(i + oit1) || (i + oit1) == oend1)
			{
				std::cout << RED << "FAIL ";
				b = false;
			}
		}
		if (b && (oend - oit) == (oend1 - oit1))
			std::cout << GREEN << "✅ ";

		/**
		 * Test operator+ with empty vectors.
		 */
		b = true;
		for (size_t i = 0; (i + eit) != eend; i++)
		{
			if (*(i + eit) != *(i + eit1) || (i + eit1) == eend1)
			{
				std::cout << RED << "FAIL" << RESET << std::endl;
				b = false;
			}
		}
		if (b && (eend - eit) == (eend1 - eit1))
			std::cout << GREEN << "✅ " << RESET << std::endl;
	}

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator- works as expected.
	 * 
	 */
	{

		usleep(244242);
		std::cout << WHITE << "operator- tests: ";
		usleep(244242);

		/**
		 * Test operator- with vectors full of ints.
		 */
		b = true;
		for (size_t i = 0; (end - i) != it; i++)
		{
			if (*(end - i) != *(end1 - i) || (end1 - i) == it1)
			{
				std::cout << "FAIL ";
				b = false;
			}
		}
		if (b && (end - it) == (end1 - it1))
			std::cout << GREEN << "✅ ";

		/**
		 * Test operator- with vectors full of std::strings.
		 */
		b = true;
		for (size_t i = 0; (send - i) != sit; i++)
		{
			if (*(send - i) != *(send1 - i) || (send1 - i) == sit1)
			{
				std::cout << "FAIL ";
				b = false;
			}
		}
		if (b && (send - sit) == (send1 - sit1))
			std::cout << GREEN << "✅ ";

		/**
		 * Test operator- with vectors with only one int.
		 */
		b = true;
		for (size_t i = 0; (oend - i) != oit; i++)
		{
			if (*(oend - i) != *(oend1 - i) || (oend1 - i) == oit1)
			{
				std::cout << "FAIL ";
				b = false;
			}
		}
		if (b && (oend - oit) == (oend1 - oit1))
			std::cout << GREEN << "✅ ";

		/**
		 * Test operator- with empty vector.
		 */
		b = true;
		for (size_t i = 0; (eend - i) != eit; i++)
		{
			if (*(eend - i) != *(eend1 - i) || (eend1 - i) == eit1)
			{
				std::cout << "FAIL" << std::endl;
				b = false;
			}
		}
		if (b && (eend - eit) == (eend1 - eit1))
			std::cout << GREEN << "✅" << std::endl;
	}

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator++ works as expected.
	 * 
	 */
	{	
		usleep(244242);
		std::cout << WHITE << "operator++ tests: ";
		usleep(244242);

		b = true;
		n = (end - it);
		for (size_t i = 0; i < n; i++)
		{
			if (*it != *it1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			it++;
			it1++;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = (send - sit);
		for (size_t i = 0; (long)i < (send - sit); i++)
		{
			if (*sit != *sit1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			sit++;
			sit1++;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = (oend - oit);
		for (size_t i = 0; i < n; i++)
		{
			if (*oit != *oit1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			oit++;
			oit1++;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = (eend - eit);
		for (size_t i = 0; i < n; i++)
		{
			if (*eit != *eit1)
			{
				std::cout << "FAIL" << std::endl;
				b = false;
			}
			eit++;
			eit1++;
		}
		if (b)
			std::cout << GREEN << "✅" << std::endl;
	}

	it = v.begin();
	it1 = v1.begin();

	sit = s.begin();
	sit1 = s1.begin();

	oit = ov.begin();
	oit1 = ov1.begin();

	eit = ev.begin();
	eit1 = ev1.begin();

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator-- works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator-- tests: ";
		usleep(244242);

		b = true;
		n = end - it;
		for (size_t i = 0; i < n; i++)
		{
			if (*end != *end1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			end--;
			end1--;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = send - sit;
		for (size_t i = 0; i < n; i++)
		{
			if (*send != *send1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			send--;
			send1--;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = oend - oit;
		for (size_t i = 0; i < n; i++)
		{
			if (*oend != *oend1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			oend--;
			oend1--;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = eend - eit;
		for (size_t i = 0; i < n; i++)
		{
			if (*eend != *eend1)
			{
				std::cout << "FAIL" << std::endl;
				b = false;
			}
			eend--;
			eend1--;
		}
		if (b)
			std::cout << GREEN << "✅" << std::endl;
	}

	end = v.end();
	end1 = v1.end();

	send = s.end();
	send1 = s1.end();

	oend = ov.end();
	oend1 = ov1.end();

	eit = ev.end();
	eit1 = ev1.end();

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the ++operator works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "++operator tests: ";
		usleep(244242);

		b = true;
		n = end - it;
		for (size_t i = 0; i < n; i++)
		{
			if (*it != *it1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			++it;
			++it1;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = send - sit;
		for (size_t i = 0; i < n; i++)
		{
			if (*sit != *sit1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			++sit;
			++sit1;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = oend - oit;
		for (size_t i = 0; i < n; i++)
		{
			if (*oit != *oit1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			++oit;
			++oit1;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = eend - eit;
		for (size_t i = 0; i < n; i++)
		{
			if (*eit != *eit1)
			{
				std::cout << "FAIL" << std::endl;
				b = false;
			}
			++eit;
			++eit1;
		}
		if (b)
			std::cout << GREEN << "✅" << std::endl;
	}

	it = v.begin();
	it1 = v1.begin();

	sit = s.begin();
	sit1 = s1.begin();

	oit = ov.begin();
	oit1 = ov1.begin();

	eit = ev.begin();
	eit1 = ev1.begin();

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the --operator works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "--operator tests: ";
		usleep(244242);

		b = true;
		n = end - it;
		for (size_t i = 0; i < n; i++)
		{
			if (*end != *end1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			--end;
			--end1;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = send - sit;
		for (size_t i = 0; i < n; i++)
		{
			if (*send != *send1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			--send;
			--send1;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = oend - oit;
		for (size_t i = 0; i < n; i++)
		{
			if (*oend != *oend1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			--oend;
			--oend1;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = eend - eit;
		for (size_t i = 0; i < n; i++)
		{
			if (*eend != *eend1)
			{
				std::cout << "FAIL " << std::endl;
				b = false;
			}
			--eend;
			--eend1;
		}
		if (b)
			std::cout << GREEN << "✅ " << std::endl;
	}

	end = v.end();
	end1 = v1.end();

	send = s.end();
	send1 = s1.end();

	oend = ov.end();
	oend1 = ov1.end();

	eit = ev.end();
	eit1 = ev1.end();

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator+= works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator+= tests: ";
		usleep(244242);

		b = true;
		n = (end - it);
		for (size_t i = 0; i < n; i++)
		{
			if (*it != *it1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			it += 1;
			it1 += 1;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = (send - sit);
		for (size_t i = 0; i < n; i++)
		{
			if (*sit != *sit1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			sit += 1;
			sit1 += 1;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = (oend - oit);
		for (size_t i = 0; i < n; i++)
		{
			if (*oit != *oit1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			oit += 1;
			oit1 += 1;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = (eend - eit);
		for (size_t i = 0; i < n; i++)
		{
			if (*eit != *eit1)
			{
				std::cout << "FAIL" << std::endl;
				b = false;
			}
			eit += 1;
			eit1 += 1;
		}
		if (b)
			std::cout << GREEN << "✅" << std::endl;
	}
	
	it = v.begin();
	it1 = v1.begin();

	sit = s.begin();
	sit1 = s1.begin();

	oit = ov.begin();
	oit1 = ov1.begin();

	eit = ev.begin();
	eit1 = ev1.begin();

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator-= works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator-= tests: ";
		usleep(244242);

		b = true;
		n = end - it;
		for (size_t i = 0; i < n; i++)
		{
			if (*end != *end1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			end -= 1;
			end1 -= 1;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = send - sit;
		for (size_t i = 0; i < n; i++)
		{
			if (*send != *send1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			send -= 1;
			send1 -= 1;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = oend - oit;
		for (size_t i = 0; i < n; i++)
		{
			if (*oend != *oend1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			oend -= 1;
			oend1 -= 1;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = eend - eit;
		for (size_t i = 0; i < n; i++)
		{
			if (*eend != *eend1)
			{
				std::cout << "FAIL " << std::endl;
				b = false;
			}
			eend -= 1;
			eend1 -= 1;
		}
		if (b)
			std::cout << GREEN << "✅" << std::endl;
	}

	end = v.end();
	end1 = v1.end();

	send = s.end();
	send1 = s1.end();

	oend = ov.end();
	oend1 = ov1.end();

	eit = ev.end();
	eit1 = ev1.end();

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator- (it - it) works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator-(it) tests: ";
		usleep(244242);

		if ((end - it) != (end1 - it1))
			std::cout << "FAIL ";
		else
			std::cout << GREEN << "✅ " << RESET;

		end--;
		end1--;
		if ((end - it) != (end1 - it1))
			std::cout << "FAIL ";
		else
			std::cout << GREEN << "✅ " << RESET;

		end -= 42;
		end1 -= 42;
		it += 42;
		it1 += 42;
		if ((end - it) != (end1 - it1))
			std::cout << RED << "FAIL" << RESET << std::endl;
		else
			std::cout << GREEN << "✅ " << RESET << std::endl;
	}

	it = v.begin();
	it1 = v1.begin();

	sit = s.begin();
	sit1 = s1.begin();

	oit = ov.begin();
	oit1 = ov1.begin();

	eit = ev.begin();
	eit1 = ev1.begin();

	end = v.end();
	end1 = v1.end();

	send = s.end();
	send1 = s1.end();

	oend = ov.end();
	oend1 = ov1.end();

	eit = ev.end();
	eit1 = ev1.end();

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator[] works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator[] tests: ";
		usleep(244242);

		b = true;
		n = end - it;
		for (size_t i = 0; i < n; i++)
		{
			if (it[i] != it1[i])
			{
				std::cout << "FAIL ";
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = send - sit;
		for (size_t i = 0; i < n; i++)
		{
			if (sit[i] != sit1[i])
			{
				std::cout << "FAIL ";
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "✅ ";
		
		b = true;
		n = oend - oit;
		for (size_t i = 0; i < n; i++)
		{
			if (oit[i] != oit1[i])
			{
				std::cout << "FAIL ";
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = eend - eit;
		for (size_t i = 0; i < n; i++)
		{
			if (eit[i] != eit1[i])
			{
				std::cout << "FAIL" << std::endl;
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "✅" << std::endl;
	}

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator* works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator* tests: ";
		usleep(244242);

		b = true;
		n = end - it;
		for (size_t i = 0; i < n; i++)
		{
			if (*it != *it1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			it++;
			it1++;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = send - sit;
		for (size_t i = 0; i < n; i++)
		{
			if (*sit != *sit1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			sit++;
			sit1++;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = oend - oit;
		for (size_t i = 0; i < n; i++)
		{
			if (*oit != *oit1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			oit++;
			oit1++;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = eend - eit;
		for (size_t i = 0; i < n; i++)
		{
			if (*eit != *eit1)
			{
				std::cout << "FAIL" << std::endl;
				b = false;
			}
			eit++;
			eit1++;
		}
		if (b)
			std::cout << GREEN << "✅" << std::endl;
	}

	it = v.begin();
	it1 = v1.begin();

	sit = s.begin();
	sit1 = s1.begin();

	oit = ov.begin();
	oit1 = ov1.begin();

	eit = ev.begin();
	eit1 = ev1.begin();

	std::vector<int>::iterator	aux = v.begin();
	ft::vector<int>::iterator	aux1 = v1.begin();

	std::vector<std::string>::iterator	saux = s.begin();
	ft::vector<std::string>::iterator	saux1 = s1.begin();

	std::vector<int>::iterator	oaux = ov.begin();
	ft::vector<int>::iterator	oaux1 = ov1.begin();

	std::vector<int>::iterator	eaux = ev.begin();
	ft::vector<int>::iterator	eaux1 = ev1.begin();

	std::string					res[2] = {"✅", "FAIL"};

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator== works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator== tests: ";
		usleep(244242);

		std::cout << res[((it == end) != (it1 == end1))] << " ";
		std::cout << res[((it == aux) != (it1 == aux1))] << " ";
		std::cout << res[((++it == aux) != (++it1 == aux1))] << " ";
		std::cout << res[((--it == aux) != (--it1 == aux1))] << " ";
		std::cout << res[((it++ == aux) != (it1++ == aux1))] << " ";
		std::cout << res[((it-- == aux) != (it1-- == aux1))] << " ";

		std::cout << res[((sit == send) != (sit1 == send1))] << " ";
		std::cout << res[((sit == saux) != (sit1 == saux1))] << " ";
		std::cout << res[((++sit == saux) != (++sit1 == saux1))] << " ";
		std::cout << res[((--sit == saux) != (--sit1 == saux1))] << " ";
		std::cout << res[((sit++ == saux) != (sit1++ == saux1))] << " ";
		std::cout << res[((sit-- == saux) != (sit1-- == saux1))] << " ";

		std::cout << res[((oit == oend) != (oit1 == oend1))] << " ";
		std::cout << res[((oit == oaux) != (oit1 == oaux1))] << " ";
		std::cout << res[((++oit == oaux) != (++oit1 == oaux1))] << " ";
		std::cout << res[((--oit == oaux) != (--oit1 == oaux1))] << " ";
		std::cout << res[((oit++ == oaux) != (oit1++ == oaux1))] << " ";
		std::cout << res[((oit-- == oaux) != (oit1-- == oaux1))] << " ";

		std::cout << res[((eit == eend) != (eit1 == eend1))] << " ";
		std::cout << res[((eit == eaux) != (eit1 == eaux1))] << " ";
		std::cout << res[((++eit == eaux) != (++eit1 == eaux1))] << " ";
		std::cout << res[((--eit == eaux) != (--eit1 == eaux1))] << " ";
		std::cout << res[((eit++ == eaux) != (eit1++ == eaux1))] << " ";
		std::cout << res[((eit-- == eaux) != (eit1-- == eaux1))] << std::endl;
	}

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator!= works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator!= tests: ";
		usleep(244242);

		std::cout << res[((it != end) != (it1 != end1))] << " ";
		std::cout << res[((it != aux) != (it1 != aux1))] << " ";
		std::cout << res[((++it != aux) != (++it1 != aux1))] << " ";
		std::cout << res[((--it != aux) != (--it1 != aux1))] << " ";
		std::cout << res[((it++ != aux) != (it1++ != aux1))] << " ";
		std::cout << res[((it-- != aux) != (it1-- != aux1))] << " ";

		std::cout << res[((sit != send) != (sit1 != send1))] << " ";
		std::cout << res[((sit != saux) != (sit1 != saux1))] << " ";
		std::cout << res[((++sit != saux) != (++sit1 != saux1))] << " ";
		std::cout << res[((--sit != saux) != (--sit1 != saux1))] << " ";
		std::cout << res[((sit++ != saux) != (sit1++ != saux1))] << " ";
		std::cout << res[((sit-- != saux) != (sit1-- != saux1))] << " ";

		std::cout << res[((oit != oend) != (oit1 != oend1))] << " ";
		std::cout << res[((oit != oaux) != (oit1 != oaux1))] << " ";
		std::cout << res[((++oit != oaux) != (++oit1 != oaux1))] << " ";
		std::cout << res[((--oit != oaux) != (--oit1 != oaux1))] << " ";
		std::cout << res[((oit++ != oaux) != (oit1++ != oaux1))] << " ";
		std::cout << res[((oit-- != oaux) != (oit1-- != oaux1))] << " ";

		std::cout << res[((eit != eend) != (eit1 != eend1))] << " ";
		std::cout << res[((eit != eaux) != (eit1 != eaux1))] << " ";
		std::cout << res[((++eit != eaux) != (++eit1 != eaux1))] << " ";
		std::cout << res[((--eit != eaux) != (--eit1 != eaux1))] << " ";
		std::cout << res[((eit++ != eaux) != (eit1++ != eaux1))] << " ";
		std::cout << res[((eit-- != eaux) != (eit1-- != eaux1))] << std::endl;
	}
	
	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator< works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator< tests: ";
		usleep(244242);

		std::cout << res[((it < end) != (it1 < end1))] << " ";
		std::cout << res[((it < aux) != (it1 < aux1))] << " ";
		std::cout << res[((++it < aux) != (++it1 < aux1))] << " ";
		std::cout << res[((--it < aux) != (--it1 < aux1))] << " ";
		std::cout << res[((it++ < aux) != (it1++ < aux1))] << " ";
		std::cout << res[((it-- < aux) != (it1-- < aux1))] << " ";

		std::cout << res[((sit < send) != (sit1 < send1))] << " ";
		std::cout << res[((sit < saux) != (sit1 < saux1))] << " ";
		std::cout << res[((++sit < saux) != (++sit1 < saux1))] << " ";
		std::cout << res[((--sit < saux) != (--sit1 < saux1))] << " ";
		std::cout << res[((sit++ < saux) != (sit1++ < saux1))] << " ";
		std::cout << res[((sit-- < saux) != (sit1-- < saux1))] << " ";

		std::cout << res[((oit < oend) != (oit1 < oend1))] << " ";
		std::cout << res[((oit < oaux) != (oit1 < oaux1))] << " ";
		std::cout << res[((++oit < oaux) != (++oit1 < oaux1))] << " ";
		std::cout << res[((--oit < oaux) != (--oit1 < oaux1))] << " ";
		std::cout << res[((oit++ < oaux) != (oit1++ < oaux1))] << " ";
		std::cout << res[((oit-- < oaux) != (oit1-- < oaux1))] << " ";

		std::cout << res[((eit < eend) != (eit1 < eend1))] << " ";
		std::cout << res[((eit < eaux) != (eit1 < eaux1))] << " ";
		std::cout << res[((++eit < eaux) != (++eit1 < eaux1))] << " ";
		std::cout << res[((--eit < eaux) != (--eit1 < eaux1))] << " ";
		std::cout << res[((eit++ < eaux) != (eit1++ < eaux1))] << " ";
		std::cout << res[((eit-- < eaux) != (eit1-- < eaux1))] << std::endl;
	}

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator<= works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator<= tests: ";
		usleep(244242);

		std::cout << res[((it <= end) != (it1 <= end1))] << " ";
		std::cout << res[((it <= aux) != (it1 <= aux1))] << " ";
		std::cout << res[((++it <= aux) != (++it1 <= aux1))] << " ";
		std::cout << res[((--it <= aux) != (--it1 <= aux1))] << " ";
		std::cout << res[((it++ <= aux) != (it1++ <= aux1))] << " ";
		std::cout << res[((it-- <= aux) != (it1-- <= aux1))] << " ";

		std::cout << res[((sit <= send) != (sit1 <= send1))] << " ";
		std::cout << res[((sit <= saux) != (sit1 <= saux1))] << " ";
		std::cout << res[((++sit <= saux) != (++sit1 <= saux1))] << " ";
		std::cout << res[((--sit <= saux) != (--sit1 <= saux1))] << " ";
		std::cout << res[((sit++ <= saux) != (sit1++ <= saux1))] << " ";
		std::cout << res[((sit-- <= saux) != (sit1-- <= saux1))] << " ";

		std::cout << res[((oit <= oend) != (oit1 <= oend1))] << " ";
		std::cout << res[((oit <= oaux) != (oit1 <= oaux1))] << " ";
		std::cout << res[((++oit <= oaux) != (++oit1 <= oaux1))] << " ";
		std::cout << res[((--oit <= oaux) != (--oit1 <= oaux1))] << " ";
		std::cout << res[((oit++ <= oaux) != (oit1++ <= oaux1))] << " ";
		std::cout << res[((oit-- <= oaux) != (oit1-- <= oaux1))] << " ";

		std::cout << res[((eit <= eend) != (eit1 <= eend1))] << " ";
		std::cout << res[((eit <= eaux) != (eit1 <= eaux1))] << " ";
		std::cout << res[((++eit <= eaux) != (++eit1 <= eaux1))] << " ";
		std::cout << res[((--eit <= eaux) != (--eit1 <= eaux1))] << " ";
		std::cout << res[((eit++ <= eaux) != (eit1++ <= eaux1))] << " ";
		std::cout << res[((eit-- <= eaux) != (eit1-- <= eaux1))] << std::endl;
	}
	
	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator> works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator> tests: ";
		usleep(244242);

		std::cout << res[((it > end) != (it1 > end1))] << " ";
		std::cout << res[((it > aux) != (it1 > aux1))] << " ";
		std::cout << res[((++it > aux) != (++it1 > aux1))] << " ";
		std::cout << res[((--it > aux) != (--it1 > aux1))] << " ";
		std::cout << res[((it++ > aux) != (it1++ > aux1))] << " ";
		std::cout << res[((it-- > aux) != (it1-- > aux1))] << " ";

		std::cout << res[((sit > send) != (sit1 > send1))] << " ";
		std::cout << res[((sit > saux) != (sit1 > saux1))] << " ";
		std::cout << res[((++sit > saux) != (++sit1 > saux1))] << " ";
		std::cout << res[((--sit > saux) != (--sit1 > saux1))] << " ";
		std::cout << res[((sit++ > saux) != (sit1++ > saux1))] << " ";
		std::cout << res[((sit-- > saux) != (sit1-- > saux1))] << " ";

		std::cout << res[((oit > oend) != (oit1 > oend1))] << " ";
		std::cout << res[((oit > oaux) != (oit1 > oaux1))] << " ";
		std::cout << res[((++oit > oaux) != (++oit1 > oaux1))] << " ";
		std::cout << res[((--oit > oaux) != (--oit1 > oaux1))] << " ";
		std::cout << res[((oit++ > oaux) != (oit1++ > oaux1))] << " ";
		std::cout << res[((oit-- > oaux) != (oit1-- > oaux1))] << " ";

		std::cout << res[((eit > eend) != (eit1 > eend1))] << " ";
		std::cout << res[((eit > eaux) != (eit1 > eaux1))] << " ";
		std::cout << res[((++eit > eaux) != (++eit1 > eaux1))] << " ";
		std::cout << res[((--eit > eaux) != (--eit1 > eaux1))] << " ";
		std::cout << res[((eit++ > eaux) != (eit1++ > eaux1))] << " ";
		std::cout << res[((eit-- > eaux) != (eit1-- > eaux1))] << std::endl;
	}

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator>= works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator>= tests: ";
		usleep(244242);
		
		std::cout << res[((it >= end) != (it1 >= end1))] << " ";
		std::cout << res[((it >= aux) != (it1 >= aux1))] << " ";
		std::cout << res[((++it >= aux) != (++it1 >= aux1))] << " ";
		std::cout << res[((--it >= aux) != (--it1 >= aux1))] << " ";
		std::cout << res[((it++ >= aux) != (it1++ >= aux1))] << " ";
		std::cout << res[((it-- >= aux) != (it1-- >= aux1))] << " ";

		std::cout << res[((sit >= send) != (sit1 >= send1))] << " ";
		std::cout << res[((sit >= saux) != (sit1 >= saux1))] << " ";
		std::cout << res[((++sit >= saux) != (++sit1 >= saux1))] << " ";
		std::cout << res[((--sit >= saux) != (--sit1 >= saux1))] << " ";
		std::cout << res[((sit++ >= saux) != (sit1++ >= saux1))] << " ";
		std::cout << res[((sit-- >= saux) != (sit1-- >= saux1))] << " ";

		std::cout << res[((oit >= oend) != (oit1 >= oend1))] << " ";
		std::cout << res[((oit >= oaux) != (oit1 >= oaux1))] << " ";
		std::cout << res[((++oit >= oaux) != (++oit1 >= oaux1))] << " ";
		std::cout << res[((--oit >= oaux) != (--oit1 >= oaux1))] << " ";
		std::cout << res[((oit++ >= oaux) != (oit1++ >= oaux1))] << " ";
		std::cout << res[((oit-- >= oaux) != (oit1-- >= oaux1))] << " ";

		std::cout << res[((eit >= eend) != (eit1 >= eend1))] << " ";
		std::cout << res[((eit >= eaux) != (eit1 >= eaux1))] << " ";
		std::cout << res[((++eit >= eaux) != (++eit1 >= eaux1))] << " ";
		std::cout << res[((--eit >= eaux) != (--eit1 >= eaux1))] << " ";
		std::cout << res[((eit++ >= eaux) != (eit1++ >= eaux1))] << " ";
		std::cout << res[((eit-- >= eaux) != (eit1-- >= eaux1))] << std::endl;
	}

	aux = v.begin();
	aux1 = v1.begin();

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator= works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator= tests: ";
		usleep(244242);
		if ((aux == it) != (aux1 == it1))
			std::cout << RED << "FAIL" << RESET << std::endl;
		else
			std::cout << GREEN << "✅ " << RESET << std::endl;
		
		std::cout << std::endl << std::endl;
	}
}

void	reverse_iterator_tests( void )
{
	std::cout << RED << "  .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--." << RESET << std::endl;
	std::cout << RESET << ":::::." << RED << "\\" <<RESET << ":::::::." << RED << "\\" << RESET<< "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << std::endl;
	std::cout << RED << "'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `" << RESET << std::endl;

	std::cout << RED << "  _____      _____ _                 _                   _            _   " << std::endl;
	std::cout << " |  __ \\    |_   _| |               | |                 | |          | |  " << std::endl;
	std::cout << " | |__) |     | | | |_ ___ _ __ __ _| |_ ___  _ __ ___  | |_ ___  ___| |_ " << std::endl;
	std::cout << " |  _  /      | | | __/ _ \\ '__/ _` | __/ _ \\| '__/ __| | __/ _ \\/ __| __|" << std::endl;
	std::cout << " | | \\ \\ _   _| |_| ||  __/ | | (_| | || (_) | |  \\__ \\ | ||  __/\\__ \\ |_ " << std::endl;
	std::cout << " |_|  \\_(_) |_____|\\__\\___|_|  \\__,_|\\__\\___/|_|  |___/  \\__\\___||___/\\__|" << RESET << std::endl << std::endl;

	std::cout << RED << "  .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--." << RESET << std::endl;
	std::cout << RESET << ":::::." << RED << "\\" <<RESET << ":::::::." << RED << "\\" << RESET<< "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << std::endl;
	std::cout << RED << "'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `" << RESET << std::endl;

	bool b;
	size_t	n;

	/**
	 * Defined one std::vector and one ft::vector that will be filled with 100 ints.
	 */
	std::vector<int>	v;
	ft::vector<int>		v1;

	/**
	 * Defined one std::vector and one ft::vector that will be filled with 100 strings.
	 */
	std::vector<std::string>	s;
	ft::vector<std::string>		s1;

	/**
	 * Defined one std::vector and one ft::vector that will be empty.
	 */
	std::vector<int>	ev;
	ft::vector<int>		ev1;

	/**
	 * Defined one std::vector and one ft::vector that will have only one int.
	 */
	std::vector<int>	ov;
	ft::vector<int>		ov1;

	for (size_t i = 0; i < 100; i++)
	{
		v.push_back(i);
		v1.push_back(i);

		s.push_back( SSTR( i ) );
		s1.push_back( SSTR( i ) );
	}

	ov.push_back(42);
	ov1.push_back(42);
	
	std::vector<int>::reverse_iterator	it = v.rbegin();
	std::vector<int>::reverse_iterator	end = v.rend();
	ft::vector<int>::reverse_iterator	it1 = v1.rbegin();
	ft::vector<int>::reverse_iterator	end1 = v1.rend();

	std::vector<std::string>::reverse_iterator	sit = s.rbegin();
	std::vector<std::string>::reverse_iterator	send = s.rend();
	ft::vector<std::string>::reverse_iterator	sit1 = s1.rbegin();
	ft::vector<std::string>::reverse_iterator	send1 = s1.rend();

	std::vector<int>::reverse_iterator	oit = ov.rbegin();
	std::vector<int>::reverse_iterator	oend = ov.rend();
	ft::vector<int>::reverse_iterator	oit1 = ov1.rbegin();
	ft::vector<int>::reverse_iterator	oend1 = ov1.rend();

	std::vector<int>::reverse_iterator	eit = ev.rbegin();
	std::vector<int>::reverse_iterator	eend = ev.rend();
	ft::vector<int>::reverse_iterator	eit1 = ev1.rbegin();
	ft::vector<int>::reverse_iterator	eend1 = ev1.rend();

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator+ works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "Operator+ tests: ";
		usleep(244242);

		/**
		 * Test operator+ with vectors full of ints.
		 */
		b = true;
		for (size_t i = 0; (it + i) != end; i++)
		{
			if (*(it + i) != *(it1 + i) || (it1 + i) == end1)
			{
				std::cout << RED << "FAIL " << std::endl;
				b = false;

			}
		}
		if (b && (end - it) == (end1 - it1))
			std::cout << GREEN << "✅ ";

		/**
		 * Test operator+ with vectors full of std::string
		 */
		b = true;
		for (size_t i = 0; (sit + i) != send; i++)
		{
			if (*(sit + i) != *(sit1 + i) || (sit1 + i) == send1)
			{
				std::cout << RED << "FAIL ";
				b = false;
			}
		}
		if (b && (send - sit) == (send1 - sit1))
			std::cout << GREEN << "✅ ";

		/**
		 * Test operator+ with vectors with only one int.
		 */
		b = true;
		for (size_t i = 0; (oit + i) != oend; i++)
		{
			if (*(oit + i) != *(oit1 + i) || (oit1 + i) == oend1)
			{
				std::cout << RED << "FAIL ";
				b = false;
			}
		}
		if (b && (oend - oit) == (oend1 - oit1))
			std::cout << GREEN << "✅ ";

		/**
		 * Test operator+ with empty vectors.
		 */
		b = true;
		for (size_t i = 0; (eit + i) != eend; i++)
		{
			if (*(eit + i) != *(eit1 + i) || (eit1 + i) == end1)
			{
				std::cout << RED << "FAIL " << RESET << std::endl;
				b = false;

			}
		}
		if (b && (eend - eit) == (eend1 - eit1))
			std::cout << GREEN << "✅ " << std::endl;
	}

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator+(size_t + iter) works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator+(size_t + iter) tests: ";
		usleep(244242);

		/**
		 * Test operator+ with vectors full of ints.
		 */
		b = true;
		for (size_t i = 0; (i + it) != end; i++)
		{
			if (*(i + it) != *(i + it1) || (i + it1) == end1)
			{
				std::cout << RED << "FAIL ";
				b = false;
			}
		}
		if (b && (end - it) == (end1 - it1))
			std::cout << GREEN << "✅ ";

		/**
		 * Test operator+ with vectors full of std::strings.
		 */
		b = true;
		for (size_t i = 0; (i + sit) != send; i++)
		{
			if (*(i + sit) != *(i + sit1) || (i + sit1) == send1)
			{
				std::cout << RED << "FAIL ";
				b = false;
			}
		}
		if (b && (send - sit) == (send1 - sit1))
			std::cout << GREEN << "✅ ";

		/**
		 * Test operator+ with vectors with only one int.
		 */
		b = true;
		for (size_t i = 0; (i + oit) != oend; i++)
		{
			if (*(i + oit) != *(i + oit1) || (i + oit1) == oend1)
			{
				std::cout << RED << "FAIL ";
				b = false;
			}
		}
		if (b && (oend - oit) == (oend1 - oit1))
			std::cout << GREEN << "✅ ";

		/**
		 * Test operator+ with empty vectors.
		 */
		b = true;
		for (size_t i = 0; (i + eit) != eend; i++)
		{
			if (*(i + eit) != *(i + eit1) || (i + eit1) == eend1)
			{
				std::cout << RED << "FAIL" << RESET << std::endl;
				b = false;
			}
		}
		if (b && (eend - eit) == (eend1 - eit1))
			std::cout << GREEN << "✅ " << RESET << std::endl;
	}

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator- works as expected.
	 * 
	 */
	{

		usleep(244242);
		std::cout << WHITE << "operator- tests: ";
		usleep(244242);

		/**
		 * Test operator- with vectors full of ints.
		 */
		b = true;
		for (size_t i = 0; (end - i) != it; i++)
		{
			if (*(end - i) != *(end1 - i) || (end1 - i) == it1)
			{
				std::cout << "FAIL ";
				b = false;
			}
		}
		if (b && (end - it) == (end1 - it1))
			std::cout << GREEN << "✅ ";

		/**
		 * Test operator- with vectors full of std::strings.
		 */
		b = true;
		for (size_t i = 0; (send - i) != sit; i++)
		{
			if (*(send - i) != *(send1 - i) || (send1 - i) == sit1)
			{
				std::cout << "FAIL ";
				b = false;
			}
		}
		if (b && (send - sit) == (send1 - sit1))
			std::cout << GREEN << "✅ ";

		/**
		 * Test operator- with vectors with only one int.
		 */
		b = true;
		for (size_t i = 0; (oend - i) != oit; i++)
		{
			if (*(oend - i) != *(oend1 - i) || (oend1 - i) == oit1)
			{
				std::cout << "FAIL ";
				b = false;
			}
		}
		if (b && (oend - oit) == (oend1 - oit1))
			std::cout << GREEN << "✅ ";

		/**
		 * Test operator- with empty vector.
		 */
		b = true;
		for (size_t i = 0; (eend - i) != eit; i++)
		{
			if (*(eend - i) != *(eend1 - i) || (eend1 - i) == eit1)
			{
				std::cout << "FAIL" << std::endl;
				b = false;
			}
		}
		if (b && (eend - eit) == (eend1 - eit1))
			std::cout << GREEN << "✅" << std::endl;
	}

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator++ works as expected.
	 * 
	 */
	{	
		usleep(244242);
		std::cout << WHITE << "operator++ tests: ";
		usleep(244242);

		b = true;
		n = (end - it);
		for (size_t i = 0; i < n; i++)
		{
			if (*it != *it1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			it++;
			it1++;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = (send - sit);
		for (size_t i = 0; (long)i < (send - sit); i++)
		{
			if (*sit != *sit1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			sit++;
			sit1++;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = (oend - oit);
		for (size_t i = 0; i < n; i++)
		{
			if (*oit != *oit1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			oit++;
			oit1++;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = (eend - eit);
		for (size_t i = 0; i < n; i++)
		{
			if (*eit != *eit1)
			{
				std::cout << "FAIL" << std::endl;
				b = false;
			}
			eit++;
			eit1++;
		}
		if (b)
			std::cout << GREEN << "✅" << std::endl;
	}

	it = v.rbegin();
	it1 = v1.rbegin();

	sit = s.rbegin();
	sit1 = s1.rbegin();

	oit = ov.rbegin();
	oit1 = ov1.rbegin();

	eit = ev.rbegin();
	eit1 = ev1.rbegin();

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator-- works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator-- tests: ";
		usleep(244242);

		b = true;
		n = end - it;
		for (size_t i = 0; i < n; i++)
		{
			if (*end != *end1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			end--;
			end1--;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = send - sit;
		for (size_t i = 0; i < n; i++)
		{
			if (*send != *send1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			send--;
			send1--;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = oend - oit;
		for (size_t i = 0; i < n; i++)
		{
			if (*oend != *oend1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			oend--;
			oend1--;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = eend - eit;
		for (size_t i = 0; i < n; i++)
		{
			if (*eend != *eend1)
			{
				std::cout << "FAIL" << std::endl;
				b = false;
			}
			eend--;
			eend1--;
		}
		if (b)
			std::cout << GREEN << "✅" << std::endl;
	}

	end = v.rend();
	end1 = v1.rend();

	send = s.rend();
	send1 = s1.rend();

	oend = ov.rend();
	oend1 = ov1.rend();

	eit = ev.rend();
	eit1 = ev1.rend();

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the ++operator works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "++operator tests: ";
		usleep(244242);

		b = true;
		n = end - it;
		for (size_t i = 0; i < n; i++)
		{
			if (*it != *it1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			++it;
			++it1;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = send - sit;
		for (size_t i = 0; i < n; i++)
		{
			if (*sit != *sit1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			++sit;
			++sit1;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = oend - oit;
		for (size_t i = 0; i < n; i++)
		{
			if (*oit != *oit1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			++oit;
			++oit1;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = eend - eit;
		for (size_t i = 0; i < n; i++)
		{
			if (*eit != *eit1)
			{
				std::cout << "FAIL" << std::endl;
				b = false;
			}
			++eit;
			++eit1;
		}
		if (b)
			std::cout << GREEN << "✅" << std::endl;
	}

	it = v.rbegin();
	it1 = v1.rbegin();

	sit = s.rbegin();
	sit1 = s1.rbegin();

	oit = ov.rbegin();
	oit1 = ov1.rbegin();

	eit = ev.rbegin();
	eit1 = ev1.rbegin();

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the --operator works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "--operator tests: ";
		usleep(244242);

		b = true;
		n = end - it;
		for (size_t i = 0; i < n; i++)
		{
			if (*end != *end1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			--end;
			--end1;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = send - sit;
		for (size_t i = 0; i < n; i++)
		{
			if (*send != *send1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			--send;
			--send1;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = oend - oit;
		for (size_t i = 0; i < n; i++)
		{
			if (*oend != *oend1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			--oend;
			--oend1;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = eend - eit;
		for (size_t i = 0; i < n; i++)
		{
			if (*eend != *eend1)
			{
				std::cout << "FAIL " << std::endl;
				b = false;
			}
			--eend;
			--eend1;
		}
		if (b)
			std::cout << GREEN << "✅ " << std::endl;
	}

	end = v.rend();
	end1 = v1.rend();

	send = s.rend();
	send1 = s1.rend();

	oend = ov.rend();
	oend1 = ov1.rend();

	eit = ev.rend();
	eit1 = ev1.rend();

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator+= works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator+= tests: ";
		usleep(244242);

		b = true;
		n = (end - it);
		for (size_t i = 0; i < n; i++)
		{
			if (*it != *it1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			it += 1;
			it1 += 1;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = (send - sit);
		for (size_t i = 0; i < n; i++)
		{
			if (*sit != *sit1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			sit += 1;
			sit1 += 1;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = (oend - oit);
		for (size_t i = 0; i < n; i++)
		{
			if (*oit != *oit1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			oit += 1;
			oit1 += 1;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = (eend - eit);
		for (size_t i = 0; i < n; i++)
		{
			if (*eit != *eit1)
			{
				std::cout << "FAIL" << std::endl;
				b = false;
			}
			eit += 1;
			eit1 += 1;
		}
		if (b)
			std::cout << GREEN << "✅" << std::endl;
	}
	
	it = v.rbegin();
	it1 = v1.rbegin();

	sit = s.rbegin();
	sit1 = s1.rbegin();

	oit = ov.rbegin();
	oit1 = ov1.rbegin();

	eit = ev.rbegin();
	eit1 = ev1.rbegin();

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator-= works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator-= tests: ";
		usleep(244242);

		b = true;
		n = end - it;
		for (size_t i = 0; i < n; i++)
		{
			if (*end != *end1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			end -= 1;
			end1 -= 1;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = send - sit;
		for (size_t i = 0; i < n; i++)
		{
			if (*send != *send1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			send -= 1;
			send1 -= 1;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = oend - oit;
		for (size_t i = 0; i < n; i++)
		{
			if (*oend != *oend1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			oend -= 1;
			oend1 -= 1;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = eend - eit;
		for (size_t i = 0; i < n; i++)
		{
			if (*eend != *eend1)
			{
				std::cout << "FAIL " << std::endl;
				b = false;
			}
			eend -= 1;
			eend1 -= 1;
		}
		if (b)
			std::cout << GREEN << "✅" << std::endl;
	}

	end = v.rend();
	end1 = v1.rend();

	send = s.rend();
	send1 = s1.rend();

	oend = ov.rend();
	oend1 = ov1.rend();

	eit = ev.rend();
	eit1 = ev1.rend();

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator- (it - it) works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator-(it) tests: ";
		usleep(244242);

		if ((end - it) != (end1 - it1))
			std::cout << "FAIL ";
		else
			std::cout << GREEN << "✅ " << RESET;

		end--;
		end1--;
		if ((end - it) != (end1 - it1))
			std::cout << "FAIL ";
		else
			std::cout << GREEN << "✅ " << RESET;

		end -= 42;
		end1 -= 42;
		it += 42;
		it1 += 42;
		if ((end - it) != (end1 - it1))
			std::cout << RED << "FAIL" << RESET << std::endl;
		else
			std::cout << GREEN << "✅ " << RESET << std::endl;
	}

	it = v.rbegin();
	it1 = v1.rbegin();

	sit = s.rbegin();
	sit1 = s1.rbegin();

	oit = ov.rbegin();
	oit1 = ov1.rbegin();

	eit = ev.rbegin();
	eit1 = ev1.rbegin();

	end = v.rend();
	end1 = v1.rend();

	send = s.rend();
	send1 = s1.rend();

	oend = ov.rend();
	oend1 = ov1.rend();

	eit = ev.rend();
	eit1 = ev1.rend();

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator[] works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator[] tests: ";
		usleep(244242);

		b = true;
		n = end - it;
		for (size_t i = 0; i < n; i++)
		{
			if (it[i] != it1[i])
			{
				std::cout << "FAIL ";
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = send - sit;
		for (size_t i = 0; i < n; i++)
		{
			if (sit[i] != sit1[i])
			{
				std::cout << "FAIL ";
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "✅ ";
		
		b = true;
		n = oend - oit;
		for (size_t i = 0; i < n; i++)
		{
			if (oit[i] != oit1[i])
			{
				std::cout << "FAIL ";
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = eend - eit;
		for (size_t i = 0; i < n; i++)
		{
			if (eit[i] != eit1[i])
			{
				std::cout << "FAIL" << std::endl;
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "✅" << std::endl;
	}

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator* works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator* tests: ";
		usleep(244242);

		b = true;
		n = end - it;
		for (size_t i = 0; i < n; i++)
		{
			if (*it != *it1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			it++;
			it1++;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = send - sit;
		for (size_t i = 0; i < n; i++)
		{
			if (*sit != *sit1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			sit++;
			sit1++;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = oend - oit;
		for (size_t i = 0; i < n; i++)
		{
			if (*oit != *oit1)
			{
				std::cout << "FAIL ";
				b = false;
			}
			oit++;
			oit1++;
		}
		if (b)
			std::cout << GREEN << "✅ ";

		b = true;
		n = eend - eit;
		for (size_t i = 0; i < n; i++)
		{
			if (*eit != *eit1)
			{
				std::cout << "FAIL" << std::endl;
				b = false;
			}
			eit++;
			eit1++;
		}
		if (b)
			std::cout << GREEN << "✅" << std::endl;
	}

	it = v.rbegin();
	it1 = v1.rbegin();

	sit = s.rbegin();
	sit1 = s1.rbegin();

	oit = ov.rbegin();
	oit1 = ov1.rbegin();

	eit = ev.rbegin();
	eit1 = ev1.rbegin();

	std::vector<int>::reverse_iterator	aux = v.rbegin();
	ft::vector<int>::reverse_iterator	aux1 = v1.rbegin();

	std::vector<std::string>::reverse_iterator	saux = s.rbegin();
	ft::vector<std::string>::reverse_iterator	saux1 = s1.rbegin();

	std::vector<int>::reverse_iterator	oaux = ov.rbegin();
	ft::vector<int>::reverse_iterator	oaux1 = ov1.rbegin();

	std::vector<int>::reverse_iterator	eaux = ev.rbegin();
	ft::vector<int>::reverse_iterator	eaux1 = ev1.rbegin();

	std::string					res[2] = {"✅", "FAIL"};

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator== works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator== tests: ";
		usleep(244242);

		std::cout << res[((it == end) != (it1 == end1))] << " ";
		std::cout << res[((it == aux) != (it1 == aux1))] << " ";
		std::cout << res[((++it == aux) != (++it1 == aux1))] << " ";
		std::cout << res[((--it == aux) != (--it1 == aux1))] << " ";
		std::cout << res[((it++ == aux) != (it1++ == aux1))] << " ";
		std::cout << res[((it-- == aux) != (it1-- == aux1))] << " ";

		std::cout << res[((sit == send) != (sit1 == send1))] << " ";
		std::cout << res[((sit == saux) != (sit1 == saux1))] << " ";
		std::cout << res[((++sit == saux) != (++sit1 == saux1))] << " ";
		std::cout << res[((--sit == saux) != (--sit1 == saux1))] << " ";
		std::cout << res[((sit++ == saux) != (sit1++ == saux1))] << " ";
		std::cout << res[((sit-- == saux) != (sit1-- == saux1))] << " ";

		std::cout << res[((oit == oend) != (oit1 == oend1))] << " ";
		std::cout << res[((oit == oaux) != (oit1 == oaux1))] << " ";
		std::cout << res[((++oit == oaux) != (++oit1 == oaux1))] << " ";
		std::cout << res[((--oit == oaux) != (--oit1 == oaux1))] << " ";
		std::cout << res[((oit++ == oaux) != (oit1++ == oaux1))] << " ";
		std::cout << res[((oit-- == oaux) != (oit1-- == oaux1))] << " ";

		std::cout << res[((eit == eend) != (eit1 == eend1))] << " ";
		std::cout << res[((eit == eaux) != (eit1 == eaux1))] << " ";
		std::cout << res[((++eit == eaux) != (++eit1 == eaux1))] << " ";
		std::cout << res[((--eit == eaux) != (--eit1 == eaux1))] << " ";
		std::cout << res[((eit++ == eaux) != (eit1++ == eaux1))] << " ";
		std::cout << res[((eit-- == eaux) != (eit1-- == eaux1))] << std::endl;
	}

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator!= works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator!= tests: ";
		usleep(244242);

		std::cout << res[((it != end) != (it1 != end1))] << " ";
		std::cout << res[((it != aux) != (it1 != aux1))] << " ";
		std::cout << res[((++it != aux) != (++it1 != aux1))] << " ";
		std::cout << res[((--it != aux) != (--it1 != aux1))] << " ";
		std::cout << res[((it++ != aux) != (it1++ != aux1))] << " ";
		std::cout << res[((it-- != aux) != (it1-- != aux1))] << " ";

		std::cout << res[((sit != send) != (sit1 != send1))] << " ";
		std::cout << res[((sit != saux) != (sit1 != saux1))] << " ";
		std::cout << res[((++sit != saux) != (++sit1 != saux1))] << " ";
		std::cout << res[((--sit != saux) != (--sit1 != saux1))] << " ";
		std::cout << res[((sit++ != saux) != (sit1++ != saux1))] << " ";
		std::cout << res[((sit-- != saux) != (sit1-- != saux1))] << " ";

		std::cout << res[((oit != oend) != (oit1 != oend1))] << " ";
		std::cout << res[((oit != oaux) != (oit1 != oaux1))] << " ";
		std::cout << res[((++oit != oaux) != (++oit1 != oaux1))] << " ";
		std::cout << res[((--oit != oaux) != (--oit1 != oaux1))] << " ";
		std::cout << res[((oit++ != oaux) != (oit1++ != oaux1))] << " ";
		std::cout << res[((oit-- != oaux) != (oit1-- != oaux1))] << " ";

		std::cout << res[((eit != eend) != (eit1 != eend1))] << " ";
		std::cout << res[((eit != eaux) != (eit1 != eaux1))] << " ";
		std::cout << res[((++eit != eaux) != (++eit1 != eaux1))] << " ";
		std::cout << res[((--eit != eaux) != (--eit1 != eaux1))] << " ";
		std::cout << res[((eit++ != eaux) != (eit1++ != eaux1))] << " ";
		std::cout << res[((eit-- != eaux) != (eit1-- != eaux1))] << std::endl;
	}
	
	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator< works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator< tests: ";
		usleep(244242);

		std::cout << res[((it < end) != (it1 < end1))] << " ";
		std::cout << res[((it < aux) != (it1 < aux1))] << " ";
		std::cout << res[((++it < aux) != (++it1 < aux1))] << " ";
		std::cout << res[((--it < aux) != (--it1 < aux1))] << " ";
		std::cout << res[((it++ < aux) != (it1++ < aux1))] << " ";
		std::cout << res[((it-- < aux) != (it1-- < aux1))] << " ";

		std::cout << res[((sit < send) != (sit1 < send1))] << " ";
		std::cout << res[((sit < saux) != (sit1 < saux1))] << " ";
		std::cout << res[((++sit < saux) != (++sit1 < saux1))] << " ";
		std::cout << res[((--sit < saux) != (--sit1 < saux1))] << " ";
		std::cout << res[((sit++ < saux) != (sit1++ < saux1))] << " ";
		std::cout << res[((sit-- < saux) != (sit1-- < saux1))] << " ";

		std::cout << res[((oit < oend) != (oit1 < oend1))] << " ";
		std::cout << res[((oit < oaux) != (oit1 < oaux1))] << " ";
		std::cout << res[((++oit < oaux) != (++oit1 < oaux1))] << " ";
		std::cout << res[((--oit < oaux) != (--oit1 < oaux1))] << " ";
		std::cout << res[((oit++ < oaux) != (oit1++ < oaux1))] << " ";
		std::cout << res[((oit-- < oaux) != (oit1-- < oaux1))] << " ";

		std::cout << res[((eit < eend) != (eit1 < eend1))] << " ";
		std::cout << res[((eit < eaux) != (eit1 < eaux1))] << " ";
		std::cout << res[((++eit < eaux) != (++eit1 < eaux1))] << " ";
		std::cout << res[((--eit < eaux) != (--eit1 < eaux1))] << " ";
		std::cout << res[((eit++ < eaux) != (eit1++ < eaux1))] << " ";
		std::cout << res[((eit-- < eaux) != (eit1-- < eaux1))] << std::endl;
	}

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator<= works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator<= tests: ";
		usleep(244242);

		std::cout << res[((it <= end) != (it1 <= end1))] << " ";
		std::cout << res[((it <= aux) != (it1 <= aux1))] << " ";
		std::cout << res[((++it <= aux) != (++it1 <= aux1))] << " ";
		std::cout << res[((--it <= aux) != (--it1 <= aux1))] << " ";
		std::cout << res[((it++ <= aux) != (it1++ <= aux1))] << " ";
		std::cout << res[((it-- <= aux) != (it1-- <= aux1))] << " ";

		std::cout << res[((sit <= send) != (sit1 <= send1))] << " ";
		std::cout << res[((sit <= saux) != (sit1 <= saux1))] << " ";
		std::cout << res[((++sit <= saux) != (++sit1 <= saux1))] << " ";
		std::cout << res[((--sit <= saux) != (--sit1 <= saux1))] << " ";
		std::cout << res[((sit++ <= saux) != (sit1++ <= saux1))] << " ";
		std::cout << res[((sit-- <= saux) != (sit1-- <= saux1))] << " ";

		std::cout << res[((oit <= oend) != (oit1 <= oend1))] << " ";
		std::cout << res[((oit <= oaux) != (oit1 <= oaux1))] << " ";
		std::cout << res[((++oit <= oaux) != (++oit1 <= oaux1))] << " ";
		std::cout << res[((--oit <= oaux) != (--oit1 <= oaux1))] << " ";
		std::cout << res[((oit++ <= oaux) != (oit1++ <= oaux1))] << " ";
		std::cout << res[((oit-- <= oaux) != (oit1-- <= oaux1))] << " ";

		std::cout << res[((eit <= eend) != (eit1 <= eend1))] << " ";
		std::cout << res[((eit <= eaux) != (eit1 <= eaux1))] << " ";
		std::cout << res[((++eit <= eaux) != (++eit1 <= eaux1))] << " ";
		std::cout << res[((--eit <= eaux) != (--eit1 <= eaux1))] << " ";
		std::cout << res[((eit++ <= eaux) != (eit1++ <= eaux1))] << " ";
		std::cout << res[((eit-- <= eaux) != (eit1-- <= eaux1))] << std::endl;
	}
	
	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator> works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator> tests: ";
		usleep(244242);

		std::cout << res[((it > end) != (it1 > end1))] << " ";
		std::cout << res[((it > aux) != (it1 > aux1))] << " ";
		std::cout << res[((++it > aux) != (++it1 > aux1))] << " ";
		std::cout << res[((--it > aux) != (--it1 > aux1))] << " ";
		std::cout << res[((it++ > aux) != (it1++ > aux1))] << " ";
		std::cout << res[((it-- > aux) != (it1-- > aux1))] << " ";

		std::cout << res[((sit > send) != (sit1 > send1))] << " ";
		std::cout << res[((sit > saux) != (sit1 > saux1))] << " ";
		std::cout << res[((++sit > saux) != (++sit1 > saux1))] << " ";
		std::cout << res[((--sit > saux) != (--sit1 > saux1))] << " ";
		std::cout << res[((sit++ > saux) != (sit1++ > saux1))] << " ";
		std::cout << res[((sit-- > saux) != (sit1-- > saux1))] << " ";

		std::cout << res[((oit > oend) != (oit1 > oend1))] << " ";
		std::cout << res[((oit > oaux) != (oit1 > oaux1))] << " ";
		std::cout << res[((++oit > oaux) != (++oit1 > oaux1))] << " ";
		std::cout << res[((--oit > oaux) != (--oit1 > oaux1))] << " ";
		std::cout << res[((oit++ > oaux) != (oit1++ > oaux1))] << " ";
		std::cout << res[((oit-- > oaux) != (oit1-- > oaux1))] << " ";

		std::cout << res[((eit > eend) != (eit1 > eend1))] << " ";
		std::cout << res[((eit > eaux) != (eit1 > eaux1))] << " ";
		std::cout << res[((++eit > eaux) != (++eit1 > eaux1))] << " ";
		std::cout << res[((--eit > eaux) != (--eit1 > eaux1))] << " ";
		std::cout << res[((eit++ > eaux) != (eit1++ > eaux1))] << " ";
		std::cout << res[((eit-- > eaux) != (eit1-- > eaux1))] << std::endl;
	}

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator>= works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator>= tests: ";
		usleep(244242);
		
		std::cout << res[((it >= end) != (it1 >= end1))] << " ";
		std::cout << res[((it >= aux) != (it1 >= aux1))] << " ";
		std::cout << res[((++it >= aux) != (++it1 >= aux1))] << " ";
		std::cout << res[((--it >= aux) != (--it1 >= aux1))] << " ";
		std::cout << res[((it++ >= aux) != (it1++ >= aux1))] << " ";
		std::cout << res[((it-- >= aux) != (it1-- >= aux1))] << " ";

		std::cout << res[((sit >= send) != (sit1 >= send1))] << " ";
		std::cout << res[((sit >= saux) != (sit1 >= saux1))] << " ";
		std::cout << res[((++sit >= saux) != (++sit1 >= saux1))] << " ";
		std::cout << res[((--sit >= saux) != (--sit1 >= saux1))] << " ";
		std::cout << res[((sit++ >= saux) != (sit1++ >= saux1))] << " ";
		std::cout << res[((sit-- >= saux) != (sit1-- >= saux1))] << " ";

		std::cout << res[((oit >= oend) != (oit1 >= oend1))] << " ";
		std::cout << res[((oit >= oaux) != (oit1 >= oaux1))] << " ";
		std::cout << res[((++oit >= oaux) != (++oit1 >= oaux1))] << " ";
		std::cout << res[((--oit >= oaux) != (--oit1 >= oaux1))] << " ";
		std::cout << res[((oit++ >= oaux) != (oit1++ >= oaux1))] << " ";
		std::cout << res[((oit-- >= oaux) != (oit1-- >= oaux1))] << " ";

		std::cout << res[((eit >= eend) != (eit1 >= eend1))] << " ";
		std::cout << res[((eit >= eaux) != (eit1 >= eaux1))] << " ";
		std::cout << res[((++eit >= eaux) != (++eit1 >= eaux1))] << " ";
		std::cout << res[((--eit >= eaux) != (--eit1 >= eaux1))] << " ";
		std::cout << res[((eit++ >= eaux) != (eit1++ >= eaux1))] << " ";
		std::cout << res[((eit-- >= eaux) != (eit1-- >= eaux1))] << std::endl;
	}

	aux = v.rbegin();
	aux1 = v1.rbegin();

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator= works as expected.
	 * 
	 */
	{
		usleep(244242);
		std::cout << WHITE << "operator= tests: ";
		usleep(244242);
		if ((aux == it) != (aux1 == it1))
			std::cout << RED << "FAIL" << RESET << std::endl;
		else
			std::cout << GREEN << "✅ " << RESET << std::endl;
		
		std::cout << std::endl << std::endl;
	}
}

void	printCase( std::string s, bool b , bool endl)
{
	usleep(244242);
	std::cout << s;
	if (b)
		std::cout << GREEN << "✅ " << RESET;
	else
		std::cout << RED << "FAIL" << RESET;

	if (endl)
		std::cout << std::endl;
	else
		std::cout << " ";
}

void	vectors_test( void )
{
	std::cout << RED << "  .--.     .-'.      .--.      .--.      .--.      .--.      .`-.      .--." << RESET << std::endl;
	std::cout << RESET << ":::::." << RED << "\\" <<RESET << ":::::::." << RED << "\\" << RESET<< "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << std::endl;
	std::cout << RED << "'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `" << RESET << std::endl;

	std::cout << RED << " __      __       _               _            _   " << std::endl;
	std::cout << " \\ \\    / /      | |             | |          | |  " << std::endl;
	std::cout << "  \\ \\  / /__  ___| |_ ___  _ __  | |_ ___  ___| |_ " << std::endl;
	std::cout << "   \\ \\/ / _ \\/ __| __/ _ \\| '__| | __/ _ \\/ __| __|" << std::endl;
	std::cout << "    \\  /  __/ (__| || (_) | |    | ||  __/\\__ \\ |_ " << std::endl;
	std::cout << "     \\/ \\___|\\___|\\__\\___/|_|     \\__\\___||___/\\__|" << RESET << std::endl << std::endl;

	std::cout << RED << "  .--.     .-'.      .--.      .--.      .--.      .--.      .`-.      .--." << RESET << std::endl;
	std::cout << RESET << ":::::." << RED << "\\" <<RESET << ":::::::." << RED << "\\" << RESET<< "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << "::::::::." << RED << "\\" << RESET << std::endl;
	std::cout << RED << "'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `" << RESET << std::endl;

	bool res;

	std::vector<int> v;
	ft::vector<int> v1;

	std::vector<int> iv(10, 42);
	ft::vector<int> iv1(10 , 42);

	std::vector<std::string> sv(10, "42");
	ft::vector<std::string> sv1(10 , "42");

	std::vector<int> ov(10);
	ft::vector<int> ov1(10);

	std::vector<int>::iterator	it = iv.begin();
	ft::vector<int>::iterator	it1 = iv1.begin();

	std::vector<int>::iterator	end = iv.end();
	ft::vector<int>::iterator	end1 = iv1.end();

	std::vector<int>	itev(it, end);
	ft::vector<int>		itev1(it1, end1);

	it = v.begin();
	it1 = v1.begin();
	end = v.end();
	end1 = v1.end();

	std::vector<int>	eitev(it, end);
	ft::vector<int>		eitev1(it1, end1);

	std::vector<int>	equalv = iv;
	ft::vector<int>		equalv1 = iv1;

	res = (v.size() == v1.size());
	printCase("\033[1;37mDefault constructor tests: ", res, false);
	res = (v.capacity() == v1.capacity());
	printCase("", res, true);

	res = (iv.size() == iv1.size());
	printCase("\033[1;37mFill constructor(int, int) tests: ", res, false);
	res = (iv.capacity() == iv1.capacity());
	printCase("", res, false);
	res = (iv.front() == iv1.front());
	printCase("", res, false);
	res = (iv.back() == iv1.back());
	printCase("", res, false);
	res = (iv[9] == iv1[9]);
	printCase("", res, true);

	res = (sv.size() == sv1.size());
	printCase("\033[1;37mFill constructor(int, string) tests: ", res, false);
	res = (sv.capacity() == sv1.capacity());
	printCase("", res, false);
	res = (sv.front() == sv1.front());
	printCase("", res, false);
	res = (sv.back() == sv1.back());
	printCase("", res, false);
	res = (sv[9] == sv1[9]);
	printCase("", res, true);

	res = (ov.size() == ov1.size());
	printCase("\033[1;37mFill constructor(int) tests: ", res, false);
	res = (ov.capacity() == ov1.capacity());
	printCase("", res, false);
	res = (ov.front() == ov1.front());
	printCase("", res, false);
	res = (ov.back() == ov1.back());
	printCase("", res, false);
	res = (ov[9] == ov1[9]);
	printCase("", res, true);

	res = (itev.size() == itev1.size());
	printCase("\033[1;37mRange constructor tests: ", res, false);
	res = (itev.capacity() == itev1.capacity());
	printCase("", res, false);
	res = (itev.front() == itev1.front());
	printCase("", res, false);
	res = (itev.back() == itev1.back());
	printCase("", res, false);
	res = (itev[9] == itev1[9]);
	printCase("", res, true);

	res = (eitev.size() == eitev1.size());
	printCase("\033[1;37mRange empty constructor tests: ", res, false);
	res = (eitev.capacity() == eitev1.capacity());
	printCase("", res, true);

	res = (equalv.size() == equalv1.size());
	printCase("\033[1;37mOperator= with vector<int> tests: ", res, false);
	res = (equalv.capacity() == equalv1.capacity());
	printCase("", res, false);
	res = (equalv.front() == equalv1.front());
	printCase("", res, false);
	res = (equalv.back() == equalv1.back());
	printCase("", res, false);
	res = (equalv[9] == equalv1[9]);
	printCase("", res, true);

	equalv = ov;
	equalv1 = ov1;

	res = (equalv.size() == equalv1.size());
	printCase("\033[1;37mOperator= with vector<int> to existing vector tests: ", res, false);
	res = (equalv.capacity() == equalv1.capacity());
	printCase("", res, false);
	res = (equalv.front() == equalv1.front());
	printCase("", res, false);
	res = (equalv.back() == equalv1.back());
	printCase("", res, false);
	res = (equalv[9] == equalv1[9]);
	printCase("", res, true);

	std::vector<std::string>	equalsv = sv;
	ft::vector<std::string>		equalsv1 = sv1;

	res = (equalsv.size() == equalsv1.size());
	printCase("\033[1;37mOperator= with vector<std::string> tests: ", res, false);
	res = (equalsv.capacity() == equalsv1.capacity());
	printCase("", res, false);
	res = (equalsv.front() == equalsv1.front());
	printCase("", res, false);
	res = (equalsv.back() == equalsv1.back());
	printCase("", res, false);
	res = (equalsv[9] == equalsv1[9]);
	printCase("", res, true);

	res = (v.size() == v1.size());
	printCase("\033[1;37msize() tests: ", res, false);
	res = (iv.size() == iv1.size());
	printCase("", res, false);
	res = (sv.size() == sv1.size());
	printCase("", res, false);
	res = (ov.size() == ov1.size());
	printCase("", res, false);
	res = (itev.size() == itev1.size());
	printCase("", res, false);
	res = (eitev.size() == eitev1.size());
	printCase("", res, true);

	res = (v.max_size() == v1.max_size());
	printCase("\033[1;37mmax_size() tests: ", res, false);
	res = (iv.max_size() == iv1.max_size());
	printCase("", res, false);
	res = (sv.max_size() == sv1.max_size());
	printCase("", res, false);
	res = (ov.max_size() == ov1.max_size());
	printCase("", res, false);
	res = (itev.max_size() == itev1.max_size());
	printCase("", res, false);
	res = (eitev.max_size() == eitev1.max_size());
	printCase("", res, true);

	res = (v.capacity() == v1.capacity());
	printCase("\033[1;37mcapacity() tests: ", res, false);
	res = (iv.capacity() == iv1.capacity());
	printCase("", res, false);
	res = (sv.capacity() == sv1.capacity());
	printCase("", res, false);
	res = (ov.capacity() == ov1.capacity());
	printCase("", res, false);
	res = (itev.capacity() == itev1.capacity());
	printCase("", res, false);
	res = (eitev.capacity() == eitev1.capacity());
	printCase("", res, true);

	res = (v.empty() == v1.empty());
	printCase("\033[1;37mempty() tests: ", res, false);
	res = (iv.empty() == iv1.empty());
	printCase("", res, false);
	res = (sv.empty() == sv1.empty());
	printCase("", res, false);
	res = (ov.empty() == ov1.empty());
	printCase("", res, false);
	res = (itev.empty() == itev1.empty());
	printCase("", res, false);
	res = (eitev.empty() == eitev1.empty());
	printCase("", res, true);

	v.reserve(42);
	v1.reserve(42);
	iv.reserve(42);
	iv1.reserve(42);
	sv.reserve(42);
	sv1.reserve(42);
	ov.reserve(42);
	ov1.reserve(42);
	itev.reserve(42);
	itev1.reserve(42);
	eitev.reserve(42);
	eitev1.reserve(42);

	res = (v.capacity() == v1.capacity() && v.size() == v1.size());
	printCase("\033[1;37mreserve() tests: ", res, false);
	res = (iv.capacity() == iv1.capacity() && iv.size() == iv1.size());
	printCase("", res, false);
	res = (sv.capacity() == sv1.capacity() && sv.size() == sv1.size());
	printCase("", res, false);
	res = (ov.capacity() == ov1.capacity() && ov.size() == ov1.size());
	printCase("", res, false);
	res = (itev.capacity() == itev1.capacity() && itev.size() == itev1.size());
	printCase("", res, false);
	res = (eitev.capacity() == eitev1.capacity() && eitev.size() == eitev1.size());
	printCase("", res, true);

	v.resize(43, 42);
	v1.resize(43, 42);
	iv.resize(43, 42);
	iv1.resize(43, 42);
	sv.resize(43, "42");
	sv1.resize(43, "42");
	ov.resize(43, 42);
	ov1.resize(43, 42);
	itev.resize(43, 42);
	itev1.resize(43, 42);
	eitev.resize(43, 42);
	eitev1.resize(43, 42);

	res = (v.capacity() == v1.capacity() && v.size() == v1.size());
	printCase("\033[1;37mresize() tests: ", res, false);
	res = (iv.capacity() == iv1.capacity() && iv.size() == iv1.size());
	printCase("", res, false);
	res = (sv.capacity() == sv1.capacity() && sv.size() == sv1.size());
	printCase("", res, false);
	res = (ov.capacity() == ov1.capacity() && ov.size() == ov1.size());
	printCase("", res, false);
	res = (itev.capacity() == itev1.capacity() && itev.size() == itev1.size());
	printCase("", res, false);
	res = (eitev.capacity() == eitev1.capacity() && eitev.size() == eitev1.size());
	printCase("", res, false);

	v.resize(10, 42);
	v1.resize(10, 42);
	iv.resize(10, 42);
	iv1.resize(10, 42);
	sv.resize(10, "42");
	sv1.resize(10, "42");
	ov.resize(10, 42);
	ov1.resize(10, 42);
	itev.resize(10, 42);
	itev1.resize(10, 42);
	eitev.resize(10, 42);
	eitev1.resize(10, 42);

	res = (v.capacity() == v1.capacity() && v.size() == v1.size());
	printCase("", res, false);
	res = (iv.capacity() == iv1.capacity() && iv.size() == iv1.size());
	printCase("", res, false);
	res = (sv.capacity() == sv1.capacity() && sv.size() == sv1.size());
	printCase("", res, false);
	res = (ov.capacity() == ov1.capacity() && ov.size() == ov1.size());
	printCase("", res, false);
	res = (itev.capacity() == itev1.capacity() && itev.size() == itev1.size());
	printCase("", res, false);
	res = (eitev.capacity() == eitev1.capacity() && eitev.size() == eitev1.size());
	printCase("", res, true);

	{
		bool b;

		std::cout << "operator[] tests: ";
		b = true;
		for (size_t i = 0; i < v.size(); i++)
		{
			if (v[i] != v1[i])
			{
				std::cout << RED << "FALSE ";
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "✅ " << RESET;

		b = true;
		for (size_t i = 0; i < iv.size(); i++)
		{
			if (iv[i] != iv1[i])
			{
				std::cout << RED << "FALSE ";
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "✅ " << RESET;

		b = true;
		for (size_t i = 0; i < sv.size(); i++)
		{
			if (sv[i] != sv1[i])
			{
				std::cout << RED << "FALSE ";
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "✅ " << RESET;

		b = true;
		for (size_t i = 0; i < ov.size(); i++)
		{
			if (ov[i] != ov1[i])
			{
				std::cout << RED << "FALSE ";
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "✅ " << RESET;

		b = true;
		for (size_t i = 0; i < itev.size(); i++)
		{
			if (itev[i] != itev1[i])
			{
				std::cout << RED << "FALSE ";
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "✅ " << RESET;

		b = true;
		for (size_t i = 0; i < eitev.size(); i++)
		{
			if (eitev[i] != eitev1[i])
			{
				std::cout << RED << "FALSE" << std::endl;
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "✅" << RESET << std::endl;
	}

	{
				bool b;

		std::cout << "at() tests: ";
		b = true;
		for (size_t i = 0; i < v.size(); i++)
		{
			if (v.at(i) != v1.at(i))
			{
				std::cout << RED << "FALSE ";
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "✅ " << RESET;

		b = true;
		for (size_t i = 0; i < iv.size(); i++)
		{
			if (iv.at(i) != iv1.at(i))
			{
				std::cout << RED << "FALSE ";
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "✅ " << RESET;

		b = true;
		for (size_t i = 0; i < sv.size(); i++)
		{
			if (sv.at(i) != sv1.at(i))
			{
				std::cout << RED << "FALSE ";
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "✅ " << RESET;

		b = true;
		for (size_t i = 0; i < ov.size(); i++)
		{
			if (ov.at(i) != ov1.at(i))
			{
				std::cout << RED << "FALSE ";
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "✅ " << RESET;

		b = true;
		for (size_t i = 0; i < itev.size(); i++)
		{
			if (itev.at(i) != itev1.at(i))
			{
				std::cout << RED << "FALSE ";
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "✅ " << RESET;

		b = true;
		for (size_t i = 0; i < eitev.size(); i++)
		{
			if (eitev.at(i) != eitev1.at(i))
			{
				std::cout << RED << "FALSE" << std::endl;
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "✅" << RESET << std::endl;

	}

	res = (v.front() == v1.front());
	printCase("\033[1;37mfront() tests: ", res, false);
	res = (iv.front() == iv1.front());
	printCase("", res, false);
	res = (sv.front() == sv1.front());
	printCase("", res, false);
	res = (ov.front() == ov1.front());
	printCase("", res, false);
	res = (itev.front() == itev1.front());
	printCase("", res, false);
	res = (eitev.front() == eitev1.front());
	printCase("", res, true);

	res = (v.back() == v1.back());
	printCase("\033[1;37mfront() tests: ", res, false);
	res = (iv.back() == iv1.back());
	printCase("", res, false);
	res = (sv.back() == sv1.back());
	printCase("", res, false);
	res = (ov.back() == ov1.back());
	printCase("", res, false);
	res = (itev.back() == itev1.back());
	printCase("", res, false);
	res = (eitev.back() == eitev1.back());
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
	// iterators_test();
	// reverse_iterator_tests();
	vectors_test();
}