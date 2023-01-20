/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:41:57 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/20 11:47:03 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./binary_search.hpp"
#include <iostream>

int	main(){
	Node	*root = 0;

	addNode(&root, 6);
	addNode(&root, 4);
	addNode(&root, 7);


	std::cout << root->value << std::endl;
	std::cout << root->left_child->value << std::endl;
	std::cout << root->right_child->value << std::endl;
}