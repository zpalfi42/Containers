#ifndef	VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <iterator>
# include <enable_if.hpp>
# include <is_integral.hpp>
# include <nullptr_t.hpp>
# include <iterator.hpp>
# include <lexicalographical_compare.hpp>

namespace ft
{
	template< class InputIterator >
	size_t	distance( InputIterator first, InputIterator last )
	{
		size_t	result = 0;

		while ((first + result) != last)
			result++;
		return (result);
	}

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
			typedef	ft::random_access_iterator<T>	iterator;

			/** @typedef const iterator is the type of ft::iterator with value_type and difference_type passed as parameter to its template. */
			typedef	ft::random_access_iterator<T>	const_iterator;

			/** @typedef reverse_iterator is the type of ft::reverse_iterator with iterator passed as parameter to its template. */
			typedef	ft::reverse_iterator<iterator>		reverse_iterator;

			/** @typedef const_reverse_iterator is the type of ft::reverse_iterator with iterator passed as parameter to its template. */
			typedef	ft::reverse_iterator<const_iterator>		const_reverse_iterator;

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

			/**
			 * @brief Operator = : Assigns new contents to the container, replacing its current contents, and modifying its size accordingly.
			 * 
			 * @param x 
			 * @return vector& 
			 */
			vector			&operator=( const vector &x );

			allocator_type	get_allocator( void );

			iterator	begin( void );

			const_iterator	begin( void ) const;

			iterator	end( void );
			 
			const_iterator	end( void ) const;

			reverse_iterator	rbegin( void );

			const_reverse_iterator	rbegin( void ) const;

			reverse_iterator	rend( void );

			const_reverse_iterator	rend( void ) const;

			/**
			 * @brief Returns the number of elements in the vector. This is the number of actual objects held in the vector, which is not necessarily equal to its storage capacity.
			 * 
			 * @return size_type 
			 */
			size_type		size( void ) const;

			/**
			 * @brief Returns the maximum number of elements that the vector can hold. This is the maximum potential size the container can reach due to known 
			 * system or library implementation limitations, but the container is by no means guaranteed to be able to reach that size: it can still fail to 
			 * allocate storage at any point before that size is reached.
			 * 
			 * @return size_type 
			 */
			size_type		max_size( void ) const;

			/**
			 * @brief Resizes the container so that it contains n elements.
			 * If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them). 
			 * If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n.
			 * If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.
			 * If n is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.
			 * Notice that this function changes the actual content of the container by inserting or erasing elements from it.
			 * 
			 * @return size_type 
			 */
			void			resize( size_type n, value_type val = value_type() );

			/**
			 * @brief Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
			 * This capacity is not necessarily equal to the vector size. It can be equal or greater, with the extra space allowing 
			 * to accommodate for growth without the need to reallocate on each insertion. Notice that this capacity does not suppose 
			 * a limit on the size of the vector. When this capacity is exhausted and more is needed, it is automatically expanded by 
			 * the container (reallocating it storage space). The theoretical limit on the size of a vector is given by member max_size.
			 * The capacity of a vector can be explicitly altered by calling member vector::reserve.
			 * 
			 * @return size_type 
			 */
			size_type		capacity( void ) const;

			/**
			 * @brief Returns whether the vector is empty (i.e. whether its size is 0). This function does not modify the container in any way. 
			 * To clear the content of a vector, see vector::clear.
			 * 
			 * @return true 
			 * @return false 
			 */
			bool			empty( void ) const;

			/**
			 * @brief Requests that the vector capacity be at least enough to contain n elements. 
			 * If n is greater than the current vector capacity, the function causes the container to reallocate its storage increasing its capacity 
			 * to n (or greater). In all other cases, the function call does not cause a reallocation and the vector capacity is not affected. 
			 * This function has no effect on the vector size and cannot alter its elements.
			 * 
			 * @param n 
			 */
			void			reserve( size_type n );

			/**
			 * @brief Requests the container to reduce its capacity to fit its size. The request is non-binding, and the container implementation is free 
			 * to optimize otherwise and leave the vector with a capacity greater than its size. This may cause a reallocation, but has no effect on the 
			 * vector size and cannot alter its elements.
			 * 
			 */
			void			shrink_to_fit( void );

			/**
			 * @brief Returns a reference to the element at position n in the vector container. A similar member function, vector::at, has the same behavior 
			 * as this operator function, except that vector::at is bound-checked and signals if the requested position is out of range by throwing an out_of_range 
			 * exception. Portable programs should never call this function with an argument n that is out of range, since this causes undefined behavior.
			 * 
			 * @param n 
			 * @return reference 
			 */
			reference		operator[](size_type n );

			/**
			 * @brief Returns a reference to the element at position n in the vector container. A similar member function, vector::at, has the same behavior 
			 * as this operator function, except that vector::at is bound-checked and signals if the requested position is out of range by throwing an out_of_range 
			 * exception. Portable programs should never call this function with an argument n that is out of range, since this causes undefined behavior.
			 * 
			 * @param n 
			 * @return const_reference
			 */
			const_reference	operator[](size_type n ) const;

			/**
			 * @brief Returns a reference to the element at position n in the vector. The function automatically checks whether n is within the bounds of valid elements 
			 * in the vector, throwing an out_of_range exception if it is not (i.e., if n is greater than, or equal to, its size). This is in contrast with member operator[], 
			 * that does not check against bounds.
			 * 
			 * @param n 
			 * @return reference 
			 */
			reference		at( size_type n );

			/**
			 * @brief Returns a reference to the element at position n in the vector. The function automatically checks whether n is within the bounds of valid elements 
			 * in the vector, throwing an out_of_range exception if it is not (i.e., if n is greater than, or equal to, its size). This is in contrast with member operator[], 
			 * that does not check against bounds.
			 * 
			 * @param n 
			 * @return const_reference 
			 */
			const_reference	at( size_type n ) const;

			/**
			 * @brief Returns a reference to the first element in the vector. Unlike member vector::begin, which returns an iterator to this same element, this function returns 
			 * a direct reference. Calling this function on an empty container causes undefined behavior.
			 * 
			 * @return reference 
			 */
			reference		front( void );

			/**
			 * @brief Returns a reference to the first element in the vector. Unlike member vector::begin, which returns an iterator to this same element, this function returns 
			 * a direct reference. Calling this function on an empty container causes undefined behavior.
			 * 
			 * @return const_reference 
			 */
			const_reference	front( void ) const;

			/**
			 * @brief Returns a reference to the last element in the vector. Unlike member vector::end, which returns an iterator just past this element, this function returns a 
			 * direct reference. Calling this function on an empty container causes undefined behavior.
			 * 
			 * @return reference 
			 */
			reference		back( void );

			/**
			 * @brief Returns a reference to the last element in the vector. Unlike member vector::end, which returns an iterator just past this element, this function returns a 
			 * direct reference. Calling this function on an empty container causes undefined behavior.
			 * 
			 * @return const_reference 
			 */
			const_reference	back( void ) const;

			/**
			 * @brief Returns a direct pointer to the memory array used internally by the vector to store its owned elements. Because elements in the vector are guaranteed to be 
			 * stored in contiguous storage locations in the same order as represented by the vector, the pointer retrieved can be offset to access any element in the array.
			 * 
			 * @return value_type* 
			 */
			value_type		*data( void );

			/**
			 * @brief Returns a direct pointer to the memory array used internally by the vector to store its owned elements. Because elements in the vector are guaranteed to be 
			 * stored in contiguous storage locations in the same order as represented by the vector, the pointer retrieved can be offset to access any element in the array.
			 * 
			 * @return const value_type* 
			 */
			const value_type		*data( void ) const;

			/**
			 * @brief Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly. The new contents are elements constructed from each of 
			 * the elements in the range between first and last, in the same order. Any elements held in the container before the call are destroyed and replaced by newly constructed 
			 * elements (no assignments of elements take place). This causes an automatic reallocation of the allocated storage space if -and only if- the new vector size surpasses the 
			 * current vector capacity.
			 * 
			 * @tparam InputIterator 
			 * @param first 
			 * @param last 
			 */
			template< class InputIterator>
			void	assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0);

			/**
			 * @brief Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly. The new contents are n elements, each initialized to a copy of val.
			 * Any elements held in the container before the call are destroyed and replaced by newly constructed elements (no assignments of elements take place). This causes an automatic 
			 * reallocation of the allocated storage space if -and only if- the new vector size surpasses the current vector capacity.
			 * 
			 * @param n 
			 * @param val 
			 */
			void	assign(size_type n, const value_type &val);

			void	push_back( const value_type &val );

			void	pop_back( void );

			iterator	insert( iterator position, const value_type &val );

			void	insert( iterator position, size_type n, const value_type &val);

			template< class InputIterator >
			void	insert( iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0 );

			iterator	erase(iterator position);

			iterator	erase(iterator first, iterator last);

			void		swap( vector &x );

			/**
			 * @brief Removes all elements from the vector (which are destroyed), leaving the container with a size of 0. A reallocation is not guaranteed to happen, and the 
			 * vector capacity is not guaranteed to change due to calling this function.
			 * 
			 */
			void			clear( void );

		private:
			allocator_type	_alloc;
			pointer			_begin;
			pointer			_end;
			pointer			_capacity;
	};

	template< class T, class Alloc>
	bool	operator==( const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size() || lhs.capacity() != rhs.capacity())
			return (false);
		for (size_t i = 0; i < lhs.size(); i++)
		{
			if (lhs[i] != rhs[i])
				return (false);
		}
		return (true);
	}

	template< class T, class Alloc>
	bool	operator!=( const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	template< class T, class Alloc>
	bool	operator<( const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template< class T, class Alloc>
	bool	operator>( const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	template< class T, class Alloc>
	bool	operator<=( const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return (!(lhs > rhs));
	}

	template< class T, class Alloc>
	bool	operator>=( const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}
}

# include	<vector.ipp>

#endif