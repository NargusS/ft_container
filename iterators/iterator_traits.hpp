/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:08:02 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/19 14:14:33 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

namespace ft{
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag{};
	struct bidirectional_iterator_tag : public forward_iterator_tag{};
	struct random_access_iterator_tag : public bidirectional_iterator_tag{};

	template <class Iter>
	struct iterator_traits {
	    typedef typename Iter::value_type          	 value_type;
	    typedef typename Iter::difference_type       difference_type;
	    typedef typename Iter::iterator_category     iterator_category;
	    typedef typename Iter::pointer               pointer;
	    typedef typename Iter::reference             reference;
	};
	template <class T>
	struct iterator_traits<T*> {
	    typedef T                          value_type;
	    typedef std::ptrdiff_t             difference_type;
	    typedef random_access_iterator_tag iterator_category;
	    typedef T*                         pointer;
	    typedef T&                         reference;
	};
	template <class T>
	struct iterator_traits<const T*> {
	    typedef T                          value_type;
	    typedef std::ptrdiff_t             difference_type;
	    typedef random_access_iterator_tag iterator_category;
	    typedef const T*                         pointer;
	    typedef const T&                         reference;
	};
}

#endif