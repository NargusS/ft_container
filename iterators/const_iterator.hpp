/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:54:07 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/19 00:21:45 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_ITERATOR_HPP
# define CONST_ITERATOR_HPP

 namespace ft {

	template <class T>
    class const_iterator{
        public:
			typedef T							value_type;
			typedef std::ptrdiff_t    			difference_type;
			typedef const T*					pointer;
			typedef const T&					reference;
			typedef random_access_iterator_tag	iterator_category;

            const_iterator():_current(NULL){};
            const_iterator(pointer other):_current(other){};
            const_iterator(const iterator<T> &other){
                _current = other.base();
            };
            const_iterator<T>& operator=(const iterator<T>& other){
                if (this != other)
                    _current = other.base();
                return (*this);
            };

			operator const_iterator<const value_type>() const {
				return const_iterator<const value_type>(_current);
			}

			~const_iterator(){};
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

            const_iterator& operator++(){
                ++_current;
				return (*(this));
            }

            const_iterator& operator--(){
                --_current;
				return (*(this));
            }

            const_iterator operator++(int){
                const_iterator  tmp(*this);
				_current++;
                return (tmp);
            }

            const_iterator operator--(int){
                const_iterator  tmp(*this);
				_current--;
                return (tmp);
            }

            const_iterator operator+(difference_type n) const{
                return (_current + n);
            }

            const_iterator operator-(difference_type n) const{
                return (_current - n);
            }

            const_iterator&  operator+=(difference_type n){
                _current += n;
                return (*this);
            }

            const_iterator&  operator-=(difference_type n){
                _current -= n;
                return (*this);
            }
        protected:
            pointer    _current;
    };

	template<class Iter1, class Iter2>
	bool	operator==(const ft::const_iterator<Iter1>& lhs,
						const ft::const_iterator<Iter2>& rhs) {

		return (lhs.base() == rhs.base());
	}

	template<class Iter1, class Iter2>
	bool	operator!=(const ft::const_iterator<Iter1>& lhs, \
						const ft::const_iterator<Iter2>& rhs) {

		return (lhs.base() != rhs.base());
	}

	template<class Iter1, class Iter2>
	bool 	operator<(const ft::const_iterator<Iter1>& lhs, \
						const ft::const_iterator<Iter2>& rhs) {

		return (lhs.base() < rhs.base());
	}

	template<class Iter1, class Iter2>
	bool 	operator<=(const ft::const_iterator<Iter1>& lhs, \
						const ft::const_iterator<Iter2>& rhs) {

		return (lhs.base() <= rhs.base());
	}

	template<class Iter1, class Iter2>
	bool 	operator>(const ft::const_iterator<Iter1>& lhs, \
						const ft::const_iterator<Iter2>& rhs) {

		return (lhs.base() > rhs.base());
	}

	template<class Iter1, class Iter2>
	bool 	operator>=(const ft::const_iterator<Iter1>& lhs, \
						const ft::const_iterator<Iter2>& rhs) {

		return (lhs.base() >= rhs.base());
	}


	/*			OPERATORS TO ADVANCE THE ITERATOR			*/

	template<class Iter>
	const_iterator<Iter>	operator+(typename const_iterator<Iter>::difference_type n, \
               						const const_iterator<Iter>& it) {

		return (iterator<Iter>(it.base() - n));
	}


	/*			OPERATORS TO COMPUTE THE DISTANCE BETWEEN TWO ITERATOR ADAPTORS			*/

	template<class Iter1, class Iter2>
	typename const_iterator<Iter1>::difference_type	operator-(const const_iterator<Iter1>& lhs, \
               												const const_iterator<Iter2>& rhs) {

		return (rhs.base() - lhs.base());
	}
};

#endif