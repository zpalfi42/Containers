#ifndef	BIDIRECTIONAL_ITERATOR_IPP
#	define	BIDIRECTIONAL_ITERATOR_IPP

# include <bidirectional_iterator.hpp>

template <class T>
ft::bidirectional_iterator<T>::bidirectional_iterator(node_type *node): _node(node), _prev(ft::nullptr_t)
{
};

template <class T>
ft::bidirectional_iterator<T>::bidirectional_iterator(const bidirectional_iterator &other): _node(other._node), _prev(other._prev)
{
};

template <class T>
ft::bidirectional_iterator<T>	&ft::bidirectional_iterator<T>::operator=(const bidirectional_iterator &other)
{
	if (this!=&other)
	{
		this->_node = other._node;
		this->_prev = other._prev;
	}
	return(*this);
}

template <class T>
ft::bidirectional_iterator<T>::~bidirectional_iterator( void )
{
};

template <class T>
bool ft::bidirectional_iterator<T>::operator==(const bidirectional_iterator& other) const
{
	return (this->_node == other._node);
};

template <class T>
bool ft::bidirectional_iterator<T>::operator!=(const bidirectional_iterator& other) const
{
	return (this->_node != other._node);
};

template <class T>
ft::bidirectional_iterator<T>	&ft::bidirectional_iterator<T>::operator++( void )
{
	if (this->_node == ft::nullptr_t)
		return (*this);
	this->_prev = this->_node;
	if (this->_node->_right != ft::nullptr_t)
	{
		this->_node = this->_node->_right;
		while (this->_node->_left != ft::nullptr_t)
			this->_node = this->_node->_left;
	}
	else
	{
		node_type	*parent = this->_node->_parent;
		while (parent != ft::nullptr_t && this->_node == parent->_right)
		{
			this->_node = parent;
			parent = parent->_parent;
		}
		this->_node = parent;
	}
	return (*this);
};

template <class T>
ft::bidirectional_iterator<T>	ft::bidirectional_iterator<T>::operator++( int )
{
	bidirectional_iterator	temp(*this);
	++(*this);
	return (temp);
};

template <class T>
ft::bidirectional_iterator<T>	&ft::bidirectional_iterator<T>::operator--( void )
{
	if (this->_node == ft::nullptr_t)
	{
		this->_node = this->_prev;
		return (*this);
	}
	this->_prev = this->_node;
	if (this->_node->_left != ft::nullptr_t)
	{
		this->_node = this->_node->_left;
		while (this->_node->_right != ft::nullptr_t)
			this->_node = this->_node->_right;
	}
	else
	{
		node_type	*parent = this->_node->_parent;
		while (parent != ft::nullptr_t && this->_node == parent->_left)
		{
			this->_node = parent;
			parent = parent->_parent;
		}
		this->_node = parent;
	}
	return (*this);
};

template <class T>
ft::bidirectional_iterator<T>	ft::bidirectional_iterator<T>::operator--( int )
{
	bidirectional_iterator	temp(*this);
	--(*this);
	return (temp);
};

template <class T>
typename ft::bidirectional_iterator<T>::reference	ft::bidirectional_iterator<T>::operator*( void ) const
{
	return(this->_node->_data);
};

template <class T>
typename ft::bidirectional_iterator<T>::pointer		ft::bidirectional_iterator<T>::operator->( void ) const
{
	return (&(this->_node->_data));
};

#endif