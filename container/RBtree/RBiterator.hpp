/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBiterator.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:12:42 by achane-l          #+#    #+#             */
/*   Updated: 2023/02/08 16:15:38 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBITERATOR_HPP
#define RBITERATOR_HPP
#include "../../iterators/iterator_traits.hpp"

namespace ft{
	template <class Pair, class Node>
	struct	RBiterator : public ft::iterator<std::bidirectional_iterator_tag, Pair>{
		public:
			typedef	Pair&		reference;
			typedef	const Pair&	const_reference;
			typedef	Pair*		pointer;
			typedef	const Pair*	const_pointer;
		private:
			Node*	_node;
		public:
			RBiterator():_node(NULL){};

			template <class _Node>
			explicit RBiterator(_Node* other):_node(other){};

			template< class _Pair, class _Node >
			RBiterator(RBiterator< _Pair, _Node > const& x) : _node(x.base()){}

			template< class _Pair, class _Node >
			RBiterator& operator=(RBiterator< _Pair const, _Node > const& x)
			{
				if (this != &x)
					_node = x._node;
				return *this;
			}

			Node* base() const
			{
				return _node;
			}

			reference operator*()
			{
				return _node->value;
			}

			const_reference operator*() const
			{
				return _node->value;
			}

			pointer operator->()
			{
				return &_node->value;
			}

			const_pointer operator->() const
			{
				return &_node->value;
			}

			RBiterator&	operator++(){
				if (!(_node->right->is_null())){
					_node = _node->right;
					while (!(_node->left->is_null()))
						_node = _node->left;
				}
				else{
					while (!_node->parent->is_null() && _node == _node->parent->right)
						_node = _node->parent;
					_node = _node->parent;
				}
				return (*this);
			}

			RBiterator	operator++(int){
				RBiterator tmp(*this);
				++(*this);
				return (tmp);
			}

			RBiterator&	operator--(){
				if (!(_node->left->is_null())){
					_node = _node->left;
					while (!(_node->right->is_null()))
						_node = _node->right;
				}
				else{
					while (!_node->parent->is_null() && _node == _node->parent->left)
						_node = _node->parent;
					_node = _node->parent;
				}
				return (*this);
			}

			RBiterator	operator--(int){
				RBiterator tmp(*this);
				--(*this);
				return (tmp);
			}
	};

	template <class P1, class N1, class P2, class N2>
	bool	operator==(const RBiterator<P1, N1>& it1, const RBiterator<P2, N2>& it2){
		return (it1.base() == it2.base());
	}

	template <class P1, class N1, class P2, class N2>
	bool	operator!=(const RBiterator<P1, N1>& it1, const RBiterator<P2, N2>& it2){
		return (!(it1 == it2));
	}
}

#endif