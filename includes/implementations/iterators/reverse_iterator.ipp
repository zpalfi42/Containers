#ifndef	REVERSE_ITERATOR_IPP
#	define	REVERSE_ITERATOR_IPP

# include <reverse_iterator.hpp>

template< class Iter>
ft::reverse_iterator<Iter>::reverse_iterator( void ): _current()
{
};

template< class Iter>
ft::reverse_iterator<Iter>::reverse_iterator( Iter x ): _current(x)
{
};

template <class Iter>
template <class It>
ft::reverse_iterator<Iter>::reverse_iterator( const ft::reverse_iterator<It> &other ): _current(other._current)
{
};

template <class Iter>
ft::reverse_iterator<Iter>::~reverse_iterator()
{
};

template <class Iter>
template <class It>
ft::reverse_iterator<Iter>	&ft::reverse_iterator<Iter>::operator=( const ft::reverse_iterator<It> &other )
{
	if (this != &other)
	{
		this->_current = other._current;
	}
	return (*this);
};

template <class Iter>
typename ft::reverse_iterator<Iter>::reference			ft::reverse_iterator<Iter>::operator[]( typename ft::reverse_iterator<Iter>::difference_type n ) const
{
	iterator_type	tmp = this->_current;
	return (tmp[-n - 1]);
};

template <class Iter>
typename ft::reverse_iterator<Iter>::reference			ft::reverse_iterator<Iter>::operator*( void ) const
{
	iterator_type	tmp = this->_current;
	return (*(--tmp));
};

template <class Iter>
typename ft::reverse_iterator<Iter>::pointer				ft::reverse_iterator<Iter>::operator->( void ) const
{
	return (&(this->operator*()));
};

template <class Iter>
typename ft::reverse_iterator<Iter>::iterator_type		ft::reverse_iterator<Iter>::base( void ) const
{
	return (this->_current);
};

template <class Iter>
ft::reverse_iterator<Iter>	&ft::reverse_iterator<Iter>::operator++( void )
{
	--this->_current;
	return (*this);
};

template <class Iter>
ft::reverse_iterator<Iter>	&ft::reverse_iterator<Iter>::operator--( void )
{
	++this->_current;
	return (*this);
};

template <class Iter>
ft::reverse_iterator<Iter>	ft::reverse_iterator<Iter>::operator++( int )
{
	reverse_iterator	tmp = *this;
	++(*this);
	return (tmp);
};

template <class Iter>
ft::reverse_iterator<Iter>	ft::reverse_iterator<Iter>::operator--( int )
{
	reverse_iterator	tmp = *this;
	--(*this);
	return (tmp);
};

template <class Iter>
ft::reverse_iterator<Iter>	ft::reverse_iterator<Iter>::operator+( ft::reverse_iterator<Iter>::difference_type n )
{
	return (reverse_iterator(this->_current - n));
};

template <class Iter>
ft::reverse_iterator<Iter>	ft::reverse_iterator<Iter>::operator-( ft::reverse_iterator<Iter>::difference_type n )
{
	return (reverse_iterator(this->_current + n));
};

template <class Iter>
ft::reverse_iterator<Iter>	ft::reverse_iterator<Iter>::operator+=( ft::reverse_iterator<Iter>::difference_type n )
{
	this->_current -= n;
	return (*this);
};

template <class Iter>
ft::reverse_iterator<Iter>	ft::reverse_iterator<Iter>::operator-=( ft::reverse_iterator<Iter>::difference_type n )
{
	this->_current += n;
	return (*this);
};

#endif