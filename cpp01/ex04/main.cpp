/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:31:07 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/14 15:04:40 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string 	filename(av[1]);
		std::string 	s1(av[2]);
		std::string 	s2(av[3]);
		std::string		str;
		std::ifstream	readFile;
		std::ofstream	printFile;
		std::size_t		startIdx;

		filename = strtrim(filename);
		if (!filename.empty() || filename.length() > 0)
		{
			readFile.open(filename);
			if (!readFile.is_open())
			{
				std::cout << "Failed to read open file" << std::endl;
				return (1);
			}
			filename += ".replace";
			printFile.open(filename);
			if (!printFile.is_open())
			{
				std::cout << "Failed to print open file" << std::endl;
				readFile.close();
				return (1);
			}
			else
			{
				while (!readFile.eof())
				{
					std::getline(readFile, str);
					startIdx = 0;
					while (str.find(av[2], startIdx) != std::string::npos)
					{
						startIdx = str.find(av[2], startIdx);
						str.erase(startIdx, std::strlen(av[2]));
						str.insert(startIdx, av[3]);
					}
					printFile << str << std::endl;
					str.clear();
				}
				readFile.close();
				printFile.close();
			}
		}
		else
			std::cout << "Invalid file path" << std::endl;
	}
	else
		std::cout << "Please put in 3 parameters" << std::endl;
	return (0);
}