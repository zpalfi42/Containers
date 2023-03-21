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
			node		*_right;
			value_type	_data;

			node(const value_type& data = value_type(), node* parent = ft::nullptr_t, node* left = ft::nullptr_t, node* right = ft::nullptr_t): _parent(parent), _left(left), _right(right), _data(data)
			{
			};

			~node( void )
			{
			};

			bool				isLeaf( void ) const
			{
				return (this->_left == ft::nullptr_t && this->_right == ft::nullptr_t);
			};

			bool				isRoot( void ) const
			{
				return (this->_parent == ft::nullptr_t);
			};

			bool				hasLeftChild( void ) const
			{
				return (this->_left != ft::nullptr_t);
			};

			bool				hasRightChild( void ) const
			{
				return (this->_right != ft::nullptr_t);
			};

			node				*getParent( void ) const
			{
				return (this->_parent);
			};

			node				*getLeftChild( void ) const
			{
				return	(this->_left);
			};

			node				*getRightChild( void ) const
			{
				return (this->_right);
			};

			const value_type	&getData( void ) const
			{
				return (this->_data);
			};

			void				setParent(node *parent)
			{
				this->_parent = parent;
			};

			void				setLeftChild(node *left)
			{
				this->_left = left;
			};

			void				setRightChild(node *right)
			{
				this->_right = right;
			};

			void				setData(const value_type &data)
			{
				this->_data = data;
			};
			
			bool				operator==(const node &other) const
			{
				return (this->_data == other._data);
			};

			bool				operator!=(const node &other) const
			{
				return (!(this == other));
			};

			bool				operator<(const node &other) const
			{
				return (this->_data < other._data);
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