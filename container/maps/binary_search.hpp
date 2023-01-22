/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:25:16 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/22 21:16:42 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BINARY_SEARCH_HPP
#define	BINARY_SEARCH_HPP
#define BLACK false
#define RED   true
#define NULL  0
#include <iostream>

struct Node{
	bool color;
	int		value;
	Node	*parent;
	Node	*left;
	Node	*right;
};

typedef Node *Nodeptr;

class RBtree{
	private:
		Nodeptr	root;
		Nodeptr	TNULL;
	public:
	RBtree(){
		TNULL = new Node;
		TNULL->color = BLACK;
		TNULL->value = 0;
		TNULL->left = NULL;
		TNULL->right = NULL;
		root = TNULL;
	};

	~RBtree(){};
	Nodeptr	SearchParent(int value){
		Nodeptr	tmp = root;
		Nodeptr	parent = NULL;

		while (tmp != TNULL){
			parent = tmp;
			if (value < tmp->value)
				tmp = tmp->left;
			else if (value > tmp->value)
				tmp = tmp->right;
		}
		return (parent);
	}

	void	rotation_left(Nodeptr node){
		Nodeptr	parent;
		Nodeptr	child;

		child = node->right;
		parent = node->parent;

		node->right = child->left;
		if (child->left != TNULL)
			child->left->parent = node;
		child->parent = parent;
		if (!parent)
			root = child;
		else if (parent->left == node)
			parent->left = child;
		else
			parent->right = child;
		child->left = node;
		node->parent = child;
	}

	void	rotation_right(Nodeptr node){
		Nodeptr	parent;
		Nodeptr	child;

		child = node->left;
		parent = node->parent;

		node->left = child->right;
		if (child->right != TNULL)
			child->right->parent = node;
		child->parent = parent;
		if (!parent)
			root = child;
		else if (parent->left == node)
			parent->left = child;
		else
			parent->right = child;
		child->right = node;
		node->parent = child;
	}


	Nodeptr	getUncle(Nodeptr parent){
		Nodeptr grandparent = parent->parent;

		if (grandparent->left == parent)
			return (grandparent->right);
		else if (grandparent->right == parent)
			return (grandparent->left);
		return (NULL);
	}

	void	insert(int value){
		Nodeptr new_node = new Node;
		Nodeptr	parent = NULL;

		new_node->color = RED;
		new_node->left = TNULL;
		new_node->right = TNULL;
		new_node->value = value;
		new_node->parent = NULL;

		if (root == TNULL){
			new_node->color = BLACK;
			root = new_node;
			return;
		}
		parent = SearchParent(value);
		new_node->parent = parent;
		if (value < parent->value)
			parent->left = new_node;
		else
			parent->right = new_node;
		fix_properties(new_node);
	}

	void	fix_properties(Nodeptr	node){
		Nodeptr	parent = node->parent;
		Nodeptr	uncle= NULL;
		Nodeptr	grandparent = NULL;

		if (!parent){
			node->color = BLACK;
			return ;
		}

		if (parent->color== BLACK)
			return;
		
		grandparent = parent->parent;
		if (!grandparent){
			parent->color = BLACK;
			root = parent;
			return;
		}
		uncle = getUncle(parent);
		if (uncle && uncle->color == RED){
			parent->color = BLACK;
			grandparent->color = RED;
			uncle->color = BLACK;
			fix_properties(grandparent);
		}
		else if (parent == grandparent->left){
			if (node == parent->right){
				rotation_left(parent);
				parent = node;
			}
			rotation_right(grandparent);

			parent->color = BLACK;
			grandparent->color = RED;
		}
		else{
			if (node == parent->left) {
				rotation_right(parent);
				parent = node;
			}
			rotation_left(grandparent);
			parent->color = BLACK;
			grandparent->color = RED;	
		}
	}

	Nodeptr	minimum(Nodeptr root){
		Nodeptr	tmp= root;

		while (tmp->left != TNULL)
			tmp = tmp->left;
		return(tmp);
	}

	void	transplant(Nodeptr node, Nodeptr new_child){
		Nodeptr	parent = node->parent;

		if (parent == NULL)
			root = new_child;
		else if (parent->left == node)
			parent->left = new_child;
		else
			parent->right = new_child;
		new_child->parent = parent;
	}

	void deleteFix(Nodeptr x) {
		Nodeptr s;
		while (x != root && x->color == BLACK) {
			if (x == x->parent->left) {
				s = x->parent->right;
				if (s->color == RED) {
					s->color = BLACK;
					x->parent->color = RED;
					rotation_left(x->parent);
					s = x->parent->right;
				}

				if (s->left->color == BLACK && s->right->color == BLACK) {
					s->color = RED;
					x = x->parent;
				} 
				else {
					if (s->right->color == BLACK) {
						s->left->color = BLACK;
						s->color = RED;
						rotation_right(s);
						s = x->parent->right;
					}
					s->color = x->parent->color;
					x->parent->color = BLACK;
					s->right->color = BLACK;
					rotation_left(x->parent);
					x = root;
				}
			} 
			else {
				s = x->parent->left;
				if (s->color == RED) {
					s->color = BLACK;
					x->parent->color = RED;
					rotation_right(x->parent);
					s = x->parent->left;
				}

				if (s->right->color == BLACK && s->right->color == BLACK) {
					s->color = RED;
					x = x->parent;
				} 
				else {
					if (s->left->color == BLACK) {
						s->right->color = BLACK;
						s->color = RED;
						rotation_left(s);
						s = x->parent->left;
					}

					s->color = x->parent->color;
					x->parent->color = BLACK;
					s->left->color = BLACK;
					rotation_right(x->parent);
					x = root;
				}
			}
		}
		x->color = BLACK;
	}

	void	deleteNode(int value){
		Nodeptr	tmp = root;
		Nodeptr	node = TNULL;
		Nodeptr	min, fix;
		bool		og_color;
		
		while (tmp != TNULL){
			if (tmp->value == value) {
				node = tmp;
			}

			if (tmp->value <= value) {
				tmp = tmp->right;
			} else {
				tmp = tmp->left;
			}
		}

		if (node == TNULL){
			std::cout << "NO FOUND" << std::endl;
			return;
		}

		min = node;
		og_color = min->color;
		if (node->left == TNULL) {
			fix = node->right;
			transplant(node, node->right);
		} 
		else if (node->right == TNULL) {
			fix = node->left;
			transplant(node, node->left);
		}
		else {
			min = minimum(node->right);
			og_color = min->color;
			fix = min->right;
			if (min->parent == node) {
				fix->parent = min;
			} 
			else {
				transplant(min, min->right);
				min->right = node->right;
				min->right->parent = min;
			}

			transplant(node, min);
			min->left = node->left;
			min->left->parent = min;
			min->color = node->color;
		}
		delete node;
		if (og_color == BLACK) {
			deleteFix(fix);
		}
	}

	void print2DUtil(Nodeptr root, int space)
	{
		// Base case
		if (root == TNULL)
			return;
	
		// Increase distance between levels
		space += 10;
	
		// Process right child first
		print2DUtil(root->right, space);
	
		// Print current node after space
		// count
		std::cout << std::endl;
		for (int i = 10; i < space; i++)
			std::cout << " ";
		std::cout << root->value << "["<< (root->color == true ? "R" : "B")<<"]" << "\n";
	
		// Process left child
		print2DUtil(root->left, space);
	}

	void	print_tree(){
		print2DUtil(root, 0);
	}
};


#endif