/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:41:57 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/29 12:35:58 by achane-l         ###   ########.fr       */
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
	// ft::map<int, std::string> test;

	for (int i = 1; i < argc - 1;){
		// std::cout << argv[i] << " "<< argv[i + 1]<< std::endl;
		test[argv[i]] = atoi(argv[i+1]);
		// test[atoi(argv[i+1])] = argv[i];
		// std::cout << argv[i] << " "<< argv[i + 1]<< std::endl;
		i += 2;
	}

	// ft::map<int,std::string>::iterator it = test.begin();
	// std::cout << (*it).first << "|" << (*it).second << std::endl;
	// std::cout << "key :"<<(*it).first << "| value:" << (*it).second << std::endl;

	// ft::map<int,std::string>::iterator it2 = test.end();
	// std::cout << "key :"<<(*it2).first << "| value:" << (*it2).second << std::endl;
	ft::map<std::string, int>::iterator it = test.begin();
	for (; it != test.end(); it++){
		std::cout << (*it).first << "|" << (*it).second << std::endl;
	}

	// ft::map<int,std::string>::iterator it2 = test.end();
	ft::map<std::string, int>::iterator it2 = test.end();
	for (; it2 != test.begin(); --it2){
		std::cout << (*it2).first << "|" << (*it2).second << std::endl;
	}
	return (1);
}