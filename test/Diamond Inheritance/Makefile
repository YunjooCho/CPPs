# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 15:31:29 by yunjcho           #+#    #+#              #
#    Updated: 2023/08/25 00:04:09 by yunjcho          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = a.out
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ 

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : 
	make fclean 
	make all

.PHONY: all clean fclean re