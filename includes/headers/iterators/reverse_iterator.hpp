#ifndef	REVERSE_ITERATOR_HPP
#	define	REVERSE_ITERATOR_HPP

namespace	ft
{
		
	template< class Iter >
	class reverse_iterator
	{
		public:
			typedef				Iter											iterator_type;
			typedef	typename	ft::iterator_traits<Iter>::iterator_category	iterator_category;
			typedef	typename	ft::iterator_traits<Iter>::value_type			value_type;
			typedef	typename	ft::iterator_traits<Iter>::difference_type		difference_type;
			typedef	typename	ft::iterator_traits<Iter>::pointer				pointer;
			typedef	typename	ft::iterator_traits<Iter>::reference			reference;
		protected:
			iterator_type		_current;
		public:
			reverse_iterator( void );
			reverse_iterator( Iter x );

			template <class It>
			reverse_iterator( const reverse_iterator<It> &other );

			virtual ~reverse_iterator();

			template <class It>
			reverse_iterator	&operator=( const reverse_iterator<It> &other );

			reference			operator[]( difference_type n ) const;
			reference			operator*( void ) const;
			pointer				operator->( void ) const;

			iterator_type		base( void ) const;

			reverse_iterator	&operator++( void );
			reverse_iterator	&operator--( void );

			reverse_iterator	operator++( int );
			reverse_iterator	operator--( int );
			reverse_iterator	operator+( difference_type n );
			reverse_iterator	operator-( difference_type n );
			reverse_iterator	operator+=( difference_type n );
			reverse_iterator	operator-=( difference_type n );
	};

	template< class Iterator1, class Iterator2 >
	bool operator==( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
	{
		return (lhs.base() == rhs.base());
	};
	
	template< class Iterator1, class Iterator2 >
	bool operator!=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
	{
		return (lhs.base() != rhs.base());
	};

	template< class Iterator1, class Iterator2 >
	bool operator<( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
	{
		return (lhs.base() > rhs.base());
	};

	template< class Iterator1, class Iterator2 >
	bool operator>( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
	{
		return (lhs.base() < rhs.base());
	};

	template< class Iterator1, class Iterator2 >
	bool operator<=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
	{
		return (lhs.base() >= rhs.base());
	};

	template< class Iterator1, class Iterator2 >
	bool operator>=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
	{
		return (lhs.base() <= rhs.base());
	};

	template< class Iter >
	reverse_iterator<Iter>	operator+( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it )
	{
		return (reverse_iterator<Iter>(it.base() - n));
	};

	template< class Iterator1, class Iterator2 >
	typename reverse_iterator<Iterator1>::difference_type	operator-( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
	{
		return (rhs.base() - lhs.base());
	};
}

# include <reverse_iterator.ipp>

#endif