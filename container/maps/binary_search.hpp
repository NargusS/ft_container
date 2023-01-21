/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:58:02 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/21 19:00:33 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP
#define	RED true
#define	BLACK false
#include <iostream>

class Node{
	public:
		bool		color;
		int			value;
		Node		*parent;
		Node		*left_child;
		Node		*right_child;
	Node(bool color, int value, Node *parent):color(color), value(value), parent(parent), left_child(0), right_child(0){};
	~Node(){};
};

Node	*SearchParentValue(Node *node, int value){
	Node *parent = NULL;

	while (node){
		parent = node;
		if (value < node->value)
			node = node->left_child;
		else if (value > node->value)
			node = node->right_child;
		else
			return(parent);// break faire quelque chose
	}
	return (parent);//pareil
}

Node	*getUncle(Node *parent){
	Node *grandparent = parent->parent;

	if (grandparent->left_child == parent)
		return (grandparent->right_child);
	else if (grandparent->right_child == parent)
		return (grandparent->left_child);
	return (0);
}

void	left_rotation(Node **root, Node *node){
	Node *parent;
	Node *child;

	child = node->right_child;
	parent = node->parent;

	node->right_child = child->left_child;
	if (child->left_child)
		child->left_child->parent = node;
	child->left_child = node;
	node->parent = child;

	if (!parent)
		*root = child;
	else if (parent->left_child == node)
		parent->left_child = child;
	else if (parent->right_child == node)
		parent->right_child = child;

	if (child)
		child->parent = parent;
}

void	right_rotation(Node **root, Node *node){
	Node *parent;
	Node *child;

	child = node->left_child;
	parent = node->parent;

	node->left_child = child->right_child;
	if (child->right_child)
		child->right_child->parent = node;
	child->right_child = node;
	node->parent = child;

	if (!parent)
		*root = child;
	else if (parent->left_child == node)
		parent->left_child = child;
	else if (parent->right_child == node)
		parent->right_child = child;

	if (child)
		child->parent = parent;
}

void	fix_properties(Node **root, Node *node){
	Node *uncle = 0;
	Node *grandparent = 0;
	Node *parent = node->parent;

	if (!parent || (parent && parent->color == BLACK))
		return ;
	grandparent = parent->parent;
	if (!grandparent){
		parent->color = BLACK;
		*root = parent;
		return;
	}
	uncle = getUncle(parent);
  if (uncle && uncle->color == RED) {
    parent->color = BLACK;
    grandparent->color = RED;
    uncle->color = BLACK;

    fix_properties(root, grandparent);
  }
  else if (parent == grandparent->left_child) {
    if (node == parent->right_child) {
      left_rotation(root, parent);
      parent = node;
    }
    right_rotation(root, grandparent);

    parent->color = BLACK;
    grandparent->color = RED;
  }
  else {
    if (node == parent->left_child) {
      right_rotation(root, parent);
      parent = node;
    }
    left_rotation(root, grandparent);
    parent->color = BLACK;
    grandparent->color = RED;
  }
}

void	addNode(Node **root,int value){
	Node *parent = NULL;
	Node *new_node = NULL;
	if (!(*root)){
		*root = new Node(BLACK, value,NULL);
		return;
	}
	parent = SearchParentValue(*root, value);
	new_node = new Node(RED, value, parent);
	if (value < parent->value)
		parent->left_child = new_node;
	else if (value >= parent->value)
		parent->right_child = new_node;
	fix_properties(root, new_node);
}

int check_rule_4(Node *root)
{
	if (!root)
		return (0);
	
	int left_child = check_rule_4(root->left_child);
	int right_child = check_rule_4(root->right_child);
	if (left_child == -1 || right_child == -1 || left_child != right_child)
		return (-1);
	else
		return (left_child + (root->color == BLACK ? 1 : 0));
}

int get_height(Node *root){
	if (!root)
		return 0;
	else{
		int left_height = get_height(root->left_child);
		int right_height = get_height(root->right_child);

		if (left_height > right_height)
			return (left_height + 1);
		else
			return (right_height + 1);
	}
	get_height(root->left_child);
}

void print2DUtil(Node* root, int space)
{
    // Base case
    if (root == 0)
        return;
 
    // Increase distance between levels
    space += 10;
 
    // Process right child first
    print2DUtil(root->right_child, space);
 
    // Print current node after space
    // count
    std::cout << std::endl;
    for (int i = 10; i < space; i++)
        std::cout << " ";
    std::cout << root->value << "["<< root->color <<"]" << "\n";
 
    // Process left child
    print2DUtil(root->left_child, space);
}

void	print_tree(Node * root){
	print2DUtil(root, 0);
}

#endif