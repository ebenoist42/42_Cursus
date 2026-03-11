# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/21 14:11:21 by ebenoist          #+#    #+#              #
#    Updated: 2025/11/24 11:36:30 by ebenoist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = account
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -IAccount.hpp

SRCS =	Account.cpp\
		tests.cpp\

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all