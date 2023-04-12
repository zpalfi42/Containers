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

	if (fl)
	{
		this->_begin = this->_alloc.allocate(fl);
		for (long i = 0; (first + i) != last; i++)
			this->_alloc.construct(this->_begin + i, *(first + i));
		this->_capacity = this->_begin + fl;
		this->_end = this->_begin + fl;
	}
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

	this->clear();
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

		this->_alloc = x._alloc;
		this->clear();
		if (tsc < xsc)
		{
			if (tsc)
			{
				for (long i = 0; i < tsc; i++)
					this->_alloc.destroy(this->_begin + i);
				this->_alloc.deallocate(this->_begin, tsc);
			}

			this->_begin = this->_alloc.allocate(xse);
			this->_capacity = this->_begin + xse;
		}
		for (long i = 0; i < xse; i++)
			this->_alloc.construct(this->_begin + i, *(x._begin + i));
		this->_end = this->_begin + xse;
	}
	return (*this);
}

template< class T, class Alloc>
typename ft::vector<T, Alloc>::allocator_type	ft::vector<T, Alloc>::get_allocator( void )
{
	return (this->_alloc);
}

template< class T, class Alloc >
typename ft::vector<T, Alloc>::iterator	ft::vector<T, Alloc>::begin( void )
{
	return (iterator(this->_begin));
}

template< class T, class Alloc >
typename ft::vector<T, Alloc>::const_iterator	ft::vector<T, Alloc>::begin( void ) const
{
	return (const_iterator(this->_begin));
}

template< class T, class Alloc >
typename ft::vector<T, Alloc>::iterator	ft::vector<T, Alloc>::end( void )
{
	return (iterator(this->_end));
}

template< class T, class Alloc >
typename ft::vector<T, Alloc>::const_iterator	ft::vector<T, Alloc>::end( void ) const
{
	return (const_iterator(this->_end));
}

template< class T, class Alloc >
typename ft::vector<T, Alloc>::reverse_iterator	ft::vector<T, Alloc>::rbegin( void )
{
	return (reverse_iterator(this->end()));
}

template< class T, class Alloc >
typename ft::vector<T, Alloc>::const_reverse_iterator	ft::vector<T, Alloc>::rbegin( void ) const
{
	return (const_reverse_iterator(this->end()));
}

template< class T, class Alloc >
typename ft::vector<T, Alloc>::reverse_iterator	ft::vector<T, Alloc>::rend( void )
{
	return (reverse_iterator(this->begin()));
}

template< class T, class Alloc >
typename ft::vector<T, Alloc>::const_reverse_iterator	ft::vector<T, Alloc>::rend( void ) const
{
	return (const_reverse_iterator(this->begin()));
}

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
		this->_alloc.construct(np + i, *(this->_begin + i));
	this->clear();
	if (sc)
		this->_alloc.deallocate(this->_begin, sc);
	this->_begin = np;
	this->_end = this->_begin + se;
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
	else
		this->reserve(n);
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
	if (sc)
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

	this->clear();
	if (fl > sc)
	{
		if (sc)
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
	if (sc)
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
	if (this->capacity() == 0)
		this->reserve(1);
	else if (this->_end == this->_capacity)
		this->reserve((this->capacity() * 2));
	this->_alloc.construct(this->_end, val);
	this->_end++;
}

template< class T, class Alloc>
void	ft::vector<T, Alloc>::pop_back( void )
{
	if (this->size() == 0)
		return ;
	this->_alloc.destroy(this->_end);
	this->_end--;
}

template< class T, class Alloc >
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::insert( iterator position, const value_type &val )
{
	typename ft::vector<T>::iterator	it = this->begin();
	typename ft::vector<T>::iterator	end	= this->end();
	int	i = position - it;

	if (position < it || it >= end)
		throw(std::logic_error("Error: vector"));
	if (this->capacity() == this->size())
		this->reserve(this->capacity() * 2);

	pointer	paux = this->_begin + i;
	it += i;

	value_type	aux;
	value_type	value = val;
	while (it != end)
	{
		aux = *paux;
		this->_alloc.destroy(paux);
		this->_alloc.construct(paux, value);
		value = aux;
		it++;
		paux++;
	}
	this->_alloc.construct(paux, value);
	this->_end++;
	return (position);
}

template< class T, class Alloc >
void	ft::vector<T, Alloc>::insert( iterator position, size_type n, const value_type &val)
{
	typename ft::vector<T>::iterator	it = this->begin();
	typename ft::vector<T>::iterator	end	= this->end();
	size_t	j = position - it;

	if (position < it || position > end)
		throw(std::logic_error("Error: vector"));

	size_type	a;
	if ((n + this->capacity()) > this->capacity() * 2)
		a = n + this->capacity();
	else
		a = this->capacity() * 2;	
	pointer	np = this->_alloc.allocate(a);
	for (size_t i = 0; i < j; i++)
		this->_alloc.construct((np + i), *(it + i));
	for (size_t i = 0; i < n; i++)
		this->_alloc.construct((np + j + i), val);
	for (size_t i = 0; i < (size_t)(end - it - j); i++)
		this->_alloc.construct((np + j + n + i), *(it + i + j));
	
	this->clear();
	if (this->capacity())
		this->_alloc.deallocate(this->_begin, this->capacity());

	this->_begin = np;
	this->_capacity = np + a;
	this->_end = np + (end - it) + n;
	
}

template< class T, class Alloc>
template< class InputIterator >
void	ft::vector<T, Alloc>::insert( iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type *)
{
	typename ft::vector<T>::iterator	it = this->begin();
	typename ft::vector<T>::iterator	end	= this->end();
	size_t	j = position - it;
	size_t	n = last - first;

	if (position < it || position >= end)
		throw(std::logic_error("Error: vector"));
	
	size_type	a;
	if ((n + this->capacity()) > this->capacity() * 2)
		a = n + this->capacity();
	else
		a = this->capacity() * 2;

	pointer	np = this->_alloc.allocate(a);
	for (size_t i = 0; i < j; i++)
		this->_alloc.construct((np + i), *(it + i));
	for (size_t i = 0; i < n; i++)
		this->_alloc.construct((np + j + i), *(first + i));
	for (size_t i = 0; i < (size_t)(end - it - j); i++)
		this->_alloc.construct((np + j + n + i), *(it + i + j));
	
	this->clear();
	if (this->capacity())
		this->_alloc.deallocate(this->_begin, this->capacity());

	this->_begin = np;
	this->_capacity = np + a;
	this->_end = np + (end - it) + n;
}

template < class T, class Alloc >
typename ft::vector<T, Alloc>::iterator	ft::vector<T, Alloc>::erase(iterator position)
{
	typename ft::vector<T>::iterator	it = this->begin();
	typename ft::vector<T>::iterator	end = this->end();

	if (position < it || position >= end)
		throw(std::logic_error("Error: vector"));
	
	pointer	p = &(*position);

	for (long i = 0; i < end - position - 1; i++)
	{
		this->_alloc.destroy(p + i);
		this->_alloc.construct(p + i, *(p + i + 1));
	}
	this->_alloc.destroy(this->_end);
	this->_end--;
	return (position);
}

template < class T, class Alloc >
typename ft::vector<T, Alloc>::iterator	ft::vector<T, Alloc>::erase(iterator first, iterator last)
{
	typename ft::vector<T>::iterator	it = this->begin();
	typename ft::vector<T>::iterator	end = this->end();

	if (first < it || first > end || last < it || last > end)
		throw(std::logic_error("Error: vector"));
	
	pointer	p = &(*first);
	pointer	l = &(*last);

	int i = 0;
	while ((first + i) != end)
	{
		this->_alloc.destroy(p + i);
		if ((last + i) < end)
		{
			this->_alloc.construct(p + i, *(l + i));
			this->_end = p + i + 1;
		}
		i++;
	}

	return (first);

	// difference_type	diff = last - first;
	// size_type		start = first - begin();

	// for (iterator it = first; it != last; it++)
	// 	this->_alloc.destroy(&(*it));
	// this->_end = this->_end - diff + 1;
	// if ( start < size_type(this->_end - this->_begin ))
	// {
	// 	for (size_type i = start; i < size_type(this->_end - this->_begin); i++)
	// 	{
	// 		this->_alloc.construct(&(*(this->_begin + i)), this->_begin + i - diff + 1);
	// 		this->_alloc.destroy(&(*(this->_begin + i - diff + 1)));
	// 	}
	// }
	// return (first);
}

template< class T, class Alloc >
void		ft::vector<T, Alloc>::swap( vector &x )
{
	pointer			cpyBegin = x._begin;
	pointer			cpyEnd = x._end;
	pointer			cpyCapacity = x._capacity;
	allocator_type	cpyAlloc = x._alloc;

	x._begin = this->_begin;
	x._end = this->_end;
	x._capacity = this->_capacity;
	x._alloc = this->_alloc;
	this->_begin = cpyBegin;
	this->_end = cpyEnd;
	this->_capacity = cpyCapacity;
	this->_alloc = cpyAlloc;
}

template< class T, class Alloc >
void	ft::vector<T, Alloc>::clear( void )
{
	this->erase(this->begin(), this->end());
}

#endif