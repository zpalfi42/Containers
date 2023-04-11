#include <tests.hpp>

#define BLK "\e[0;30m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

//Regular underline text
# define UBLK "\e[4;30m"
# define URED "\e[4;31m"
# define UGRN "\e[4;32m"
# define UYEL "\e[4;33m"
# define UBLU "\e[4;34m"
# define UMAG "\e[4;35m"
# define UCYN "\e[4;36m"
# define UWHT "\e[4;37m"


#define MAX_RAM 429496729
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

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

void testMapSubject()
{
	const int seed = atoi("1");
	srand(seed);

	double time_spent = 0.0;

	clock_t begin = clock();

	int sum = 0;
	int sum2 = 0;
	{
		ft::map<int, int> map_int;

		for (int i = 0; i < COUNT; ++i)
		{
			map_int.insert(ft::make_pair(rand(), rand()));
		}

		for (int i = 0; i < 10000; i++)
		{
			int access = rand();
			sum += map_int[access];
		}
		{
			ft::map<int, int> copy = map_int;
		}
	}
	clock_t end = clock();

	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	double time_spent2 = 0.0;

	clock_t begin2 = clock();
	{
		std::map<int, int> map_int;

		for (int i = 0; i < COUNT; ++i)
		{
			map_int.insert(std::make_pair(rand(), rand()));
		}

		for (int i = 0; i < 10000; i++)
		{
			int access = rand();
			sum2 += map_int[access];
		}

		{
			std::map<int, int> copy = map_int;
		}
	}

	clock_t end2 = clock();

	(void)sum;
	(void)sum2;

	time_spent2 += (double)(end2 - begin2) / CLOCKS_PER_SEC;
	std::cout << "time\t\t";
	(time_spent <= time_spent2 * 20) ? testOk() : testKo();
	std::cout << "\n";
	std::cout << "\n";
	std::cout << UMAG "Result Time" RESET << std::endl;
	std::cout << YEL "Time ft::map:\t" << time_spent << "s" RESET << std::endl;
	std::cout << YEL "Time std::map:\t" << time_spent2 << "s" RESET << std::endl;
	if (time_spent > time_spent2 * 20)
		std::cout << RED "ft::map time must be less than " <<  time_spent2 * 20 << "s" RESET << std::endl;

}

void mapTest()
{
	std::cout << std::endl;
	{
		std::map<char, int> first;
		ft::map<char, int> first2;

		first['a'] = 10;
		first['b'] = 30;
		first['c'] = 50;
		first['d'] = 70;
		first2['a'] = 10;
		first2['b'] = 30;
		first2['c'] = 50;
		first2['d'] = 70;

		std::cout << "empty\t\t";
		ft::map<char, int>::iterator it2 = first2.begin();
		for (std::map<char, int>::iterator it = first.begin(); it != first.end(); ++it)
		{
			(it->first == it2->first && it->second == it2->second) ? testOk() : testKo();
			++it2;
		}
		std::cout << std::endl;
		std::cout << "range\t\t";
		std::map<char, int> second(first.begin(), first.end());
		ft::map<char, int> second2(first2.begin(), first2.end());
		ft::map<char, int>::iterator it3 = second2.begin();
		for (std::map<char, int>::iterator it4 = second.begin(); it4 != second.end(); ++it4)
		{
			(it3->first == it4->first && it3->second == it4->second) ? testOk() : testKo();
			++it3;
		}
		{
			std::pair<std::string, std::string> old_arr[] =
				{
					std::make_pair("Ground", "Grass"),
					std::make_pair("Floor", "Cement"),
					std::make_pair("Table", "Wood")};

			int n = (sizeof(old_arr) /
					 sizeof(old_arr[0]));
			std::map<std::string, std::string> New_Map(old_arr, old_arr + n);
			ft::pair<std::string, std::string> old_arr2[] =
				{
					ft::make_pair("Ground", "Grass"),
					ft::make_pair("Floor", "Cement"),
					ft::make_pair("Table", "Wood")};

			int n2 = (sizeof(old_arr2) /
					  sizeof(old_arr2[0]));
			ft::map<std::string, std::string> New_Map2(old_arr2, old_arr2 + n2);

			ft::map<std::string, std::string>::iterator it2 = New_Map2.begin();
			for (std::map<std::string, std::string>::iterator it = New_Map.begin(); it != New_Map.end(); ++it)
			{
				(it->first == it2->first && it->second == it2->second) ? testOk() : testKo();
				++it2;
			}
		}
		std::cout << std::endl;
		std::cout << "copy\t\t";
		std::map<char, int> third(first);
		ft::map<char, int> third2(first2);
		ft::map<char, int>::iterator it5 = third2.begin();
		for (std::map<char, int>::iterator it6 = third.begin(); it6 != third.end(); ++it6)
		{
			(it5->first == it6->first && it5->second == it6->second) ? testOk() : testKo();
			++it5;
		}
		std::cout << std::endl;
	}
	std::cout << UCYN "Test non-member functions" RESET << std::endl;
	{
		ft::map<char, int> first;
		ft::map<char, int> second;

		first['x'] = 8;
		first['y'] = 16;
		first['z'] = 32;

		second = first;				  // second now contains 3 ints
		first = ft::map<char, int>(); // and first is now empty
		ft::map<char, int> first2;
		ft::map<char, int> second2;

		first2['x'] = 8;
		first2['y'] = 16;
		first2['z'] = 32;

		second2 = first2;			   // second now contains 3 ints
		first2 = ft::map<char, int>(); // and first is now empty

		std::cout << "operator=\t";
		(first.size() == first2.size()) ? testOk() : testKo();
		(second.size() == second2.size()) ? testOk() : testKo();
		std::cout << std::endl;
	}
	std::cout << UCYN "Test iterators" RESET << std::endl;

	{
		std::map<char, int> mymap;
		ft::map<char, int> mymap2;

		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;
		mymap2['b'] = 100;
		mymap2['a'] = 200;
		mymap2['c'] = 300;

		std::cout << "begin\t\t";
		ft::map<char, int>::iterator it2 = mymap2.begin();
		for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		{
			(it->first == it2->first && it->second == it2->second) ? testOk() : testKo();
			++it2;
		}
		std::cout << std::endl;
	}
	{
		std::map<char, int> mymap;
		ft::map<char, int> mymap2;

		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;
		mymap2['b'] = 100;
		mymap2['a'] = 200;
		mymap2['c'] = 300;

		std::cout << "end\t\t";
		ft::map<char, int>::iterator it2 = mymap2.begin();
		for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		{
			(it->first == it2->first && it->second == it2->second) ? testOk() : testKo();
			++it2;
		}
		std::cout << std::endl;
	}
	{
		std::map<char, int> mymap;
		ft::map<char, int> mymap2;

		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;
		mymap2['x'] = 100;
		mymap2['y'] = 200;
		mymap2['z'] = 300;

		std::cout << "rbegin\t\t";
		std::map<char, int>::reverse_iterator rit;
		ft::map<char, int>::reverse_iterator rit2;
		rit2 = mymap2.rbegin();
		for (rit = mymap.rbegin(); rit != mymap.rend(); ++rit)
		{
			(rit->first == rit2->first && rit->second == rit2->second) ? testOk() : testKo();
            std::cout << rit->first << " == " << rit2->first << std::endl;
			++rit2;
		}
		std::cout << std::endl;
	}
	{
		std::map<char, int> mymap;
		ft::map<char, int> mymap2;

		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;
		mymap2['x'] = 100;
		mymap2['y'] = 200;
		mymap2['z'] = 300;

		std::cout << "rend\t\t";
		std::map<char, int>::reverse_iterator rit;
		ft::map<char, int>::reverse_iterator rit2;
		rit2 = mymap2.rbegin();
		for (rit = mymap.rbegin(); rit != mymap.rend(); ++rit)
		{
			(rit->first == rit2->first && rit->second == rit2->second) ? testOk() : testKo();
			++rit2;
		}
		std::cout << std::endl;
	}

	std::cout << UCYN "Test capacity" RESET << std::endl;
	{
		std::map<char, int> mymap;
		ft::map<char, int> mymap2;

		mymap['a'] = 10;
		mymap['b'] = 20;
		mymap['c'] = 30;
		mymap2['a'] = 10;
		mymap2['b'] = 20;
		mymap2['c'] = 30;
		std::cout << "empty\t\t";
		while (!mymap.empty() && !mymap2.empty())
		{
			(mymap.begin()->first == mymap2.begin()->first && mymap.begin()->second == mymap2.begin()->second) ? testOk() : testKo();
			mymap.erase(mymap.begin());
			mymap2.erase(mymap2.begin());
		}
		std::cout << std::endl;
	}
	{
		std::map<char, int> mymap;
		ft::map<char, int> mymap2;
		mymap['a'] = 101;
		mymap['b'] = 202;
		mymap['c'] = 302;
		mymap2['a'] = 101;
		mymap2['b'] = 202;
		mymap2['c'] = 302;
		std::cout << "size\t\t";
		(mymap.size() == mymap2.size()) ? testOk() : testKo();
		std::map<char, int> mymap3;
		ft::map<char, int> mymap4;
		(mymap3.size() == mymap4.size()) ? testOk() : testKo();
		std::map<int, int> mymap5;
		ft::map<int, int> mymap6;
		mymap5[2] = 435;
		mymap6[2] = 435;
		(mymap3.size() == mymap4.size()) ? testOk() : testKo();

		std::cout << std::endl;
	}
	{
		std::map<int, int> mymap;
		ft::map<int, int> mymap2;
		std::cout << "max_size\t";
		(mymap.max_size() == mymap2.max_size()) ? testOk() : testKo();
		std::cout << std::endl;
	}
	std::cout << UCYN "Test element access " RESET << std::endl;
	{
		std::map<char, std::string> mymap;
		ft::map<char, std::string> mymap2;

		mymap['a'] = "an element";
		mymap['b'] = "another element";
		mymap['c'] = mymap['b'];
		mymap2['a'] = "an element";
		mymap2['b'] = "another element";
		mymap2['c'] = mymap2['b'];
		std::cout << "operator[]\t";
		(mymap['a'] == mymap2['a']) ? testOk() : testKo();
		(mymap['b'] == mymap2['b']) ? testOk() : testKo();
		(mymap['c'] == mymap2['c']) ? testOk() : testKo();
		(mymap['d'] == mymap2['d']) ? testOk() : testKo();

		std::cout << std::endl;
	}
	{
		std::map<std::string, int> mymap;
		ft::map<std::string, int> mymap2;
		mymap["alpha"] = 0;
		mymap["beta"] = 0;
		mymap["gamma"] = 0;
		mymap2["alpha"] = 0;
		mymap2["beta"] = 0;
		mymap2["gamma"] = 0;

		mymap.at("alpha") = 10;
		mymap.at("beta") = 20;
		mymap.at("gamma") = 30;
		mymap2.at("alpha") = 10;
		mymap2.at("beta") = 20;
		mymap2.at("gamma") = 30;
		std::cout << "at\t\t";
		ft::map<std::string, int>::iterator it2 = mymap2.begin();
		for (std::map<std::string, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		{
			(it->first == it2->first && it->second == it2->second) ? testOk() : testKo();
			++it2;
		}
		try
		{
			mymap2.at("sigma") = 40;
			testKo();
		}
		catch (const std::exception &e)
		{
			testOk();
		}

		std::cout << std::endl;
	}
	std::cout << UCYN "Test modifiers" RESET << std::endl;
	{
		std::map<char, int> mymap;
		ft::map<char, int> mymap2;

		// first insert function version (single parameter):
		mymap.insert(std::pair<char, int>('a', 100));
		mymap.insert(std::pair<char, int>('z', 200));
		mymap2.insert(ft::pair<char, int>('a', 100));
		mymap2.insert(ft::pair<char, int>('z', 200));

		std::pair<std::map<char, int>::iterator, bool> ret;
		ft::pair<ft::map<char, int>::iterator, bool> ret2;
		ret = mymap.insert(std::pair<char, int>('z', 500));
		ret2 = mymap2.insert(ft::pair<char, int>('z', 500));

		std::cout << "insert\t\t";

		(ret.second == ret2.second) ? testOk() : testKo();

		// second insert function version (with hint position):
		std::map<char, int>::iterator it = mymap.begin();
		ft::map<char, int>::iterator it2 = mymap2.begin();
		mymap.insert(it, std::pair<char, int>('b', 300));  // max efficiency inserting
		mymap.insert(it, std::pair<char, int>('c', 400));  // no max efficiency inserting
		mymap2.insert(it2, ft::pair<char, int>('b', 300)); // max efficiency inserting
		mymap2.insert(it2, ft::pair<char, int>('c', 400)); // no max efficiency inserting

		// third insert function version (range insertion):
		std::map<char, int> anothermap;
		ft::map<char, int> anothermap2;
		anothermap.insert(mymap.begin(), mymap.find('c'));
		anothermap2.insert(mymap2.begin(), mymap2.find('c'));

		for (it = mymap.begin(); it != mymap.end(); ++it)
		{
			(it->first == it2->first && it->second == it2->second) ? testOk() : testKo();
			++it2;
		}

		it2 = anothermap2.begin();
		for (it = anothermap.begin(); it != anothermap.end(); ++it)
		{
			(it->first == it2->first && it->second == it2->second) ? testOk() : testKo();
			++it2;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "erease\t\t";
		std::map<char, int> mymap;
		std::map<char, int>::iterator it;
		ft::map<char, int> mymap2;
		ft::map<char, int>::iterator it2;

		// insert some values:
		mymap['a'] = 10;
		mymap['b'] = 20;
		mymap['c'] = 30;
		mymap['d'] = 40;
		mymap['e'] = 50;
		mymap['f'] = 60;
		mymap2['a'] = 10;
		mymap2['b'] = 20;
		mymap2['c'] = 30;
		mymap2['d'] = 40;
		mymap2['e'] = 50;
		mymap2['f'] = 60;

		it = mymap.find('b');
		mymap.erase(it); // erasing by iterator
		it2 = mymap2.find('b');
		mymap2.erase(it2); // erasing by iterator

		mymap.erase('c');  // erasing by key
		mymap2.erase('c'); // erasing by key

		it = mymap.find('e');
		mymap.erase(it, mymap.end()); // erasing by range
		it2 = mymap2.find('e');
		mymap2.erase(it2, mymap2.end()); // erasing by range
		it2 = mymap2.begin();
		for (it = mymap.begin(); it != mymap.end(); ++it)
		{
			(it->first == it2->first && it->second == it2->second) ? testOk() : testKo();
			++it2;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "swap\t\t";

		std::map<char, int> foo, bar;
		ft::map<char, int> foo2, bar2;

		foo['x'] = 100;
		foo['y'] = 200;
		foo2['x'] = 100;
		foo2['y'] = 200;

		bar['a'] = 11;
		bar['b'] = 22;
		bar['c'] = 33;
		bar2['a'] = 11;
		bar2['b'] = 22;
		bar2['c'] = 33;

		foo.swap(bar);
		foo2.swap(bar2);

		ft::map<char, int>::iterator it2;

		it2 = foo2.begin();
		for (std::map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
		{
			(it->first == it2->first && it->second == it2->second) ? testOk() : testKo();
			++it2;
		}

		it2 = bar2.begin();
		for (std::map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
		{
			(it->first == it2->first && it->second == it2->second) ? testOk() : testKo();
			++it2;
		}

		std::cout << std::endl;
	}
	{
		std::cout << "clear\t\t";
		std::map<char, int> mymap;
		ft::map<char, int> mymap2;

		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;
		mymap2['x'] = 100;
		mymap2['y'] = 200;
		mymap2['z'] = 300;

		ft::map<char, int>::iterator it2;

		it2 = mymap2.begin();
		for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		{
			(it->first == it2->first && it->second == it2->second) ? testOk() : testKo();
			++it2;
		}

		mymap.clear();
		mymap2.clear();
		mymap['a'] = 1101;
		mymap['b'] = 2202;
		mymap2['a'] = 1101;
		mymap2['b'] = 2202;

		it2 = mymap2.begin();
		for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		{
			(it->first == it2->first && it->second == it2->second) ? testOk() : testKo();
			++it2;
		}
		std::cout << std::endl;
	}
	std::cout << UCYN "Test observers" RESET << std::endl;
	{
		std::cout << "key_comp\t";
		std::map<char, int> mymap;
		ft::map<char, int> mymap2;

		std::map<char, int>::key_compare mycomp = mymap.key_comp();
		ft::map<char, int>::key_compare mycomp2 = mymap2.key_comp();

		mymap['a'] = 100;
		mymap['b'] = 200;
		mymap['c'] = 300;
		mymap2['a'] = 100;
		mymap2['b'] = 200;
		mymap2['c'] = 300;

		char highest = mymap.rbegin()->first;	// key value of last element
		char highest2 = mymap2.rbegin()->first; // key value of last element

		std::map<char, int>::iterator it = mymap.begin();
		ft::map<char, int>::iterator it2 = mymap2.begin();
		do
		{
			(it->first == it2->first && it->second == it2->second) ? testOk() : testKo();
		} while (mycomp((*it++).first, highest) && mycomp2((*it2++).first, highest2));
		std::cout << std::endl;
	}
	{
		std::cout << "value_comp\t";
		std::map<char, int> mymap;
		ft::map<char, int> mymap2;

		mymap['x'] = 1001;
		mymap['y'] = 2002;
		mymap['z'] = 3003;
		mymap2['x'] = 1001;
		mymap2['y'] = 2002;
		mymap2['z'] = 3003;

		std::pair<char, int> highest = *mymap.rbegin();	 // last element
		ft::pair<char, int> highest2 = *mymap2.rbegin(); // last element

		std::map<char, int>::iterator it = mymap.begin();
		ft::map<char, int>::iterator it2 = mymap2.begin();
		do
		{
			(it->first == it2->first && it->second == it2->second) ? testOk() : testKo();

		} while (mymap.value_comp()(*it++, highest) && mymap2.value_comp()(*it2++, highest2));
		std::cout << std::endl;
	}
	std::cout << UCYN "Test operators" RESET << std::endl;
	{
		std::cout << "find\t\t";
		std::map<char, int> mymap;
		std::map<char, int>::iterator it;
		ft::map<char, int> mymap2;
		ft::map<char, int>::iterator it2;

		mymap['a'] = 50;
		mymap['b'] = 100;
		mymap['c'] = 150;
		mymap['d'] = 200;
		mymap2['a'] = 50;
		mymap2['b'] = 100;
		mymap2['c'] = 150;
		mymap2['d'] = 200;

		it = mymap.find('b');
		if (it != mymap.end())
			mymap.erase(it);
		it2 = mymap2.find('b');
		if (it2 != mymap2.end())
			mymap2.erase(it2);

		(mymap.find('a')->second == mymap2.find('a')->second) ? testOk() : testKo();
		(mymap.find('c')->second == mymap2.find('c')->second) ? testOk() : testKo();
		(mymap.find('d')->second == mymap2.find('d')->second) ? testOk() : testKo();

		std::cout << std::endl;
	}
	{
		std::cout << "count\t\t";

		std::map<char, int> mymap;
		ft::map<char, int> mymap2;
		char c;

		mymap['a'] = 101;
		mymap['c'] = 202;
		mymap['f'] = 303;
		mymap2['a'] = 101;
		mymap2['c'] = 202;
		mymap2['f'] = 303;

		for (c = 'a'; c < 'h'; c++)
		{
			(mymap.count(c) == mymap2.count(c)) ? testOk() : testKo();
		}
		std::cout << std::endl;
	}
	{
		std::cout << "lower_bound\t";
		std::map<char, int> mymap;
		std::map<char, int>::iterator itlow, itup;
		ft::map<char, int> mymap2;
		ft::map<char, int>::iterator itlow2, itup2;

		mymap['a'] = 20;
		mymap['b'] = 40;
		mymap['c'] = 60;
		mymap['d'] = 80;
		mymap['e'] = 100;
		mymap2['a'] = 20;
		mymap2['b'] = 40;
		mymap2['c'] = 60;
		mymap2['d'] = 80;
		mymap2['e'] = 100;

		itlow = mymap.lower_bound('b');	  // itlow points to b
		itup = mymap.upper_bound('d');	  // itup points to e (not d!)
		itlow2 = mymap2.lower_bound('b'); // itlow points to b
		itup2 = mymap2.upper_bound('d');  // itup points to e (not d!)

		mymap.erase(itlow, itup);	 // erases [itlow,itup)
		mymap2.erase(itlow2, itup2); // erases [itlow,itup)

		ft::map<char, int>::iterator it2 = mymap2.begin();
		for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		{
			(it->first == it2->first && it->second == it2->second) ? testOk() : testKo();
			++it2;
		}

		std::cout << std::endl;
	}
	{
		std::cout << "upper_bound\t";

		std::map<char, int> mymap;
		std::map<char, int>::iterator itlow, itup;
		ft::map<char, int> mymap2;
		ft::map<char, int>::iterator itlow2, itup2;

		mymap['a'] = 20;
		mymap['b'] = 40;
		mymap['c'] = 60;
		mymap['d'] = 80;
		mymap['e'] = 100;
		mymap2['a'] = 20;
		mymap2['b'] = 40;
		mymap2['c'] = 60;
		mymap2['d'] = 80;
		mymap2['e'] = 100;

		itlow = mymap.lower_bound('b');	  // itlow points to b
		itup = mymap.upper_bound('d');	  // itup points to e (not d!)
		itlow2 = mymap2.lower_bound('b'); // itlow points to b
		itup2 = mymap2.upper_bound('d');  // itup points to e (not d!)

		mymap.erase(itlow, itup);	 // erases [itlow,itup)
		mymap2.erase(itlow2, itup2); // erases [itlow,itup)

		ft::map<char, int>::iterator it2 = mymap2.begin();
		for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		{
			(it->first == it2->first && it->second == it2->second) ? testOk() : testKo();
			++it2;
		}

		std::cout << std::endl;
	}
	{
		std::cout << "equal_range\t";
		std::map<char, int> mymap;
		ft::map<char, int> mymap2;

		mymap['a'] = 10;
		mymap['b'] = 20;
		mymap['c'] = 30;
		mymap2['a'] = 10;
		mymap2['b'] = 20;
		mymap2['c'] = 30;

		std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator> ret;
		ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> ret2;
		ret = mymap.equal_range('b');
		ret2 = mymap2.equal_range('b');

		(ret.first->first == ret2.first->first && ret.first->second == ret2.first->second) ? testOk() : testKo();
		(ret.second->first == ret2.second->first && ret.second->second == ret2.second->second) ? testOk() : testKo();

		std::cout << std::endl;
	}
	std::cout << UCYN "Test allocators" RESET << std::endl;
	{
		std::cout << "get_allocator\t";
		int psize;
		std::map<char, int> mymap;
		std::pair<const char, int> *p;
		int psize2;
		ft::map<char, int> mymap2;
		ft::pair<const char, int> *p2;

		// allocate an array of 5 elements using mymap's allocator:
		p = mymap.get_allocator().allocate(5);
		p2 = mymap2.get_allocator().allocate(5);

		// assign some values to array
		psize = sizeof(std::map<char, int>::value_type) * 5;
		psize2 = sizeof(ft::map<char, int>::value_type) * 5;

		(psize == psize2) ? testOk() : testKo();

		mymap.get_allocator().deallocate(p, 5);
		mymap2.get_allocator().deallocate(p2, 5);

		std::cout << std::endl;
	}
	std::cout << UCYN "Test rendiment" RESET << std::endl;
	{
		testMapSubject();
	}
}

int main( void )
{
	// iteratorsTest();
	// riteratorsTests();
	// vectorsTest();

    // mapTest();

	// std::map<int, std::string> myMap2;

    // // Insert root node
    // myMap2.insert(std::make_pair(5, "five"));

    // // Insert child nodes
    // myMap2.insert(std::make_pair(2, "two"));
    // myMap2.insert(std::make_pair(8, "eight"));

    // // Insert grandchild nodes
    // myMap2.insert(std::make_pair(1, "one"));
    // myMap2.insert(std::make_pair(4, "four"));
    // myMap2.insert(std::make_pair(6, "six"));
    // myMap2.insert(std::make_pair(7, "seven"));
    // myMap2.insert(std::make_pair(3, "three"));

    // // Insert new leaf node
    // myMap2.insert(std::make_pair(0, "zero"));

	// std::map<int, std::string> myMap4;
	// myMap2.erase(++(++(myMap2.begin())));
	// std::map<int, std::string>::iterator it2 = myMap2.begin();
	// std::map<int, std::string>::iterator end2 = --myMap2.end();
	// myMap4.insert(it2, end2);
	// myMap4.erase(5);
	// myMap4.erase(7);
    // // Print out key-value pairs
    // for (std::map<int, std::string>::iterator it = myMap4.begin(); it != myMap4.end(); ++it) {
    //     std::cout << it->first << ": " << it->second << std::endl;
    // }
	// std::cout << "--> " << myMap4.upper_bound(-1)->first << std::endl;

    // std::cout << "----------------------------" << std::endl;

    ft::map<int, std::string> myMap;

    // Insert root node
    myMap.insert(ft::make_pair(5, "five"));

    // Insert child nodes
    myMap.insert(ft::make_pair(2, "two"));
    myMap.insert(ft::make_pair(8, "eight"));

    // Insert grandchild nodes
    myMap.insert(ft::make_pair(1, "one"));
    myMap.insert(ft::make_pair(4, "four"));
    myMap.insert(ft::make_pair(6, "six"));
    myMap.insert(ft::make_pair(7, "seven"));
    myMap.insert(ft::make_pair(3, "three"));

    // Insert new leaf node
    myMap.insert(ft::make_pair(0, "zero"));

    // Print out key-value pairs

	ft::map<int, std::string> myMap3;
	myMap.erase(++(++(myMap.begin())));
	ft::map<int, std::string>::iterator it1 = myMap.begin();
	ft::map<int, std::string>::iterator end1 = --myMap.end();
	myMap3.insert(it1, end1);
	myMap3.erase(5);
	myMap3.erase(7);
    std::cout << "-------------" << std::endl;
    for (ft::map<int, std::string>::reverse_iterator it = myMap3.rbegin(); it != myMap3.rend(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
        break;
    }
	std::cout << "--> " << myMap3.upper_bound(0)->first << std::endl;
    std::cout << "FINISH" << std::endl;
}