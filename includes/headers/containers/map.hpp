#ifndef	MAP_HPP
# define MAP_HPP

# include <iterator.hpp>
# include <pair.hpp>
# include <node.hpp>
# include <enable_if.hpp>
# include <is_integral.hpp>

namespace ft
{
	template <class Compare, class T>
	class comp
	{
	public:
		comp(Compare c) : _comp(c) {}

		bool operator()(const T &x, const T &y) const
		{
			return _comp(x.first, y.first);
		}

		Compare _comp;
	};

	template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator< ft::pair<const Key, T> > >
	class map
	{
		public:
		
			typedef	Key										key_type;
			typedef	T										mapped_type;
			typedef	ft::pair<const Key, T>					value_type;
			typedef	std::size_t								size_type;
			typedef	Compare									key_compare;
			typedef ft::comp<Compare, value_type>			value_compare;
			typedef	Allocator								allocator_type;
			typedef	value_type&								reference;
			typedef const value_type&						const_reference;
			typedef	typename Allocator::pointer				pointer;
			typedef	typename Allocator::const_pointer		const_pointer;
			typedef	ft::bidirectional_iterator<value_type>	iterator;
			typedef	ft::bidirectional_iterator<value_type>	const_iterator;
			typedef	ft::reverse_iterator<iterator>			reverse_iterator;
			typedef	ft::reverse_iterator<iterator>			const_reverse_iterator;

		private:

			typedef		ft::node<value_type>			node_type;
			typename	allocator_type::template	rebind<node_type>::other _allocNode;

			size_type		_size;
			node_type*		_root;
			node_type*		_min;
			allocator_type	_allocator;
			key_compare		_comp;

			ft::pair<iterator, bool>	min( void );
			ft::pair<iterator, bool>	max( void );

			ft::pair<iterator, bool>	min( void ) const;
			ft::pair<iterator, bool>	max( void ) const;

			void	clearNodes( node_type *node );

		public : 

			map( const allocator_type& alloc = allocator_type() );
			
			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );
			map( const map& other );
			~map( void );

			map &operator=( const map &other );

			allocator_type	get_allocator( void ) const;

			mapped_type	&at( const Key &key );
			mapped_type	&operator[]( const Key &key );

			iterator			begin( void );
			const_iterator		begin( void ) const;
			iterator			end( void );
			const_iterator		end( void ) const;

			reverse_iterator		rbegin( void );
			const_reverse_iterator	rbegin( void ) const;
			reverse_iterator		rend( void );
			const_reverse_iterator	rend( void ) const;

			bool	empty( void ) const;

			size_type	size( void ) const;
			size_type	max_size( void ) const;

			void	clear( void );

			ft::pair<iterator, bool>	insert( const value_type &val );
			iterator					insert( iterator pos, const value_type &val );
			template< class InputIt >
			void						insert( InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value>::type * = 0 );

			iterator	erase( iterator pos );
			iterator erase( iterator first, iterator last );
			size_type	erase( const Key &key );

			void	swap( map &other );

			size_type	count( const Key &key ) const;


			iterator	find( const Key &key );
			const_iterator	find( const Key &key ) const;

			ft::pair<iterator, iterator>	equal_range( const Key &key );
			ft::pair<const_iterator, const_iterator>	equal_range( const Key &key ) const;

			iterator	lower_bound( const Key &key );
			const_iterator	lower_bound( const Key &key ) const;
			iterator	upper_bound( const Key &key );
			const_iterator	upper_bound( const Key &key ) const;
				
			
			Compare	key_comp( void ) const;
			value_compare value_comp() const;
	
	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs )
	{
		if  (lhs. size () != rhs. size ()) 
			return   false  ; 
		typename  map<Key, T>::const_iterator it1 = lhs.begin(); 
		typename  map<Key, T>::const_iterator it2 = rhs.begin(); 

		while  (it1 != lhs.end() && it2 != rhs.end()) 
		{ 
			if  (*it1 != *it2) 
				return	false; 
			it1++; 
			it2++; 
		} 
		return  (it1 == lhs.end()) && (it2 == rhs.end());
	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs )
	{
		return (!(lhs == rhs));
	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs )
	{
		typename  map<Key, T>::const_iterator it1 = lhs.begin(); 
		typename  map<Key, T>::const_iterator it2 = rhs.begin(); 

		while  (it1 != lhs.end() && it2 != rhs.end()) 
		{ 
			if  (*it1 < *it2) 
				return  true ; 
			if  (*it1 > *it2) 
				return   false  ; 
			it1++; 
			it2++; 
		} 
		return  (it1 == lhs.end()) && (it2 != rhs.end()); 
	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs )
	{
		return (!(rhs < lhs));
	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs )
	{
		return (rhs < lhs);
	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs )
	{
		return (!(lhs < rhs));
	};

	template< class Key, class T, class Compare, class Alloc >
	void swap( ft::map<Key, T, Compare, Alloc>& lhs, ft::map<Key, T, Compare, Alloc>& rhs )
	{
		lhs.swap(rhs);
	};
}

#include <map.ipp>

#endif