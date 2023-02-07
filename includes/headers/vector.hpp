#ifndef	VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <iterator.hpp>

namespace ft
{

	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		private:
			/* data */
		public:

			typedef				T								value_type;
			typedef				Alloc							allocator_type;
			typedef	typename	allocator_type::reference		reference;
			typedef	typename	allocator_type::const_reference	const_reference;
			typedef	typename	allocator_type::pointer			pointer;
			typedef	typename	allocator_type::const_pointer	const_pointer;
			// typedef	typename	std::iterator	iterator;
			// typedef	typename	std::iterator	const_iterator;

			// template < class iterator >
			// class reverse_iterator
			// {

			// };

			// template < class const_iterator >
			// class const_reverse_iterator
			// {

			// };

			typedef	typename	std::ptrdiff_t	difference_type;
			typedef	typename	std::size_t		size_type;

			vector(/* args */);
			~vector();
	};

}

#endif