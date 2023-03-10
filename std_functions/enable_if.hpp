/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:01:56 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/19 00:50:04 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

namespace ft{
	template<bool B, class T = void>
	struct enable_if {};
	template<typename T>
	struct enable_if<true, T> { typedef T type; };
}

#endif