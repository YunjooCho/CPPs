/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:40:33 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/29 21:50:13 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
	private:
		T	*arr;
		int	capacity;
		int	length;
	public:
		Array() : arr(new T[0]), capacity(0), length(0) {}
 
		Array(unsigned int n) : arr(new T[n]), capacity(n), length(0) 
		{
			for (unsigned int i = 0; i < n; i++)
			{
				T tmp = T();
				arr[i] = tmp;
				++length;
			}
		}

		Array(const Array &array) : arr(new T[0]), capacity(0), length(0)
		{
			*this = array;
		}

		Array& operator=(const Array &array)
		{
			if (this != &array)
			{
				T	*newArr = new T[array.length];
				for (int i = 0; i < array.length; i++)
				{
					newArr[i] = array.arr[i];
				}
				if (this->length > 0)
					delete[] arr;
				this->arr = newArr;
				this->capacity = array.capacity;
				this->length = array.length;
			}
			return (*this);
		}

		T& operator[](const int &idx) const
		{
			if (idx < 0 || idx > (length - 1))
			{
				std::cout << "idx : " << idx << std::endl;
				throw std::out_of_range("Invalid Index!");
			}
			return (arr[idx]);
		}

		~Array()
		{
			if (length > 0)
				delete[] arr;
		}

		int size(void)
		{
			return (length);
		}
};

#endif