/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:54:07 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/19 00:50:06 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

 namespace ft {
    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag{};
    struct bidirectional_iterator_tag : public forward_iterator_tag{};
    struct random_access_iterator_tag : public bidirectional_iterator_tag{};

	template <class T>
    class iterator{
        public:
			typedef T							value_type;
			typedef std::ptrdiff_t    			difference_type;
			typedef T*							pointer;
			typedef T&							reference;
			typedef random_access_iterator_tag	iterator_category;

            iterator():_current(NULL){};
            iterator(pointer other):_current(other){};
            iterator(const iterator<T> &other){
                _current = other.base();
            };

            iterator<T>& operator=(const iterator<T>& other){
                if (this != other)
                    _current = other.base();
                return (*this);
            };

			operator iterator<const value_type>() const {
				return iterator<const value_type>(_current);
			}

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