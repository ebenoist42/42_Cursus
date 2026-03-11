# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/03 13:57:41 by ebenoist          #+#    #+#              #
#    Updated: 2025/12/08 14:54:29 by ebenoist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Polymorphism
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS =	main.cpp\
		Polymorphism.cpp\
		brain.cpp\

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all