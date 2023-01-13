/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:54:07 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/13 14:26:01 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>

 namespace ft {
    class input_iterator_tag {};
    class output_iterator_tag {};
    class forward_iterator_tag : public input_iterator_tag{};
    class bidirectional_iterator_tag : public forward_iterator_tag{};
    class random_access_iterator_tag : public bidirectional_iterator_tag{};

    template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	class iterator {
		public:
			typedef T           value_type;
			typedef Distance    difference_type;
			typedef Pointer     pointer;
			typedef Reference   reference;
			typedef Category    iterator_category;
	};
    template <class T>
    class iterator_traits {
        typedef typename T::value_type            value_type;
        typedef typename T::difference_type       difference_type;
        typedef typename T::iterator_category     iterator_category;
        typedef typename T::pointer               pointer;
        typedef typename T::reference             reference;
    };
    template <class T>
    class iterator_traits<T*> {
        typedef T                          value_type;
        typedef ptrdiff_t                  difference_type;
        typedef random_access_iterator_tag iterator_category;
        typedef T*                         pointer;
        typedef T&                         reference;
    };
    template <class T>
    class iterator_traits<const T*> {
        typedef T                          value_type;
        typedef ptrdiff_t                  difference_type;
        typedef random_access_iterator_tag iterator_category;
        typedef const T*                         pointer;
        typedef const T&                         reference;
    };
}
