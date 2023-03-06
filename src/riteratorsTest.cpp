#include <tests.hpp>

void	riteratorTests( void )
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