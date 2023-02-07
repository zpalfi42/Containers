#ifndef	ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>

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
	class random_access_iterator: public iterator<ft::random_access_iterator_tag, T, T, T*, T&>
	{
	private:
		/* data */
	public:
		random_access_iterator( void );
		random_access_iterator( random_access_iterator &r );

		random_access_iterator	&operator=( random_access_iterator &r );

		~random_access_iterator();

		random_access_iterator	&operator++( void );
		
		bool	&operator==( random_access_iterator &r );
		bool	&operator!=( random_access_iterator &r );

		
	};
	
	class bidirectional_iterator: public ft::iterator<ft::bidirectional_iterator_tag, int, int, int*, int&>
	{
		private:
			/* data */
		public:
			bidirectional_iterator( void );
			~bidirectional_iterator( void );
	};
	
}


#endif