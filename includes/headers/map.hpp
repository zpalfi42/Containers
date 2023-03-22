#ifndef	MAP_HPP
# define MAP_HPP

# include <iostream>
# include <iterator.hpp>
# include <pair.hpp>
# include <node.hpp>
# include <enable_if.hpp>
# include <is_integral.hpp>

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
			typedef	typename Allocator::pointer			pointer;
			typedef	typename Allocator::const_pointer		const_pointer;
			typedef	ft::bidirectional_iterator<value_type>	iterator;
			typedef	ft::bidirectional_iterator<value_type>	const_iterator;
			typedef	ft::reverse_iterator<iterator>	reverse_iterator;
			typedef	ft::reverse_iterator<iterator>	const_reverse_iterator;

		private:

			typedef		node<value_type>			node_type;
			typename	allocator_type::template	rebind<node_type>::other _allocNode;

			size_type		_size;
			node_type*		_root;
			node_type*		_min;
			allocator_type	_allocator;


			// ft::pair<iterator, bool>	nodeInsert( const value_type &val )
			// {
			// 	node_type n = new ft::node<ft::pair<Key, T> >(val);

			// 	if (this->_root == ft::nullptr_t)
			// 	{
			// 		this->_root = n;
			// 		this->_size++;
			// 		return (ft::make_pair(iterator(this->_root), true));
			// 	}

			// 	node_type	current = this->_root;
			// 	while (current != ft::nullptr_t)
			// 	{
			// 		if (n->_data < current->_data)
			// 		{
			// 			if (current->_left == ft::nullptr_t)
			// 			{
			// 				current->_left = n;
			// 				n->_parent = current;
			// 				this->_size++;
			// 				return (ft::make_pair(iterator(n), true));
			// 			}
			// 			current = current->_left;
			// 		}
			// 		else if (n->_data > current->_data)
			// 		{
			// 			if (current->_right == ft::nullptr_t)
			// 			{
			// 				current->_right = n;
			// 				n->_parent = current;
			// 				this->_size++;
			// 				return (ft::make_pair(iterator(n), true));
			// 			}
			// 			current = current->_right;
			// 		}
			// 		else
			// 		{
			// 			delete n;
			// 			return (ft::make_pair(iterator(current), false));
			// 		}
			// 	}
			// 	return (ft::make_pair(iterator(), false));
			// };

			ft::pair<iterator, bool>	min( void )
			{
				node_type	*current = this->_root;
				while (current != ft::nullptr_t)
				{
					if (current->_left == ft::nullptr_t)
					{
						return (ft::make_pair(iterator(current) , true));
					}
					current = current->_left;
				}
				return (ft::make_pair(iterator(), false));
			}

			ft::pair<iterator, bool>	max( void )
			{
				node_type	*current = this->_root;
				while (current != ft::nullptr_t)
				{
					if (current->_right == ft::nullptr_t)
					{
						return (ft::make_pair(iterator(current), true));
					}
					current = current->_right;
				}
				return (ft::make_pair(iterator(), false));
			}

			void	copyNodes( node_type *dest, const node_type *src )
			{
				if (src->_left != ft::nullptr_t)
				{
					dest->_left = new ft::node<ft::pair<Key, T> >(src->_left->_data);
					dest->_left->_parent = dest;
					copyNodes(dest->_left, src->_left);
				}

				if (src->_right != ft::nullptr_t)
				{
					dest->_right = new ft::node<ft::pair<Key, T> >(src->_right->_data);
					dest->_right->_parent = dest;
					copyNodes(dest->_right, src->_right);
				}
			}

			void	clearNodes( node_type *node )
			{
				if (node->_left != ft::nullptr_t)
					clearNodes(node->_left);
				if (node->_right != ft::nullptr_t)
					clearNodes(node->_right);
				this->_allocator.destroy(&node->_data);
				this->_allocator.deallocate(node, 1);
			};

		public : 

			map( const allocator_type& alloc = allocator_type() ): _size(0), _root(ft::nullptr_t), _allocator(alloc){};
			
			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );

			map( const map& other ): _size(other._size), _root(other._root), _allocator(other._allocator){};

			~map( void ){};

			map &operator=( const map &other )
			{
				if (this!=&other)
				{
					this->clear();
					this->_allocator = other._allocator;
					this->_size = other._size;
					if (other._root)
					{
						this->_root	= new node<ft::pair<Key, T> >(other._root->_data);
						copyNodes(this->_root, other._root);
					}
				}
				return (*this);
			};

			allocator_type	get_allocator( void ) const
			{
				return(this->_allocator);
			};

			mapped_type	&at( const Key &key )
			{
				node_type	*node = this->_root;
				while (node != ft::nullptr_t)
				{
					if (node->_data.first == key)
						return (node->_data._second);
					else if (key < node->_data.first)
						node = node->_left;
					else
						node = node->_right;
				}
				throw(std::out_of_range("map::at:  key not found"));
			};

			mapped_type	&operator[]( const Key &key )
			{
				iterator it = this->find(key);
				if (it == this->end())
				{
					// The key doesn't exist, so insert a new element
					value_type val = ft::make_pair(key, mapped_type());
					it = insert(val).first;
				}
				// The key already exists, so return a reference to its value
				return it->second;
			};

			iterator			begin( void ){ return(this->min().first); };
			const_iterator		begin( void ) const { return(this->min()._irst); };
			iterator			end( void ){ return(this->max().first); };
			const_iterator		end( void ) const { return(this->max().first); };

			reverse_iterator		rbegin( void ){ return(reverse_iterator(this->end())); };
			const_reverse_iterator	rbegin( void ) const { return(reverse_iterator(this->end())); };
			reverse_iterator		rend( void ) { return(reverse_iterator(this->begin())); };
			const_reverse_iterator	rend( void ) const { return(reverse_iterator(this->begin())); };

			bool	empty( void ) const
			{
				return(this->_size == 0);
			};

			size_type	size( void ) const
			{
				return(this->_size);
			};

			size_type	max_size( void ) const
			{
				return(this->_allocator.max_size());
			};

			void	clear( void )
			{
				if (this->_root == ft::nullptr_t)
					return ;
				clearNodes(this->_root);
				this->_root == ft::nullptr_t;
				this->_size = 0;
			};

			ft::pair<iterator, bool>	insert( const value_type &val )
			{
				node_type	*parent = ft::nullptr_t;
				node_type	*node = this->_root;
				while (node != ft::nullptr_t)
				{
					parent = node;
					if (val.first < node->_data.first)
						node = node->_left;
					else if (val.first > node->_data.first)
						node = node->_right;
					else
						return (ft::make_pair(iterator(node), false));
				}

				node_type	*new_node = this->_allocNode.allocate(1);
				this->_allocNode.construct(new_node, node_type(val));

				if (parent == ft::nullptr_t)
					this->_root = new_node;
				else if (val.first < parent->_data.first)
					parent->_left = new_node;
				else
					parent->_right = new_node;

				new_node->_parent = parent;
				++this->_size;
				return (ft::make_pair(iterator(new_node), true));
			};

			iterator					insert( iterator pos, const value_type &val )
			{
				node_type	*new_node = this->_allocNode.allocate(1);
				this->_allocNode.construct(new_node, node_type(val));
				new_node->_left = ft::nullptr_t;
				new_node->_right = ft::nullptr_t;

				if (this->_root == ft::nullptr_t)
				{
					this->_root = new_node;
					++this->_size;
					return (iterator(this->_root));
				}

				if (pos == this->end() || val.first > pos->first)
				{
					if (pos._node->_right != ft::nullptr_t)
					{
						new_node->_right = pos._node->_right;
						pos._node->_right->_parent = new_node;
					}
					pos._node->_right = new_node;
					new_node->_parent = pos._node;
				}
				else if (val.first < pos->first)
				{
					if (pos._node->_left != ft::nullptr_t)
					{
						new_node->_left = pos._node->_left;
						pos._node->_left->_parent = new_node;
					}
					pos._node->_left = new_node;
					new_node->_parent = pos._node;
				}
				else
				{
					pos->second = val.second;
				}
				std::cout << "BBB" << std::endl;
				return (pos);
			};

			template< class InputIt >
			void						insert( InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value>::type * = 0 );

			iterator	erase( iterator pos );
			size_type	erase( const Key &key );

			void	swap( map &other );

			size_type	count( const Key &key ) const;

			iterator	find( const Key &key )
			{
				iterator	it = this->begin();
				iterator	end = this->end();

				while (it != end)
				{
					if (it->first == key)
					{
						return (it);
					}
					++it;
				}
				return it;
			};

			const_iterator	find( const Key &key ) const
			{
				const_iterator	it = this->begin();
				const_iterator	end = this->end();

				while (it != end)
				{
					if (it->first == key)
					{
						return (it);
					}
					++it;
				}
				return it;
			};

			ft::pair<iterator, iterator>	equal_range( const Key &key );
			ft::pair<const_iterator, const_iterator>	equal_range( const Key &key ) const;
			iterator	lower_bound( const Key &key );
			const_iterator	lower_bound( const Key &key ) const;
			iterator	upper_bound( const Key &key );
			const_iterator	upper_bound( const Key &key ) const;
			
			compare	key_compare( void ) const;
	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const std::map<Key, T, Compare, Alloc>& lhs, const std::map<Key, T, Compare, Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const std::map<Key, T, Compare, Alloc>& lhs, const std::map<Key, T, Compare, Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const std::map<Key, T, Compare, Alloc>& lhs, const std::map<Key, T, Compare, Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const std::map<Key, T, Compare, Alloc>& lhs, const std::map<Key, T, Compare, Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const std::map<Key, T, Compare, Alloc>& lhs, const std::map<Key, T, Compare, Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const std::map<Key, T, Compare, Alloc>& lhs, const std::map<Key, T, Compare, Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	void swap( std::map<Key, T, Compare, Alloc>& lhs, std::map<Key, T, Compare, Alloc>& rhs );
}
#endif