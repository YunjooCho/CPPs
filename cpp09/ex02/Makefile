# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 15:31:29 by yunjcho           #+#    #+#              #
#    Updated: 2023/10/28 22:59:40 by yunjcho          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = main.cpp PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC =	PmergeMe
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

test: all 
	./$(EXEC) 5 8 10 20 30 1 2 4 6 9 11 21

test1: all 
	./$(EXEC) 5 8 10 20 30 1 2 4 6 9 11 21 31

sanitize :
	make SANITIZE=1 re

.PHONY: all clean fclean re sanitize