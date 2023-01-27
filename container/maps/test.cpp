/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:41:57 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/27 19:18:21 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./map.hpp"
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
	ft::map<std::string, int> test;

	for (int i = 1; i < argc - 1; i++){
		// std::cout << argv[i] << " "<< argv[i + 1]<< std::endl;
		test[argv[i]] = atoi(argv[i+1]);
		// std::cout << argv[i] << " "<< argv[i + 1]<< std::endl;
	}

	ft::map<std::string, int>::iterator it = test.begin();
	for (; it != test.end(); it++){
		std::cout << (*it).first << "|" << (*it).second << std::endl;
	}
	return (1);
}