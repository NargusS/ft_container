/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:14:37 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/27 19:23:17 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft{
	template <class Pair>
	struct Node{
		bool		color;
		Pair		value;
		Node<Pair>	*parent;
		Node<Pair>	*left;
		Node<Pair>	*right;
		public:
			Node():color(BLACK), value(), parent(NULL), left(NULL), right(NULL){};
			Node(Node<Pair>*parent, const Pair& new_pair):color(RED), value(new_pair), parent(parent), left(NULL), right(NULL){};
			Node(const Node<Pair>& other):color(other.color), value(other.value), parent(other.parent), left(other.left), right(other.right){};

			Node<Pair>&	operator=(const Node<Pair>& other){
				if (this != &other){
					this->color = other.color;
					this->value = other.value;
					this->parent = other.parent;
					this->left = other.left;
					this->right= other.right;
				}
				return(*this);
			}

			~Node(){};

			bool is_null(){
				return (parent == NULL && left == NULL && right == NULL);
			}

			void	swap(Node&	other){
				Node tmp;

				tmp.color = this->color;
				tmp.value = this->value;
				tmp.parent = this->parent;
				tmp.left = this->left;
				tmp.right= this->right;

				this->color = other.color;
				this->value = other.value;
				this->parent = other.parent;
				this->left = other.left;
				this->right= other.right;

				other.color = tmp.color;
				other.value = tmp.value;
				other.parent = tmp.parent;
				other.left = tmp.left;
				other.right= tmp.right;
			}
	};

	template <class P1, class P2>
	bool	operator==(const Node<P1>& N1, const Node<P2> N2){
		return (&N1 == &N2);
	}

	template <class P1, class P2>
	bool	operator!=(const Node<P1>& N1, const Node<P2> N2){
		return (!(N1 == N2));
	}
}