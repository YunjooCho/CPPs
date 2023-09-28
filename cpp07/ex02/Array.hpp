/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:40:33 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/28 21:22:39 by yunjcho          ###   ########.fr       */
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
			std::cout << "[] idx : " << idx << std::endl;
			try
			{
				// if (!arr[idx])
				// 	throw std::out_of_range("Not exist Array!");
				if (idx < 0)
					throw std::out_of_range("Invalid Index!1");
				else if (idx > (length - 1))
					throw std::out_of_range("Invalid Index!2");
				// if (idx < 0)
				// 	throw std::exception("1");
				// else if (idx > (length - 1))
				// 	throw std::exception("2");
				return (arr[idx]);
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