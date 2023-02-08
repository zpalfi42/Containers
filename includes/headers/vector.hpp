#ifndef	VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <iterator>
# include <enable_if.hpp>
# include <is_integral.hpp>
// # include <iterator.hpp>

namespace ft
{

	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:

			typedef				T									value_type;
			typedef				Alloc								allocator_type;
			typedef	typename	allocator_type::reference			reference;
			typedef	typename	allocator_type::const_reference		const_reference;
			typedef	typename	allocator_type::pointer				pointer;
			typedef	typename	allocator_type::const_pointer		const_pointer;
			typedef	std::ptrdiff_t						difference_type;
			typedef	std::size_t							size_type;
			typedef	std::iterator<T, difference_type>	iterator;
			typedef	std::iterator<T, difference_type>	const_iterator;
			typedef	std::reverse_iterator<iterator>		reverse_iterator;
			typedef	std::reverse_iterator<iterator>		const_reverse_iterator;

			explicit	vector(const allocator_type& alloc = allocator_type());

			explicit 	vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());

			template <class InputIterator>
			vector( InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
			{
				(void) first;
				(void) last;
				(void) alloc;
			};

			vector( const vector &x );

			~vector( void ) {};
		private:
			allocator_type	_alloc;
			pointer			_start;
			pointer			_end;
			pointer			_capacity;
	};

	template < class T, class Alloc>
	ft::vector<T, Alloc>::vector( const allocator_type& alloc): _alloc(alloc), _start(nullptr), _end(nullptr), _capacity(nullptr)
	{
	}

	template < class T, class Alloc>
	ft::vector<T, Alloc>::vector( size_type n, const value_type& val, const allocator_type& alloc ): _alloc(alloc), _start(nullptr), _end(nullptr), _capacity(nullptr)
	{
		std::cout << "HOLA1" << std::endl;
		this->_start = _alloc.allocate(n);
		for (size_t i = 0; i < n; i++)
			this->_alloc.construct(this->_start + i, val);
		this->_capacity = this->_start + n;
		this->_end = this->_start + n;
	}

}

#endif