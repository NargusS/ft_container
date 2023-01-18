/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:54:07 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/18 21:17:06 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
// #include "./reverse_iterator.hpp"
// #include "./random_access_iterator.hpp"

 namespace ft {
    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag{};
    struct bidirectional_iterator_tag : public forward_iterator_tag{};
    struct random_access_iterator_tag : public bidirectional_iterator_tag{};

    template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
    struct iterator {
		typedef T           value_type;
		typedef Distance    difference_type;
		typedef Pointer     pointer;
		typedef Reference   reference;
		typedef Category    iterator_category;
	};

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
        typedef random_access_iterator_tag iterator_category; // replace with my random access
        typedef T*                         pointer;
        typedef T&                         reference;
    };
    template <class T>
    struct iterator_traits<const T*> {
        typedef T                          value_type;
        typedef std::ptrdiff_t             difference_type;
        typedef random_access_iterator_tag iterator_category; // replace with my random access
        typedef const T*                         pointer;
        typedef const T&                         reference;
    };

    template <class It>
	class reverse_iterator : public It {

		public:
			typedef It iterator_type;
			typedef typename ft::iterator_traits<It>::iterator_category 	iterator_category;
			typedef typename ft::iterator_traits<It>::value_type 			value_type;
			typedef typename ft::iterator_traits<It>::difference_type 		difference_type;
			typedef typename ft::iterator_traits<It>::pointer 				pointer;
			typedef typename ft::iterator_traits<It>::reference 			reference;

			/*			CONSTRUCTORS		*/

			reverse_iterator() : current(It()) {};

			explicit reverse_iterator(iterator_type x) : current(x) {};

			template< class U >
			reverse_iterator(const reverse_iterator<U>& other) : current(other.base()) {};

			/*			BASE			*/

			iterator_type base() const{

				return (current);
			}

			/*			OPERATORS =			*/

			template <class U>
			reverse_iterator& operator=(const reverse_iterator<U>& other) {

				return (other.base());
			}

			/*			OPERATORS POINTED-TO ELEMENT			*/

			template <class U>
			reference operator*() const {

				It tmp = current;
				return *(--tmp);
			}

			template <class U>
			pointer operator->() const {

				return (&(operator*()));
			}

			/*			OPERATORS TO ACCESS INDEX			*/

			void	operator[](difference_type n) const {

				return (base()[-n-1]);
			}

			/*			OPERATORS TO (IN)(DE)CREMENT			*/

			reverse_iterator&	operator++(){

				return(*(--this));
			}

			reverse_iterator&	operator--(){

				return(*(++this));
			}

			reverse_iterator	operator++(int){

				reverse_iterator tmp = *(--this);
				return (tmp);
			}

			reverse_iterator	operator--(int){

				reverse_iterator tmp = *(++this);
				return (tmp);
			}

			reverse_iterator	operator+(difference_type n) const{

				return (reverse_iterator(current - n));
			}

			reverse_iterator	operator-(difference_type n) const{

				return (reverse_iterator(current + n));
			}

			reverse_iterator&	operator+=(difference_type n){

				current -= n;
				return (*this);
			}

			reverse_iterator&	operator-=(difference_type n){

				current += n;
				return (*this);
			}

		protected:
			iterator_type current;
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

		return (lhs.base() > rhs.base());
	}

	template<class It1, class It2>
	bool 	operator<=(const ft::reverse_iterator<It1>& lhs, \
						const ft::reverse_iterator<It2>& rhs) {

		return (lhs.base() >= rhs.base());
	}

	template<class It1, class It2>
	bool 	operator>(const ft::reverse_iterator<It1>& lhs, \
						const ft::reverse_iterator<It2>& rhs) {

		return (lhs.base() < rhs.base());
	}

	template<class It1, class It2>
	bool 	operator>=(const ft::reverse_iterator<It1>& lhs, \
						const ft::reverse_iterator<It2>& rhs) {

		return (lhs.base() <= rhs.base());
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

    template<class Iter>
    class random_access_iterator : public iterator<random_access_iterator_tag, Iter>{
        public:
            typedef typename iterator<random_access_iterator_tag, Iter>::value_type			iterator_type;
			typedef typename iterator<random_access_iterator_tag, Iter>::iterator_category 	iterator_category;
			typedef typename iterator<random_access_iterator_tag, Iter>::difference_type 	difference_type;
			typedef typename iterator<random_access_iterator_tag, Iter>::pointer 			pointer;
			typedef typename iterator<random_access_iterator_tag, Iter>::reference 			reference;

            random_access_iterator():_current(Iter()){};
            random_access_iterator(Iter &other):_current(other){};
            template<class U>
            random_access_iterator(const random_access_iterator<U> &other){
                return (_current = other.base());
            };

            template<class U>
            random_access_iterator& operator=(const random_access_iterator<U>& other){
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
                ++_current;
				return (*(this));
            }

            random_access_iterator& operator--(){
                --_current;
				return (*(this));
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

            random_access_iterator&  operator-=(difference_type n){
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

		return (random_access_iterator<Iter>(it.base() - n));
	}


	/*			OPERATORS TO COMPUTE THE DISTANCE BETWEEN TWO ITERATOR ADAPTORS			*/

	template<class Iter1, class Iter2>
	typename random_access_iterator<Iter1>::difference_type	operator-(const random_access_iterator<Iter1>& lhs, \
               												const random_access_iterator<Iter2>& rhs) {

		return (rhs.base() - lhs.base());
	}
};

#endif