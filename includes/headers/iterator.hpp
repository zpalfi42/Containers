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
		typedef	typename	base::difference_type							difference_type;

	private:
		pointer	_ptr;

	public:

		random_access_iterator( void ): _ptr(ft::nullptr_t)
		{
		};

		random_access_iterator( pointer ptr ): _ptr(ptr)
		{
		};

		random_access_iterator( const random_access_iterator &r ): _ptr(r._ptr)
		{
		};

		virtual ~random_access_iterator()
		{
		};

		T	&operator[]( difference_type n )
		{
			return (*(this->_ptr + n));
		};
		
		T	&operator*( void )
		{
			return (*(this->_ptr));
		};

		pointer	operator->( void )
		{
			return (&(*(this->_ptr)));
		};

		random_access_iterator	&operator=( const random_access_iterator &r )
		{
			if (this != &r)
			{
				this->_ptr = r._ptr;
			}
			return (*this);
		};

		difference_type	operator-( const random_access_iterator &r ) const
		{
			return (this->_ptr - r._ptr);
		};

		random_access_iterator	&operator++( void )
		{
			this->_ptr++;
			return (*this);
		};

		random_access_iterator	operator++( int )
		{
			random_access_iterator	r = *this;
			this->_ptr++;
			return (r);
		};

		random_access_iterator	&operator--( void )
		{
			this->_ptr--;
			return (*this);
		};
		random_access_iterator	operator--( int )
		{
			random_access_iterator	r = *this;
			this->_ptr--;
			return (r);
		};

		random_access_iterator	operator+( difference_type n ) const
		{
			random_access_iterator	it(*this);
			return (it += n);
		};
		random_access_iterator	operator-( difference_type n ) const
		{
			random_access_iterator	it(*this);
			return (it -= n);
		};
		random_access_iterator	&operator+=( difference_type n )
		{
			this->_ptr += n;
			return (*this);
		};
		random_access_iterator	&operator-=( difference_type n)
		{
			this->_ptr -= n;
			return (*this);
		};
		
		bool	operator==( const random_access_iterator &r ) const 
		{
			if (this->_ptr == r._ptr)
				return (true);
			return (false);
		};
		bool	operator!=( const random_access_iterator &r ) const 
		{
			if (this->_ptr != r._ptr)
				return (true);
			return (false);
		};
		bool	operator<( const random_access_iterator &r ) const 
		{
			if (this->_ptr < r._ptr)
				return (true);
			return (false);
		};
		bool	operator>( const random_access_iterator &r ) const 
		{
			if (this->_ptr > r._ptr)
				return (true);
			return (false);
		};
		bool	operator<=( const random_access_iterator &r ) const
		{
			if (this->_ptr <= r._ptr)
				return (true);
			return (false);
		};
		bool	operator>=( const random_access_iterator &r ) const
		{
			if (this->_ptr >= r._ptr)
				return (true);
			return (false);
		};

	};

	template< class T >
	ft::random_access_iterator<T>	operator+( typename ft::random_access_iterator<T>::difference_type n, const ft::random_access_iterator<T> &r )
	{
		return (r + n);
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

// template<class T>
// ft::random_access_iterator<T>::random_access_iterator( void )
// {
// 	std::cout << "Hola" << std::endl;
// }

// template<class T>
// ft::random_access_iterator<T>::~random_access_iterator( void )
// {
// 	std::cout << "Adios" << std::endl;
// }

// template<class T>
// ft::random_access_iterator<T>	&ft::random_access_iterator<T>::operator=( const ft::random_access_iterator<T> &r )
// {
// 	if (this != &r)
// 	{
// 		this->value_type = r->value_type;
// 		this->difference_type = r->difference_type;
// 		this->pointer = r->pointer;
// 		this->reference = r->reference;
// 		this->iterator_category = r->iterator_category;
// 	}
// 	return (*this);
// }

// template<class T>
// ft::random_access_iterator<T>	&ft::random_access_iterator<T>::operator+( const ft::random_access_iterator<T> &r ) const
// {
// 	(void) r;
// }

// template<class T>
// ft::random_access_iterator<T>	&ft::random_access_iterator<T>::operator-( const ft::random_access_iterator<T> &r ) const
// {
// 	(void) r;
// }

// template<class T>
// ft::random_access_iterator<T>	&ft::random_access_iterator<T>::operator++( void )
// {

// }

// template<class T>
// ft::random_access_iterator<T>	&ft::random_access_iterator<T>::operator--( void )
// {

// }

// template<class T>
// ft::random_access_iterator<T>	&ft::random_access_iterator<T>::operator++( int n )
// {
// 	(void) n;
// }

// template<class T>
// ft::random_access_iterator<T>	&ft::random_access_iterator<T>::operator--( int n )
// {
// 	(void) n;
// }

// template<class T>
// ft::random_access_iterator<T>	&ft::random_access_iterator<T>::operator+( int n )
// {
// 	(void) n;
// }

// template<class T>
// ft::random_access_iterator<T>	&ft::random_access_iterator<T>::operator-( int n )
// {
// 	(void) n;
// }

// template<class T>
// ft::random_access_iterator<T>	&ft::random_access_iterator<T>::operator+=( int n )
// {
// 	(void) n;
// }

// template<class T>
// ft::random_access_iterator<T>	&ft::random_access_iterator<T>::operator-=( int n )
// {
// 	(void) n;
// }

// template<class T>
// bool	&ft::random_access_iterator<T>::operator==( const ft::random_access_iterator<T> &r ) const
// {
// 	(void) r;
// }

// template<class T>
// bool	&ft::random_access_iterator<T>::operator!=( const ft::random_access_iterator<T> &r ) const
// {
// 	(void) r;
// }

// template<class T>
// bool	&ft::random_access_iterator<T>::operator<( const ft::random_access_iterator<T> &r ) const
// {
// 	(void) r;
// }

// template<class T>
// bool	&ft::random_access_iterator<T>::operator>( const ft::random_access_iterator<T> &r ) const
// {
// 	(void) r;
// }

// template<class T>
// bool	&ft::random_access_iterator<T>::operator<=( const ft::random_access_iterator<T> &r ) const
// {
// 	(void) r;
// }

// template<class T>
// bool	&ft::random_access_iterator<T>::operator>=( const ft::random_access_iterator<T> &r ) const
// {
// 	(void) r;
// }

// template<class T>
// T	&ft::random_access_iterator<T>::operator*( void )
// {
// 	return (this->_ptr);
// }

// template<class T>
// T	&ft::random_access_iterator<T>::operator[]( int n )
// {
// 	return (this->_ptr + n);
// }

// template<class T>
// T	&ft::random_access_iterator<T>::operator->( void )
// {
	
// }


#endif