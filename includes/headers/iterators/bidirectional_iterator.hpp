#ifndef	BIDIRECTIONAL_ITERATOR_HPP
#	define	BIDIRECTIONAL_ITERATOR_HPP

namespace ft
{	
	template< class T >
	class bidirectional_iterator: public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
			typedef	typename	ft::iterator<ft::random_access_iterator_tag, T>	base_it;
			typedef	typename	base_it::value_type								value_type;
			typedef	typename	base_it::difference_type						difference_type;
			typedef	typename	base_it::pointer								pointer;
			typedef	typename	base_it::reference								reference;
			typedef	typename	base_it::iterator_category						iterator_category;
			typedef				ft::node<value_type>							node_type;

			node_type	*_node;
			node_type	*_prev;
			
			bidirectional_iterator(node_type *node=ft::nullptr_t);
			bidirectional_iterator(const bidirectional_iterator &other);
			bidirectional_iterator	&operator=(const bidirectional_iterator &other);

			~bidirectional_iterator( void );

			bool operator==(const bidirectional_iterator& other) const;
    		bool operator!=(const bidirectional_iterator& other) const;

			bidirectional_iterator	&operator++( void );
			bidirectional_iterator	operator++( int );
			bidirectional_iterator	&operator--( void );
			bidirectional_iterator	operator--( int );

			reference	operator*( void ) const;
			pointer		operator->( void ) const;
	};
}

#include <bidirectional_iterator.ipp>

#endif