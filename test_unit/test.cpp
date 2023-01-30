/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:41:57 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/30 18:29:12 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "../container/maps/map.hpp"
#include <map>
#ifndef lib_used
#define lib_used ft
#endif

int	main(int argc, char **argv){
	// lib_used::map<std::string, int> test;
	// lib_used::map<int, std::string> test;

	for (int i = 1; i < argc - 1;){
		// test[argv[i]] = atoi(argv[i+1]);
		// test[atoi(argv[i+1])] = argv[i];
		std::cout << argv[i] << std::endl;
		i += 2;
	}


	// lib_used::map<int,std::string>::iterator it = test.begin();
	// lib_used::map<std::string, int>::iterator it = test.begin();
	// for (; it != test.end(); it++){
	// 	std::cout << it->first << "|" << it->second << std::endl;
	// }

	// lib_used::map<int,std::string>::reverse_iterator it2 = test.rbegin();
	// lib_used::map<std::string, int>::reverse_iterator it2 = test.rbegin();
	// for (; it2 != test.rend(); ++it2){
	// 	std::cout << it2->first << "|" << it2->second << std::endl;
	// }

	return (1);
}