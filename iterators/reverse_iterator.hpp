/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:58:39 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/19 00:07:17 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
#include "./iterator_traits.hpp"
#include "./iterator.hpp"

namespace ft {

	template <class It>
	class reverse_iterator {

		public:
			typedef It iterator_type;
			typedef typename ft::iterator_traits<It>::iterator_category 	iterator_category;
			typedef typename ft::iterator_traits<It>::value_type 			value_type;
			typedef typename ft::iterator_traits<It>::difference_type 		difference_type;
			typedef typename ft::iterator_traits<It>::pointer 				pointer;
			typedef typename ft::iterator_traits<It>::reference 			reference;

			/*			CONSTRUCTORS		*/

			reverse_iterator() : _current(iterator_type()) {};

			explicit reverse_iterator(iterator_type x) : _current(x) {};

			reverse_iterator(const reverse_iterator<It>& other) : _current(other.base()) {};

			/*			BASE			*/

			virtual ~reverse_iterator(){};
			iterator_type base() const{

				return (_current);
			}

			/*			OPERATORS =			*/

			reverse_iterator& operator=(const reverse_iterator<It>& other) {

				return (other.base());
			}

			/*			OPERATORS POINTED-TO ELEMENT			*/

			reference operator*() const {
				It tmp = _current;
				return *(--tmp);
			}

			pointer operator->() const {

				return (_current);
			}

			/*			OPERATORS TO ACCESS INDEX			*/

			reference	operator[](difference_type n) const {
				return (_current - n);
			}

			/*			OPERATORS TO (IN)(DE)CREMENT			*/

			reverse_iterator&	operator++(){
				--_current;
				return(*(this));
			}

			reverse_iterator&	operator--(){
				++_current;
				return(*(this));
			}

			reverse_iterator	operator++(int){
				reverse_iterator tmp(*this);
				--_current;
				return (tmp);
			}

			reverse_iterator	operator--(int){
				reverse_iterator tmp(*this);
				++_current;
				return (tmp);
			}

			reverse_iterator	operator+(difference_type n) const{

				return (reverse_iterator(_current - n));
			}

			reverse_iterator	operator-(difference_type n) const{
				return (reverse_iterator(_current + n));
			}

			reverse_iterator&	operator+=(difference_type n){

				_current -= n;
				return (*this);
			}

			reverse_iterator&	operator-=(difference_type n){

				_current += n;
				return (*this);
			}

		protected:
			iterator_type _current;
	};

	/*			OPERATORS TO COMPARE			*/

	template<class It1, class It2>
	bool	operator==(const ft::reverse_iterator<It1>& lhs, \
						const ft::reverse_iterator<It2>& rhs) {

		return (lhs.base() == rhs.base());
	}

	template<class It1, class It2>
	bool	operator!=(const ft::reverse_iterator<It1>& lhs, \
						const ft::reverse_iterator<It2>& rhs) {

		return (lhs.base() != rhs.base());
	}

	template<class It1, class It2>
	bool 	operator<(const ft::reverse_iterator<It1>& lhs, \
						const ft::reverse_iterator<It2>& rhs) {

		return (lhs.base() < rhs.base());
	}

	template<class It1, class It2>
	bool 	operator<=(const ft::reverse_iterator<It1>& lhs, \
						const ft::reverse_iterator<It2>& rhs) {

		return (lhs.base() <= rhs.base());
	}

	template<class It1, class It2>
	bool 	operator>(const ft::reverse_iterator<It1>& lhs, \
						const ft::reverse_iterator<It2>& rhs) {

		return (lhs.base() > rhs.base());
	}

	template<class It1, class It2>
	bool 	operator>=(const ft::reverse_iterator<It1>& lhs, \
						const ft::reverse_iterator<It2>& rhs) {

		return (lhs.base() >= rhs.base());
	}


	/*			OPERATORS TO ADVANCE THE ITERATOR			*/

	template<class It>
	reverse_iterator<It>	operator+(typename reverse_iterator<It>::difference_type n, \
               						const reverse_iterator<It>& it) {

		return (reverse_iterator<It>(it.base() - n));
	}


	/*			OPERATORS TO COMPUTE THE DISTANCE BETWEEN TWO ITERATOR ADAPTORS			*/

	template<class It1, class It2>
	typename reverse_iterator<It1>::difference_type	operator-(const reverse_iterator<It1>& lhs, \
               												const reverse_iterator<It2>& rhs) {

		return (rhs.base() - lhs.base());
	}
}

#endif