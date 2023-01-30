/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:54:07 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/30 18:41:03 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP
#include "./iterator_traits.hpp"
#include <cstddef>

 namespace ft {
	template <class T>
	class random_access_iterator{
		public:
			typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<T>::value_type			value_type;
			typedef typename ft::iterator_traits<T>::difference_type	difference_type;
			typedef typename ft::iterator_traits<T>::pointer			pointer;
			typedef typename ft::iterator_traits<T>::reference			reference;

			explicit random_access_iterator():_current(NULL){};
			explicit random_access_iterator(pointer const other):_current(other){};

			template <class U>
			random_access_iterator(const random_access_iterator<U> &other):_current(other.base()){};

			random_access_iterator(const random_access_iterator& other){
				*this = other;
			}

			random_access_iterator& operator=(const random_access_iterator& other){
				if (*this != other)
					_current = other.base();
				return (*this);
			};

			~random_access_iterator(){};

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

			random_access_iterator& operator++(){
				_current++;
				return (*(this));
			}

			random_access_iterator& operator--(){
				_current--;
				return (*(this));
			}

			random_access_iterator operator++(int){
				random_access_iterator  tmp(*this);
				_current++;
				return (tmp);
			}

			random_access_iterator operator--(int){
				random_access_iterator  tmp(*this);
				_current--;
				return (tmp);
			}

			random_access_iterator operator+(difference_type n) const{
				return (random_access_iterator(_current + n));
			}

			difference_type	operator+(random_access_iterator n) const{
				return (_current + n._current);
			}

			random_access_iterator operator-(difference_type n) const{
				return (random_access_iterator(_current - n));
			}

			difference_type	operator-(random_access_iterator n) const{
				return (_current - n._current);
			}

			random_access_iterator&  operator+=(difference_type n){
				_current += n;
				return (*this);
			}

			random_access_iterator&  operator-=(difference_type n){
				_current -= n;
				return (*this);
			}
		protected:
			pointer    _current;
	};

	template<class Iter1, class Iter2>
	bool	operator==(const ft::random_access_iterator<Iter1>& lhs,const ft::random_access_iterator<Iter2>& rhs) {
		return (lhs.base() == rhs.base());
	}

	template<class Iter1, class Iter2>
	bool	operator!=(const ft::random_access_iterator<Iter1>& lhs,const ft::random_access_iterator<Iter2>& rhs) {
		return (lhs.base() != rhs.base());
	}

	template<class Iter1, class Iter2>
	bool 	operator<(const ft::random_access_iterator<Iter1>& lhs,const ft::random_access_iterator<Iter2>& rhs) {
		return (lhs.base() < rhs.base());
	}

	template<class Iter1, class Iter2>
	bool 	operator<=(const ft::random_access_iterator<Iter1>& lhs, const ft::random_access_iterator<Iter2>& rhs) {
		return (lhs.base() <= rhs.base());
	}

	template<class Iter1, class Iter2>
	bool 	operator>(const ft::random_access_iterator<Iter1>& lhs, const ft::random_access_iterator<Iter2>& rhs) {
		return (lhs.base() > rhs.base());
	}

	template<class Iter1, class Iter2>
	bool 	operator>=(const ft::random_access_iterator<Iter1>& lhs, const ft::random_access_iterator<Iter2>& rhs) {
		return (lhs.base() >= rhs.base());
	}

	template<class T>
	random_access_iterator<T>	operator+(typename random_access_iterator<T>::difference_type n, const random_access_iterator<T>& it) {
		return (random_access_iterator<T>(it.base() + n));
	}

	template<class T>
	random_access_iterator<T>	operator-(typename random_access_iterator<T>::difference_type n, const random_access_iterator<T>& it) {
		return (random_access_iterator<T>(it.base() - n));
	}

	template<class T1, class T2>
	typename random_access_iterator<T1>::difference_type	operator-(const random_access_iterator<T1>& lhs,const random_access_iterator<T2>& rhs) {
		return (lhs.base() - rhs.base());
	}

	template<class T1, class T2>
	typename random_access_iterator<T1>::difference_type	operator+(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs) {
		return (lhs.base() + rhs.base());
	}
};

#endif