/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:41:57 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/21 19:44:00 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./binary_search.hpp"
#include <iostream>
#include <cstdlib>
int	main(int argc, char **argv){
	Node	*root = NULL;

	if (argc == 2){
		std::string test(argv[1]);
		int start = 0;
		int end = test.find(" ");
		while (end != -1) {
			addNode(&root, atoi(test.substr(start, end - start).c_str()));
			start = end + 1;
			end = test.find(" ", start);
		}
		addNode(&root, atoi(test.substr(start, end - start).c_str()));
	}

	// std::cout << root->value << std::endl;
	// std::cout << root->left_child->value << std::endl;
	// std::cout << root->right_child->value << std::endl;
	print_tree(root);
	check_rules(root);
}