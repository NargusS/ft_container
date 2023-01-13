/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:24:57 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/13 19:54:31 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP
#include <memory>
#include <cstddef>

namespace ft{
	template<
		class T,
		class Allocator = std::allocator<T>
	> class vector{
		public:
			typename T	value_type;
			typename Allocator allocator_type;
			typename std::size_t	size_type;
			typename ptrdiff_t	difference_type;
			typename value_type&	reference;
			typename const value_type& const_reference;
			typename Allocator::pointer	pointer;
			typename Allocator::const_pointer const_pointer;

			// typename random_access_iterator<value_type> iterator
			// typename const random_access_iterator<value_type> const_iterator

			// typename ft::iterator<T> iterator
			// typename ft::const_iterator<T> const_iterator

			// typename ft::reverse_iterator<iterator> reverse_iterator
			// typename ft::reverse_iterator<const_iterator> const_reverse_iterator

			vector(): allocator_type(Allocator());
			vector(const Allocator& alloc): allocator_type(alloc));
			explicit vector( size_type count,const T& value = T(),const Allocator& alloc = Allocator()):
				size_type(count), value_type(value), allocator_type(alloc)
			;
			template< class InputIt >
			vector( InputIt first, InputIt last,const Allocator& alloc = Allocator() );
			vector( const vector& other );

			~vector();
	};

}

#endif