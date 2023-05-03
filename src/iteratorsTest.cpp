#include <tests.hpp>

void	iteratorsTest( void )
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

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator+ works as expected.
	 * 
	 */
	{
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

		usleep(4242);
		std::cout << WHITE << "Operator+: \t\t\t";
		usleep(4242);

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
			std::cout << GREEN << "✅";

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
			std::cout << GREEN << "✅";

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
			std::cout << GREEN << "✅";

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
			std::cout << GREEN << "✅" << std::endl;
	}

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator+(size_t + iter) works as expected.
	 * 
	 */
	{
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

		usleep(4242);
		std::cout << WHITE << "operator+(size_t + iter): \t";
		usleep(4242);

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
			std::cout << GREEN << "✅";

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
			std::cout << GREEN << "✅";

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
			std::cout << GREEN << "✅";

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
			std::cout << GREEN << "✅" << RESET << std::endl;
	}

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator- works as expected.
	 * 
	 */
	{
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

		usleep(4242);
		std::cout << WHITE << "operator-: \t\t\t";
		usleep(4242);

		/**
		 * Test operator- with vectors full of ints.
		 */
		b = true;
		for (size_t i = 1; (end - i) != it; i++)
		{
			if (*(end - i) != *(end1 - i) || (end1 - i) == it1)
			{
				std::cout << "FAIL ";
				b = false;
			}
		}
		if (b && (end - it) == (end1 - it1))
			std::cout << GREEN << "✅";

		/**
		 * Test operator- with vectors full of std::strings.
		 */
		b = true;
		for (size_t i = 1; (send - i) != sit; i++)
		{
			if (*(send - i) != *(send1 - i) || (send1 - i) == sit1)
			{
				std::cout << "FAIL ";
				b = false;
			}
		}
		if (b && (send - sit) == (send1 - sit1))
			std::cout << GREEN << "✅";

		/**
		 * Test operator- with vectors with only one int.
		 */
		b = true;
		for (size_t i = 1; (oend - i) != oit; i++)
		{
			if (*(oend - i) != *(oend1 - i) || (oend1 - i) == oit1)
			{
				std::cout << "FAIL ";
				b = false;
			}
		}
		if (b && (oend - oit) == (oend1 - oit1))
			std::cout << GREEN << "✅" << std::endl;
	}

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator++ works as expected.
	 * 
	 */
	{	
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

		usleep(4242);
		std::cout << WHITE << "operator++: \t\t\t";
		usleep(4242);

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
			std::cout << GREEN << "✅";

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
			std::cout << GREEN << "✅";

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
			std::cout << GREEN << "✅";

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

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator-- works as expected.
	 * 
	 */
	{
		std::vector<int>::iterator	it = v.begin();
		std::vector<int>::iterator	end = v.end() - 1;
		ft::vector<int>::iterator	it1 = v1.begin();
		ft::vector<int>::iterator	end1 = v1.end() - 1;

		std::vector<std::string>::iterator	sit = s.begin();
		std::vector<std::string>::iterator	send = s.end() - 1;
		ft::vector<std::string>::iterator	sit1 = s1.begin();
		ft::vector<std::string>::iterator	send1 = s1.end() - 1;

		std::vector<int>::iterator	oit = ov.begin();
		std::vector<int>::iterator	oend = ov.end() - 1;
		ft::vector<int>::iterator	oit1 = ov1.begin();
		ft::vector<int>::iterator	oend1 = ov1.end() - 1;

		usleep(4242);
		std::cout << WHITE << "operator--: \t\t\t";
		usleep(4242);

		b = true;
		n = end - it;
		for (size_t i = 0; end != it - 1; i++)
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
			std::cout << GREEN << "✅";

		b = true;
		n = send - sit;
		for (size_t i = 0;send != sit - 1; i++)
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
			std::cout << GREEN << "✅";

		b = true;
		n = oend - oit;
		for (size_t i = 0; i < n && oend != oit; i++)
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
			std::cout << GREEN << "✅" << std::endl;
	}

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the ++operator works as expected.
	 * 
	 */
	{
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

		usleep(4242);
		std::cout << WHITE << "++operator: \t\t\t";
		usleep(4242);

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
			std::cout << GREEN << "✅";

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
			std::cout << GREEN << "✅";

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
			std::cout << GREEN << "✅";

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

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the --operator works as expected.
	 * 
	 */
	{
		std::vector<int>::iterator	it = v.begin();
		std::vector<int>::iterator	end = v.end() - 1;
		ft::vector<int>::iterator	it1 = v1.begin();
		ft::vector<int>::iterator	end1 = v1.end() - 1;

		std::vector<std::string>::iterator	sit = s.begin();
		std::vector<std::string>::iterator	send = s.end() - 1;
		ft::vector<std::string>::iterator	sit1 = s1.begin();
		ft::vector<std::string>::iterator	send1 = s1.end() - 1;

		std::vector<int>::iterator	oit = ov.begin();
		std::vector<int>::iterator	oend = ov.end() - 1;
		ft::vector<int>::iterator	oit1 = ov1.begin();
		ft::vector<int>::iterator	oend1 = ov1.end() - 1;

		usleep(4242);
		std::cout << WHITE << "--operator: \t\t\t";
		usleep(4242);

		b = true;
		n = end - it;
		for (size_t i = 0; end != it - 1; i++)
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
			std::cout << GREEN << "✅";

		b = true;
		n = send - sit;
		for (size_t i = 0; send != sit - 1; i++)
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
			std::cout << GREEN << "✅";

		b = true;
		n = oend - oit;
		for (size_t i = 0; oend != oit - 1; i++)
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
			std::cout << GREEN << "✅" << std::endl;
	}

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator+= works as expected.
	 * 
	 */
	{
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

		usleep(4242);
		std::cout << WHITE << "operator+=: \t\t\t";
		usleep(4242);

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
			std::cout << GREEN << "✅";

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
			std::cout << GREEN << "✅";

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
			std::cout << GREEN << "✅";

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

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator-= works as expected.
	 * 
	 */
	{
		std::vector<int>::iterator	it = v.begin();
		std::vector<int>::iterator	end = v.end() - 1;
		ft::vector<int>::iterator	it1 = v1.begin();
		ft::vector<int>::iterator	end1 = v1.end() - 1;

		std::vector<std::string>::iterator	sit = s.begin();
		std::vector<std::string>::iterator	send = s.end() - 1;
		ft::vector<std::string>::iterator	sit1 = s1.begin();
		ft::vector<std::string>::iterator	send1 = s1.end() - 1;

		std::vector<int>::iterator	oit = ov.begin();
		std::vector<int>::iterator	oend = ov.end() - 1;
		ft::vector<int>::iterator	oit1 = ov1.begin();
		ft::vector<int>::iterator	oend1 = ov1.end() - 1;


		usleep(4242);
		std::cout << WHITE << "operator-=: \t\t\t";
		usleep(4242);

		b = true;
		n = end - it;
		for (size_t i = 0; end != it - 1; i++)
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
			std::cout << GREEN << "✅";

		b = true;
		n = send - sit;
		for (size_t i = 0; send != sit - 1; i++)
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
			std::cout << GREEN << "✅";

		b = true;
		n = oend - oit;
		for (size_t i = 0; oend != oit - 1; i++)
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
			std::cout << GREEN << "✅" << std::endl;
	}

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator- (it - it) works as expected.
	 * 
	 */
	{
		std::vector<int>::iterator	it = v.begin();
		std::vector<int>::iterator	end = v.end();
		ft::vector<int>::iterator	it1 = v1.begin();
		ft::vector<int>::iterator	end1 = v1.end();

		usleep(4242);
		std::cout << WHITE << "operator-(it): \t\t\t";
		usleep(4242);

		if ((end - it) != (end1 - it1))
			std::cout << "FAIL ";
		else
			std::cout << GREEN << "✅" << RESET;

		end--;
		end1--;
		if ((end - it) != (end1 - it1))
			std::cout << "FAIL ";
		else
			std::cout << GREEN << "✅" << RESET;

		end -= 42;
		end1 -= 42;
		it += 42;
		it1 += 42;
		if ((end - it) != (end1 - it1))
			std::cout << RED << "FAIL" << RESET << std::endl;
		else
			std::cout << GREEN << "✅" << RESET << std::endl;
	}

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator[] works as expected.
	 * 
	 */
	{
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

		usleep(4242);
		std::cout << WHITE << "operator[]: \t\t\t";
		usleep(4242);

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
			std::cout << GREEN << "✅";

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
			std::cout << GREEN << "✅";
		
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
			std::cout << GREEN << "✅";

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

		usleep(4242);
		std::cout << WHITE << "operator*: \t\t\t";
		usleep(4242);

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
			std::cout << GREEN << "✅";

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
			std::cout << GREEN << "✅";

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
			std::cout << GREEN << "✅";

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

	std::string	res[2] = {"✅", "FAIL"};

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator== works as expected.
	 * 
	 */
	{
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

		std::vector<int>::iterator	aux = v.begin();
		ft::vector<int>::iterator	aux1 = v1.begin();

		std::vector<std::string>::iterator	saux = s.begin();
		ft::vector<std::string>::iterator	saux1 = s1.begin();

		std::vector<int>::iterator	oaux = ov.begin();
		ft::vector<int>::iterator	oaux1 = ov1.begin();

		std::vector<int>::iterator	eaux = ev.begin();
		ft::vector<int>::iterator	eaux1 = ev1.begin();

		usleep(4242);
		std::cout << WHITE << "operator==: \t\t\t";
		usleep(4242);

		std::cout << res[((it == end) != (it1 == end1))] << "";
		std::cout << res[((it == aux) != (it1 == aux1))] << "";
		std::cout << res[((++it == aux) != (++it1 == aux1))] << "";
		std::cout << res[((--it == aux) != (--it1 == aux1))] << "";
		std::cout << res[((it++ == aux) != (it1++ == aux1))] << "";
		std::cout << res[((it-- == aux) != (it1-- == aux1))] << "";

		std::cout << res[((sit == send) != (sit1 == send1))] << "";
		std::cout << res[((sit == saux) != (sit1 == saux1))] << "";
		std::cout << res[((++sit == saux) != (++sit1 == saux1))] << "";
		std::cout << res[((--sit == saux) != (--sit1 == saux1))] << "";
		std::cout << res[((sit++ == saux) != (sit1++ == saux1))] << "";
		std::cout << res[((sit-- == saux) != (sit1-- == saux1))] << "";

		std::cout << res[((oit == oend) != (oit1 == oend1))] << "";
		std::cout << res[((oit == oaux) != (oit1 == oaux1))] << "";
		std::cout << res[((++oit == oaux) != (++oit1 == oaux1))] << "";
		std::cout << res[((--oit == oaux) != (--oit1 == oaux1))] << "";
		std::cout << res[((oit++ == oaux) != (oit1++ == oaux1))] << "";
		std::cout << res[((oit-- == oaux) != (oit1-- == oaux1))] << "";

		std::cout << res[((eit == eend) != (eit1 == eend1))] << "";
		std::cout << res[((eit == eaux) != (eit1 == eaux1))] << "";
		std::cout << res[((++eit == eaux) != (++eit1 == eaux1))] << "";
		std::cout << res[((--eit == eaux) != (--eit1 == eaux1))] << "";
		std::cout << res[((eit++ == eaux) != (eit1++ == eaux1))] << "";
		std::cout << res[((eit-- == eaux) != (eit1-- == eaux1))] << std::endl;
	}

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator!= works as expected.
	 * 
	 */
	{
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

		std::vector<int>::iterator	aux = v.begin();
		ft::vector<int>::iterator	aux1 = v1.begin();

		std::vector<std::string>::iterator	saux = s.begin();
		ft::vector<std::string>::iterator	saux1 = s1.begin();

		std::vector<int>::iterator	oaux = ov.begin();
		ft::vector<int>::iterator	oaux1 = ov1.begin();

		std::vector<int>::iterator	eaux = ev.begin();
		ft::vector<int>::iterator	eaux1 = ev1.begin();

		usleep(4242);
		std::cout << WHITE << "operator!=: \t\t\t";
		usleep(4242);

		std::cout << res[((it != end) != (it1 != end1))] << "";
		std::cout << res[((it != aux) != (it1 != aux1))] << "";
		std::cout << res[((++it != aux) != (++it1 != aux1))] << "";
		std::cout << res[((--it != aux) != (--it1 != aux1))] << "";
		std::cout << res[((it++ != aux) != (it1++ != aux1))] << "";
		std::cout << res[((it-- != aux) != (it1-- != aux1))] << "";

		std::cout << res[((sit != send) != (sit1 != send1))] << "";
		std::cout << res[((sit != saux) != (sit1 != saux1))] << "";
		std::cout << res[((++sit != saux) != (++sit1 != saux1))] << "";
		std::cout << res[((--sit != saux) != (--sit1 != saux1))] << "";
		std::cout << res[((sit++ != saux) != (sit1++ != saux1))] << "";
		std::cout << res[((sit-- != saux) != (sit1-- != saux1))] << "";

		std::cout << res[((oit != oend) != (oit1 != oend1))] << "";
		std::cout << res[((oit != oaux) != (oit1 != oaux1))] << "";
		std::cout << res[((++oit != oaux) != (++oit1 != oaux1))] << "";
		std::cout << res[((--oit != oaux) != (--oit1 != oaux1))] << "";
		std::cout << res[((oit++ != oaux) != (oit1++ != oaux1))] << "";
		std::cout << res[((oit-- != oaux) != (oit1-- != oaux1))] << "";

		std::cout << res[((eit != eend) != (eit1 != eend1))] << "";
		std::cout << res[((eit != eaux) != (eit1 != eaux1))] << "";
		std::cout << res[((++eit != eaux) != (++eit1 != eaux1))] << "";
		std::cout << res[((--eit != eaux) != (--eit1 != eaux1))] << "";
		std::cout << res[((eit++ != eaux) != (eit1++ != eaux1))] << "";
		std::cout << res[((eit-- != eaux) != (eit1-- != eaux1))] << std::endl;
	}
	
	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator< works as expected.
	 * 
	 */
	{
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

		std::vector<int>::iterator	aux = v.begin();
		ft::vector<int>::iterator	aux1 = v1.begin();

		std::vector<std::string>::iterator	saux = s.begin();
		ft::vector<std::string>::iterator	saux1 = s1.begin();

		std::vector<int>::iterator	oaux = ov.begin();
		ft::vector<int>::iterator	oaux1 = ov1.begin();

		std::vector<int>::iterator	eaux = ev.begin();
		ft::vector<int>::iterator	eaux1 = ev1.begin();

		usleep(4242);
		std::cout << WHITE << "operator<: \t\t\t";
		usleep(4242);

		std::cout << res[((it < end) != (it1 < end1))] << "";
		std::cout << res[((it < aux) != (it1 < aux1))] << "";
		std::cout << res[((++it < aux) != (++it1 < aux1))] << "";
		std::cout << res[((--it < aux) != (--it1 < aux1))] << "";
		std::cout << res[((it++ < aux) != (it1++ < aux1))] << "";
		std::cout << res[((it-- < aux) != (it1-- < aux1))] << "";

		std::cout << res[((sit < send) != (sit1 < send1))] << "";
		std::cout << res[((sit < saux) != (sit1 < saux1))] << "";
		std::cout << res[((++sit < saux) != (++sit1 < saux1))] << "";
		std::cout << res[((--sit < saux) != (--sit1 < saux1))] << "";
		std::cout << res[((sit++ < saux) != (sit1++ < saux1))] << "";
		std::cout << res[((sit-- < saux) != (sit1-- < saux1))] << "";

		std::cout << res[((oit < oend) != (oit1 < oend1))] << "";
		std::cout << res[((oit < oaux) != (oit1 < oaux1))] << "";
		std::cout << res[((++oit < oaux) != (++oit1 < oaux1))] << "";
		std::cout << res[((--oit < oaux) != (--oit1 < oaux1))] << "";
		std::cout << res[((oit++ < oaux) != (oit1++ < oaux1))] << "";
		std::cout << res[((oit-- < oaux) != (oit1-- < oaux1))] << "";

		std::cout << res[((eit < eend) != (eit1 < eend1))] << "";
		std::cout << res[((eit < eaux) != (eit1 < eaux1))] << "";
		std::cout << res[((++eit < eaux) != (++eit1 < eaux1))] << "";
		std::cout << res[((--eit < eaux) != (--eit1 < eaux1))] << "";
		std::cout << res[((eit++ < eaux) != (eit1++ < eaux1))] << "";
		std::cout << res[((eit-- < eaux) != (eit1-- < eaux1))] << std::endl;
	}

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator<= works as expected.
	 * 
	 */
	{
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

		std::vector<int>::iterator	aux = v.begin();
		ft::vector<int>::iterator	aux1 = v1.begin();

		std::vector<std::string>::iterator	saux = s.begin();
		ft::vector<std::string>::iterator	saux1 = s1.begin();

		std::vector<int>::iterator	oaux = ov.begin();
		ft::vector<int>::iterator	oaux1 = ov1.begin();

		std::vector<int>::iterator	eaux = ev.begin();
		ft::vector<int>::iterator	eaux1 = ev1.begin();

		usleep(4242);
		std::cout << WHITE << "operator<=: \t\t\t";
		usleep(4242);

		std::cout << res[((it <= end) != (it1 <= end1))] << "";
		std::cout << res[((it <= aux) != (it1 <= aux1))] << "";
		std::cout << res[((++it <= aux) != (++it1 <= aux1))] << "";
		std::cout << res[((--it <= aux) != (--it1 <= aux1))] << "";
		std::cout << res[((it++ <= aux) != (it1++ <= aux1))] << "";
		std::cout << res[((it-- <= aux) != (it1-- <= aux1))] << "";

		std::cout << res[((sit <= send) != (sit1 <= send1))] << "";
		std::cout << res[((sit <= saux) != (sit1 <= saux1))] << "";
		std::cout << res[((++sit <= saux) != (++sit1 <= saux1))] << "";
		std::cout << res[((--sit <= saux) != (--sit1 <= saux1))] << "";
		std::cout << res[((sit++ <= saux) != (sit1++ <= saux1))] << "";
		std::cout << res[((sit-- <= saux) != (sit1-- <= saux1))] << "";

		std::cout << res[((oit <= oend) != (oit1 <= oend1))] << "";
		std::cout << res[((oit <= oaux) != (oit1 <= oaux1))] << "";
		std::cout << res[((++oit <= oaux) != (++oit1 <= oaux1))] << "";
		std::cout << res[((--oit <= oaux) != (--oit1 <= oaux1))] << "";
		std::cout << res[((oit++ <= oaux) != (oit1++ <= oaux1))] << "";
		std::cout << res[((oit-- <= oaux) != (oit1-- <= oaux1))] << "";

		std::cout << res[((eit <= eend) != (eit1 <= eend1))] << "";
		std::cout << res[((eit <= eaux) != (eit1 <= eaux1))] << "";
		std::cout << res[((++eit <= eaux) != (++eit1 <= eaux1))] << "";
		std::cout << res[((--eit <= eaux) != (--eit1 <= eaux1))] << "";
		std::cout << res[((eit++ <= eaux) != (eit1++ <= eaux1))] << "";
		std::cout << res[((eit-- <= eaux) != (eit1-- <= eaux1))] << std::endl;
	}
	
	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator> works as expected.
	 * 
	 */
	{
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

		std::vector<int>::iterator	aux = v.begin();
		ft::vector<int>::iterator	aux1 = v1.begin();

		std::vector<std::string>::iterator	saux = s.begin();
		ft::vector<std::string>::iterator	saux1 = s1.begin();

		std::vector<int>::iterator	oaux = ov.begin();
		ft::vector<int>::iterator	oaux1 = ov1.begin();

		std::vector<int>::iterator	eaux = ev.begin();
		ft::vector<int>::iterator	eaux1 = ev1.begin();

		usleep(4242);
		std::cout << WHITE << "operator>: \t\t\t";
		usleep(4242);

		std::cout << res[((it > end) != (it1 > end1))] << "";
		std::cout << res[((it > aux) != (it1 > aux1))] << "";
		std::cout << res[((++it > aux) != (++it1 > aux1))] << "";
		std::cout << res[((--it > aux) != (--it1 > aux1))] << "";
		std::cout << res[((it++ > aux) != (it1++ > aux1))] << "";
		std::cout << res[((it-- > aux) != (it1-- > aux1))] << "";

		std::cout << res[((sit > send) != (sit1 > send1))] << "";
		std::cout << res[((sit > saux) != (sit1 > saux1))] << "";
		std::cout << res[((++sit > saux) != (++sit1 > saux1))] << "";
		std::cout << res[((--sit > saux) != (--sit1 > saux1))] << "";
		std::cout << res[((sit++ > saux) != (sit1++ > saux1))] << "";
		std::cout << res[((sit-- > saux) != (sit1-- > saux1))] << "";

		std::cout << res[((oit > oend) != (oit1 > oend1))] << "";
		std::cout << res[((oit > oaux) != (oit1 > oaux1))] << "";
		std::cout << res[((++oit > oaux) != (++oit1 > oaux1))] << "";
		std::cout << res[((--oit > oaux) != (--oit1 > oaux1))] << "";
		std::cout << res[((oit++ > oaux) != (oit1++ > oaux1))] << "";
		std::cout << res[((oit-- > oaux) != (oit1-- > oaux1))] << "";

		std::cout << res[((eit > eend) != (eit1 > eend1))] << "";
		std::cout << res[((eit > eaux) != (eit1 > eaux1))] << "";
		std::cout << res[((++eit > eaux) != (++eit1 > eaux1))] << "";
		std::cout << res[((--eit > eaux) != (--eit1 > eaux1))] << "";
		std::cout << res[((eit++ > eaux) != (eit1++ > eaux1))] << "";
		std::cout << res[((eit-- > eaux) != (eit1-- > eaux1))] << std::endl;
	}

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator>= works as expected.
	 * 
	 */
	{
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

		std::vector<int>::iterator	aux = v.begin();
		ft::vector<int>::iterator	aux1 = v1.begin();

		std::vector<std::string>::iterator	saux = s.begin();
		ft::vector<std::string>::iterator	saux1 = s1.begin();

		std::vector<int>::iterator	oaux = ov.begin();
		ft::vector<int>::iterator	oaux1 = ov1.begin();

		std::vector<int>::iterator	eaux = ev.begin();
		ft::vector<int>::iterator	eaux1 = ev1.begin();

		usleep(4242);
		std::cout << WHITE << "operator>=: \t\t\t";
		usleep(4242);
		
		std::cout << res[((it >= end) != (it1 >= end1))] << "";
		std::cout << res[((it >= aux) != (it1 >= aux1))] << "";
		std::cout << res[((++it >= aux) != (++it1 >= aux1))] << "";
		std::cout << res[((--it >= aux) != (--it1 >= aux1))] << "";
		std::cout << res[((it++ >= aux) != (it1++ >= aux1))] << "";
		std::cout << res[((it-- >= aux) != (it1-- >= aux1))] << "";

		std::cout << res[((sit >= send) != (sit1 >= send1))] << "";
		std::cout << res[((sit >= saux) != (sit1 >= saux1))] << "";
		std::cout << res[((++sit >= saux) != (++sit1 >= saux1))] << "";
		std::cout << res[((--sit >= saux) != (--sit1 >= saux1))] << "";
		std::cout << res[((sit++ >= saux) != (sit1++ >= saux1))] << "";
		std::cout << res[((sit-- >= saux) != (sit1-- >= saux1))] << "";

		std::cout << res[((oit >= oend) != (oit1 >= oend1))] << "";
		std::cout << res[((oit >= oaux) != (oit1 >= oaux1))] << "";
		std::cout << res[((++oit >= oaux) != (++oit1 >= oaux1))] << "";
		std::cout << res[((--oit >= oaux) != (--oit1 >= oaux1))] << "";
		std::cout << res[((oit++ >= oaux) != (oit1++ >= oaux1))] << "";
		std::cout << res[((oit-- >= oaux) != (oit1-- >= oaux1))] << "";

		std::cout << res[((eit >= eend) != (eit1 >= eend1))] << "";
		std::cout << res[((eit >= eaux) != (eit1 >= eaux1))] << "";
		std::cout << res[((++eit >= eaux) != (++eit1 >= eaux1))] << "";
		std::cout << res[((--eit >= eaux) != (--eit1 >= eaux1))] << "";
		std::cout << res[((eit++ >= eaux) != (eit1++ >= eaux1))] << "";
		std::cout << res[((eit-- >= eaux) != (eit1-- >= eaux1))] << std::endl;
	}

	/**
	 * 
	 * @brief In this section it will perform multiple testes to ensure that the operator= works as expected.
	 * 
	 */
	{
		std::vector<int>::iterator	it = v.begin();
		ft::vector<int>::iterator	it1 = v1.begin();

		std::vector<int>::iterator	aux = v.begin();
		ft::vector<int>::iterator	aux1 = v1.begin();


		usleep(4242);
		std::cout << WHITE << "operator=: \t\t\t";
		usleep(4242);
		if ((aux == it) != (aux1 == it1))
			std::cout << RED << "FAIL" << RESET << std::endl;
		else
			std::cout << GREEN << "✅" << RESET << std::endl;
		
		std::cout << std::endl << std::endl;
	}
}