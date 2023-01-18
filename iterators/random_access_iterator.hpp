/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:51:16 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/18 18:34:57 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	RANDOM_ACCESS_ITERATOR_HPP
#define	RANDOM_ACCESS_ITERATOR_HPP
#include "./iterator.hpp"

namespace ft{
    template<class Iter>
    class random_access_iterator {
        public:
            typedef Iter iterator_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category 	iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type 			value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type 	difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer 			pointer;
			typedef typename ft::iterator_traits<Iter>::reference 			reference;

            random_access_iterator():_current(Iter()){};
            random_access_iterator(Iter &other):_current(other){};
            template<class U>
            random_access_iterator(random_access_iterator<U> &other){
                return (_current = other.base());
            };

            template<class U>
            random_access_iterator& operator=(random_access_iterator<U>& other){
                return (_current = other.base());
            };

            Iter& base(){
                return (_current);
            }


            reference   operator*() const{
                Iter tmp = _current;
                return (*(--tmp));
            }

            pointer operator->() const{
                return (&(operator*()));
            }

            Iter    operator[](difference_type n) const{
                return (base()[-1*(-n-1)]);
            }

            random_access_iterator& operator++(){
                return (*(++this));
            }

            random_access_iterator& operator--(){
                return (*(--this));
            }

            random_access_iterator operator++(int){
                random_access_iterator  tmp = *(++this);
                return (tmp);
            }

            random_access_iterator operator--(int){
                random_access_iterator  tmp = *(--this);
                return (tmp);
            }

            random_access_iterator operator+(difference_type n) const{
                return (random_access_iterator(_current + n));
            }

            random_access_iterator operator-(difference_type n) const{
                return (random_access_iterator(_current + n));
            }

            random_access_iterator&  operator+=(difference_type n){
                _current += n;
                return (*this);
            }

            random_access_iterator&  operator+=(difference_type n){
                _current -= n;
                return (*this);
            }
        protected:
            Iter    _current;
    };

	template<class Iter1, class Iter2>
	bool	operator==(const ft::random_access_iterator<Iter1>& lhs,
						const ft::random_access_iterator<Iter2>& rhs) {

		return (lhs.base() == rhs.base());
	}

	template<class Iter1, class Iter2>
	bool	operator!=(const ft::random_access_iterator<Iter1>& lhs, \
						const ft::random_access_iterator<Iter2>& rhs) {

		return (lhs.base() != rhs.base());
	}

	template<class Iter1, class Iter2>
	bool 	operator<(const ft::random_access_iterator<Iter1>& lhs, \
						const ft::random_access_iterator<Iter2>& rhs) {

		return (lhs.base() < rhs.base());
	}

	template<class Iter1, class Iter2>
	bool 	operator<=(const ft::random_access_iterator<Iter1>& lhs, \
						const ft::random_access_iterator<Iter2>& rhs) {

		return (lhs.base() <= rhs.base());
	}

	template<class Iter1, class Iter2>
	bool 	operator>(const ft::random_access_iterator<Iter1>& lhs, \
						const ft::random_access_iterator<Iter2>& rhs) {

		return (lhs.base() > rhs.base());
	}

	template<class Iter1, class Iter2>
	bool 	operator>=(const ft::random_access_iterator<Iter1>& lhs, \
						const ft::random_access_iterator<Iter2>& rhs) {

		return (lhs.base() >= rhs.base());
	}


	/*			OPERATORS TO ADVANCE THE ITERATOR			*/

	template<class Iter>
	random_access_iterator<Iter>	operator+(typename random_access_iterator<Iter>::difference_type n, \
               						const random_access_iterator<Iter>& it) {

		return (random_access_iterator<It>(it.base() - n));
	}


	/*			OPERATORS TO COMPUTE THE DISTANCE BETWEEN TWO ITERATOR ADAPTORS			*/

	template<class Iter1, class Iter2>
	typename random_access_iterator<Iter1>::difference_type	operator-(const random_access_iterator<Iter1>& lhs, \
               												const random_access_iterator<Iter2>& rhs) {

		return (rhs.base() - lhs.base());
	}
}

#endif