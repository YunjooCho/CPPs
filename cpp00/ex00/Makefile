# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 15:31:29 by yunjcho           #+#    #+#              #
#    Updated: 2023/08/10 13:56:19 by yunjcho          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

ifdef SANITIZE
	CXXFLAGS += -fsanitize=address
endif

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

sanitize :
	make SANITIZE=1 re

.PHONY: all clean fclean re bonus sanitize