#ifndef	PAIR_HPP
# define	PAIR_HPP

# include <iostream>

namespace ft
{
	template< class T1, class T2 >
	struct pair
	{
		public:
			typedef	T1	first_type;
			typedef T2	second_type;

			first_type	_first;
			second_type	_second;

			pair( void ): _first(NULL), _second(NULL){};

			pair( const first_type &x, const second_type &y ): _first(x), _second(y){};

			template< class U1, class U2 >
			pair( const pair<U1, U2> &p ): _first(p._first), _second(p._second){};

			pair& operator=( const pair& other )
			{
				if (this!=&other)
				{
					this->_first = other._first;
					this->_second = other._second;
				}
				return (*this);
			};
	};

	template< class T1, class T2 >
	ft::pair<T1, T2>	make_pair( T1 t, T2 u )
	{
		return(ft::pair<T1,T2>(t,u));
	};

	template< class T1, class T2, class U1, class U2 >
	bool operator==( const ft::pair<T1, T2>& lhs, const ft::pair<U1, U2>& rhs )
	{
		return (lhs._first == rhs._first && lhs._second == rhs._second);
	};

	template< class T1, class T2, class U1, class U2 >
	bool operator!=( const ft::pair<T1, T2>& lhs, const ft::pair<U1, U2>& rhs )
	{
		return(!(lhs==rhs));
	};

	template< class T1, class T2, class U1, class U2 >
	bool operator<( const ft::pair<T1, T2>& lhs, const ft::pair<U1, U2>& rhs )
	{
		return(lhs._first < rhs._first || (!rhs.first < lhs.first && lhs._second < rhs._second));
	};

	template< class T1, class T2, class U1, class U2 >
	bool operator<=( const ft::pair<T1, T2>& lhs, const ft::pair<U1, U2>& rhs )
	{
		return(!(rhs<lhs));
	};

	template< class T1, class T2, class U1, class U2 >
	bool operator>( const ft::pair<T1, T2>& lhs, const ft::pair<U1, U2>& rhs )
	{
		return(rhs<lhs);
	};

	template< class T1, class T2, class U1, class U2 >
	bool operator>=( const ft::pair<T1, T2>& lhs, const ft::pair<U1, U2>& rhs )
	{
		return(!(lhs<rhs));
	};
}

#endif