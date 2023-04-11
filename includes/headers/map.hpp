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

			ft::pair<iterator, bool>	min( void ) const
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

			ft::pair<iterator, bool>	max( void ) const
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
				this->_allocNode.deallocate(node, 1);
			};

		public : 

			map( const allocator_type& alloc = allocator_type() ): _size(0), _root(ft::nullptr_t), _allocator(alloc){};
			
			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() )
			{
				this->_root = ft::nullptr_t;
				this->_allocator = alloc;
				this->_size = 0;
				(void) comp;
				this->insert(first, last);
			};

			map( const map& other )
			{
				this->_root = ft::nullptr_t;
				this->_allocator = other._allocator;
				this->_size = 0;
				this->insert(other.begin(), other.end());
			};

			~map( void )
			{
				this->clear();
			};

			map &operator=( const map &other )
			{
				if (this!=&other)
				{
					this->clear();
					this->insert(other.begin(), other.max().first);
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
						return (node->_data.second);
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

			iterator			begin( void )
			{
				return(this->min().first);
			};
			const_iterator		begin( void ) const
			{
				return(this->min().first);
			};
			iterator			end( void )
			{
				iterator	it = this->max().first;
				++it;
				return(it);
			};
			const_iterator		end( void ) const
			{
				const_iterator	it = this->max().first;
				++it;
				return(it);
			};

			reverse_iterator		rbegin( void )
			{
				reverse_iterator rit(this->max().first);
				--rit;
				return(rit);
			};

			const_reverse_iterator	rbegin( void ) const
			{
				const_reverse_iterator rit(this->max().first);
				--rit;
				return(rit);
			};
			
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
				this->_root = ft::nullptr_t;
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
				(void) pos;

				map::iterator	exist = this->find(val.first);

				if (exist != NULL)
				{
					exist->second = val.second;
					return (exist);
				}
				return this->insert(val).first;
			};

			template< class InputIt >
			void						insert( InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value>::type * = 0 )
			{
				while (first != last)
				{
					this->insert(*first);
					first++;
				}
			};

			iterator	erase( iterator pos )
			{
				node_type	*curr = pos._node;
				node_type	*tmp = ft::nullptr_t;

				if (curr == ft::nullptr_t)
					return pos;
				if (curr->hasLeftChild())
				{
					tmp = curr->_left;
					while (42)
					{
						if (tmp->_right == ft::nullptr_t)
							break;
						tmp = tmp->_right;
					}
					tmp->_right = curr->_right;
					if (curr->_right != ft::nullptr_t)
						curr->_right->_parent = tmp;
					tmp = curr->_left;
					tmp->_parent = curr->_parent;
				}
				else if (curr->hasRightChild())
				{
					tmp = curr->_right;

					tmp->_parent = curr->_parent;	
				}
				if (curr->_parent != ft::nullptr_t)
				{
					if (curr->_parent->_right == curr)
						curr->_parent->_right = tmp;
					else
						curr->_parent->_left = tmp;
				}
				else
					this->_root = tmp;
				this->_allocNode.deallocate(curr, 1);
				this->_size--;
				return (iterator(tmp));
			};

			iterator erase( iterator first, iterator last )
			{
				iterator tmp;

				while (first != last)
				{
					tmp = first++;
					this->erase(tmp);
				}
				return (NULL);
			};

			size_type	erase( const Key &key )
			{
				iterator	tmp = this->find(key);

				if (tmp != NULL)
				{
					this->erase(tmp);
					return (1);
				}
				return (0);
			};

			void	swap( map &other )
			{
				node_type	*tmp = this->_root;
				size_type	stmp = this->_size;

				this->_size = other._size;
				other._size = stmp;

				this->_root = other._root;
				other._root = tmp;
			};

			size_type	count( const Key &key ) const
			{
				const_iterator	tmp = this->find(key);

				if (tmp != NULL)
				{
					return (1);
				}
				return (0);
			};

			iterator	find( const Key &key )
			{
				iterator	it = this->begin();
				iterator	end = this->end();

				while (it != end)
				{
					if (it->first == key)
						return (it);
					++it;
				}
				return NULL;
			};

			const_iterator	find( const Key &key ) const
			{
				const_iterator	it = this->begin();
				const_iterator	end = this->end();

				while (it != end)
				{
					if (it->first == key)
						return (it);
					++it;
				}
				return NULL;
			};

			ft::pair<iterator, iterator>	equal_range( const Key &key )
			{
				return (ft::make_pair(lower_bound(key), upper_bound(key)));
			};

			ft::pair<const_iterator, const_iterator>	equal_range( const Key &key ) const
			{
				return (ft::make_pair(lower_bound(key), upper_bound(key)));
			};

			iterator	lower_bound( const Key &key )
			{
				node_type	*tmp = this->_root;
				
				while (42)
				{
					if (!_comp(key, tmp->_data.first) && !_comp(tmp->_data.first, key))
						return (iterator(tmp));
					else if (_comp(key, tmp->_data.first))
						tmp = tmp->_left;
					else if (_comp(tmp->_data.first, key))
						tmp = tmp->_right;
					else
						break ;
				}
				return (NULL);
			};

			const_iterator	lower_bound( const Key &key ) const
			{
				node_type	*tmp = this->_root;
				
				while (42)
				{
					if (!_comp(key, tmp->_data.first) && !_comp(tmp->_data.first, key))
						return (const_iterator(tmp));
					else if (_comp(key, tmp->_data.first))
						tmp = tmp->_left;
					else if (_comp(tmp->_data.first, key))
						tmp = tmp->_right;
					else
						break ;
				}
				return (NULL);
			};

			iterator	upper_bound( const Key &key )
			{
				node_type	*tmp = this->_root;
				
				while (42)
				{
					if (!_comp(key, tmp->_data.first) && !_comp(tmp->_data.first, key))
					{
						if (tmp->_right)
							return (iterator(tmp->_right));
						else if (tmp->_parent && tmp->_parent->_left == tmp)
							return (iterator(tmp->_parent));
						else
							break ;
					}
					else if (_comp(key, tmp->_data.first))
						tmp = tmp->_left;
					else if (_comp(tmp->_data.first, key))
						tmp = tmp->_right;
					else
						break ;
				}
				return (NULL);
			};

			const_iterator	upper_bound( const Key &key ) const
			{
				node_type	*tmp = this->_root;
				
				while (42)
				{
					if (!_comp(key, tmp->_data.first) && !_comp(tmp->_data.first, key))
					{
						if (tmp->_right)
							return (const_iterator(tmp->_right));
						else if (tmp->_parent && tmp->_parent._left == tmp)
							return (const_iterator(tmp->_parent));
						else
							break ;
					}
					else if (_comp(key, tmp->_data.first))
						tmp = tmp->_left;
					else if (_comp(tmp->_data.first, key))
						tmp = tmp->_right;
					else
						break ;
				}
				return (NULL);
			};
			
			Compare	key_comp( void ) const
			{
				return (key_compare());
			};

			value_compare value_comp() const
			{
				return(value_compare(key_compare()));
			};
	
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