/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:01:56 by achane-l          #+#    #+#             */
/*   Updated: 2022/12/17 19:02:23 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft{
	template<bool B, typename T>
	struct enable_if {};
	template<typename T>
	struct enable_if<true, T> { typedef T type; };
}