#ifndef	ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>
# include <nullptr_t.hpp>

/**
 * Iterators have some special things:
 * - base iterator
 * - iterator_traits
 * 
 * The base class iterator has all the parameters that a iterator needs:
 * - value_type
 * - difference_type;
 * - pointer;
 * - reference;
 * - iterator category
 * 
 * This parameters are set inside the <container> class. Each container usese a different tipe of iterator 
 * (for example, vectors use the random_access_iterator and map uses the bidirectional iterator). Each of this iterator types
 * have more or less propieties.
 * 
 * The iterator_traits are used for accessing the information about a specific iterator.
 * 
 */

namespace	ft
{
	struct	random_access_iterator_tag	{};
	struct	bidirectional_iterator_tag	{};

	template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef	T			value_type;
		typedef	Distance	difference_type;
		typedef	Pointer		pointer;
		typedef	Reference	reference;
		typedef	Category	iterator_category;
	};

	template <class Iterator>
	struct iterator_traits
	{
		typedef	typename	Iterator::value_type		value_type;
		typedef	typename	Iterator::difference_type	difference_type;
		typedef	typename	Iterator::pointer			pointer;
		typedef	typename	Iterator::reference			reference;
		typedef	typename	Iterator::iterator_category	iterator_category;
	};

	template <class T>
	class iterator_traits<T*>
	{
		typedef	T								value_type;
		typedef	std::ptrdiff_t					difference_type;
		typedef T*								pointer;
		typedef	T&								reference;
		typedef	ft::random_access_iterator_tag	iterator_category;
	};

	template <class T>
	class iterator_traits<const T*>
	{
		typedef	T								value_type;
		typedef	std::ptrdiff_t					difference_type;
		typedef const T*						pointer;
		typedef	const T&						reference;
		typedef	ft::random_access_iterator_tag	iterator_category;
	};

	template <class T>
	class random_access_iterator: public ft::iterator<ft::random_access_iterator_tag, T>
	{
		public:

			typedef	typename	ft::iterator<ft::random_access_iterator_tag, T>	base;
			typedef	typename	base::pointer									pointer;
			typedef	typename	base::reference									reference;
			typedef	typename	base::difference_type							difference_type;

		private:
			pointer	_ptr;

		public:

			random_access_iterator( void );
			random_access_iterator( pointer ptr );
			random_access_iterator( const random_access_iterator &r );

			virtual ~random_access_iterator(){};

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
	ft::random_access_iterator<T>	operator+( typename ft::random_access_iterator<T>::difference_type n, const ft::random_access_iterator<T> &r );
	
	class bidirectional_iterator: public ft::iterator<ft::bidirectional_iterator_tag, int, int, int*, int&>
	{
		private:
			/* data */
		public:
			bidirectional_iterator( void );
			~bidirectional_iterator( void );
	};
	
}

# include <iterator.ipp>

#endif