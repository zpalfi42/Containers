#ifndef	RANDOM_ACCESS_ITERATOR_HPP
# define	RANDOM_ACCESS_ITERATOR_HPP

# include <iterator.hpp>

namespace	ft
{
	template <class T>
	class random_access_iterator: public ft::iterator<ft::random_access_iterator_tag, T>
	{
		public:

			typedef	typename	ft::iterator<ft::random_access_iterator_tag, T>	base_it;
			typedef	typename	base_it::value_type								value_type;
			typedef	typename	base_it::difference_type						difference_type;
			typedef	typename	base_it::pointer								pointer;
			typedef	typename	base_it::reference								reference;
			typedef	typename	base_it::iterator_category						iterator_category;

		private:
			pointer	_ptr;

		public:

			random_access_iterator( void );
			random_access_iterator( pointer ptr );
			random_access_iterator( const random_access_iterator &r );

			virtual ~random_access_iterator();

			pointer	base( void );

			reference				operator[]( difference_type n );
			reference				operator*( void );
			pointer					operator->( void );

			difference_type			operator-( const random_access_iterator &r ) const;

			random_access_iterator	&operator=( const random_access_iterator &r );
			random_access_iterator	&operator+=( difference_type n );
			random_access_iterator	&operator-=( difference_type n);
			random_access_iterator	&operator++( void );
			random_access_iterator	&operator--( void );

			random_access_iterator	operator+( difference_type n ) const;
			random_access_iterator	operator-( difference_type n ) const;
			random_access_iterator	operator++( int );
			random_access_iterator	operator--( int );
			
			bool					operator==( const random_access_iterator &r ) const ;
			bool					operator!=( const random_access_iterator &r ) const ;
			bool					operator<( const random_access_iterator &r ) const ;
			bool					operator>( const random_access_iterator &r ) const ;
			bool					operator<=( const random_access_iterator &r ) const;
			bool					operator>=( const random_access_iterator &r ) const;
	};

	template< class T >
	ft::random_access_iterator<T>	operator+( typename ft::random_access_iterator<T>::difference_type n, const ft::random_access_iterator<T> &r )
	{
		return (r + n);
	};
}

#include <random_access_iterator.ipp>

#endif