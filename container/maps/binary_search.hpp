/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:25:16 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/26 19:12:02 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BINARY_SEARCH_HPP
#define	BINARY_SEARCH_HPP
#define BLACK false
#define RED   true
#define NULL  0
#include <iostream>
#include "./Node.hpp"

namespace ft{

	template <typename T>
	struct Node{
		private:
			bool	color;
			T		value;
			Node	*parent;
			Node	*left;
			Node	*right;
		Node():color(BLACK), parent(NULL), left(NULL), right(NULL){};
		~Node();
	};

	template <typename NodePtr>
	NodePtr get_next_node(NodePtr ptr, NodePtr TNULL) {
		if (ptr->_right != TNULL)
			return (get_min_node(ptr->_right, TNULL));
		while (!is_left_child(ptr))
			ptr = ptr->_parent;
		return (ptr->_parent);
	}
	template <typename NodePtr>
	NodePtr get_prev_node(NodePtr ptr, NodePtr TNULL) {
		if (ptr->_left != TNULL)
			return (get_max_node(ptr->_left, TNULL));
		while (!is_right_child(ptr))
			ptr = ptr->_parent;
		return (ptr->_parent);
	}

	template <typename U, typename V>
	class RBtree_iterator {

		public:
			typedef U                                                           value_type;
			typedef value_type*                                                 pointer;
			typedef value_type&                                                 reference;
			typedef V*                                                          iterator_type;
			typedef typename iterator_traits<iterator_type>::difference_type    difference_type;
			typedef typename iterator_traits<iterator_type>::value_type         node_type;
			typedef typename iterator_traits<iterator_type>::pointer            node_pointer;
			typedef typename iterator_traits<iterator_type>::reference          node_reference;
			typedef typename iterator_traits<iterator_type>::iterator_category  iterator_category;

		private:
			node_pointer  _current;
			node_pointer  _nil;

		public:
			tree_iterator() : _current(NULL), _nil(NULL) {}
			tree_iterator(node_pointer cur, node_pointer nil) : _current(cur), _nil(nil) {}
			tree_iterator(const tree_iterator& ref) : _current(ref._current), _nil(ref._nil) {}
			~tree_iterator() {}

			tree_iterator& operator=(const tree_iterator& ref) {
				if (this != &ref) {
					_current = ref._current;
					_nil = ref._nil;
				}
				return (*this);
			}

			node_pointer base()       const { return (_current); }
			pointer      operator->() const { return (&_current->_value); }
			reference    operator*()  const { return (_current->_value); }

			tree_iterator& operator++() {
				_current = get_next_node(_current, _nil);
				return (*this);
			}
			tree_iterator operator++(int) {
				tree_iterator tmp(*this);
				++(*this);
				return (tmp);
			}

			tree_iterator& operator--() {
				_current = get_prev_node(_current, _nil);
				return (*this);
			}
			tree_iterator operator--(int) {
				tree_iterator tmp(*this);
				--(*this);
				return (tmp);
			}

			template <typename T>
			bool operator==(const tree_iterator<T, node_type>& x) const {
				return (_current == x.base());
			}
			template <typename T>
			bool operator!=(const tree_iterator<T, node_type>& x) const {
				return !(*this == x);
			}

			operator tree_iterator<const value_type, node_type>(void) const {
				return (tree_iterator<const value_type, node_type>(_current, _nil));
			}

			// ---------------------------------------------/
			friend bool operator==(const tree_iterator& lhs, const tree_iterator& rhs) {
				return (lhs._current == rhs._current);
			}
			// ---------------------------------------------/
			friend bool operator!=(const tree_iterator& lhs, const tree_iterator& rhs) {
				return (!(lhs == rhs));
			}
  	};

	template <class Key, class T, class Compare, class Allocator>
	class RBtree{
		public:
			typedef Key			key_type;
			typedef T			value_type;
			typedef Compare		value_compare;
			typedef Allocator	allocator_type;
			typedef	tree_iterator<value_type, Node<value_type>> iterator;
			typedef	tree_iterator<const value_type, Node<value_type>> iterator;
			typedef std::size_t   	size_type;
			typedef std::ptrdiff_t	difference_type;
			typedef Node*		Nodeptr;
		private:
			Nodeptr	root;
			Nodeptr	begin;
			Nodeptr	end;
			Nodeptr	TNULL;
			Compare _comp;
			allocator_type alloc;
			
		public:
		
		RBtree(): _comp(std::less<value_type>), alloc(allocator_type()){
			TNULL = alloc.allocate(1);
			TNULL->color = BLACK;
			TNULL->left = NULL;
			TNULL->right = NULL;
			root = TNULL;
			begin = TNULL;
			end = TNULL;
		};

		RBtree(Compare &comp, Allocator&allocate):_comp(comp), alloc(allocate){
			TNULL = alloc.allocate(1);
			TNULL->color = BLACK;
			TNULL->left = NULL;
			TNULL->right = NULL;
			root = TNULL;
			begin = TNULL;
			end = TNULL;
		};

		template <class InputIt>
		RBtree(InputIt first, InputIt last, Compare &comp, Allocator&allocate){
			alloc = allocate;
			_comp = comp;
			TNULL = alloc.allocate(1);
			TNULL->color = BLACK;
			TNULL->left = NULL;
			TNULL->right = NULL;
			root = TNULL;
			begin = TNULL;
			end = TNULL;
		};
	
		~RBtree(){};
		Nodeptr	SearchParent(value_type& value){
			Nodeptr	tmp = root;
			Nodeptr	parent = NULL;

			while (tmp != TNULL){
				parent = tmp;
				if (_comp(value, tmp->value))
					tmp = tmp->left;
				else if (!_comp(value, tmp->value))
					tmp = tmp->right;
			}
			return (parent);
		}

		Nodeptr	minimum(Nodeptr root){
			Nodeptr	tmp= root;

			while (tmp->left != TNULL)
				tmp = tmp->left;
			return(tmp);
		}

		Nodeptr	maximum(Nodeptr root){
			Nodeptr	tmp= root;

			while (tmp->right != TNULL)
				tmp = tmp->right;
			return(tmp);
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

		void	insert(value_type& value){
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
			if (_comp(value,parent->value))
				parent->left = new_node;
			else
				parent->right = new_node;
			fix_properties(new_node);
			begin = minimum(root);
			end = maximum(root);
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

		void	deleteNode(value_type& value){
			Nodeptr	tmp = root;
			Nodeptr	node = TNULL;
			Nodeptr	min, fix;
			bool		og_color;
			
			while (tmp != TNULL){
				if (!_comp(tmp->value, value) && !_comp(value, tmp->value)) {
					node = tmp;
				}

				if (_comp(tmp->value, value) || (!_comp(tmp->value, value) && !_comp(value, tmp->value))) {
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
			begin = minimum(root);
			end = maximum(root);
		}

		// bool	check_rule_1(Node *root){
		// 	if (root->color == BLACK)
		// 		return (true);
		// 	else
		// 		return (false);
		// }

		// int	check_rule_2(Node *root){
		// 	if (root == TNULL)
		// 		return (1);
		// 	int left_child = check_rule_2(root->left);
		// 	int right_child = check_rule_2(root->right);
		// 	if (left_child == -1 || right_child == -1 || (root->color == RED && ((root->left->color == RED) || (root->right->color == RED))))
		// 		return (-1);
		// 	return (1);
		// }

		// int check_rule_3(Node *root)
		// {
		// 	if (root == TNULL)
		// 		return (0);
			
		// 	int left_child = check_rule_3(root->left);
		// 	int right_child = check_rule_3(root->right);
		// 	if (left_child == -1 || right_child == -1 || left_child != right_child)
		// 		return (-1);
		// 	else
		// 		return (left_child + (root->color == BLACK ? 1 : 0));
		// }

		// void	check_rules(){
		// 	if (check_rule_1(root) && check_rule_2(root) == 1 && check_rule_3(root) >= 1)
		// 		std::cout <<"[OK]" << std::endl;
		// 	else
		// 		std::cout <<"[KO]"<< std::endl;
		// }

		// void print2DUtil(Nodeptr root, int space)
		// {
		// 	// Base case
		// 	if (root == TNULL)
		// 		return;
		
		// 	// Increase distance between levels
		// 	space += 10;
		
		// 	// Process right child first
		// 	print2DUtil(root->right, space);
		
		// 	// Print current node after space
		// 	// count
		// 	std::cout << std::endl;
		// 	for (int i = 10; i < space; i++)
		// 		std::cout << " ";
		// 	std::cout << root->value << "["<< (root->color == true ? "R" : "B")<<"]" << "\n";
		
		// 	// Process left child
		// 	print2DUtil(root->left, space);
		// }

		// void	print_tree(){
		// 	print2DUtil(root, 0);
		// }

		// void	tree_to_list(Nodeptr node){
		// 	if (node == TNULL)
		// 		return;
		// 	tree_to_list(node->left);
		// 	std::cout <<"[" << node->value << "] ";
		// 	tree_to_list(node->right);
		// 	return;
		// }

		// void	test(){
		// 	tree_to_list(root);
		// 	std::cout << std::endl;
		// }
	};
}
#endif