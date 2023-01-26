/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:49:55 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/26 15:09:07 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include "../../std_functions/pair.hpp"
#include <functional>
#include <memory>
#include "./binary_search.hpp"

namespace ft{
	template <class value_type>
	class	value_compare : public std::binary_function<value_type, value_type, bool>{
		protected:
			Compare _comp;
		public:
			value_compare(){};
			value_compare(Compare	comp):_comp(comp){};
		bool operator()(const value_type& x, const value_type& y)const {
			return (comp(x.first, y.first));
		}
		bool operator()(const value_type& x, const key_type& y)const {
			return (comp(x.first, y));
		}
		bool operator()(const key_type& x, const value_type& y)const {
			return (comp(x, y.first));
		}
	};

	template<class Key,class T,class Compare = std::less<Key>,class Allocator = std::allocator<ft::pair<const Key, T>>>
	class map
	{
		public:
			typedef	Key	key_type;
			typedef	T	mapped_type;
			typedef	typename ft::pair<const key_type, mapped_type>	value_type;
			typedef	typename std::size_t		size_type;
			typedef	typename std::ptrdiff_t	difference_type;
			typedef	Compare			key_compare;
			typedef	Allocator		allocator_type;
			typedef value_type&		reference;
			typedef const value_type&		const_reference;
			typedef	typename Allocator::pointer	pointer;
			typedef	typename Allocator::const_pointer	const_pointer;
			typedef	typename ft::iterator_map<value_type>	iterator;
			typedef	typename ft::iterator_map<const value_type>	const_iterator;
			typedef	typename ft::reverse_iterator<iterator>	reverse_iterator;
			typedef	typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		private:
			key_compare     _key_comp;
			value_compare   _value_comp;
			RBtree<value_type, key_type, value_compare, allocator_type>   _tree;
		public:
			map():_tree(Rbtree()), _size(0), _alloc(allocator_type()), _comp(std::less){};
			explicit map( const Compare& comp,const Allocator& alloc = Allocator()){
				_tree = Rbtree();
				_size = 0;
				_alloc = allocator_type();
				_capacity = 0;
				_comp = comp;
			}

			template< class InputIt >
			map( InputIt first, InputIt last,const Compare& comp = Compare(),const Allocator& alloc = Allocator()){

			}
			map( const map& other );
			~map();
			allocator_type	get_allocator() const{
				return (_alloc);
			}

			T&	at(const &key_type key){
				//std_out_of_range
			}

			T&	operator[](const &key_type key) const{
				
			}

			bool	empty(){
				if (size == 0)
					return (true);
				return (false);
			}

			size_type	size(){
				return (_size);
			}

			size_type	max_size(){
				return (_alloc.max_size());
			}

			std::pair<iterator, bool> insert( const value_type& value ){

			}

			template< class InputIt >
			void insert( InputIt first, InputIt last ){

			}

			key_compare key_comp() const{
				return (_key_comp);
			}

			std::map::value_compare value_comp() const{
				return(_value_comp);
			}
	};
};

#endif