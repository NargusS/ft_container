/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:21:08 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/19 20:13:02 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../container/ft_vector.hpp"
#include "./vector_test.hpp"
#include <vector>
#define BLK "\033[0;30m"
#define RED "\033[0;31m"
#define GRN "\033[0;32m"
#define YEL "\033[0;33m"
#define BLU "\033[0;34m"
#define MAG "\033[0;35m"
#define CYN "\033[0;36m"
#define WHT "\033[0;37m"
#define RESET "\033[0m"
#include <iostream>
#include "../std_functions/equal.hpp"

void	compare_and_print(size_t p1, size_t p2){
	if (p1 == p2)
		std::cout << GRN <<"[OK]" << RESET;
	else
		std::cout << RED << "[KO]" << RESET;
}

template <class InputIterator1, class InputIterator2>
void	compare_vector_and_print(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2){
	if (ft::equal(first1, last1, first2))
		std::cout << GRN <<"[OK]" << RESET;
	else
		std::cout << RED << "[KO]" << RESET;
}


int main(){
	ft::vector<int> ft1;
	ft::vector<int> ft2;
	ft::vector<int> ft3;

	std::vector<int> std1;
	std::vector<int> std2;
	std::vector<int> std3;
	for (int i = 0 ; i < 100 ; i++){
		ft1.push_back(i);
		ft2.push_back(i);
		ft3.push_back(i * 2);
		std1.push_back(i);
		std2.push_back(i);
		std3.push_back(i * 2);
	}

	std::cout << YEL<<"compare size of vectors" <<RESET << std::endl;
	compare_and_print(ft1.size(), std1.size());
	compare_and_print(ft2.size(), std2.size());
	compare_and_print(ft3.size(), std3.size());
	std::cout << std::endl;
	std::cout << YEL<<"compare empty of vectors" <<RESET << std::endl;
	compare_and_print(ft1.empty(), std1.empty());
	compare_and_print(ft2.empty(), std2.empty());
	compare_and_print(ft3.empty(), std3.empty());
	std::cout << std::endl;
	std::cout << YEL<<"compare capacity of vector" <<RESET << std::endl;
	compare_and_print(ft1.capacity(), std1.capacity());
	compare_and_print(ft2.capacity(), std2.capacity());
	compare_and_print(ft3.capacity(), std3.capacity());
	std::cout << std::endl;
	std::cout << YEL<<"compare empty of max_size" <<RESET << std::endl;
	compare_and_print(ft1.max_size(), std1.max_size());
	compare_and_print(ft2.max_size(), std2.max_size());
	compare_and_print(ft3.max_size(), std3.max_size());
	std::cout << std::endl;
	std::cout << YEL<<"compare vector element" <<RESET << std::endl;
	compare_vector_and_print(std1.begin(),std1.end(), ft1.begin());
	compare_vector_and_print(std2.begin(),std2.end(), ft2.begin());
	compare_vector_and_print(std3.begin(),std3.end(), ft3.begin());
	std::cout << std::endl;
	std::cout << YEL<<"compare reverse vector element" <<RESET << std::endl;
	compare_vector_and_print(std1.rbegin(),std1.rend(), ft1.rbegin());
	compare_vector_and_print(std2.rbegin(),std2.rend(), ft2.rbegin());
	compare_vector_and_print(std3.rbegin(),std3.rend(), ft3.rbegin());
	std::cout << std::endl;
	std::cout << YEL<<"create new vector with = operator and compare" <<RESET << std::endl;
	std::vector<int> std4 = std1;
	ft::vector<int>	ft4 = ft1;

	compare_and_print(std4.size(), ft4.size());
	compare_and_print(std1.size(), ft1.size());
	compare_and_print(std4.capacity(), ft4.capacity());
	compare_and_print(std1.capacity(), ft1.capacity());
	compare_and_print(std4.max_size(), ft4.max_size());
	compare_and_print(std1.max_size(), ft1.max_size());
	compare_and_print(std4.empty(), ft4.empty());
	compare_and_print(std1.empty(), ft1.empty());

	compare_vector_and_print(std4.begin(), std4.end(), ft4.begin());
	compare_vector_and_print(std4.begin(), std4.end(), std1.begin());
	compare_vector_and_print(ft4.begin(), ft4.end(), std4.begin());
	compare_vector_and_print(ft4.begin(), ft4.end(), ft1.begin());
	std::cout << std::endl;
	std::cout << YEL<<"create new vector with vector(const vector &other) and compare" <<RESET << std::endl;
	std::vector<int> std5(std1);
	ft::vector<int>	ft5(ft1);
	compare_and_print(std5.size(), ft5.size());
	compare_and_print(std1.size(), ft1.size());
	compare_and_print(std5.capacity(), ft5.capacity());
	compare_and_print(std1.capacity(), ft1.capacity());
	compare_and_print(std5.max_size(), ft5.max_size());
	compare_and_print(std1.max_size(), ft1.max_size());
	compare_and_print(std5.empty(), ft5.empty());
	compare_and_print(std1.empty(), ft1.empty());

	compare_vector_and_print(std5.begin(), std5.end(), ft5.begin());
	compare_vector_and_print(std5.begin(), std5.end(), std1.begin());
	compare_vector_and_print(ft5.begin(), ft5.end(), std5.begin());
	compare_vector_and_print(ft5.begin(), ft5.end(), ft1.begin());


}