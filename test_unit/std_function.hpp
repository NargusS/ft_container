/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_function.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:26:06 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/19 18:09:40 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STD_FUNCTION_HPP
# define STD_FUNCTION_HPP
#define BLK "\033[0;30m"
#define RED "\033[0;31m"
#define GRN "\033[0;32m"
#define YEL "\033[0;33m"
#define BLU "\033[0;34m"
#define MAG "\033[0;35m"
#define CYN "\033[0;36m"
#define WHT "\033[0;37m"
#define RESET "\033[0m"

#include "../std_functions/lexicographical_compare.hpp"
#include "../std_functions/pair.hpp"
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include "../std_functions/enable_if.hpp"
#include "../std_functions/equal.hpp"
#include "../std_functions/is_integral.hpp"
#include <type_traits>

template <typename T1, typename T2>
typename std::enable_if<std::is_same<T1, T2>::value, int>::type check_enable_if(T1 t1, T2 t2){
	(void)t1;
	(void)t2;
	return true;
}

template <typename T1, typename T2>
typename ft::enable_if<std::is_same<T1, T2>::value, int>::type check_my_enable_if(T1 t1, T2 t2){
	(void)t1;
	(void)t2;
	return true;
}

#endif