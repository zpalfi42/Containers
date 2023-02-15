#ifndef	VECTOR_IPP
# define	VECTOR_IPP

# include	<vector.hpp>

template < class T, class Alloc >
ft::vector<T, Alloc>::vector( const allocator_type& alloc): _alloc(alloc), _start(ft::nullptr_t), _end(ft::nullptr_t), _capacity(ft::nullptr_t)
{
}

template < class T, class Alloc >
ft::vector<T, Alloc>::vector( size_type n, const value_type& val, const allocator_type& alloc ): _alloc(alloc), _start(ft::nullptr_t), _end(ft::nullptr_t), _capacity(ft::nullptr_t)
{
	this->_start = _alloc.allocate(n);
	for (size_t i = 0; i <= n; i++)
		this->_alloc.construct(this->_start + i, val);
	this->_capacity = this->_start + n;
	this->_end = this->_start + n;
}


template< typename T, typename Alloc >
template< typename InputIterator >
ft::vector<T, Alloc>::vector(InputIterator first, InputIterator last, const allocator_type& alloc, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*): _alloc(alloc), _start(ft::nullptr_t), _end(ft::nullptr_t), _capacity(ft::nullptr_t)
{
	long	fl = ft::distance(first, last);

	this->_start = this->_alloc.allocate(fl);
	for (long i = 0; i < fl; i++)
		this->_alloc.construct(this->_start + i, *(first + i));
	this->_capacity = this->_start + (fl) - 1;
	this->_end = this->_start + (fl) - 1;
	std::cout << *(this->_end) << std::endl;
}


template< class T, class Alloc >
ft::vector<T, Alloc>::vector( const ft::vector<T, Alloc> &x): _alloc(x._alloc), _start(ft::nullptr_t), _end(ft::nullptr_t), _capacity(ft::nullptr_t)
{
	long	sc = x._capacity - x._start;
	long	se = x._end - x._start;

	this->_start = this->_alloc.allocate(sc);
	for (long i = 0; i < se; i++)
		this->_alloc.construct(this->start + i, *(x._start + i));
	this->_capacity = this->_start + sc;
	this->_end = this->_start + se;
}

template< class T, class Alloc >
ft::vector<T, Alloc>::~vector( void )
{
	long	sc = this->_capacity - this->_start;

	for (long i = 0; i < sc; i++)
		this->_alloc.destroy(this->_start + i);
	this->_alloc.deallocate(this->_start, sc);
}

template< class T, class Alloc >
ft::vector<T, Alloc>	&ft::vector<T, Alloc>::operator=( const ft::vector<T, Alloc> &x )
{
	if (this != &x)
	{
		long	tsc = this->_capacity - this->_start;
		long	xsc = x._capacity - x._start;
		long	xse = x._end - x._start;

		this->clear();
		this->_alloc.deallocate(this->_start, tsc);

		this->_alloc = x._alloc;
		this->_start = this->_alloc.allocate(xsc);
		for (long i = 0; i < xse; i++)
			this->_alloc.construct(this->_start + i, *(x._start + i));
		this->_capacity = this->_start + xsc;
		this->_end = this->_start + xse;
	}
	return (*this);
}

template< class T, class Alloc >
typename ft::vector<T, Alloc>::size_type	ft::vector<T, Alloc>::size( void ) const
{
	ft::vector<T, Alloc>::size_type size = this->_end - this->_start;
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
	ft::vector<T, Alloc>::size_type	max_size = this->_capacity - this->_start;
	return (max_size);
}

template< class T, class Alloc >
bool	ft::vector<T, Alloc>::empty( void ) const
{
	return ( (this->_start == this->_end) ? true : false);
}

template< class T, class Alloc >
void	ft::vector<T, Alloc>::reserve(size_type n)
{
	size_type	sc = this->_capacity - this->_start;
	size_type	se = this->_end - this->_start;

	if (n < sc)
		return ;

	pointer	np = this->_alloc.allocate(n);
	for (size_type i = 0; i <= se; i++)
	{
		this->_alloc.construct(np + i, *(this->_start + i));
		this->_end = np + i;
	}

	this->clear();
	this->_alloc.deallocate(this->_start, sc);
	
	this->_start = np;
	this->_capacity = this->_start + n;
}

template< class T, class Alloc >
void		ft::vector<T, Alloc>::resize(size_type n, value_type val)
{
	size_type	sc = this->_capacity - this->_start;
	size_type	se = this->_end - this->_start;

	if (n <= se)
	{
		for (size_type i = se; i >= n; i--)
		{
			this->_alloc.destroy(this->_start + i);
			this->_end = this->_start + i;
			if (i == 0)
				return ;
		}
	}
	if (n > sc * 2)
		this->reserve(n);
	else if (n > sc)
		this->reserve(sc * 2);
	for (size_type i = se; i < n; i++)
		this->_alloc.construct(this->_start + i, val);
	this->_end = this->_start + n;
}

template< class T, class Alloc>
void	ft::vector<T, Alloc>::shrink_to_fit( void )
{
	size_type	sc = this->_capacity - this->_start;
	size_type	se = this->_end - this->_start;

	if (sc == se)
		return ;
	pointer	np = this->_alloc.allocate(se);
	for (size_type i = 0; i <= se; i++)
		this->_alloc.construct(np + i, *(this->_start + i));
	this->clear();
	this->_alloc.deallocate(this->_start, sc);
	
	this->_end = np + se;
	this->_start = np;
	this->_capacity = this->_end;
}

template< class T, class Alloc >
typename	ft::vector<T, Alloc>::reference	ft::vector<T, Alloc>::operator[]( size_type n )
{
	reference	r = *(this->_start + n);
	return (r);
}

template< class T, class Alloc >
typename	ft::vector<T, Alloc>::const_reference	ft::vector<T, Alloc>::operator[]( size_type n ) const
{
	const_reference	r = *(this->_start + n);
	return (r);
}

template< class T, class Alloc >
typename	ft::vector<T, Alloc>::reference	ft::vector<T, Alloc>::at( size_type n )
{
	size_type	se = this->_end - this->_start;

	if (n > se)
		throw std::out_of_range("vector");
	reference	r = *(this->_start + n);
	return (r);
}

template< class T, class Alloc >
typename	ft::vector<T, Alloc>::const_reference	ft::vector<T, Alloc>::at( size_type n ) const
{
	size_type	se = this->_end - this->_start;

	if (n > se)
		throw std::out_of_range("vector");
	const_reference	r = *(this->_start + n);
	return (r);
}

template< class T, class Alloc>
typename	ft::vector<T, Alloc>::reference	ft::vector<T, Alloc>::front( void )
{
	return (*this->_start);
}

template< class T, class Alloc>
typename	ft::vector<T, Alloc>::const_reference	ft::vector<T, Alloc>::front( void ) const
{
	return (*this->_start);
}

template< class T, class Alloc>
typename	ft::vector<T, Alloc>::reference	ft::vector<T, Alloc>::back( void )
{
	return (*this->_end);
}

template< class T, class Alloc>
typename	ft::vector<T, Alloc>::const_reference	ft::vector<T, Alloc>::back( void ) const
{
	return (*this->_end);
}

template< class T, class Alloc >
typename	ft::vector<T, Alloc>::value_type	*ft::vector<T, Alloc>::data( void )
{
	return (this->_start);
}

template< class T, class Alloc >
const typename	ft::vector<T, Alloc>::value_type	*ft::vector<T, Alloc>::data( void ) const
{
	return (this->_start);
}

template< class T, class Alloc>
template< class InputIterator >
void	ft::vector<T, Alloc>::assign(InputIterator first, InputIterator last)
{
	size_type	fl = ft::distance(first, last);
	size_type	sc = this->_capacity - this->_start;
	// size_type	se = this->_end - this->_start;

	if (fl > sc)
	{
		pointer	np = this->_alloc.allocate(fl);
		for (size_type i = 0; i < fl; i++)
			this->_alloc.construct(np + i, *(first + i));
		this->clear();
		this->_alloc.deallocate(this->_start, sc);
		
		this->_end = np + fl - 1;
		this->_start = np;
	}
}

template< class T, class Alloc >
void	ft::vector<T, Alloc>::clear( void )
{
	size_type	se = this->_end - this->_start;

	for (size_type i = 0; i < se; i++)
		this->_alloc.destroy(this->_start + i);
	this->_end = this->_start;
}

#endif