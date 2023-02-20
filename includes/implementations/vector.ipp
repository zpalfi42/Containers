#ifndef	VECTOR_IPP
# define	VECTOR_IPP

# include	<vector.hpp>

template < class T, class Alloc >
ft::vector<T, Alloc>::vector( const allocator_type& alloc): _alloc(alloc), _begin(ft::nullptr_t), _end(ft::nullptr_t), _capacity(ft::nullptr_t)
{
}

template < class T, class Alloc >
ft::vector<T, Alloc>::vector( size_type n, const value_type& val, const allocator_type& alloc ): _alloc(alloc), _begin(ft::nullptr_t), _end(ft::nullptr_t), _capacity(ft::nullptr_t)
{
	this->_begin = _alloc.allocate(n);
	for (size_t i = 0; i < n; i++)
		this->_alloc.construct(this->_begin + i, val);
	this->_capacity = this->_begin + n;
	this->_end = this->_begin + n;
}


template< typename T, typename Alloc >
template< typename InputIterator >
ft::vector<T, Alloc>::vector(InputIterator first, InputIterator last, const allocator_type& alloc, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*): _alloc(alloc), _begin(ft::nullptr_t), _end(ft::nullptr_t), _capacity(ft::nullptr_t)
{
	long	fl = ft::distance(first, last);

	this->_begin = this->_alloc.allocate(fl);
	for (long i = 0; i <= fl; i++)
		this->_alloc.construct(this->_begin + i, *(first + i));
	this->_capacity = this->_begin + fl;
	this->_end = this->_begin + fl;
}


template< class T, class Alloc >
ft::vector<T, Alloc>::vector( const ft::vector<T, Alloc> &x): _alloc(x._alloc), _begin(ft::nullptr_t), _end(ft::nullptr_t), _capacity(ft::nullptr_t)
{
	long	sc = x._capacity - x._begin;
	long	se = x._end - x._begin;

	this->_begin = this->_alloc.allocate(sc);
	for (long i = 0; i < se; i++)
		this->_alloc.construct(this->_begin + i, *(x._begin + i));
	this->_capacity = this->_begin + sc;
	this->_end = this->_begin + se;
}

template< class T, class Alloc >
ft::vector<T, Alloc>::~vector( void )
{
	long	sc = this->_capacity - this->_begin;

	for (long i = 0; i < sc; i++)
		this->_alloc.destroy(this->_begin + i);
	this->_alloc.deallocate(this->_begin, sc);
}

template< class T, class Alloc >
ft::vector<T, Alloc>	&ft::vector<T, Alloc>::operator=( const ft::vector<T, Alloc> &x )
{
	if (this != &x)
	{
		long	tsc = this->_capacity - this->_begin;
		long	xsc = x._capacity - x._begin;
		long	xse = x._end - x._begin;

		this->clear();
		this->_alloc.deallocate(this->_begin, tsc);

		this->_alloc = x._alloc;
		this->_begin = this->_alloc.allocate(xsc);
		for (long i = 0; i < xse; i++)
			this->_alloc.construct(this->_begin + i, *(x._begin + i));
		this->_capacity = this->_begin + xsc;
		this->_end = this->_begin + xse;
	}
	return (*this);
}

// template< class T, class Alloc >
// typename ft::vector<T, Alloc>::iterator	ft::vector<T, Alloc>::begin( void )
// {
// 	iterator	it(this->_begin);
// 	return (iterator(it));
// }

// template< class T, class Alloc >
// typename ft::vector<T, Alloc>::const_iterator	ft::vector<T, Alloc>::begin( void ) const
// {
// 	return (const_iterator(this->_begin));
// }

// template< class T, class Alloc >
// typename ft::vector<T, Alloc>::iterator	ft::vector<T, Alloc>::end( void )
// {
// 	return (iterator(this->_end));
// }

// template< class T, class Alloc >
// typename ft::vector<T, Alloc>::const_iterator	ft::vector<T, Alloc>::end( void ) const
// {
// 	return (const_iterator(this->_end));
// }

// template< class T, class Alloc >
// typename ft::vector<T, Alloc>::reverse_iterator	ft::vector<T, Alloc>::rbegin( void )
// {
// 	return (reverse_iterator(this->_begin));
// }

// template< class T, class Alloc >
// typename ft::vector<T, Alloc>::const_reverse_iterator	ft::vector<T, Alloc>::rbegin( void ) const
// {
// 	return (const_reverse_iterator(this->_begin));
// }

// template< class T, class Alloc >
// typename ft::vector<T, Alloc>::reverse_iterator	ft::vector<T, Alloc>::rend( void )
// {
// 	return (reverse_iterator(this->_end));
// }

// template< class T, class Alloc >
// typename ft::vector<T, Alloc>::const_reverse_iterator	ft::vector<T, Alloc>::rend( void ) const
// {
// 	return (const_reverse_iterator(this->_end));
// }


template< class T, class Alloc >
typename ft::vector<T, Alloc>::size_type	ft::vector<T, Alloc>::size( void ) const
{
	ft::vector<T, Alloc>::size_type size = this->_end - this->_begin;
	return (size);
}

template< class T, class Alloc >
typename	ft::vector<T, Alloc>::size_type	ft::vector<T, Alloc>::max_size( void ) const
{
	return (this->_alloc.max_size());
}

template< class T, class Alloc >
typename	ft::vector<T, Alloc>::size_type	ft::vector<T, Alloc>::capacity( void ) const
{
	ft::vector<T, Alloc>::size_type	max_size = this->_capacity - this->_begin;
	return (max_size);
}

template< class T, class Alloc >
bool	ft::vector<T, Alloc>::empty( void ) const
{
	return ( (this->_begin == this->_end) ? true : false);
}

template< class T, class Alloc >
void	ft::vector<T, Alloc>::reserve(size_type n)
{
	size_type	sc = this->_capacity - this->_begin;
	size_type	se = this->_end - this->_begin;

	if (n < sc)
		return ;

	pointer	np = this->_alloc.allocate(n);
	for (size_type i = 0; i < se; i++)
	{
		this->_alloc.construct(np + i, *(this->_begin + i));
		this->_end = np + i;
	}

	this->clear();
	this->_alloc.deallocate(this->_begin, sc);
	
	this->_begin = np;
	this->_capacity = this->_begin + n;
}

template< class T, class Alloc >
void		ft::vector<T, Alloc>::resize(size_type n, value_type val)
{
	size_type	sc = this->_capacity - this->_begin;
	size_type	se = this->_end - this->_begin;

	if (n < se)
	{
		for (size_type i = n; i < se; i++)
			this->_alloc.destroy(this->_begin + i);
		this->_end = this->_begin + n;
		return ;
	}
	if (n > sc * 2)
		this->reserve(n);
	else if (n > sc)
		this->reserve(sc * 2);
	for (size_type i = se; i < n; i++)
		this->_alloc.construct(this->_begin + i, val);
	this->_end = this->_begin + n;
}

template< class T, class Alloc>
void	ft::vector<T, Alloc>::shrink_to_fit( void )
{
	size_type	sc = this->_capacity - this->_begin;
	size_type	se = this->_end - this->_begin;

	if (sc == se)
		return ;
	pointer	np = this->_alloc.allocate(se);
	for (size_type i = 0; i < se; i++)
		this->_alloc.construct(np + i, *(this->_begin + i));
	this->clear();
	this->_alloc.deallocate(this->_begin, sc);
	
	this->_end = np + se;
	this->_begin = np;
	this->_capacity = this->_end;
}

template< class T, class Alloc >
typename	ft::vector<T, Alloc>::reference	ft::vector<T, Alloc>::operator[]( size_type n )
{
	reference	r = *(this->_begin + n);
	return (r);
}

template< class T, class Alloc >
typename	ft::vector<T, Alloc>::const_reference	ft::vector<T, Alloc>::operator[]( size_type n ) const
{
	const_reference	r = *(this->_begin + n);
	return (r);
}

template< class T, class Alloc >
typename	ft::vector<T, Alloc>::reference	ft::vector<T, Alloc>::at( size_type n )
{
	size_type	se = this->_end - this->_begin;

	if (n >= se)
		throw std::out_of_range("vector");
	reference	r = *(this->_begin + n);
	return (r);
}

template< class T, class Alloc >
typename	ft::vector<T, Alloc>::const_reference	ft::vector<T, Alloc>::at( size_type n ) const
{
	size_type	se = this->_end - this->_begin;

	if (n >= se)
		throw std::out_of_range("vector");
	const_reference	r = *(this->_begin + n);
	return (r);
}

template< class T, class Alloc>
typename	ft::vector<T, Alloc>::reference	ft::vector<T, Alloc>::front( void )
{
	return (*this->_begin);
}

template< class T, class Alloc>
typename	ft::vector<T, Alloc>::const_reference	ft::vector<T, Alloc>::front( void ) const
{
	return (*this->_begin);
}

template< class T, class Alloc>
typename	ft::vector<T, Alloc>::reference	ft::vector<T, Alloc>::back( void )
{
	return (*(this->_end - 1));
}

template< class T, class Alloc>
typename	ft::vector<T, Alloc>::const_reference	ft::vector<T, Alloc>::back( void ) const
{
	return (*(this->_end - 1));
}

template< class T, class Alloc >
typename	ft::vector<T, Alloc>::value_type	*ft::vector<T, Alloc>::data( void )
{
	return (this->_begin);
}

template< class T, class Alloc >
const typename	ft::vector<T, Alloc>::value_type	*ft::vector<T, Alloc>::data( void ) const
{
	return (this->_begin);
}

template< class T, class Alloc>
template< class InputIterator >
void	ft::vector<T, Alloc>::assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*)
{
	size_type	fl = ft::distance(first, last);
	size_type	sc = this->_capacity - this->_begin;
	// size_type	se = this->_end - this->_begin;

	this->clear();
	if (fl > sc)
	{
		this->_alloc.deallocate(this->_begin, sc);
		pointer	np = this->_alloc.allocate(fl);
		for (size_type i = 0; i < fl; i++)
			this->_alloc.construct(np + i, *(first + i));
		this->_begin = np;
		this->_end = this->_begin + fl;
		this->_capacity = this->_end;
		return ;
	}
	for (size_type i = 0; i < fl; i++)
		this->_alloc.construct(this->_begin + i, *(first + i));
	this->_end = this->_begin + fl;
}

template< class T, class Alloc>
void	ft::vector<T, Alloc>::assign(size_type n, const value_type &val)
{
	size_type	sc = this->_capacity - this->_begin;

	this->clear();
	if (n < sc)
	{
		for (size_type i = 0; i < n; i++)
			this->_alloc.construct(this->_begin + i, val);
		this->_end = this->_begin + n;
		return ;
	}
	this->_alloc.deallocate(this->_begin, sc);
	pointer	np = this->_alloc.allocate(n);
	for (size_type i = 0; i < n; i++)
		this->_alloc.construct(np + i, val);
	this->_begin = np;
	this->_end = this->_begin + n;
	this->_capacity = this->_end;
}

template< class T, class Alloc >
void	ft::vector<T, Alloc>::push_back( const value_type &val )
{
	if (this->_end == this->_capacity)
		this->reserve((this->capacity() * 2));
	if (this->capacity() == 0)
		this->reserve(1);
	this->_alloc.construct(this->_end, val);
	this->_end++;
}

template< class T, class Alloc>
void	ft::vector<T, Alloc>::pop_back( void )
{
	if (this->_begin == this->_end)
		return ;
	this->_alloc.destroy(this->_end);
	this->_end--;
}

// template< class T, class Alloc >
// ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::insert( iterator position, const value_type &val )
// {
// 	if (position == this->_end)
// 	{
// 		push_back(val);
// 		return (ft::vector<int>::iterator	it = this->_end);
// 	}
// 	pointer np = this->_alloc.allocate(this->capacity());

// }

template< class T, class Alloc >
void	ft::vector<T, Alloc>::clear( void )
{
	size_type	se = this->_end - this->_begin;

	for (size_type i = 0; i <= se; i++)
		this->_alloc.destroy(this->_begin + i);
	this->_end = this->_begin;
}

#endif