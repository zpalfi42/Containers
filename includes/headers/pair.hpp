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

			pair( void );

			pair( const first_type &x, const second_type &y );

			template< class U1, class U2 >
			pair( const pair<U1, U2> &p );

			pair& operator=( const pair& other );
	};

	template< class T1, class T2 >
	ft::pair<T1, T2>	make_pair( T1 t, T2 u )
	{
		return(ft::pair(t,u));
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