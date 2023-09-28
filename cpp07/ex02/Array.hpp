/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:40:33 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/28 20:52:08 by yunjcho          ###   ########.fr       */
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
		Array() : arr(new T[0], capacity(0), length(0)) {}
 
		Array(unsigned int n) : arr(new T[n]), capacity(n), length(0) {}

		Array(const Array &array) 
		{
			*this = array;
		}

		Array& operator=(const Array &array) 
		{
			if (this != &array)
			{
				T	*newArr;
				newArr = new T[array.length];
				for (int i = 0; i < array.size(); i++)
				{
					newArr[i] = array.arr[i];
				}
			}
			return (*this);
		}

		T& operator[](const int idx) const
		{
			try
			{
				if (!arr || idx < 0 || idx > (length - 1))
					throw std::out_of_range("Invalid Index!");
			}
			catch(const std::exception& e)
			{
				//Debugging
				std::cout << "<<<<<<<<<<<<<<< Test exception <<<<<<<<<<<" << std::endl;
				std::cout << e.what() << std::endl;
			}
			return (arr[idx]);
		}

		~Array()
		{
			if (arr)
				delete[] arr;
		}

		int size(void)
		{
			return (length);
		}
};

#endif