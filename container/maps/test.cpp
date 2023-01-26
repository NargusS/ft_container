/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:41:57 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/26 18:44:19 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./binary_search.hpp"
#include <iostream>
#include <cstdlib>

// int	main(int argc, char **argv){
// 	Node	*root = NULL;

// 	for (int i = 1; i < argc; i++){
// 		addNode(&root, atoi(argv[i]));
// 	}
// 	// std::cout << root->value << std::endl;
// 	// std::cout << root->left_child->value << std::endl;
// 	// std::cout << root->right_child->value << std::endl;
// 	print_tree(root);
// 	std::cout << "ROOT TEST MAIN:" << root << std::endl;
// 	delete_node(&root, getNode(root, 1));
// 	std::cout << "ROOT TEST MAIN:" << root << std::endl;
// 	delete_node(&root, getNode(root, 2));
// 	std::cout << "ROOT TEST MAIN:" << root << std::endl;
// 	delete_node(&root, getNode(root, 3));
// 	std::cout << "ROOT TEST MAIN:" << root << std::endl;
// 	std::cout<<std::endl;
// 	std::cout<<std::endl;
// 	std::cout<<std::endl;
// 	std::cout<<std::endl;
// 	std::cout<<std::endl;
// 	std::cout<<std::endl;
// 	std::cout<<std::endl;
// 	print_tree(root);
// 	// check_rules(root);
// }

int	main(int argc, char **argv){
	RBtree rbt;

	for (int i = 1; i < argc; i++){
		rbt.insert(atoi(argv[i]));
	}

	
	// rbt.deleteNode(5);
	// rbt.deleteNode(1);
	// rbt.deleteNode(2);
	// rbt.deleteNode(8);
	rbt.print_tree();
	rbt.check_rules();
	rbt.test();
}