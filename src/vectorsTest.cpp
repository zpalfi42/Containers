#include <tests.hpp>

void	printCase( std::string s, bool b , bool endl)
{
	usleep(4242);
	std::cout << RESET << s;
	if (b)
		std::cout << GREEN << "✅" << WHITE;
	else
		std::cout << RED << "FAIL" << WHITE;

	if (endl)
		std::cout << std::endl;
	else
		std::cout << "";
}

void testOk()
{
	// std::cout << GRN "[OK]" RESET;
	std::cout << "✅";
}

void testKo()
{
	// std::cout << RED "[KO]" RESET;
	std::cout << "❌";
}

void testVectorSubject()
{

	const int seed = atoi("1");
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::vector<Buffer> vector_buffer;

	double time_spent = 0.0;

	clock_t begin = clock();

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}
	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);
	std::cout << "empty\t\t";
	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			testKo();
		}
	}
	catch (const std::exception &e)
	{
		testOk();
	}

	clock_t end = clock();

	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	double time_spent2 = 0.0;

	clock_t begin2 = clock();

	std::vector<Buffer> vector_buffer2;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer2.push_back(Buffer());
	}
	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer2[idx].idx = 5;
	}
	std::vector<Buffer>().swap(vector_buffer2);
	clock_t end2 = clock();

	time_spent2 += (double)(end2 - begin2) / CLOCKS_PER_SEC;
	std::cout << "\n";
	std::cout << "time\t\t";
	(time_spent <= time_spent2 * 20) ? testOk() : testKo();
	std::cout << "\n";
	std::cout << "\n";
	std::cout << UMAG "Result Time" RESET << std::endl;
	std::cout << YEL "Time ft::vector:\t" << time_spent << "s" RESET << std::endl;
	std::cout << YEL "Time std::vector:\t" << time_spent2 << "s" RESET << std::endl;
	if (time_spent > time_spent2 * 20)
		std::cout << RED "ft::vector time must be less than " <<  time_spent2 * 20 << "s" RESET << std::endl;
}

void	vectorsTest( void )
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

	// Vectors full of ints.
	std::vector<int> v(42, 42);
	ft::vector<int> v1(42, 42);

	// Vectors with only one int.
	std::vector<int> ov(1, 42);
	ft::vector<int> ov1(1, 42);

	// Vectors without int.
	std::vector<int> ev;
	ft::vector<int> ev1;

	// Vector full of strings
	std::vector<std::string> sv(42, "42");
	ft::vector<std::string> sv1(42, "42");

	std::cout << std::endl << BLUE << "MEMBER FUNCTION TESTS:" << RESET << std::endl;

	// Default constructor test.
	{
		std::vector<int>	dv;
		ft::vector<int>		dv1;

		std::vector<std::string>	dsv;
		ft::vector<std::string>		dsv1;

		std::vector<double>		ddv;
		ft::vector<double>		ddv1;

		res = (dv.capacity() == dv1.capacity() && dv.size() == dv1.size());
		printCase("\033[0;37mconstructor( void ): \t\t\t", res, false);
		res = (dsv.capacity() == dsv1.capacity() && dsv.size() == dsv1.size());
		printCase("", res, false);
		res = (ddv.capacity() == ddv1.capacity() && ddv.size() == ddv1.size());
		printCase("", res, true);
	}

	// Fill constructor(size_type, value) test.
	{
		std::vector<int>	fv(42, 42);
		ft::vector<int>		fv1(42, 42);

		std::vector<std::string>	fsv(42, "42");
		ft::vector<std::string>		fsv1(42, "42");

		std::vector<double>		fdv(42, 42.0);
		ft::vector<double>		fdv1(42, 42.0);

		std::vector<int>	fev(0, 42);
		ft::vector<int>		fev1(0, 42);

		res = (fv.capacity() == fv1.capacity() && fv.size() == fv1.size() && fv.front() == fv1.front() && fv.back() == fv1.back());
		printCase("\033[0;37mconstructor(size_type, value): \t\t", res, false);
		res = (fsv.capacity() == fsv1.capacity() && fsv.size() == fsv1.size() && fsv.front() == fsv1.front() && fsv.back() == fsv1.back());
		printCase("", res, false);
		res = (fdv.capacity() == fdv1.capacity() && fdv.size() == fdv1.size() && fdv.front() == fdv1.front() && fdv.back() == fdv1.back());
		printCase("", res, false);
		res = (fev.capacity() == fev1.capacity() && fev.size() == fev1.size());
		printCase("", res, true);
	}

	// Fill constructor(size_type) test.
	{
		std::vector<int>	fv(42);
		ft::vector<int>		fv1(42);

		std::vector<std::string>	fsv(42);
		ft::vector<std::string>		fsv1(42);

		std::vector<double>		fdv(42);
		ft::vector<double>		fdv1(42);

		std::vector<int>	fev(0);
		ft::vector<int>		fev1(0);

		res = (fv.capacity() == fv1.capacity() && fv.size() == fv1.size());
		printCase("\033[0;37mconstructor(size_type): \t\t", res, false);
		res = (fsv.capacity() == fsv1.capacity() && fsv.size() == fsv1.size());
		printCase("", res, false);
		res = (fdv.capacity() == fdv1.capacity() && fdv.size() == fdv1.size());
		printCase("", res, false);
		res = (fev.capacity() == fev1.capacity() && fev.size() == fev1.size());
		printCase("", res, true);
	}

	// Range constructor(iterator, iterator) test.
	{
		std::vector<int>::iterator	it = v.begin();
		std::vector<int>::iterator	end = v.end();
		ft::vector<int>::iterator	it1 = v1.begin();
		ft::vector<int>::iterator	end1 = v1.end();

		std::vector<std::string>::iterator	sit = sv.begin();
		std::vector<std::string>::iterator	send = sv.end();
		ft::vector<std::string>::iterator	sit1 = sv1.begin();
		ft::vector<std::string>::iterator	send1 = sv1.end();

		std::vector<int>::iterator	oit = ov.begin();
		std::vector<int>::iterator	oend = ov.end();
		ft::vector<int>::iterator	oit1 = ov1.begin();
		ft::vector<int>::iterator	oend1 = ov1.end();

		std::vector<int>::iterator	eit = ev.begin();
		std::vector<int>::iterator	eend = ev.end();
		ft::vector<int>::iterator	eit1 = ev1.begin();
		ft::vector<int>::iterator	eend1 = ev1.end();

		std::vector<int>	rv(it, end);
		ft::vector<int>		rv1(it1, end1);

		std::vector<std::string>	rsv(sit, send);
		ft::vector<std::string>		rsv1(sit1, send1);

		std::vector<int>	rov(oit, oend);
		ft::vector<int>		rov1(oit1, oend1);

		std::vector<int>	rev(eit, eend);
		ft::vector<int>		rev1(eit1, eend1);

		res = (rv.capacity() == rv1.capacity() && rv.size() == rv1.size() && rv.front() == rv1.front() && rv.back() == rv1.back());
		printCase("\033[0;37mconstructor(iterator, iterator): \t", res, false);
		res = (rsv.capacity() == rsv1.capacity() && rsv.size() == rsv1.size() && rsv.front() == rsv1.front() && rsv.back() == rsv1.back());
		printCase("", res, false);
		res = (rov.capacity() == rov1.capacity() && rov.size() == rov1.size() && rov.front() == rov1.front() && rov.back() == rov1.back());
		printCase("", res, false);
		res = (rev.capacity() == rev1.capacity() && rev.size() == rev1.size());
		printCase("", res, true);
	}

	// Operator= test.
	{
		std::vector<int>	cv = v;
		ft::vector<int>		cv1 = v1;

		std::vector<std::string>	csv = sv;
		ft::vector<std::string>		csv1 = sv1;

		// From a smaller vector to a bigger.
		std::vector<int>		csbv = ov;
		ft::vector<int>		csbv1 = ov1;
		csbv = v;
		csbv1 = v1;

		
		// From a bigger vector to a smaller.
		std::vector<int>	cbsv = v;
		ft::vector<int>		cbsv1 = v1;
		cbsv = ov;
		cbsv1 = ov1;

		res = (cv.capacity() == cv1.capacity() && cv.size() == cv1.size() && cv.front() == cv1.front() && cv.back() == cv1.back());
		printCase("\033[0;37moperator=( vector ): \t\t\t", res, false);
		res = (csv.capacity() == csv1.capacity() && csv.size() == csv1.size() && csv.front() == csv1.front() && csv.back() == csv1.back());
		printCase("", res, false);
		res = (csbv.capacity() == csbv1.capacity() && csbv.size() == csbv1.size() && csbv.front() == csbv1.front() && csbv.back() == csbv1.back());
		printCase("", res, false);
		res = (cbsv.capacity() == cbsv1.capacity() && cbsv.size() == cbsv1.size() && cbsv.front() == cbsv1.front() && cbsv.back() == cbsv1.back());
		printCase("", res, true);
	}

	// Range assign test.
	{
		std::vector<int>::iterator	it = v.begin();
		std::vector<int>::iterator	end = v.end();
		ft::vector<int>::iterator	it1 = v1.begin();
		ft::vector<int>::iterator	end1 = v1.end();

		std::vector<std::string>::iterator	sit = sv.begin();
		std::vector<std::string>::iterator	send = sv.end();
		ft::vector<std::string>::iterator	sit1 = sv1.begin();
		ft::vector<std::string>::iterator	send1 = sv1.end();

		std::vector<int>::iterator	oit = ov.begin();
		std::vector<int>::iterator	oend = ov.end();
		ft::vector<int>::iterator	oit1 = ov1.begin();
		ft::vector<int>::iterator	oend1 = ov1.end();

		std::vector<int>	rv;
		ft::vector<int>		rv1;

		rv.assign(it, end);
		rv1.assign(it1, end1);

		std::vector<std::string>	rsv;
		ft::vector<std::string>		rsv1;

		rsv.assign(sit, send);
		rsv1.assign(sit1, send1);

		std::vector<int>	rov;
		ft::vector<int>		rov1;

		rov.assign(oit, oend);
		rov1.assign(oit1, oend1);

		std::vector<int>	rdv;
		ft::vector<int>		rdv1;

		rdv.assign(it + 3, end - 6);
		rdv1.assign(it1 + 3, end1 - 6);

		res = (rv.capacity() == rv1.capacity() && rv.size() == rv1.size() && rv.front() == rv1.front() && rv.back() == rv1.back());
		printCase("\033[0;37massign(iterator, iterator): \t\t", res, false);
		res = (rsv.capacity() == rsv1.capacity() && rsv.size() == rsv1.size() && rsv.front() == rsv1.front() && rsv.back() == rsv1.back());
		printCase("", res, false);
		res = (rov.capacity() == rov1.capacity() && rov.size() == rov1.size() && rov.front() == rov1.front() && rov.back() == rov1.back());
		printCase("", res, false);
		res = (rdv.capacity() == rdv1.capacity() && rdv.size() == rdv1.size() && rdv.front() == rdv1.front() && rdv.back() == rdv1.back());
		printCase("", res, true);
	}

	// Fill assign test.
	{

		std::vector<int>	rv;
		ft::vector<int>		rv1;

		rv.assign(42, 42);
		rv1.assign(42, 42);

		std::vector<std::string>	rsv;
		ft::vector<std::string>		rsv1;

		rsv.assign(42, "42");
		rsv1.assign(42, "42");

		std::vector<int>	rov;
		ft::vector<int>		rov1;

		rov.assign(1, 42);
		rov1.assign(1, 42);

		std::vector<int>	rdv(42, 42);
		ft::vector<int>		rdv1(42, 42);

		rdv.assign(1, 24);
		rdv1.assign(1, 24);

		res = (rv.capacity() == rv1.capacity() && rv.size() == rv1.size() && rv.front() == rv1.front() && rv.back() == rv1.back());
		printCase("\033[0;37massign(size_type, value): \t\t", res, false);
		res = (rsv.capacity() == rsv1.capacity() && rsv.size() == rsv1.size() && rsv.front() == rsv1.front() && rsv.back() == rsv1.back());
		printCase("", res, false);
		res = (rov.capacity() == rov1.capacity() && rov.size() == rov1.size() && rov.front() == rov1.front() && rov.back() == rov1.back());
		printCase("", res, false);
		res = (rdv.capacity() == rdv1.capacity() && rdv.size() == rdv1.size() && rdv.front() == rdv1.front() && rdv.back() == rdv1.back());
		printCase("", res, true);
	}

	// Get_allocator() test.
	{
		std::vector<int>	rv;
		ft::vector<int>		rv1;

		std::vector<std::string>	rsv;
		ft::vector<std::string>		rsv1;

		std::vector<double>	rov;
		ft::vector<double>		rov1;

		std::vector<int>	rdv = rv;
		ft::vector<int>		rdv1 = rv1;

		res = (rv.get_allocator() == rv1.get_allocator());
		printCase("\033[0;37mget_allocator( void ): \t\t\t", res, false);
		res = (rsv.get_allocator() == rsv1.get_allocator());
		printCase("", res, false);
		res = (rov.get_allocator() == rov1.get_allocator());
		printCase("", res, false);
		res = (rdv.get_allocator() == rdv1.get_allocator());
		printCase("", res, true);
	}

	std::cout << std::endl << BLUE << "ELEMENT ACCESS TESTS:" << RESET << std::endl;

	// At() tests.
	{
		bool b;

		std::cout << "\033[0;37mat( void ): \t\t\t\t";
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
			std::cout << GREEN << "✅" << RESET;

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
			std::cout << GREEN << "✅" << RESET;

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
			std::cout << GREEN << "✅" << RESET;

		b = true;
		for (size_t i = 0; i < ev.size(); i++)
		{
			if (ev.at(i) != ev1.at(i))
			{
				std::cout << RED << "FALSE ";
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "✅" << RESET << std::endl;
	}

	// Operator[] tests.
	{
		bool b;

		std::cout << "\033[0;37moperator[]: \t\t\t\t";
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
			std::cout << GREEN << "✅" << RESET;

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
			std::cout << GREEN << "✅" << RESET;

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
			std::cout << GREEN << "✅" << RESET;

		b = true;
		for (size_t i = 0; i < ev.size(); i++)
		{
			if (ev[i] != ev1[i])
			{
				std::cout << RED << "FALSE ";
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "✅" << RESET << std::endl;
	}

	// Front() tests.
	{
		std::vector<int>	rv;
		ft::vector<int>		rv1;
		for (size_t i = 0; i < 43; i++)
		{
			rv.push_back(i);
			rv1.push_back(i);
		}
		
		res = (v.front() == v1.front());
		printCase("\033[0;37mfront( void ): \t\t\t\t", res, false);
		res = (sv.front() == sv1.front());
		printCase("", res, false);
		res = (ov.front() == ov1.front());
		printCase("", res, false);
		res = (rv.front() == rv1.front());
		printCase("", res, true);
	}

	// Back() tests.
	{
		std::vector<int>	rv;
		ft::vector<int>		rv1;
		for (size_t i = 0; i < 43; i++)
		{
			rv.push_back(i);
			rv1.push_back(i);
		}
		
		res = (v.back() == v1.back());
		printCase("\033[0;37mback( void ): \t\t\t\t", res, false);
		res = (sv.back() == sv1.back());
		printCase("", res, false);
		res = (ov.back() == ov1.back());
		printCase("", res, false);
		res = (rv.back() == rv1.back());
		printCase("", res, true);
	}

	// Data() tests.
	{
		bool b;

		int			*dv = v.data();
		int			*dv1 = v1.data();
		int			*dov = ov.data();
		int			*dov1 = ov1.data();
		int			*dev = ev.data();
		int			*dev1 = ev1.data();
		std::string	*dsv = sv.data();
		std::string	*dsv1 = sv1.data();
		
		std::cout << "\033[0;37mdata( void ) tests: \t\t\t";
		b = true;
		for (size_t i = 0; i < v.size(); i++)
		{
			if (dv[i] != dv1[i])
			{
				std::cout << RED << "FALSE ";
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "✅" << RESET;

		b = true;
		for (size_t i = 0; i < sv.size(); i++)
		{
			if (dsv[i] != dsv1[i])
			{
				std::cout << RED << "FALSE ";
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "✅" << RESET;

		b = true;
		for (size_t i = 0; i < ov.size(); i++)
		{
			if (dov[i] != dov1[i])
			{
				std::cout << RED << "FALSE ";
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "✅" << RESET;

		b = true;
		for (size_t i = 0; i < ev.size(); i++)
		{
			if (dev[i] != dev1[i])
			{
				std::cout << RED << "FALSE" << std::endl;
				b = false;
			}
		}
		if (b)
			std::cout << GREEN << "✅" << RESET << std::endl;
	}

	std::cout << std::endl << BLUE << "ITERATORS TESTS:" << RESET << std::endl;

	// Begin() tests.
	{
		std::vector<int>::iterator	it = v.begin();
		ft::vector<int>::iterator	it1 = v1.begin();

		std::vector<std::string>::iterator	sit = sv.begin();
		ft::vector<std::string>::iterator	sit1 = sv1.begin();

		res = (*it == *it1);
		printCase("\033[0;37mbegin( void ): \t\t\t\t", res, false);
		res = (it[3] == it1[3]);
		printCase("", res, false);
		res = (*sit == *sit1);
		printCase("", res, false);
		res = (sit[3] == sit1[3]);
		printCase("", res, true);
	}

	// End() tests.
	{
		std::vector<int>::iterator	it = v.end();
		ft::vector<int>::iterator	it1 = v1.end();

		std::vector<std::string>::iterator	sit = sv.end();
		ft::vector<std::string>::iterator	sit1 = sv1.end();

		std::vector<int>	dv;
		ft::vector<int>		dv1;
		for (size_t i = 0; i < 43; i++)
		{
			dv.push_back(i);
			dv1.push_back(i);
		}
		std::vector<int>::iterator	dit = dv.end();
		ft::vector<int>::iterator	dit1 = dv1.end();

		res = (*(it - 1) == *(it1 - 1));
		printCase("\033[0;37mend( void ): \t\t\t\t", res, false);
		res = (*(it - 28) == *(it1 - 28));
		printCase("", res, false);
		res = (*(sit - 1) == *(sit1 - 1));
		printCase("", res, false);
		res = (*(sit - 27) == *(sit1 - 27));
		printCase("", res, false);
		res = (*(dit - 1) == *(dit1 - 1));
		printCase("", res, false);
		res = (*(dit - 19) == *(dit1 - 19));
		printCase("", res, true);
	}

	// Rbegin() tests.
	{
		std::vector<int>::reverse_iterator	it = v.rbegin();
		ft::vector<int>::reverse_iterator	it1 = v1.rbegin();

		std::vector<std::string>::reverse_iterator	sit = sv.rbegin();
		ft::vector<std::string>::reverse_iterator	sit1 = sv1.rbegin();

		std::vector<int>	dv;
		ft::vector<int>		dv1;
		for (size_t i = 0; i < 43; i++)
		{
			dv.push_back(i);
			dv1.push_back(i);
		}
		std::vector<int>::reverse_iterator	dit = dv.rbegin();
		ft::vector<int>::reverse_iterator	dit1 = dv1.rbegin();

		res = (*(it + 1) == *(it1 + 1));
		printCase("\033[0;37mrbegin( void ): \t\t\t", res, false);
		res = (*(it + 28) == *(it1 + 28));
		printCase("", res, false);
		res = (*(sit + 1) == *(sit1 + 1));
		printCase("", res, false);
		res = (*(sit + 27) == *(sit1 + 27));
		printCase("", res, false);
		res = (*(dit + 1) == *(dit1 + 1));
		printCase("", res, false);
		res = (*(dit + 19) == *(dit1 + 19));
		printCase("", res, true);
	}

	// Rend() tests.
	{
		std::vector<int>::reverse_iterator	it = v.rend();
		ft::vector<int>::reverse_iterator	it1 = v1.rend();

		std::vector<std::string>::reverse_iterator	sit = sv.rend();
		ft::vector<std::string>::reverse_iterator	sit1 = sv1.rend();

		std::vector<int>	dv;
		ft::vector<int>		dv1;
		for (size_t i = 0; i < 43; i++)
		{
			dv.push_back(i);
			dv1.push_back(i);
		}
		std::vector<int>::reverse_iterator	dit = dv.rend();
		ft::vector<int>::reverse_iterator	dit1 = dv1.rend();

		res = (*(it - 1) == *(it1 - 1));
		printCase("\033[0;37mrend( void ): \t\t\t\t", res, false);
		res = (*(it - 28) == *(it1 - 28));
		printCase("", res, false);
		res = (*(sit - 1) == *(sit1 - 1));
		printCase("", res, false);
		res = (*(sit - 27) == *(sit1 - 27));
		printCase("", res, false);
		res = (*(dit - 1) == *(dit1 - 1));
		printCase("", res, false);
		res = (*(dit - 19) == *(dit1 - 19));
		printCase("", res, true);
	}

	std::cout << std::endl << BLUE << "CAPACITY TESTS:" << RESET << std::endl;

	// Empty() tests.
	{
		res = (v.empty() == v1.empty());
		printCase("\033[0;37mempty( void ): \t\t\t\t", res, false);
		res = (sv.empty() == sv1.empty());
		printCase("", res, false);
		res = (ov.empty() == ov1.empty());
		printCase("", res, false);
		res = (ev.empty() == ev1.empty());
		printCase("", res, true);
	}

	// Size() tests.
	{
		res = (v.size() == v1.size());
		printCase("\033[0;37msize( void ): \t\t\t\t", res, false);
		res = (sv.size() == sv1.size());
		printCase("", res, false);
		res = (ov.size() == ov1.size());
		printCase("", res, false);
		res = (ev.size() == ev1.size());
		printCase("", res, true);
	}

	// Max_size() tests.
	{
		res = (v.max_size() == v1.max_size());
		printCase("\033[0;37mmax_size( void ): \t\t\t", res, false);
		res = (sv.max_size() == sv1.max_size());
		printCase("", res, false);
		res = (ov.max_size() == ov1.max_size());
		printCase("", res, false);
		res = (ev.max_size() == ev1.max_size());
		printCase("", res, true);
	}

	// Reserve() tests.
	{
		std::vector<int>			cv = v;
		ft::vector<int>				cv1 = v1;
		std::vector<int>			cov = ov;
		ft::vector<int>				cov1 = ov1;
		std::vector<int>			cev = ev;
		ft::vector<int>				cev1 = ev1;
		std::vector<std::string>	csv = sv;
		ft::vector<std::string>		csv1 = sv1;

		cv.reserve(24);
		cv1.reserve(24);
		csv.reserve(24);
		csv1.reserve(24);
		cov.reserve(42);
		cov1.reserve(42);
		cev.reserve(24);
		cev1.reserve(24);

		res = (cv.capacity() == cv1.capacity());
		printCase("\033[0;37mreserve( void ): \t\t\t", res, false);
		res = (csv.capacity() == csv1.capacity());
		printCase("", res, false);
		res = (cov.capacity() == cov1.capacity());
		printCase("", res, false);
		res = (cev.capacity() == cev1.capacity());
		printCase("", res, true);
	}

	// Capacity() tests.
	{
		res = (v.capacity() == v1.capacity());
		printCase("\033[0;37mreserve( void ): \t\t\t", res, false);
		res = (sv.capacity() == sv1.capacity());
		printCase("", res, false);
		res = (ov.capacity() == ov1.capacity());
		printCase("", res, false);
		res = (ev.capacity() == ev1.capacity());
		printCase("", res, true);
	}

	std::cout << std::endl << BLUE << "MODIFIERS TESTS:" << RESET << std::endl;

	// Clear() test.
	{
		std::vector<int>			cv = v;
		ft::vector<int>				cv1 = v1;
		std::vector<int>			cov = ov;
		ft::vector<int>				cov1 = ov1;
		std::vector<int>			cev = ev;
		ft::vector<int>				cev1 = ev1;
		std::vector<std::string>	csv = sv;
		ft::vector<std::string>		csv1 = sv1;

		cv.clear();
		cv1.clear();
		cov.clear();
		cov1.clear();
		cev.clear();
		cev1.clear();
		csv.clear();
		csv1.clear();

		res = (cv.capacity() == cv1.capacity() && cv.size() == cv1.size());
		printCase("\033[0;37mclear( void ): \t\t\t\t", res, false);
		res = (csv.capacity() == csv1.capacity() && csv.size() == csv1.size());
		printCase("", res, false);
		res = (cov.capacity() == cov1.capacity() && cov.size() == cov1.size());
		printCase("", res, false);
		res = (cev.capacity() == cev1.capacity() && cev.size() == cev1.size());
		printCase("", res, true);
	}

	// Insert(position, value) test.
	{
		std::vector<int>			cv = v;
		ft::vector<int>				cv1 = v1;
		std::vector<int>			cov = ov;
		ft::vector<int>				cov1 = ov1;
		std::vector<int>			cev = ev;
		ft::vector<int>				cev1 = ev1;
		std::vector<std::string>	csv = sv;
		ft::vector<std::string>		csv1 = sv1;

		std::vector<int>::iterator	it = cv.begin();
		ft::vector<int>::iterator	it1 = cv1.begin();

		std::vector<std::string>::iterator	sit = csv.begin();
		ft::vector<std::string>::iterator	sit1 = csv1.begin();

		std::vector<int>::iterator	oit = cov.begin();
		ft::vector<int>::iterator	oit1 = cov1.begin();

		cv.insert(it + 4, 24);
		cv1.insert(it1 + 4, 24);
		csv.insert(sit + 4, "24");
		csv1.insert(sit1 + 4, "24");
		cov.insert(oit, 24);
		cov1.insert(oit1, 24);

		res = (cv.capacity() == cv1.capacity() && cv.size() == cv1.size() && cv[4] == cv1[4] && cv[5] == cv1[5]);
		printCase("\033[0;37minsert(position, value): \t\t", res, false);
		res = (csv.capacity() == csv1.capacity() && csv.size() == csv1.size() && csv[4] == csv1[4] && csv[5] == csv1[5]);
		printCase("", res, false);
		res = (cov.capacity() == cov1.capacity() && cov.size() == cov1.size() && cov.front() == cov1.front() && cov.back() == cov1.back());
		printCase("", res, false);
		res = (cev.capacity() == cev1.capacity() && cev.size() == cev1.size());
		printCase("", res, true);
	}

	// Insert(position, n, value) test.
	{
		std::vector<int>			cv = v;
		ft::vector<int>				cv1 = v1;
		std::vector<int>			cov = ov;
		ft::vector<int>				cov1 = ov1;
		std::vector<int>			cev = ev;
		ft::vector<int>				cev1 = ev1;
		std::vector<std::string>	csv = sv;
		ft::vector<std::string>		csv1 = sv1;

		std::vector<int>::iterator	it = cv.begin();
		ft::vector<int>::iterator	it1 = cv1.begin();

		std::vector<std::string>::iterator	sit = csv.begin();
		ft::vector<std::string>::iterator	sit1 = csv1.begin();

		std::vector<int>::iterator	oit = cov.begin();
		ft::vector<int>::iterator	oit1 = cov1.begin();

		cv.insert(it + 4, 50, 24);
		cv1.insert(it1 + 4, 50, 24);
		csv.insert(sit + 4, 10, "24");
		csv1.insert(sit1 + 4, 10, "24");
		cov.insert(oit, 5, 24);
		cov1.insert(oit1, 5, 24);

		res = (cv.capacity() == cv1.capacity() && cv.size() == cv1.size() && cv[4] == cv1[4] && cv[5] == cv1[5] && cv[14] == cv1[14] && cv[15] == cv1[15]);
		printCase("\033[0;37minsert(position, n, value): \t\t", res, false);
		res = (csv.capacity() == csv1.capacity() && csv.size() == csv1.size() && csv[4] == csv1[4] && csv[5] == csv1[5] && csv[14] == csv1[14] && csv[15] == csv1[15]);
		printCase("", res, false);
		res = (cov.capacity() == cov1.capacity() && cov.size() == cov1.size() && cov.front() == cov1.front() && cov.back() == cov1.back());
		printCase("", res, false);
		res = (cev.capacity() == cev1.capacity() && cev.size() == cev1.size());
		printCase("", res, true);
	}

	// Insert(position, n, value) test.
	{
		std::vector<int>			cv = v;
		ft::vector<int>				cv1 = v1;
		std::vector<int>			cov = ov;
		ft::vector<int>				cov1 = ov1;
		std::vector<int>			cev = ev;
		ft::vector<int>				cev1 = ev1;
		std::vector<std::string>	csv = sv;
		ft::vector<std::string>		csv1 = sv1;

		std::vector<int>::iterator	it = cv.begin();
		ft::vector<int>::iterator	it1 = cv1.begin();

		std::vector<std::string>::iterator	sit = csv.begin();
		ft::vector<std::string>::iterator	sit1 = csv1.begin();

		std::vector<int>::iterator	oit = cov.begin();
		ft::vector<int>::iterator	oit1 = cov1.begin();

		std::vector<int>			aux(43, 24);
		ft::vector<int>				aux1(43, 24);
		std::vector<std::string>	saux(43, "24");
		ft::vector<std::string>		saux1(43, "24");

		std::vector<int>::iterator	ait = aux.begin();
		ft::vector<int>::iterator	ait1 = aux1.begin();
		std::vector<int>::iterator	aend = aux.end();
		ft::vector<int>::iterator	aend1 = aux1.end();

		std::vector<std::string>::iterator	asit = saux.begin();
		ft::vector<std::string>::iterator	asit1 = saux1.begin();
		std::vector<std::string>::iterator	asend = saux.end();
		ft::vector<std::string>::iterator	asend1 = saux1.end();


		cv.insert(it + 4, ait, aend);
		cv1.insert(it1 + 4, ait1, aend1);
		csv.insert(sit + 4, asit, asend);
		csv1.insert(sit1 + 4, asit1, asend1);
		cov.insert(oit, ait, aend);
		cov1.insert(oit1, ait1, aend1);

		res = (cv.capacity() == cv1.capacity() && cv.size() == cv1.size() && cv[4] == cv1[4] && cv[5] == cv1[5] && cv[14] == cv1[14] && cv[15] == cv1[15]);
		printCase("\033[0;37minsert(position, iterator, iterator): \t", res, false);
		res = (csv.capacity() == csv1.capacity() && csv.size() == csv1.size() && csv[4] == csv1[4] && csv[5] == csv1[5] && csv[14] == csv1[14] && csv[15] == csv1[15]);
		printCase("", res, false);
		res = (cov.capacity() == cov1.capacity() && cov.size() == cov1.size() && cov.front() == cov1.front() && cov.back() == cov1.back());
		printCase("", res, false);
		res = (cev.capacity() == cev1.capacity() && cev.size() == cev1.size());
		printCase("", res, true);
	}

	// Erase(position) test.
	{
		std::vector<int>			cv = v;
		ft::vector<int>				cv1 = v1;
		std::vector<int>			cov = ov;
		ft::vector<int>				cov1 = ov1;
		std::vector<int>			cev = ev;
		ft::vector<int>				cev1 = ev1;
		std::vector<std::string>	csv = sv;
		ft::vector<std::string>		csv1 = sv1;

		std::vector<int>::iterator	it = cv.begin();
		ft::vector<int>::iterator	it1 = cv1.begin();

		std::vector<std::string>::iterator	sit = csv.begin();
		ft::vector<std::string>::iterator	sit1 = csv1.begin();

		std::vector<int>::iterator	oit = cov.begin();
		ft::vector<int>::iterator	oit1 = cov1.begin();

		cv.erase(it + 4);
		cv1.erase(it1 + 4);
		csv.erase(sit + 4);
		csv1.erase(sit1 + 4);
		cov.erase(oit);
		cov1.erase(oit1);

		res = (cv.capacity() == cv1.capacity() && cv.size() == cv1.size() && cv[4] == cv1[4] && cv[5] == cv1[5]);
		printCase("\033[0;37merase(position): \t\t\t", res, false);
		res = (csv.capacity() == csv1.capacity() && csv.size() == csv1.size() && csv[4] == csv1[4] && csv[5] == csv1[5]);
		printCase("", res, false);
		res = (cov.capacity() == cov1.capacity() && cov.size() == cov1.size());
		printCase("", res, false);
		res = (cev.capacity() == cev1.capacity() && cev.size() == cev1.size());
		printCase("", res, true);
	}

	// Erase(iterator, iterator) test.
	{
		std::vector<int>			cv = v;
		ft::vector<int>				cv1 = v1;
		std::vector<int>			cov = ov;
		ft::vector<int>				cov1 = ov1;
		std::vector<int>			cev = ev;
		ft::vector<int>				cev1 = ev1;
		std::vector<std::string>	csv = sv;
		ft::vector<std::string>		csv1 = sv1;

		std::vector<int>::iterator	it = cv.begin();
		ft::vector<int>::iterator	it1 = cv1.begin();

		std::vector<std::string>::iterator	sit = csv.begin();
		ft::vector<std::string>::iterator	sit1 = csv1.begin();

		std::vector<int>::iterator	oit = cov.begin();
		ft::vector<int>::iterator	oit1 = cov1.begin();

		cv.erase(it + 4, it + 8);
		cv1.erase(it1 + 4, it1 + 8);
		csv.erase(sit + 4, sit + 8);
		csv1.erase(sit1 + 4, sit1 + 8);
		cov.erase(oit, oit);
		cov1.erase(oit1, oit1);

		res = (cv.capacity() == cv1.capacity() && cv.size() == cv1.size() && cv[4] == cv1[4] && cv[5] == cv1[5]);
		printCase("\033[0;37merase(iterator, iterator): \t\t", res, false);
		res = (csv.capacity() == csv1.capacity() && csv.size() == csv1.size() && csv[4] == csv1[4] && csv[5] == csv1[5]);
		printCase("", res, false);
		res = (cov.capacity() == cov1.capacity() && cov.size() == cov1.size());
		printCase("", res, false);
		res = (cev.capacity() == cev1.capacity() && cev.size() == cev1.size());
		printCase("", res, true);
	}


	// Push_back() test.
	{
		std::vector<int>			cv = v;
		ft::vector<int>				cv1 = v1;
		std::vector<int>			cov = ov;
		ft::vector<int>				cov1 = ov1;
		std::vector<int>			cev = ev;
		ft::vector<int>				cev1 = ev1;
		std::vector<std::string>	csv = sv;
		ft::vector<std::string>		csv1 = sv1;

		cv.push_back(24);
		cv1.push_back(24);
		csv.push_back("24");
		csv1.push_back("24");
		cov.push_back(24);
		cov1.push_back(24);
		cev.push_back(24);
		cev1.push_back(24);

		res = (cv.capacity() == cv1.capacity() && cv.size() == cv1.size() && cv[4] == cv1[4] && cv[5] == cv1[5]);
		printCase("\033[0;37mpush_back(value): \t\t\t", res, false);
		res = (csv.capacity() == csv1.capacity() && csv.size() == csv1.size() && csv[4] == csv1[4] && csv[5] == csv1[5]);
		printCase("", res, false);
		res = (cov.capacity() == cov1.capacity() && cov.size() == cov1.size());
		printCase("", res, false);
		res = (cev.capacity() == cev1.capacity() && cev.size() == cev1.size());
		printCase("", res, true);
	}

	// Pop_back() test.
	{
		std::vector<int>			cv = v;
		ft::vector<int>				cv1 = v1;
		std::vector<int>			cov = ov;
		ft::vector<int>				cov1 = ov1;
		std::vector<int>			cev = ev;
		ft::vector<int>				cev1 = ev1;
		std::vector<std::string>	csv = sv;
		ft::vector<std::string>		csv1 = sv1;

		cv.pop_back();
		cv1.pop_back();
		csv.pop_back();
		csv1.pop_back();
		cov.pop_back();
		cov1.pop_back();

		res = (cv.capacity() == cv1.capacity() && cv.size() == cv1.size() && cv[4] == cv1[4] && cv[5] == cv1[5]);
		printCase("\033[0;37mpop_back( void ): \t\t\t", res, false);
		res = (csv.capacity() == csv1.capacity() && csv.size() == csv1.size() && csv[4] == csv1[4] && csv[5] == csv1[5]);
		printCase("", res, false);
		res = (cov.capacity() == cov1.capacity() && cov.size() == cov1.size());
		printCase("", res, false);
		res = (cev.capacity() == cev1.capacity() && cev.size() == cev1.size());
		printCase("", res, true);
	}

	// // Resize() test.
	// {
	// 	std::vector<int>			cv = v;
	// 	ft::vector<int>				cv1 = v1;
	// 	std::vector<int>			cov = ov;
	// 	ft::vector<int>				cov1 = ov1;
	// 	std::vector<int>			cev = ev;
	// 	ft::vector<int>				cev1 = ev1;
	// 	std::vector<std::string>	csv = sv;
	// 	ft::vector<std::string>		csv1 = sv1;

	// 	cv.resize(24, 24);
	// 	cv1.resize(24, 24);
	// 	csv.resize(24, "24");
	// 	csv1.resize(24, "24");
	// 	cov.resize(24, 24);
	// 	cov1.resize(24, 24);
	// 	cev.resize(24, 24);
	// 	cev1.resize(24, 24);
		
	// 	res = (cv.capacity() == cv1.capacity() && cv.size() == cv1.size() && cv[4] == cv1[4] && cv[5] == cv1[5]);
	// 	printCase("\033[0;37mresize( size_type, value ): \t\t", res, false);
	// 	res = (csv.capacity() == csv1.capacity() && csv.size() == csv1.size() && csv[4] == csv1[4] && csv[5] == csv1[5]);
	// 	printCase("", res, false);
	// 	res = (cov.capacity() == cov1.capacity() && cov.size() == cov1.size() && cov.front() == cov1.front() && cov.back() == cov1.back());
	// 	printCase("", res, false);
	// 	res = (cev.capacity() == cev1.capacity() && cev.size() == cev1.size() && cev.front() == cev1.front() && cev.back() == cev1.back());
	// 	printCase("", res, true);
	// }

	// Swap() test.
	{
		std::vector<int>			acv = v;
		ft::vector<int>				acv1 = v1;
		std::vector<int>			acov = ov;
		ft::vector<int>				acov1 = ov1;
		std::vector<int>			acev = ev;
		ft::vector<int>				acev1 = ev1;
		std::vector<std::string>	acsv = sv;
		ft::vector<std::string>		acsv1 = sv1;

		std::vector<int>			bcv;
		ft::vector<int>				bcv1;
		std::vector<int>			bcov;
		ft::vector<int>				bcov1;
		std::vector<int>			bcev;
		ft::vector<int>				bcev1;
		std::vector<std::string>	bcsv;
		ft::vector<std::string>		bcsv1;

		acv.swap(bcv);
		acv1.swap(bcv1);
		acsv.swap(bcsv);
		acsv1.swap(bcsv1);
		acov.swap(bcov);
		acov1.swap(bcov1);
		acev.swap(bcev);
		acev1.swap(bcev1);
		
		res = (bcv.capacity() == bcv1.capacity() && bcv.size() == bcv1.size() && bcv[4] == bcv1[4] && bcv[5] == bcv1[5]);
		printCase("\033[0;37mswap( vector ): \t\t\t", res, false);
		res = (bcsv.capacity() == bcsv1.capacity() && bcsv.size() == bcsv1.size() && bcsv[4] == bcsv1[4] && bcsv[5] == bcsv1[5]);
		printCase("", res, false);
		res = (bcov.capacity() == bcov1.capacity() && bcov.size() == bcov1.size());
		printCase("", res, false);
		res = (bcev.capacity() == bcev1.capacity() && bcev.size() == bcev1.size());
		printCase("", res, true);
	}

	std::cout << std::endl << BLUE << "NON-MEMBER FUNCTIONS TESTS:" << RESET << std::endl;

	// Operator==() tests.
	{
		std::vector<int>			tv = v;
		ft::vector<int>				tv1 = v1;
		std::vector<int>			tov = ov;
		ft::vector<int>				tov1 = ov1;
		std::vector<int>			tev = ev;
		ft::vector<int>				tev1 = ev1;
		std::vector<std::string>	tsv = sv;
		ft::vector<std::string>		tsv1 = sv1;

		std::vector<int>			fv = v;
		ft::vector<int>				fv1 = v1;
		std::vector<int>			fov = ov;
		ft::vector<int>				fov1 = ov1;
		std::vector<int>			fev = ev;
		ft::vector<int>				fev1 = ev1;
		std::vector<std::string>	fsv = sv;
		ft::vector<std::string>		fsv1 = sv1;

		fv.push_back(42);
		fv1.push_back(42);
		fov.push_back(42);
		fov1.push_back(42);
		fev.push_back(42);
		fev1.push_back(42);
		fsv.push_back("42");
		fsv1.push_back("42");

		res = ((tv == v) == (tv1 == v1) && (fv == v) == (fv1 == v1));
		printCase("\033[0;37moperator==( left, right ): \t\t", res, false);
		res = ((tsv == sv) == (tsv1 == sv1) && (fsv == sv) == (fsv1 == sv1));
		printCase("", res, false);
		res = ((tov == ov) == (tov1 == ov1) && (fov == ov) == (fov1 == ov1));
		printCase("", res, false);
		res = ((tev == ev) == (tev1 == ev1) && (fev == ev) == (fev1 == ev1));
		printCase("", res, true);
	}

	// Operator!=() tests.
	{
		std::vector<int>			tv = v;
		ft::vector<int>				tv1 = v1;
		std::vector<int>			tov = ov;
		ft::vector<int>				tov1 = ov1;
		std::vector<int>			tev = ev;
		ft::vector<int>				tev1 = ev1;
		std::vector<std::string>	tsv = sv;
		ft::vector<std::string>		tsv1 = sv1;

		std::vector<int>			fv = v;
		ft::vector<int>				fv1 = v1;
		std::vector<int>			fov = ov;
		ft::vector<int>				fov1 = ov1;
		std::vector<int>			fev = ev;
		ft::vector<int>				fev1 = ev1;
		std::vector<std::string>	fsv = sv;
		ft::vector<std::string>		fsv1 = sv1;

		fv.push_back(42);
		fv1.push_back(42);
		fov.push_back(42);
		fov1.push_back(42);
		fev.push_back(42);
		fev1.push_back(42);
		fsv.push_back("42");
		fsv1.push_back("42");

		res = ((tv != v) == (tv1 != v1) && (fv != v) == (fv1 != v1));
		printCase("\033[0;37moperator!=( left, right ): \t\t", res, false);
		res = ((tsv != sv) == (tsv1 != sv1) && (fsv != sv) == (fsv1 != sv1));
		printCase("", res, false);
		res = ((tov != ov) == (tov1 != ov1) && (fov != ov) == (fov1 != ov1));
		printCase("", res, false);
		res = ((tev != ev) == (tev1 != ev1) && (fev != ev) == (fev1 != ev1));
		printCase("", res, true);
	}

	// Operator<() tests.
	{
		std::vector<int>			wv = v;
		ft::vector<int>				wv1 = v1;
		std::vector<int>			wov = ov;
		ft::vector<int>				wov1 = ov1;
		std::vector<int>			wev = ev;
		ft::vector<int>				wev1 = ev1;
		std::vector<std::string>	wsv = sv;
		ft::vector<std::string>		wsv1 = sv1;

		std::vector<int>			tv = v;
		ft::vector<int>				tv1 = v1;
		std::vector<int>			tov = ov;
		ft::vector<int>				tov1 = ov1;
		std::vector<int>			tev = ev;
		ft::vector<int>				tev1 = ev1;
		std::vector<std::string>	tsv = sv;
		ft::vector<std::string>		tsv1 = sv1;

		std::vector<int>			fv = v;
		ft::vector<int>				fv1 = v1;
		std::vector<int>			fov = ov;
		ft::vector<int>				fov1 = ov1;
		std::vector<int>			fev = ev;
		ft::vector<int>				fev1 = ev1;
		std::vector<std::string>	fsv = sv;
		ft::vector<std::string>		fsv1 = sv1;

		fv.push_back(42);
		fv1.push_back(42);
		fov.push_back(42);
		fov1.push_back(42);
		fev.push_back(42);
		fev1.push_back(42);
		fsv.push_back("42");
		fsv1.push_back("42");

		wv.pop_back();
		wv1.pop_back();
		wov.pop_back();
		wov1.pop_back();
		wsv.pop_back();
		wsv1.pop_back();

		res = ((tv < v) == (tv1 < v1) && (fv < v) == (fv1 < v1) && (wv < v) == (wv1 < v1));
		printCase("\033[0;37moperator<( left, right ): \t\t", res, false);
		res = ((tsv < sv) == (tsv1 < sv1) && (fsv < sv) == (fsv1 < sv1) && (wsv < sv) == (wsv1 < sv1));
		printCase("", res, false);
		res = ((tov < ov) == (tov1 < ov1) && (fov < ov) == (fov1 < ov1) && (wov < ov) == (wov1 < ov1));
		printCase("", res, false);
		res = ((tev < ev) == (tev1 < ev1) && (fev < ev) == (fev1 < ev1) && (wev < ev) == (wev1 < ev1));
		printCase("", res, true);
	}

	// Operator<=() tests.
	{
		std::vector<int>			wv = v;
		ft::vector<int>				wv1 = v1;
		std::vector<int>			wov = ov;
		ft::vector<int>				wov1 = ov1;
		std::vector<int>			wev = ev;
		ft::vector<int>				wev1 = ev1;
		std::vector<std::string>	wsv = sv;
		ft::vector<std::string>		wsv1 = sv1;

		std::vector<int>			tv = v;
		ft::vector<int>				tv1 = v1;
		std::vector<int>			tov = ov;
		ft::vector<int>				tov1 = ov1;
		std::vector<int>			tev = ev;
		ft::vector<int>				tev1 = ev1;
		std::vector<std::string>	tsv = sv;
		ft::vector<std::string>		tsv1 = sv1;

		std::vector<int>			fv = v;
		ft::vector<int>				fv1 = v1;
		std::vector<int>			fov = ov;
		ft::vector<int>				fov1 = ov1;
		std::vector<int>			fev = ev;
		ft::vector<int>				fev1 = ev1;
		std::vector<std::string>	fsv = sv;
		ft::vector<std::string>		fsv1 = sv1;

		fv.push_back(42);
		fv1.push_back(42);
		fov.push_back(42);
		fov1.push_back(42);
		fev.push_back(42);
		fev1.push_back(42);
		fsv.push_back("42");
		fsv1.push_back("42");

		wv.pop_back();
		wv1.pop_back();
		wov.pop_back();
		wov1.pop_back();
		wsv.pop_back();
		wsv1.pop_back();

		res = ((tv <= v) == (tv1 <= v1) && (fv <= v) == (fv1 <= v1) && (wv <= v) == (wv1 <= v1));
		printCase("\033[0;37moperator<=( left, right ): \t\t", res, false);
		res = ((tsv <= sv) == (tsv1 <= sv1) && (fsv <= sv) == (fsv1 <= sv1) && (wsv <= sv) == (wsv1 <= sv1));
		printCase("", res, false);
		res = ((tov <= ov) == (tov1 <= ov1) && (fov <= ov) == (fov1 <= ov1) && (wov <= ov) == (wov1 <= ov1));
		printCase("", res, false);
		res = ((tev <= ev) == (tev1 <= ev1) && (fev <= ev) == (fev1 <= ev1) && (wev <= ev) == (wev1 <= ev1));
		printCase("", res, true);
	}
	
	// Operator>() tests.
	{
		std::vector<int>			wv = v;
		ft::vector<int>				wv1 = v1;
		std::vector<int>			wov = ov;
		ft::vector<int>				wov1 = ov1;
		std::vector<int>			wev = ev;
		ft::vector<int>				wev1 = ev1;
		std::vector<std::string>	wsv = sv;
		ft::vector<std::string>		wsv1 = sv1;

		std::vector<int>			tv = v;
		ft::vector<int>				tv1 = v1;
		std::vector<int>			tov = ov;
		ft::vector<int>				tov1 = ov1;
		std::vector<int>			tev = ev;
		ft::vector<int>				tev1 = ev1;
		std::vector<std::string>	tsv = sv;
		ft::vector<std::string>		tsv1 = sv1;

		std::vector<int>			fv = v;
		ft::vector<int>				fv1 = v1;
		std::vector<int>			fov = ov;
		ft::vector<int>				fov1 = ov1;
		std::vector<int>			fev = ev;
		ft::vector<int>				fev1 = ev1;
		std::vector<std::string>	fsv = sv;
		ft::vector<std::string>		fsv1 = sv1;

		fv.push_back(42);
		fv1.push_back(42);
		fov.push_back(42);
		fov1.push_back(42);
		fev.push_back(42);
		fev1.push_back(42);
		fsv.push_back("42");
		fsv1.push_back("42");

		wv.pop_back();
		wv1.pop_back();
		wov.pop_back();
		wov1.pop_back();
		wsv.pop_back();
		wsv1.pop_back();

		res = ((tv > v) == (tv1 > v1) && (fv > v) == (fv1 > v1) && (wv > v) == (wv1 > v1));
		printCase("\033[0;37moperator>( left, right ): \t\t", res, false);
		res = ((tsv > sv) == (tsv1 > sv1) && (fsv > sv) == (fsv1 > sv1) && (wsv > sv) == (wsv1 > sv1));
		printCase("", res, false);
		res = ((tov > ov) == (tov1 > ov1) && (fov > ov) == (fov1 > ov1) && (wov > ov) == (wov1 > ov1));
		printCase("", res, false);
		res = ((tev > ev) == (tev1 > ev1) && (fev > ev) == (fev1 > ev1) && (wev > ev) == (wev1 > ev1));
		printCase("", res, true);
	}

	// Operator>=() tests.
	{
		std::vector<int>			wv = v;
		ft::vector<int>				wv1 = v1;
		std::vector<int>			wov = ov;
		ft::vector<int>				wov1 = ov1;
		std::vector<int>			wev = ev;
		ft::vector<int>				wev1 = ev1;
		std::vector<std::string>	wsv = sv;
		ft::vector<std::string>		wsv1 = sv1;

		std::vector<int>			tv = v;
		ft::vector<int>				tv1 = v1;
		std::vector<int>			tov = ov;
		ft::vector<int>				tov1 = ov1;
		std::vector<int>			tev = ev;
		ft::vector<int>				tev1 = ev1;
		std::vector<std::string>	tsv = sv;
		ft::vector<std::string>		tsv1 = sv1;

		std::vector<int>			fv = v;
		ft::vector<int>				fv1 = v1;
		std::vector<int>			fov = ov;
		ft::vector<int>				fov1 = ov1;
		std::vector<int>			fev = ev;
		ft::vector<int>				fev1 = ev1;
		std::vector<std::string>	fsv = sv;
		ft::vector<std::string>		fsv1 = sv1;

		fv.push_back(42);
		fv1.push_back(42);
		fov.push_back(42);
		fov1.push_back(42);
		fev.push_back(42);
		fev1.push_back(42);
		fsv.push_back("42");
		fsv1.push_back("42");

		wv.pop_back();
		wv1.pop_back();
		wov.pop_back();
		wov1.pop_back();
		wsv.pop_back();
		wsv1.pop_back();

		res = ((tv >= v) == (tv1 >= v1) && (fv >= v) == (fv1 >= v1) && (wv >= v) == (wv1 >= v1));
		printCase("\033[0;37moperator>( left, right ): \t\t", res, false);
		res = ((tsv >= sv) == (tsv1 >= sv1) && (fsv >= sv) == (fsv1 >= sv1) && (wsv >= sv) == (wsv1 >= sv1));
		printCase("", res, false);
		res = ((tov >= ov) == (tov1 >= ov1) && (fov >= ov) == (fov1 >= ov1) && (wov >= ov) == (wov1 >= ov1));
		printCase("", res, false);
		res = ((tev >= ev) == (tev1 >= ev1) && (fev >= ev) == (fev1 >= ev1) && (wev >= ev) == (wev1 >= ev1));
		printCase("", res, true);
	}

	// ft::swap() tests.
	{
		std::vector<int>			acv = v;
		ft::vector<int>				acv1 = v1;
		std::vector<int>			acov = ov;
		ft::vector<int>				acov1 = ov1;
		std::vector<int>			acev = ev;
		ft::vector<int>				acev1 = ev1;
		std::vector<std::string>	acsv = sv;
		ft::vector<std::string>		acsv1 = sv1;

		std::vector<int>			bcv;
		ft::vector<int>				bcv1;
		std::vector<int>			bcov;
		ft::vector<int>				bcov1;
		std::vector<int>			bcev;
		ft::vector<int>				bcev1;
		std::vector<std::string>	bcsv;
		ft::vector<std::string>		bcsv1;

		std::swap(acv, bcv);
		ft::swap(acv1, bcv1);
		std::swap(acsv, bcsv);
		ft::swap(acsv1, bcsv1);
		std::swap(acov, bcov);
		ft::swap(acov1, bcov1);
		std::swap(acev, bcev);
		ft::swap(acev1, bcev1);
		
		res = (bcv.capacity() == bcv1.capacity() && bcv.size() == bcv1.size() && bcv[4] == bcv1[4] && bcv[5] == bcv1[5]);
		printCase("\033[0;37mft::swap( left, rigth ): \t\t", res, false);
		res = (bcsv.capacity() == bcsv1.capacity() && bcsv.size() == bcsv1.size() && bcsv[4] == bcsv1[4] && bcsv[5] == bcsv1[5]);
		printCase("", res, false);
		res = (bcov.capacity() == bcov1.capacity() && bcov.size() == bcov1.size());
		printCase("", res, false);
		res = (bcev.capacity() == bcev1.capacity() && bcev.size() == bcev1.size());
		printCase("", res, true);
	}

	std::cout << std::endl << BLUE << "RENDIMENT TESTS:" << RESET << std::endl;
	{
		testVectorSubject();
	}
}