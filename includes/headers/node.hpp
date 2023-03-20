#ifndef	NODE_HPP
# define NODE_HPP

# include <nullptr_t.hpp>

namespace ft
{
	template< class T >
	class node
	{
		public:
			typedef	T	value_type;

			node		*_parent;
			node		*_left;
			node		*_rigth;
			value_type	_data;

			node(const value_type& data = value_type(), node* parent = ft::nullptr_t, node* left = ft::nullptr_t, node* right = ft::nullptr_t): _parent(parent), _left(left), _rigth(right), _data(data)
			{
			};

			~node( void )
			{
			};
	
			value_type	getData( void )
			{
				return(this->_data);
			};

			node	getLeft( void )
			{
				return(this->_left);
			};

			node	getRight( void )
			{
				return(this->_rigth);
			};

			// insert
			// find
			// min
			// max
			// successor
			// predecessor
			// remove
	};
}
#endif