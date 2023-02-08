/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:09:54 by achane-l          #+#    #+#             */
/*   Updated: 2023/02/08 19:41:48 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	STACK_HPP
#define STACK_HPP
#include "./vector.hpp"

namespace ft{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef Container							container_type;
			typedef typename Container::value_type		value_type; 
			typedef typename Container::size_type		size_type; 
			typedef typename Container::reference		reference; 
			typedef typename Container::const_reference	const_reference; 

			explicit stack( const container_type& cont = container_type()): _cont(cont){};

			stack( const stack& other ){
				_cont = other._cont;
			}

			~stack();
			stack& operator=( const stack& other ){
				if (this != &other)
					_cont = other._cont;
				return (*this);
			}

			reference top(){
				return (_cont.back());
			};

			const_reference top() const{
				return (_cont.back());
			}

			bool empty() const{
				return (_cont.size() == 0);
			}

			size_type size() const{
				return (_cont.size());
			}

			void push( const value_type& value ){
				_cont.push_back(value);
			}

			void pop(){
				_cont.pop_back();
			}

		protected:
			Container	_cont;

		friend bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){
			return (lhs._cont == rhs._cont);
		}

		friend bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){
			return (lhs._cont != rhs._cont);
		}

		friend bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){
			return (lhs._cont < rhs._cont);
		}

		friend bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){
			return (lhs._cont <= rhs._cont);
		}

		friend bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){
			return (lhs._cont > rhs._cont);
		}

		friend bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){
			return (lhs._cont >= rhs._cont);
		}
	};
}


#endif