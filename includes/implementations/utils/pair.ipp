#ifndef	PAIR_IPP
# define PAIR_IPP

#include <pair.hpp>

template< class T1, class T2 >
ft::pair<T1,T1>( void ): _first(), _second()
{
}

template< class T1, class T2 >
ft::pair<T1,T1>( const typedef ft::pait<T1,T2>::first_type &x, const typedef ft::pait<T1,T2>::second_type &y ): _first(x), _second(y)
{
}

template< class T1, class T2 >
template< class U1, class U2 >
ft::pair<T1,T1>( const pair<U1, U2> &p ): _first(p._first), _second(p._second)
{
}

template< class T1, class T2 >
ft::pair<T1, T2> &ft::pair<T1, T2>::operator=( const ft::pair<T1, T2>& other )
{
	if (this!=&other)
	{
		this->_first = other._first;
		this->_second = other._second;
	}
	return(*this);
};

#endif