#ifndef MAP_IPP
# define	MAP_IPP

#include <map.hpp>

/**
 *********************************************
 * @brief PRIVATE FUNCTIONS
 *********************************************
 */

template< class Key, class T, class Compare, class Allocator >
ft::pair<typename ft::map<Key, T, Compare, Allocator>::iterator, bool>	ft::map<Key, T, Compare, Allocator>::min( void )
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

template< class Key, class T, class Compare, class Allocator >
ft::pair<typename ft::map<Key, T, Compare, Allocator>::iterator, bool>	ft::map<Key, T, Compare, Allocator>::max( void )
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

template< class Key, class T, class Compare, class Allocator >
ft::pair<typename ft::map<Key, T, Compare, Allocator>::iterator, bool>	ft::map<Key, T, Compare, Allocator>::min( void ) const
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

template< class Key, class T, class Compare, class Allocator >
ft::pair<typename ft::map<Key, T, Compare, Allocator>::iterator, bool>	ft::map<Key, T, Compare, Allocator>::max( void ) const
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

template< class Key, class T, class Compare, class Allocator >
void	ft::map<Key, T, Compare, Allocator>::clearNodes( node_type *node )
{
	if (node->_left != ft::nullptr_t)
		clearNodes(node->_left);
	if (node->_right != ft::nullptr_t)
		clearNodes(node->_right);
	this->_allocNode.destroy(node);
	this->_allocNode.deallocate(node, 1);
};

/**
 *********************************************
 * @brief PUBLIC FUNCTIONS
 **********************************************
 */

template< class Key, class T, class Compare, class Allocator >
ft::map<Key, T, Compare, Allocator>::map( const typename ft::map<Key, T, Compare, Allocator>::allocator_type& alloc ): _size(0), _root(ft::nullptr_t), _allocator(alloc)
{
};

template< class Key, class T, class Compare, class Allocator >
template< class InputIt >
ft::map<Key, T, Compare, Allocator>::map( InputIt first, InputIt last, const Compare& comp, const Allocator& alloc)
{
	this->_root = ft::nullptr_t;
	this->_allocator = alloc;
	this->_size = 0;
	(void) comp;
	this->insert(first, last);
};

template< class Key, class T, class Compare, class Allocator >
ft::map<Key, T, Compare, Allocator>::map( const map& other )
{
	this->_root = ft::nullptr_t;
	this->_allocator = other._allocator;
	this->_size = 0;
	this->insert(other.begin(), other.end());
};

template< class Key, class T, class Compare, class Allocator >
ft::map<Key, T, Compare, Allocator>::~map( void )
{
	this->clear();
};

template< class Key, class T, class Compare, class Allocator >
ft::map<Key, T, Compare, Allocator> &ft::map<Key, T, Compare, Allocator>::operator=( const map &other )
{
	if (this!=&other)
	{
		this->clear();
		this->insert(other.begin(), other.max().first);
	}
	return (*this);
};

template< class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::allocator_type	ft::map<Key, T, Compare, Allocator>::get_allocator( void ) const
{
	return(this->_allocator);
};

template< class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::mapped_type	&ft::map<Key, T, Compare, Allocator>::at( const Key &key )
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

template< class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::mapped_type	&ft::map<Key, T, Compare, Allocator>::operator[]( const Key &key )
{
	iterator it = this->find(key);
	if (it == this->end())
	{
		value_type val = ft::make_pair(key, mapped_type());
		it = insert(val).first;
	}
	return it->second;
};

template< class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::iterator			ft::map<Key, T, Compare, Allocator>::begin( void )
{
	return(this->min().first);
};

template< class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::const_iterator		ft::map<Key, T, Compare, Allocator>::begin( void ) const
{
	return(this->min().first);
};

template< class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::iterator			ft::map<Key, T, Compare, Allocator>::end( void )
{
	iterator	it = this->max().first;
	++it;
	return(it);
};

template< class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::const_iterator		ft::map<Key, T, Compare, Allocator>::end( void ) const
{
	const_iterator	it = this->max().first;
	++it;
	return(it);
};

template< class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::reverse_iterator		ft::map<Key, T, Compare, Allocator>::rbegin( void )
{
	reverse_iterator rit(this->max().first);
	--rit;
	return(rit);
};

template< class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::const_reverse_iterator	ft::map<Key, T, Compare, Allocator>::rbegin( void ) const
{
	const_reverse_iterator rit(this->max().first);
	--rit;
	return(rit);
};

template< class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::reverse_iterator		ft::map<Key, T, Compare, Allocator>::rend( void )
{
	return(reverse_iterator(this->begin()));
};

template< class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::const_reverse_iterator	ft::map<Key, T, Compare, Allocator>::rend( void ) const
{
	return(reverse_iterator(this->begin()));
};

template< class Key, class T, class Compare, class Allocator >
bool	ft::map<Key, T, Compare, Allocator>::empty( void ) const
{
	return(this->_size == 0);
};

template< class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::size_type	ft::map<Key, T, Compare, Allocator>::size( void ) const
{
	return(this->_size);
};

template< class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::size_type	ft::map<Key, T, Compare, Allocator>::max_size( void ) const
{
	return((this->_allocator.max_size()*2) / 10);
};

template< class Key, class T, class Compare, class Allocator >
void	ft::map<Key, T, Compare, Allocator>::clear( void )
{
	if (this->_root == ft::nullptr_t)
		return ;
	clearNodes(this->_root);
	this->_root = ft::nullptr_t;
	this->_size = 0;
};

template< class Key, class T, class Compare, class Allocator >
ft::pair<typename ft::map<Key, T, Compare, Allocator>::iterator, bool>	ft::map<Key, T, Compare, Allocator>::insert( const value_type &val )
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

template< class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::iterator					ft::map<Key, T, Compare, Allocator>::insert( iterator pos, const value_type &val )
{
	(void) pos;
	return this->insert(val).first;
};

template< class Key, class T, class Compare, class Allocator >
template< class InputIt >
void						ft::map<Key, T, Compare, Allocator>::insert( InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value>::type * )
{
	InputIt start = first;
	size_t chunks = 100;
	for (size_t i = 0; i < chunks; i++)
	{
		first = start;
		while (first != last)
		{
			insert(*first);
			for (size_t i = 0; i < chunks && first != last; i++)
			{
				first++;
				if (first == last)
					break;
			}
		}
		start++;
		if (start == last)
			break;
	}
};

template< class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::iterator	ft::map<Key, T, Compare, Allocator>::erase( iterator pos )
{
	node_type	*curr = pos._node;

	if (curr == ft::nullptr_t)
		return pos;

	node_type	*tmp = ft::nullptr_t;

	if (curr->hasLeftChild())
	{
		tmp = curr->_left;
		while (tmp->_right)
		{
			tmp = tmp->_right;
		}
		tmp->_right = curr->_right;
		if (curr->_right)
			curr->_right->_parent = tmp;
		tmp = curr->_left;
		tmp->_parent = curr->_parent;
	}
	else if (curr->hasRightChild())
	{
		tmp = curr->_right;
		tmp->_parent = curr->_parent;	
	}

	if (curr->_parent)
	{
		if (curr->_parent->_right == curr)
			curr->_parent->_right = tmp;
		else
			curr->_parent->_left = tmp;
	}
	else
		this->_root = tmp;
	this->_allocNode.deallocate(curr, 1);
	--this->_size;
	return (iterator(tmp));
};

template< class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::iterator ft::map<Key, T, Compare, Allocator>::erase( iterator first, iterator last )
{
	iterator tmp;

	while (first != last)
	{
		tmp = first++;
		this->erase(tmp);
	}
	return (NULL);
};

template< class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::size_type	ft::map<Key, T, Compare, Allocator>::erase( const Key &key )
{
	iterator	tmp = this->find(key);

	if (tmp != NULL)
	{
		this->erase(tmp);
		return (1);
	}
	return (0);
};

template< class Key, class T, class Compare, class Allocator >
void	ft::map<Key, T, Compare, Allocator>::swap( map &other )
{
	node_type	*tmp = this->_root;
	size_type	stmp = this->_size;

	this->_size = other._size;
	other._size = stmp;

	this->_root = other._root;
	other._root = tmp;
};

template< class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::size_type	ft::map<Key, T, Compare, Allocator>::count( const Key &key ) const
{
	const_iterator	tmp = this->find(key);

	if (tmp != NULL)
	{
		return (1);
	}
	return (0);
};

template< class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::iterator	ft::map<Key, T, Compare, Allocator>::find( const Key &key )
{
	node_type *found = this->_root;
	if (!this->_root)
		return NULL;
	while (found)
	{
		if (found->_data.first == key)
			return found;
		if (key < found->_data.first)
			found = found->_left;
		else
			found = found->_right;
	}
	return NULL;
};

template< class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::const_iterator	ft::map<Key, T, Compare, Allocator>::find( const Key &key ) const
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

template< class Key, class T, class Compare, class Allocator >
ft::pair<typename ft::map<Key, T, Compare, Allocator>::iterator, typename ft::map<Key, T, Compare, Allocator>::iterator>	ft::map<Key, T, Compare, Allocator>::equal_range( const Key &key )
{
	return (ft::make_pair(lower_bound(key), upper_bound(key)));
};

template< class Key, class T, class Compare, class Allocator >
ft::pair<typename ft::map<Key, T, Compare, Allocator>::const_iterator, typename ft::map<Key, T, Compare, Allocator>::const_iterator>	ft::map<Key, T, Compare, Allocator>::equal_range( const Key &key ) const
{
	return (ft::make_pair(lower_bound(key), upper_bound(key)));
};

template< class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::iterator	ft::map<Key, T, Compare, Allocator>::lower_bound( const Key &key )
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

template< class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::const_iterator	ft::map<Key, T, Compare, Allocator>::lower_bound( const Key &key ) const
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

template< class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::iterator	ft::map<Key, T, Compare, Allocator>::upper_bound( const Key &key )
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

template< class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::const_iterator	ft::map<Key, T, Compare, Allocator>::upper_bound( const Key &key ) const
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

template< class Key, class T, class Compare, class Allocator >
Compare	ft::map<Key, T, Compare, Allocator>::key_comp( void ) const
{
	return (key_compare());
};

template< class Key, class T, class Compare, class Allocator >
typename ft::map<Key, T, Compare, Allocator>::value_compare ft::map<Key, T, Compare, Allocator>::value_comp() const
{
	return(value_compare(key_compare()));
};


#endif