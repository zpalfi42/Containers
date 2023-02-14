#ifndef	VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <iterator>
# include <enable_if.hpp>
# include <is_integral.hpp>
# include <nullptr_t.hpp>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:

			/** @typedef value_type refers to the type of the value passed as parameter for the template. */
			typedef				T									value_type;

			/** @typedef allocator_type refers to the type of the allocator in function of the value passed as parameter for the template. */
			typedef				Alloc								allocator_type;

			/** @typedef reference is the type of allocator_type::reference. */
			typedef	typename	allocator_type::reference			reference;

			/** @typedef const_reference is the type of allocator_type::const_reference. */
			typedef	typename	allocator_type::const_reference		const_reference;

			/** @typedef pointer is the type of allocator_type::pointer */
			typedef	typename	allocator_type::pointer				pointer;

			/** @typedef const_pointer is the type of allocator_type::const_pointer. */
			typedef	typename	allocator_type::const_pointer		const_pointer;

			/** @typedef difference_type is the type of std::ptrdiff_t. */
			typedef	std::ptrdiff_t						difference_type;

			/** @typedef size_type is the type of std::size_t. */
			typedef	std::size_t							size_type;

			/** @typedef iterator is the type of ft::iterator with value_type and difference_type passed as parameter to its template. */
			typedef	std::iterator<value_type, difference_type>	iterator;

			/** @typedef const iterator is the type of ft::iterator with value_type and difference_type passed as parameter to its template. */
			typedef	std::iterator<value_type, difference_type>	const_iterator;

			/** @typedef reverse_iterator is the type of ft::reverse_iterator with iterator passed as parameter to its template. */
			typedef	std::reverse_iterator<iterator>		reverse_iterator;

			/** @typedef const_reverse_iterator is the type of ft::reverse_iterator with iterator passed as parameter to its template. */
			typedef	std::reverse_iterator<iterator>		const_reverse_iterator;

			/**
			 * @brief Empty container constructor (default constructor):
			 * Constructs an empty container, with no elements.
			 * 
			 * @tparam T 
			 * @tparam Alloc 
			 * @param alloc 
			 */
			explicit	vector( const allocator_type& alloc = allocator_type() );

			/**
			 * @brief  Fill constructor: 
			 * Constructs a container with n elements. Each element is a copy of val.
			 * 
			 * @tparam T 
			 * @tparam Alloc 
			 * @param n 
			 * @param val 
			 * @param alloc 
			 */
			explicit 	vector ( size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type() );

			/**
			 * @brief Range constructor:
			 * Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.
			 * 
			 * @tparam T 
			 * @tparam Alloc 
			 * @tparam InputIterator 
			 * @param first 
			 * @param last 
			 * @param alloc 
			 */
			template<typename InputIterator>
			vector( InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0 );

			/**
			 * @brief Copy constructor: 
			 * Constructs a container with a copy of each of the elements in x, in the same order.
			 * 
			 * @tparam T 
			 * @tparam Alloc 
			 * @param v 
			 */
			vector( const vector &x );

			/**
			 * @brief Vector destructor:
			 * This destroys all container elements, and deallocates all the storage capacity allocated by the vector using its allocator.
			 * 
			 * @tparam T 
			 * @tparam Alloc 
			 */
			~vector( void );

			vector			&operator=( const vector &x );

			size_type		size( void ) const;

			size_type		max_size( void ) const;

			size_type		capacity( void ) const;

			bool			empty( void ) const;

			void			reserve( size_type n );
	
			void			resize( size_type n, value_type val = value_type() );

			void			shrink_to_fit( void );

			reference		operator[](size_type n );

			const_reference	operator[](size_type n ) const;

			reference		at( size_type n );

			const_reference	at( size_type n ) const;

			reference		front( void );

			const_reference	front( void ) const;

			reference		back( void );

			const_reference	back( void ) const;

			value_type		*data( void );

			const value_type		*data( void ) const;

			template< class InputIterator>
			void	assign(InputIterator first, InputIterator last);

			void	assign(size_type n, const value_type &val);

			void			clear( void );

		private:
			allocator_type	_alloc;
			pointer			_start;
			pointer			_end;
			pointer			_capacity;
	};
}

# include	<vector.ipp>

#endif