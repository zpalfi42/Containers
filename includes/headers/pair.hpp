#ifndef	PAIR_HPP
# define	PAIR_HPP

# include <iostream>

namespace ft
{
	template< class T1, class T2 >
	class pair
	{
		public:
			typedef	T	first_type;
			typedef T	second_type;

			first_type	_first;
			second_type	_second;

			pair( void ): _first(), _second()
			{
			};

			pair( const first_type &x, const second_type &y ): _first(x), _second(y)
			{

			};

			template< class U1, class U2 >
			pair( const pair<U1, U2> &p )
			{
				
			};

			pair& operator=( const pair& other );

	};

	template< class T1, class T2 >
	ft::pair<T1, T2>	make_pair( T1 t, T2 u )
	{
	}

	template< class T1, class T2, class U1, class U2 >
	bool operator==( const ft::pair<T1, T2>& lhs, const ft::pair<U1, U2>& rhs )
	{
	}

	template< class T1, class T2, class U1, class U2 >
	bool operator!=( const ft::pair<T1, T2>& lhs, const ft::pair<U1, U2>& rhs )
	{
	}

	template< class T1, class T2, class U1, class U2 >
	bool operator<( const ft::pair<T1, T2>& lhs, const ft::pair<U1, U2>& rhs )
	{
	}

	template< class T1, class T2, class U1, class U2 >
	bool operator<=( const ft::pair<T1, T2>& lhs, const ft::pair<U1, U2>& rhs )
	{
	}

	template< class T1, class T2, class U1, class U2 >
	bool operator>( const ft::pair<T1, T2>& lhs, const ft::pair<U1, U2>& rhs )
	{
	}

	template< class T1, class T2, class U1, class U2 >
	bool operator>=( const ft::pair<T1, T2>& lhs, const ft::pair<U1, U2>& rhs )
	{
	}
}

#endif