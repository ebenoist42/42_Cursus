# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/28 13:36:12 by ebenoist          #+#    #+#              #
#    Updated: 2025/11/28 13:36:20 by ebenoist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Harl_filter
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS =	main.cpp\
		Harl.cpp\

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all