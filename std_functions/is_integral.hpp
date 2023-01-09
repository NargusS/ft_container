/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:24:32 by achane-l          #+#    #+#             */
/*   Updated: 2022/12/19 15:44:50 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft{
	template <typename T>
	struct is_integral {
		static const bool value = false;
	};
	template <>
	struct is_integral<bool> {
		static const bool value = true;
	};
	template <>
	struct is_integral<char> {
		static const bool value = true;
	};
	template <>
	struct is_integral<unsigned char> {
		static const bool value = true;
	};
	template <>
	struct is_integral<signed char> {
		static const bool value = true;
	};
	template <>
	struct is_integral<wchar_t> {
		static const bool value = true;
	};
	template <>
	struct is_integral<short> {
		static const bool value = true;
	};
	template <>
	struct is_integral<unsigned short> {
		static const bool value = true;
	};
	template <>
	struct is_integral<int> {
		static const bool value = true;
	};
	template <>
	struct is_integral<unsigned int> {
		static const bool value = true;
	};
	template <>
	struct is_integral<long> {
		static const bool value = true;
	};
	template <>
	struct is_integral<unsigned long> {
		static const bool value = true;
	};
	template <>
	struct is_integral<long long> {
		static const bool value = true;
	};
	template <>
	struct is_integral<unsigned long long> {
		static const bool value = true;
	};
}