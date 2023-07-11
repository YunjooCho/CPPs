# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 15:31:29 by yunjcho           #+#    #+#              #
#    Updated: 2023/07/11 15:57:18 by yunjcho          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = moarBrainz
CC = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = main.cpp Zombie.cpp zombieHorde.cpp
OBJS = $(SRCS:.cpp=.o)

ifdef SANITIZE
	CXXFLAGS += -fsanitize=address
endif

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

sanitize :
	make SANITIZE=1 re

.PHONY: all clean fclean re bonus sanitize