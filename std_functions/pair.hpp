/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:12:12 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/17 22:24:10 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft{
	template <class T1, class T2>
	struct pair{
		typedef T1 first_type;
		typedef T2 second_type;
	
		T1 first;
		T2 second;
		pair(void): first(T1()), second(T2()){};
		pair(const T1& x, const T2& y): first(x), second(y){};
        template <class U, class V>
        pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) {}
        pair& operator=(const pair& pr)
        {
            first = pr.first;
            second = pr.second;
            return (*this);
        }
	};

	template <typename T1, typename T2>
	bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
  		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

    template <class T1, class T2>
    bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
    {
        return (!(lhs == rhs));
    }

	template <typename T1, typename T2>
	bool operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
	return lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second);
	}

    template <class T1, class T2>
    bool operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
    {
        return (!(rhs < lhs));
    }

    template <class T1, class T2>
    bool operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
    {
        return (rhs < lhs);
    }

    template <class T1, class T2>
    bool operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
    {
        return (!(lhs < rhs));
    }

	template <typename T1, typename T2>
	void swap(pair<T1, T2>& lhs, pair<T1, T2>& rhs) {
		pair<T1, T2> temp(lhs);
		lhs = rhs;
		rhs = temp;
	}
	template <typename T1, typename T2>
	pair<T1, T2> make_pair(const T1& x, const T2& y) {
	return pair<T1, T2>(x, y);
	}
}

#endif