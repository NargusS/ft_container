/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:58:39 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/18 18:38:11 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
namespace ft {

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
}

#endif