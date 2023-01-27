/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:49:55 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/27 18:19:14 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include "../../std_functions/pair.hpp"
#include "../../std_functions/equal.hpp"
#include "../../std_functions/lexicographical_compare.hpp"
#include <functional>
#include <memory>
#include "./binary_search.hpp"
#include "../../iterators/reverse_iterator.hpp"

namespace ft{
	template<class Key,class T,class Compare = std::less< Key >,class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		private:
			typedef Node<ft::pair<const Key, T> >	node_type;
			typedef typename Allocator::template rebind<node_type>::other 	node_allocator_type;
		public:
			class value_compare;
			typedef	Key	key_type;
			typedef	T	mapped_type;
			typedef	ft::pair<const key_type, mapped_type>	value_type;
			typedef	Compare			key_compare;
			typedef	Allocator		allocator_type;
			typedef typename allocator_type::reference		reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef	typename allocator_type::pointer	pointer;
			typedef	typename allocator_type::const_pointer	const_pointer;
			typedef	ft::RBiterator<value_type, node_type>	iterator;
			typedef	ft::RBiterator<const value_type, node_type>	const_iterator;
			typedef	ft::reverse_iterator<iterator>	reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef	typename std::size_t		size_type;
			typedef	typename std::ptrdiff_t	difference_type;

		private:
			typedef RBtree< value_type, value_compare, node_allocator_type > tree_type;
		private:
			allocator_type	_alloc;
			key_compare     _key_comp;
			tree_type		_tree;
		public:
			explicit map( const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type()): 
				_alloc(alloc),
				_key_comp(comp),
				_tree(value_compare(comp), node_allocator_type(alloc))
			{}

			template< class InputIt >
			map( InputIt first, InputIt last,const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type()):
				_alloc(alloc),
				_key_comp(comp),
				_tree(value_compare(comp), node_allocator_type(alloc))
			{
				insert(first, last);
			}

			map( const map& other ){
				_alloc = other._alloc;
				_key_comp = other._key_comp;
				_tree = other._tree;
			};


			map& operator=(map const& other)
			{
				if (this != &other)
				{
					_key_comp = other._key_comp;
					_tree = other._tree;
				}
				return *this;
			}

			~map(){};

			iterator	begin(){
				return (iterator(_tree.begin()));
			}

			const_iterator	begin()const{
				return (const_iterator(_tree.begin()));
			}

			iterator	end(){
				return (iterator(_tree.end()));
			}

			const_iterator	end()const{
				return (const_iterator(_tree.end()));
			}

			iterator	rbegin(){
				return (reverse_iterator(_tree.end()));
			}

			const_iterator	rbegin()const{
				return (const_reverse_iterator(_tree.end()));
			}

			iterator	rend(){
				return (reverse_iterator(_tree.begin()));
			}

			const_iterator	rend()const{
				return (const_reverse_iterator(_tree.begin()));
			}

			allocator_type	get_allocator() const{
				return (_alloc);
			}

			// T&	at(const &key_type key){
			// 	//std_out_of_range
			// }

			mapped_type& operator[](key_type const& key)
			{
				return (*((this->insert(ft::make_pair(key, mapped_type()))).first)).second;
			}

			bool	empty(){
				return (_tree.size() == 0);
			}

			size_type	size(){
				return (_tree.size());
			}

			size_type	max_size(){
				return (_tree.get_allocator().max_size());
			}

			std::pair<iterator, bool> insert( const value_type& value ){
				return (_tree->insert(value));
			}

			iterator insert (iterator position, const value_type& val){
				(void)position;
				return (insert(val).first);
			}

			template< class InputIt >
			void insert( InputIt first, InputIt last ){
				for (InputIt it = first; it != last; it++){
					insert(*it);
				}
			}

			void erase (iterator position){
				if (position == end())
					return;
				_tree.deleteNode(*position);
			}

			size_type erase (const key_type& k){
				iterator position = find(k);
				if (position == end())
					return (0);
				erase(position);
				return (1);
			}

			void erase (iterator first, iterator last){
				if (first == begin() && last == end()){
					clear();
					return;
				}
				iterator it = first;
				iterator eraser;

				while (it != last){
					eraser = it;
					it++;
					erase(eraser);
				}
			}

			void	clear(){
				_tree.clear();
			}

			void	swap(map& other){
				key_type	tmp;
				_tree.swap(other);

				tmp = other._key_comp;
				_key_comp = other._key_comp;
				other._key_comp = tmp;
			}

			key_compare key_comp() const{
				return (_key_comp);
			}

			value_compare value_comp() const{
				return(_tree.comp());
			}

			// iterator	find(const key_type& k){
			// 	node_type*	node = _tree.root;

			// 	while (node != TNULL){
			// 		if (_key_comp()(k, node->value.first))
			// 			node = node->left;
			// 		else if (_key_comp()(node->value.first, k))
			// 			node = node->right;
			// 		else
			// 			break;
			// 	}
			// 	return (iterator(k));
			// }

			// const_iterator	find(const key_type& k){
			// 	node_type*	node = _tree.root;

			// 	while (node != TNULL){
			// 		if (_key_comp()(k, node->value.first))
			// 			node = node->left;
			// 		else if (_key_comp()(node->value.first, k))
			// 			node = node->right;
			// 		else
			// 			break;
			// 	}
			// 	return (const_iterator(k));
			// }

			template <class It>
			It	find(const key_type& k){
				node_type*	node = _tree.root;

				while (node->is_null()){
					if (_key_comp()(k, node->value.first))
						node = node->left;
					else if (_key_comp()(node->value.first, k))
						node = node->right;
					else
						break;
				}
				return (It(k));
			}

			size_type	count(const key_type& k){
				iterator position = begin();

				for (; position != end(); position++){
					if ((*position).first == k)
						break;
				}
				if (position == end())
					return (0);
				return (1);
			}


			iterator lower_bound (const key_type& k){
				iterator first = begin();

				for (; first != end(); first++){
					if (!_key_comp()((*first).first, k))
						break;
				}
				return (first);
			}
			
			const_iterator lower_bound (const key_type& k) const{
				iterator first = begin();

				for (; first != end(); first++){
					if (!_key_comp()((*first).first, k))
						break;
				}
				return (const_iterator(first));
			}

			iterator upper_bound (const key_type& k){
				iterator first = begin();

				for (; first != end(); first++){
					if (!_key_comp()((*first).first, k))
						break;
				}
				return (first);
			}
			
			const_iterator upper_bound (const key_type& k) const{
				iterator first = begin();

				for (; first != end(); first++){
					if (_key_comp()(k, (*first).first))
						break;
				}
				return (const_iterator(first));
			}

			ft::pair<iterator,iterator> equal_range( const Key& key ){
				return (ft::make_pair(lower_bound(key), upper_bound(key)));
			}

			ft::pair<const_iterator,const_iterator> equal_range( const Key& key )const{
				return (ft::make_pair(lower_bound(key), upper_bound(key)));
			}

		class value_compare : public std::binary_function< value_type, value_type, bool >
		{
			friend class map;

			protected:
				Compare _comp;

				value_compare(Compare comp) :
					_comp(comp)
				{
				}

			public:
				bool operator()(value_type const& x, value_type const& y)
				{
					return this->_comp(x.first, y.first);
				}
		};
	};

	template< class Key, class T, class Compare, class Alloc >
	void swap( ft::map<Key,T,Compare,Alloc>& lhs,ft::map<Key,T,Compare,Alloc>& rhs ){
		lhs.swap(rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs,const ft::map<Key,T,Compare,Alloc>& rhs ){
		return ((&lhs == &rhs) || ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin())));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs,const ft::map<Key,T,Compare,Alloc>& rhs ){
		return (!(lhs == rhs));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs,const ft::map<Key,T,Compare,Alloc>& rhs ){
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs,const ft::map<Key,T,Compare,Alloc>& rhs ){
		return (rhs < lhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs,const ft::map<Key,T,Compare,Alloc>& rhs ){
		return (!(lhs > rhs));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs,const ft::map<Key,T,Compare,Alloc>& rhs ){
		return (!(lhs < rhs));
	}
};

#endif