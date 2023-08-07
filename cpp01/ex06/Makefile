# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 15:31:29 by yunjcho           #+#    #+#              #
#    Updated: 2023/08/07 11:21:28 by yunjcho          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harlFilter
CC = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = main.cpp Harl.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

%.o : %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@
	
$(NAME) : $(OBJS)
	$(CC) $(CXXFLAGS) $^ -o $@ 

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : 
	make fclean 
	make all

.PHONY: all clean fclean re bonus