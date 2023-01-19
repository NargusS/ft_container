/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:54:07 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/19 19:27:12 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
#include "./iterator_traits.hpp"

 namespace ft {
	template <class T>
	class iterator{
		public:
			typedef typename ft::iterator_traits<T*>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<T*>::value_type			value_type;
			typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
			typedef typename ft::iterator_traits<T*>::pointer			pointer;
			typedef typename ft::iterator_traits<T*>::reference			reference;

			iterator():_current(0){};
			iterator(pointer other):_current(other){};
			iterator(const iterator<T> &other){
				_current = other.base();
			};

			iterator& operator=(const iterator& other){
				if (this != other)
					_current = other.base();
				return (*this);
			};

			~iterator(){};

			pointer base() const {
				return (_current);
			}

			reference   operator*() const{
				return (*_current);
			}

			pointer operator->() const{
				return (&(operator*()));
			}

			reference	operator[](difference_type n) const{
				return (_current[n]);
			}

			iterator& operator++(){
				++_current;
				return (*(this));
			}

			iterator& operator--(){
				--_current;
				return (*(this));
			}

			iterator operator++(int){
				iterator  tmp(*this);
				_current++;
				return (tmp);
			}

			iterator operator--(int){
				iterator  tmp(*this);
				_current--;
				return (tmp);
			}

			iterator operator+(difference_type n) const{
				return (_current + n);
			}

			iterator operator-(difference_type n) const{
				return (_current - n);
			}

			iterator&  operator+=(difference_type n){
				_current += n;
				return (*this);
			}

			iterator&  operator-=(difference_type n){
				_current -= n;
				return (*this);
			}
		protected:
			pointer    _current;
	};

	template<class Iter1, class Iter2>
	bool	operator==(const ft::iterator<Iter1>& lhs,
						const ft::iterator<Iter2>& rhs) {

		return (lhs.base() == rhs.base());
	}

	template<class Iter1, class Iter2>
	bool	operator!=(const ft::iterator<Iter1>& lhs, \
						const ft::iterator<Iter2>& rhs) {

		return (lhs.base() != rhs.base());
	}

	template<class Iter1, class Iter2>
	bool 	operator<(const ft::iterator<Iter1>& lhs, \
						const ft::iterator<Iter2>& rhs) {

		return (lhs.base() < rhs.base());
	}

	template<class Iter1, class Iter2>
	bool 	operator<=(const ft::iterator<Iter1>& lhs, \
						const ft::iterator<Iter2>& rhs) {

		return (lhs.base() <= rhs.base());
	}

	template<class Iter1, class Iter2>
	bool 	operator>(const ft::iterator<Iter1>& lhs, \
						const ft::iterator<Iter2>& rhs) {

		return (lhs.base() > rhs.base());
	}

	template<class Iter1, class Iter2>
	bool 	operator>=(const ft::iterator<Iter1>& lhs, \
						const ft::iterator<Iter2>& rhs) {

		return (lhs.base() >= rhs.base());
	}


	/*			OPERATORS TO ADVANCE THE ITERATOR			*/

	template<class Iter>
	iterator<Iter>	operator+(typename iterator<Iter>::difference_type n, \
			   						const iterator<Iter>& it) {

		return (iterator<Iter>(it.base() - n));
	}


	/*			OPERATORS TO COMPUTE THE DISTANCE BETWEEN TWO ITERATOR ADAPTORS			*/

	template<class Iter1, class Iter2>
	typename iterator<Iter1>::difference_type	operator-(const iterator<Iter1>& lhs, \
			   												const iterator<Iter2>& rhs) {

		return (rhs.base() - lhs.base());
	}
};

#endif