# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oben-ham <oben-ham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/17 09:15:42 by dbhujoo           #+#    #+#              #
#    Updated: 2025/12/11 12:12:36 by oben-ham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ircserv
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = 	srcs/main.cpp \
		srcs/Server.cpp \
		srcs/Client.cpp \
		srcs/Channel.cpp \
		srcs/Message.cpp \
		srcs/Commands.cpp \
		srcs/File.cpp \
		srcs/Bot.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all