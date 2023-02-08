/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_function.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:10:22 by achane-l          #+#    #+#             */
/*   Updated: 2023/02/08 17:01:13 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../std_functions/iterator.hpp"
#include "./std_function.hpp"

void	compare_and_print(bool std, bool ft){
	if (std == ft)
		std::cout << GRN <<"[OK]" << RESET;
	else
		std::cout << RED << "[KO]" << RESET;
}

void	compare_and_print(std::pair<std::string, int> std, ft::pair<std::string, int> ft){
	if (std.first == ft.first && std.second == ft.second)
		std::cout << GRN <<"[OK]" << RESET;
	else
		std::cout << RED << "[KO]" << RESET;
}

int main(){
	std::vector<int> v1;
	std::vector<int> v2;
	std::vector<int> v3;

	for (int i = 0 ; i < 100 ; i++){
		v1.push_back(i);
		v2.push_back(i);
		v3.push_back(i * 2);
	}
	
	//-------------------------------std::equal-----------------------------------------------
	std::cout << YEL<< "equal function"<< RESET << std::endl;
	compare_and_print(std::equal(v1.begin(), v1.end(), v2.begin()), ft::equal(v1.begin(), v1.end(), v2.begin()));
	compare_and_print(std::equal(v2.begin(), v2.end(), v3.begin()), ft::equal(v2.begin(), v2.end(), v3.begin()));
	compare_and_print(std::equal(v1.begin(), v1.end(), v3.begin()), ft::equal(v1.begin(), v1.end(), v3.begin()));
	std::cout << std::endl;
	//-------------------------------std::lexicographical_compare-----------------------------------------------
	std::cout << YEL<< "lexicographical_compare function"<< RESET << std::endl;
	compare_and_print(std::equal(v1.begin(), v1.end(), v2.begin()), ft::equal(v1.begin(), v1.end(), v2.begin()));
	compare_and_print(std::equal(v2.begin(), v2.end(), v3.begin()), ft::equal(v2.begin(), v2.end(), v3.begin()));
	compare_and_print(std::equal(v1.begin(), v1.end(), v3.begin()), ft::equal(v1.begin(), v1.end(), v3.begin()));
	std::cout << std::endl;
	//-------------------------------std::is_integral-----------------------------------------------
	std::cout << YEL<< "is_integral function"<< RESET << std::endl;
	compare_and_print(std::is_integral<bool>::value, ft::is_integral<bool>::value);
	compare_and_print(std::is_integral<char>::value, ft::is_integral<char>::value);
	compare_and_print(std::is_integral<unsigned char>::value, ft::is_integral<unsigned char>::value);
	compare_and_print(std::is_integral<signed char>::value, ft::is_integral<signed char>::value);
	compare_and_print(std::is_integral<wchar_t>::value, ft::is_integral<wchar_t>::value);
	compare_and_print(std::is_integral<short>::value, ft::is_integral<short>::value);
	compare_and_print(std::is_integral<unsigned short>::value, ft::is_integral<unsigned short>::value);
	compare_and_print(std::is_integral<int>::value, ft::is_integral<int>::value);
	compare_and_print(std::is_integral<unsigned int>::value, ft::is_integral<unsigned int>::value);
	compare_and_print(std::is_integral<long>::value, ft::is_integral<long>::value);
	compare_and_print(std::is_integral<unsigned long>::value, ft::is_integral<unsigned long>::value);
	compare_and_print(std::is_integral<long long>::value, ft::is_integral<long long>::value);
	compare_and_print(std::is_integral<unsigned long long>::value, ft::is_integral<unsigned long long>::value);
	std::cout << std::endl;
	//-------------------------------std::pair-----------------------------------------------
	std::cout << YEL<< "pair function" << RESET << std::endl;
	for (int i = 0; i < 10; i++){
		std::pair<std::string, int> std_pair(std::string("test" + std::to_string(i)), i);
		ft::pair<std::string, int> ft_pair(std::string("test" + std::to_string(i)), i);
		compare_and_print(std_pair, ft_pair);
		compare_and_print(std::make_pair(std::string("test" + std::to_string(i)), i), ft::make_pair(std::string("test" + std::to_string(i)), i));
	}
	std::cout << std::endl;
	//-------------------------------std::enable_if-----------------------------------------------
	std::cout <<YEL<<  "enable_if function"<< RESET << std::endl;
	compare_and_print(check_enable_if(1, 1), check_my_enable_if(1, 1));
	compare_and_print(check_enable_if(1.0, 2.0), check_my_enable_if(1.0, 2.0));
	// compare_and_print(check_enable_if(1, 2.0), check_my_enable_if(1, 2.0)); //compile error
	std::cout << std::endl;
	//-------------------------------std::iterator-----------------------------------------------
}