#ifndef	ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>
# include <nullptr_t.hpp>
# include <node.hpp>

/**
 * Iterators have some special things:
 * - base iterator
 * - iterator_traits
 * 
 * The base class iterator has all the parameters that a iterator needs:
 * - value_type
 * - difference_type;
 * - pointer;
 * - reference;
 * - iterator category
 * 
 * This parameters are set inside the <container> class. Each container usese a different tipe of iterator 
 * (for example, vectors use the random_access_iterator and map uses the bidirectional iterator). Each of this iterator types
 * have more or less propieties.
 * 
 * The iterator_traits are used for accessing the information about a specific iterator.
 * 
 */

namespace	ft
{
	struct	random_access_iterator_tag	{};
	struct	bidirectional_iterator_tag	{};

	template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef	T			value_type;
		typedef	Distance	difference_type;
		typedef	Pointer		pointer;
		typedef	Reference	reference;
		typedef	Category	iterator_category;
	};

	template <class Iterator>
	class iterator_traits
	{
		public:
			typedef	typename	Iterator::value_type		value_type;
			typedef	typename	Iterator::difference_type	difference_type;
			typedef	typename	Iterator::pointer			pointer;
			typedef	typename	Iterator::reference			reference;
			typedef	typename	Iterator::iterator_category	iterator_category;
	};

	template <class T>
	class iterator_traits<T*>
	{
		public:
			typedef	T								value_type;
			typedef	std::ptrdiff_t					difference_type;
			typedef T*								pointer;
			typedef	T&								reference;
			typedef	ft::random_access_iterator_tag	iterator_category;
	};

	template <class T>
	class iterator_traits<const T*>
	{
		public:
			typedef	T								value_type;
			typedef	std::ptrdiff_t					difference_type;
			typedef const T*						pointer;
			typedef	const T&						reference;
			typedef	ft::random_access_iterator_tag	iterator_category;
	};

	template <class T>
	class random_access_iterator: public ft::iterator<ft::random_access_iterator_tag, T>
	{
		public:

			typedef	typename	ft::iterator<ft::random_access_iterator_tag, T>	base_it;
			typedef	typename	base_it::value_type								value_type;
			typedef	typename	base_it::difference_type						difference_type;
			typedef	typename	base_it::pointer								pointer;
			typedef	typename	base_it::reference								reference;
			typedef	typename	base_it::iterator_category						iterator_category;

		private:
			pointer	_ptr;

		public:

			random_access_iterator( void );
			random_access_iterator( pointer ptr );
			random_access_iterator( const random_access_iterator &r );

			virtual ~random_access_iterator(){};

			pointer	base( void ){ return (this->_ptr); };

			reference				operator[]( difference_type n );
			reference				operator*( void );
			pointer					operator->( void );

			difference_type			operator-( const random_access_iterator &r ) const;

			random_access_iterator	&operator=( const random_access_iterator &r );
			random_access_iterator	&operator+=( difference_type n );
			random_access_iterator	&operator-=( difference_type n);
			random_access_iterator	&operator++( void );
			random_access_iterator	&operator--( void );

			random_access_iterator	operator+( difference_type n ) const;
			random_access_iterator	operator-( difference_type n ) const;
			random_access_iterator	operator++( int );
			random_access_iterator	operator--( int );
			
			bool					operator==( const random_access_iterator &r ) const ;
			bool					operator!=( const random_access_iterator &r ) const ;
			bool					operator<( const random_access_iterator &r ) const ;
			bool					operator>( const random_access_iterator &r ) const ;
			bool					operator<=( const random_access_iterator &r ) const;
			bool					operator>=( const random_access_iterator &r ) const;
	};

	template< class T >
	ft::random_access_iterator<T>	operator+( typename ft::random_access_iterator<T>::difference_type n, const ft::random_access_iterator<T> &r )
	{
		return (r + n);
	};
	
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
			reverse_iterator( void ): _current(){};
			reverse_iterator( Iter x ): _current(x){};

			reverse_iterator( const reverse_iterator &other )
			{
				this->_current = other._current;
			};

			~reverse_iterator(){};

			reverse_iterator	&operator=( const reverse_iterator &other )
			{
				if (this != &other)
				{
					this->_current = other._current;
				}
				return (*this);
			};

			reference			operator[]( difference_type n ) const
			{
				iterator_type	tmp = this->_current;
				return (tmp[-n - 1]);
			};

			reference			operator*( void ) const
			{
				iterator_type	tmp = this->_current;
				return (*(tmp - 1));
			};

			pointer				operator->( void ) const
			{
				return (&(this->operator*()));
			};

			iterator_type		base( void ) const
			{
				return (this->_current);
			};

			reverse_iterator	&operator++( void )
			{
				--this->_current;
				return (*this);
			};

			reverse_iterator	&operator--( void )
			{
				++this->_current;
				return (*this);
			};

			reverse_iterator	operator++( int )
			{
				reverse_iterator	tmp = *this;
				++(*this);
				return (tmp);
			};

			reverse_iterator	operator--( int )
			{
				reverse_iterator	tmp = *this;
				--(*this);
				return (tmp);
			};

			reverse_iterator	operator+( difference_type n )
			{
				return (reverse_iterator(this->_current - n));
			};

			reverse_iterator	operator-( difference_type n )
			{
				return (reverse_iterator(this->_current + n));
			};

			reverse_iterator	operator+=( difference_type n )
			{
				this->_current -= n;
				return (*this);
			};

			reverse_iterator	operator-=( difference_type n )
			{
				this->_current += n;
				return (*this);
			};
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
			typedef				node<value_type>								node_type;

		private:
			node_type	*_node;

		public:
			
			bidirectional_iterator(node_type *node=NULL): _node(node)
			{
			};

			bidirectional_iterator(const bidirectional_iterator &other): _node(other._node)
			{
			};

			bidirectional_iterator	&operator=(const bidirectional_iterator &other)
			{
				if (this!=&other)
				{
					this->_node = other._node;
				}
				return(*this);
			}

			~bidirectional_iterator( void )
			{
			};

			bool operator==(const bidirectional_iterator& other) const
			{
				return (this->_node == other._node);
			};

    		bool operator!=(const bidirectional_iterator& other) const
			{
				return (this->_node != other._node);
			};

			bidirectional_iterator	&operator++( void )
			{
				// If the current node has a right node, then go to the leftest node of the right node.
				// We do this because if the current niode has a right node it means that is smaller than the parent node.
				if (this->_node->_rigth != ft::nullptr_t)
				{
					this->_node = this->_node->_rigth;
					while (this->_node->_left != ft::nullptr_t)
						this->_node = this->_node->_left;
				}
				else
				{
					// Else we climb the tree until the root or until we get to the left of a node
					node_type	*parent = this->_node->_parent;
					while (parent != ft::nullptr_t && this->_node == parent->_rigth)
					{
						this->_node = parent;
						parent = parent->_parent;
					}
					this->_node = parent;
				}
				return (*this);
			};

			bidirectional_iterator	operator++( int )
			{
				bidirectional_iterator	temp(*this);
				++(*this);
				return (temp);
			};

			bidirectional_iterator	&operator--( void )
			{
				// If the current node has a left node, then go to the rightest node of the left node.
				// We do this because if the current node has a left node it means that is smaller than the parent node.
				if (this->_node->_left != ft::nullptr_t)
				{
					this->_node = this->_node->_left;
					while (this->_node->_rigth != ft::nullptr_t)
						this->_node = this->_node->_rigth;
				}
				else
				{
					// Else we climb the tree until the root or until we get to the right of a node
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

			bidirectional_iterator	operator--( int )
			{
				bidirectional_iterator	temp(*this);
				--(*this);
				return (temp);
			};

			reference	operator*( void ) const
			{
				return(this->_node->_data);
			};
	};
}

# include <iterator.ipp>

#endif