/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:41:57 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/22 10:06:47 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./binary_search.hpp"
#include <iostream>
#include <cstdlib>

int	main(int argc, char **argv){
	Node	*root = NULL;

	for (int i = 1; i < argc; i++){
		addNode(&root, atoi(argv[i]));
	}
	// std::cout << root->value << std::endl;
	// std::cout << root->left_child->value << std::endl;
	// std::cout << root->right_child->value << std::endl;
	print_tree(root);
	check_rules(root);
}