#ifndef	ITERATOR_IPP
# define ITERATOR_IPP

# include <iterator.hpp>

template< class T >
ft::random_access_iterator<T>::random_access_iterator( void ): _ptr(ft::nullptr_t)
{
}

template< class T >
ft::random_access_iterator<T>::random_access_iterator( ft::random_access_iterator<T>::pointer ptr ): _ptr(ptr)
{
};

template< class T >
ft::random_access_iterator<T>::random_access_iterator( const ft::random_access_iterator<T> &r ): _ptr(r._ptr)
{
};

template< class T>
typename ft::random_access_iterator<T>::reference ft::random_access_iterator<T>::operator[]( ft::random_access_iterator<T>::difference_type n )
{
	return (*(this->_ptr + n));
};

template< class T>
typename ft::random_access_iterator<T>::reference ft::random_access_iterator<T>::operator*( void )
{
	return (*(this->_ptr));
};

template< class T>
typename ft::random_access_iterator<T>::pointer	ft::random_access_iterator<T>::operator->( void )
{
	return (&(*(this->_ptr)));
};

template< class T >
ft::random_access_iterator<T>	&ft::random_access_iterator<T>::operator=( const random_access_iterator &r )
{
	if (this != &r)
	{
		this->_ptr = r._ptr;
	}
	return (*this);
};

template< class T >
typename ft::random_access_iterator<T>::difference_type	ft::random_access_iterator<T>::operator-( const random_access_iterator &r ) const
{
	return (this->_ptr - r._ptr);
};

template< class T >
ft::random_access_iterator<T>	&ft::random_access_iterator<T>::operator++( void )
{
	this->_ptr++;
	return (*this);
};

template< class T >
ft::random_access_iterator<T>	ft::random_access_iterator<T>::operator++( int )
{
	random_access_iterator	r = *this;
	this->_ptr++;
	return (r);
};

template< class T >
ft::random_access_iterator<T>	&ft::random_access_iterator<T>::operator--( void )
{
	this->_ptr--;
	return (*this);
};

template< class T >
ft::random_access_iterator<T>	ft::random_access_iterator<T>::operator--( int )
{
	random_access_iterator	r = *this;
	this->_ptr--;
	return (r);
};

template< class T >
ft::random_access_iterator<T>	ft::random_access_iterator<T>::operator+( difference_type n ) const
{
	random_access_iterator	it(*this);
	return (it += n);
};

template< class T >
ft::random_access_iterator<T>	ft::random_access_iterator<T>::operator-( difference_type n ) const
{
	random_access_iterator	it(*this);
	return (it -= n);
};

template< class T >
ft::random_access_iterator<T>	&ft::random_access_iterator<T>::operator+=( difference_type n )
{
	this->_ptr += n;
	return (*this);
};

template< class T >
ft::random_access_iterator<T>	&ft::random_access_iterator<T>::operator-=( difference_type n)
{
	this->_ptr -= n;
	return (*this);
};
		
template< class T >
bool	ft::random_access_iterator<T>::operator==( const ft::random_access_iterator<T> &r ) const 
{
	if (this->_ptr == r._ptr)
		return (true);
	return (false);
};

template< class T >
bool	ft::random_access_iterator<T>::operator!=( const ft::random_access_iterator<T> &r ) const 
{
	if (this->_ptr != r._ptr)
		return (true);
	return (false);
};

template< class T >
bool	ft::random_access_iterator<T>::operator<( const ft::random_access_iterator<T>&r ) const 
{
	if (this->_ptr < r._ptr)
		return (true);
	return (false);
};

template< class T >
bool	ft::random_access_iterator<T>::operator>( const ft::random_access_iterator<T> &r ) const 
{
	if (this->_ptr > r._ptr)
		return (true);
	return (false);
};

template< class T >
bool	ft::random_access_iterator<T>::operator<=( const ft::random_access_iterator<T> &r ) const
{
	if (this->_ptr <= r._ptr)
		return (true);
	return (false);
};

template< class T >
bool	ft::random_access_iterator<T>::operator>=( const ft::random_access_iterator<T> &r ) const
{
	if (this->_ptr >= r._ptr)
		return (true);
	return (false);
};

template< class T >
ft::random_access_iterator<T>	operator+( typename ft::random_access_iterator<T>::difference_type n, const ft::random_access_iterator<T> &r )
{
	return (r + n);
};

#endif