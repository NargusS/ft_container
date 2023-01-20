/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:58:02 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/20 18:59:27 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP
#define	RED true
#define	BLACK true

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

Node	*SearchParentValue(Node *parent, int value){
	while (parent){
		if ((value < parent->value && !parent->left_child) || (value >= parent->value && !parent->right_child))
			return (parent);
		else if (value < parent->value && parent->left_child)
			parent = parent->left_child;
		else if (value >= parent->value && parent->right_child)
			parent = parent->right_child;
		else
			return(parent);// break faire quelque chose
	}
	return (parent);//pareil
}

#include <iostream>

void	addNode(Node **root,int value){
	Node *parent = *root;
	Node *new_node = 0;
	if (!parent){
		*root = new Node(BLACK, value, 0);
		return;
	}
	parent = SearchParentValue(*root, value);
	new_node = new Node(RED, value, 0);
	if (value < parent->value)
		parent->left_child = new_node;
	else if (value >= parent->value)
		parent->right_child = new_node;
	if (parent->color == BLACK)
		return ;
	
}

void	left_rotation(Node **root, Node *node){
	Node *child;

	child = node->left_child;

	if (node->color == BLACK)
	{
		node->color = RED;
		node->left_child->color = BLACK;
	}
	node->right_child = child->left_child;
	child->left_child = node;
	child->parent = node->parent;
	node->parent = child;
}

void	right_rotation(Node **root, Node *node){
	Node *child;

	child = node->right_child;

	if (node->color == BLACK)
	{
		node->color = RED;
		node->right_child->color = BLACK;
	}
	node->left_child = child->right_child;
	child->right_child = node;
	child->parent = node->parent;
	node->parent = child;
}
#endif

//parent -> noir
//feuille -> noir
// pere rouge -> fils noir
// pour chaque noeud de l'arbre,le nombre de noeud noir parcouru entre ce noeud la et la feuille et la meme pour tte les feuilles de ce noeud la