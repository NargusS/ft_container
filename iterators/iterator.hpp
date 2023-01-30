/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:54:07 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/30 13:06:45 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
#include "./iterator_traits.hpp"

 namespace ft {
	template <class T>
	class iterator{
		public:
			typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<T>::value_type			value_type;
			typedef typename ft::iterator_traits<T>::difference_type	difference_type;
			typedef typename ft::iterator_traits<T>::pointer			pointer;
			typedef typename ft::iterator_traits<T>::reference			reference;

			explicit iterator():_current(NULL){};
			explicit iterator(pointer const other):_current(other){};

			template <class U>
			iterator(const iterator<U> &other){
				_current = other.base();
			};

			iterator(const iterator& other){
				*this = other;
			}

			iterator& operator=(const iterator& other){
				if (*this != other)
					_current = other.base();
				return (*this);
			};

			~iterator(){};

			const pointer base() const {
				return (_current);
			}

			reference   operator*() const{
				return (*_current);
			}

			pointer operator->() const{
				return (_current);
			}

			reference	operator[](difference_type n) const{
				return (_current[n]);
			}

			iterator& operator++(){
				_current++;
				return (*(this));
			}

			iterator& operator--(){
				_current--;
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
				return (iterator(_current + n));
			}

			difference_type	operator+(iterator n) const{
				return (_current + n._current);
			}

			iterator operator-(difference_type n) const{
				return (iterator(_current - n));
			}

			difference_type	operator-(iterator n) const{
				return (_current - n._current);
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

	template<class T>
	iterator<T>	operator+(typename iterator<T>::difference_type n, const iterator<T>& it) {
		return (iterator<T>(it.base() + n));
	}

	template<class T>
	iterator<T>	operator-(typename iterator<T>::difference_type n, const iterator<T>& it) {
		return (iterator<T>(it.base() - n));
	}

	template<class T1, class T2>
	typename iterator<T1>::difference_type	operator-(const iterator<T1>& lhs,const iterator<T2>& rhs) {
		return (lhs.base() - rhs.base());
	}

	template<class T1, class T2>
	typename iterator<T1>::difference_type	operator+(const iterator<T1>& lhs, const iterator<T2>& rhs) {
		return (lhs.base() + rhs.base());
	}
};

#endif