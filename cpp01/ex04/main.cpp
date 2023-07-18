/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:31:07 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/18 13:36:35 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string 	filename(av[1]);
		std::string 	s1(av[2]);
		std::string 	s2(av[3]);
		std::string		str;
		std::string		replace_str;
		std::ifstream	readFile;
		std::ofstream	printFile;
		size_t			start_idx;

		
		if (!filename.empty() && !s1.empty() && !s2.empty())
		{
			readFile.open(filename);
			filename += ".replace";
			printFile.open(filename);
			if (readFile.is_open() && printFile.is_open())
			{
				while (!readFile.eof())
				{
					std::getline(readFile, str);
					if (str.length() <= 0)
					{
						std::cerr << "File is empty" << std::endl;
						readFile.close();
						printFile.close();
						return (1);
					}
					else
					{
						replace_str = std::strstr(str.c_str(), av[2]);
						start_idx = strlen(str.c_str()) - strlen(replace_str.c_str());
						str.erase(start_idx, std::strlen(av[2]));
						str.insert(start_idx, av[3]);
						printFile << str << std::endl;
					}
				}
			}
			else
				std::cerr << "Failed to open file" << std::endl;
			readFile.close();
			printFile.close();
		}
		else
			std::cerr << "Invalid arguments existed" << std::endl;
	}
	else
		std::cerr << "Please put in 3 parameters" << std::endl;
	return (0);
}