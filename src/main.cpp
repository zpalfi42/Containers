#include <tests.hpp>

int main( void )
{
	iteratorsTest();
	riteratorsTests();
	vectorsTest();


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
    myMap.insert(myMap.end(),ft::make_pair(0, "zero"));

    // Print out key-value pairs
    for (ft::map<int, std::string>::iterator it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    std::cout << "----------------------------" << std::endl;

    std::map<int, std::string> myMap2;

    // Insert root node
    myMap2.insert(std::make_pair(5, "five"));

    // Insert child nodes
    myMap2.insert(std::make_pair(2, "two"));
    myMap2.insert(std::make_pair(8, "eight"));

    // Insert grandchild nodes
    myMap2.insert(std::make_pair(1, "one"));
    myMap2.insert(std::make_pair(4, "four"));
    myMap2.insert(std::make_pair(6, "six"));
    myMap2.insert(std::make_pair(7, "seven"));
    myMap2.insert(std::make_pair(3, "three"));

    // Insert new leaf node
    myMap2.insert(myMap2.end(),std::make_pair(0, "zero"));

    // Print out key-value pairs
    for (std::map<int, std::string>::iterator it = myMap2.begin(); it != myMap2.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}