/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:24:57 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/30 14:39:03 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP
#include <memory>
#include "../iterators/random_access_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../std_functions/equal.hpp"
#include "../std_functions/enable_if.hpp"
#include "../std_functions/lexicographical_compare.hpp"
#include "../std_functions/is_integral.hpp"
#include <iostream>

namespace ft{

	template<typename Iterator>
	std::ptrdiff_t distance(Iterator first, Iterator last) {
		std::ptrdiff_t dist = 0;
		while (first != last) {
			++dist;
			++first;
		}
		return (dist);
	}

	template<
		class T,
		class Allocator = std::allocator<T>
	> class vector{
		public:
			typedef				T												value_type;
			typedef				Allocator										allocator_type;
			typedef typename	allocator_type::size_type						size_type;
			typedef typename	allocator_type::reference						reference;
			typedef typename	allocator_type::const_reference					const_reference;
			typedef typename	allocator_type::pointer							pointer;
			typedef typename	allocator_type::const_pointer					const_pointer;
			typedef typename	ft::random_access_iterator<pointer>				iterator;
			typedef typename	ft::random_access_iterator<const_pointer>		const_iterator;
			typedef typename	ft::reverse_iterator<iterator>					reverse_iterator;
			typedef typename	ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef typename	ft::iterator_traits<iterator>::difference_type	difference_type;

			// ================ Constructors ================
			explicit vector(const allocator_type& alloc = allocator_type()): _data(NULL), _size(0), _capacity(0), _allocator(alloc) {};

			explicit vector( size_type count,const value_type& value = value_type(),const allocator_type& alloc = allocator_type()){
				_data = NULL;
				_allocator = alloc;
				_size = 0;
				_capacity = 0;
				assign(count, value);
			};

			template< class InputIt >
			vector( InputIt first, InputIt last,const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = NULL){
				_data = NULL;
				_allocator = alloc;
				_size = 0;
				_capacity = 0;
				assign(first, last);
			};

			vector(const vector& other ): _data(NULL), _size(0), _capacity(0),_allocator(other._allocator){
				*this = other;
			};

			vector&	operator=(const vector& other){
				if (this != &other){
					clear();
					reserve(other._size);
					for (size_type i = 0; i < other.size(); i++){
						_allocator.construct(_data + i, other[i]);
						_size++;
					}
				}
				return (*this);
			};

			~vector(){
				for (size_type i = 0; i < _size; i++) {
					_allocator.destroy(_data + i);
				}
				if (_capacity > 0) 
					_allocator.deallocate(_data, _capacity);
			};
			// ================  END Destructor  ================

			// ================     Iterator     ================
			iterator begin(){
				return (iterator(_data));
			};

			const_iterator begin() const{
				return (const_iterator(_data));
			};

			iterator end(){
				return (iterator(_data + _size));
			};

			const_iterator end() const{
				return (const_iterator(_data + _size));
			};

			reverse_iterator rbegin(){
				return (reverse_iterator(end()));
			};

			const_reverse_iterator rbegin() const{
				return (const_reverse_iterator(end()));
			};

			reverse_iterator rend(){
				return (reverse_iterator(begin()));
			};

			const_reverse_iterator rend() const{
				return (const_reverse_iterator(begin()));
			};

			size_type size() const{
				return (_size);
			};

			size_type max_size() const{
				return (_allocator.max_size());
			};

			void	resize(size_type n, value_type val = value_type()){
				if (n < _size)
					erase(begin() + n, end());

				else 
					insert(end(), n - _size, val);
			}

			size_type capacity() const{
				return (_capacity);
			};

			bool empty() const{
				return (_size == 0);
			};

			void	reserve(size_type n){
				if (n > max_size())
					throw std::length_error("vector::reserve");
				if (n > _capacity){
					pointer tmp = _allocator.allocate(n);
					for (size_type i = 0; i < _size; i++){
						_allocator.construct(tmp + i, _data[i]);
						_allocator.destroy(_data + i);
					}
					if (_capacity > 0)
						_allocator.deallocate(_data, _capacity);
					_data = tmp;
					_capacity = n;
				}
			};

			reference operator[](size_type pos){
				return (_data[pos]);
			};

			const_reference operator[](size_type pos) const{
				return (_data[pos]);
			};

			reference at(size_type pos){
				if (pos >= _size)
					throw std::out_of_range("vector::at");
				return (_data[pos]);
			}

			const_reference at(size_type pos) const{
				if (pos >= _size)
					throw std::out_of_range("vector::at");
				return (_data[pos]);
			}

			reference front(){
				return (_data[0]);
			};

			const_reference front() const{
				return (_data[0]);
			};

			reference back(){
				return (_data[_size - 1]);
			};

			const_reference back() const{
				return (_data[_size - 1]);
			};

			void	clear(){
				if (_data){
					while (_size > 0)
						pop_back();
				}
			}

			iterator	insert(iterator position, const value_type& val){
				size_type n = ft::distance(begin(), position);
				insert(position, 1, val);
				return (iterator(&_data[n]));
			};

			void	insert(iterator position, size_type n,const value_type& val){
				size_type index = position - begin();

				if (n) {
					if (_size + n  > _capacity) {
						if (_size + n > _capacity * 2)
							reserve(_size + n);
						else
							reserve(_size * 2);
					}
					for (size_type i = _size; i > index; i--) {
						_allocator.construct(_data + i + n - 1,*(_data + i - 1));
						_allocator.destroy(_data + i - 1);
					}
					for (size_type i = 0; i < n; i++) {
						_allocator.construct(_data + index + i, val);
						_size++;
					}
				}
			};

			template <class InputIt>
			void	insert(iterator position, InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = NULL){
				size_type count = ft::distance(first, last);
				ft::vector<value_type> tmp(first, last);
				size_type pos = position - begin();

				while (count--)
					insert(begin() + pos, tmp[count]);
			};

			iterator	erase(iterator position){
				iterator ret = position == end() ? end() : position;

				while (position + 1 != end()) {
					*position = *(position + 1);
					position++;
				}
				pop_back();
				return ret;
			};

			iterator erase (iterator first, iterator last){
				iterator end = end();
				size_type count = last - first;

				if (count == 0)
					return last;
				while (first + count != end()) {

					*(first) = *(first + count);
					first++;
				}
				while (count--)
					pop_back();
				if (last == end)
					return end();
				return iterator(first);
			};

			void	push_back(const value_type& val){
				if (_size == _capacity)
					empty() ? reserve(1) : reserve(_size * 2);
				_allocator.construct(_data + _size, val);
				_size++;
			};

			void	pop_back(){
				if (_size > 0){
					_size--;
					_allocator.destroy(_data + _size);
				}
			};

			void	swap(vector& other){
				allocator_type    tmp_allocator = _allocator;
				pointer           tmp_data = _data;
				size_type         tmp_capacity = _capacity;
				size_type         tmp_size = _size;

				_allocator = other._allocator;
				_data = other._data;
				_capacity = other._capacity;
				_size = other._size;

				other._alloc = tmp_allocator;
				other._data = tmp_data;
				other._capacity = tmp_capacity;
				other._size = tmp_size;
			}

			template <class InputIt>
			void assign(InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = NULL){
				size_type	n = ft::distance(first, last);

				clear();
				if (_size + n > _capacity && (_size) + n > _capacity * 2)
					reserve((_capacity - _size) + n);
				else if (_size + n > _capacity && (_size) + n < _capacity * 2)
					reserve(_capacity * 2);
				while (first != last)
					push_back(*(first++));
			};

			void assign(size_type n, const value_type& val){
				clear();
				if (_capacity == _size){
					if (_capacity + n > _capacity * 2)
						reserve(_capacity + n);

					else
						reserve(_capacity * 2);
				}
				while (n--)
				 	push_back(val);
			};

			allocator_type	get_allocator()const {
				return (_allocator);
			}

		private:
			pointer _data;
			size_type _size;
			size_type _capacity;
			allocator_type _allocator;
	};

	template <class T, class Alloc>
	bool operator==( const ft::vector<T,Alloc>& lhs,const ft::vector<T,Alloc>& rhs ){
		return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool operator!=( const ft::vector<T,Alloc>& lhs,const ft::vector<T,Alloc>& rhs ){
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<( const ft::vector<T,Alloc>& lhs,const ft::vector<T,Alloc>& rhs ){
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<=( const ft::vector<T,Alloc>& lhs,const ft::vector<T,Alloc>& rhs ){
		return ((lhs < rhs) || (lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator>( const ft::vector<T,Alloc>& lhs,const ft::vector<T,Alloc>& rhs ){
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>=( const ft::vector<T,Alloc>& lhs,const ft::vector<T,Alloc>& rhs ){
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){
		x.swap(y);
	}
}

#endif