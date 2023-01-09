/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:50:46 by achane-l          #+#    #+#             */
/*   Updated: 2022/12/19 15:53:34 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft{
	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1!=last1) {
			if (!(*first1==*first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}
}