#ifndef	MAP_HPP
# define MAP_HPP

# include <iostream>
# include <iterator.hpp>
# include <pair.hpp>
# include <node.hpp>

namespace ft
{
	template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator< ft::pair<const Key, T> > >
	class map
	{
		public:
		
			typedef	Key								key_type;
			typedef	T								mapped_type;
			typedef	ft::pair<const Key, T>			value_type;
			typedef	std::size_t						size_type;
			typedef	Compare							compare;
			typedef	Allocator						allocator_type;
			typedef	value_type&						reference;
			typedef const value_type&				const_reference;
			typedef	Allocator::reference			reference;
			typedef	Allocator::const_pointer		const_pointer;
			typedef	ft::bidirectional_iterator<T>	iterator;
			typedef	ft::bidirectional_iterator<T>	const_iterator;
			typedef	ft::reverse_iterator<iterator>	reverse_iterator;
			typedef	ft::reverse_iterator<iterator>	const_reverse_iterator;

		private:

			typedef	node<value_type>	node_type;

			size_type		_size;
			node_type*		_root;
			allocator_type	_allocator;

		public : 

			map( void );
			
			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );

			map( const map& other );

	};
}
#endif