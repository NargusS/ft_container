/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBiterator.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:12:42 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/27 19:24:26 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft{
	template <class Pair, class Node>
	struct	RBiterator{
		public:
			typedef	Pair&	reference;
			typedef	const Pair&	const_reference;
			typedef	Pair*	pointer;
			typedef	const Pair*	const_pointer;
		private:
			Node*	_node;
		public:
			RBiterator():_node(NULL){};

			template <class _Node>
			explicit RBiterator(_Node* other):_node(other){};

			template< class _Pair, class _Node >
			RBiterator(RBiterator< _Pair, _Node > const& x) :
				_node(x.base())
			{
			}

			template< class _Pair, class _Node >
			RBiterator& operator=(RBiterator< _Pair const, _Node > const& x)
			{
				if (this != &x)
					this->_node = x._node;
				return *this;
			}

			Node* base() const
			{
				return this->_node;
			}

			reference operator*()
			{
				return this->_node->value;
			}

			const_reference operator*() const
			{
				return this->_node->value;
			}

			pointer operator->()
			{
				return &this->_node->value;
			}

			const_pointer operator->() const
			{
				return &this->_node->value;
			}

			RBiterator&	operator++(){
				if (!_node->is_null() && !(_node->right->is_null())){
					_node = _node->right;
					while (!(_node->left->is_null()))
						_node = _node->left;
				}
				else{
					while (!_node->parent && !_node->parent->right->is_null())
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
				if (!_node->is_null() && !(_node->left->is_null())){
					_node = _node->left;
					while (!(_node->right->is_null()))
						_node = _node->right;
				}
				else{
					while (!_node->parent && !_node->parent->left->is_null())
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

