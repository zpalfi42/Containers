#ifndef MAP_IPP
# define	MAP_IPP

#include <map.hpp>

template< class Key, class T, class Compare, class Allocator >
ft::map<Key, T, Compare, Allocator>::map( const typename ft::map<Key, T, Compare, Allocator>::allocator_type& alloc = ft::map<Key, T, Compare, Allocator>::allocator_type() ): _size(0), _root(ft::nullptr_t), _allocator(ft::map<Key, T>::alloc){};


#endif