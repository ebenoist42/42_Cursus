# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/06 13:45:48 by ebenoist          #+#    #+#              #
#    Updated: 2025/06/25 16:38:45 by ebenoist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= cc -g

CFLAGS	= -Wall -Werror -Wextra -g -Ilibft/includes -Iincludes

SRC		=	srcs/error.c\
			srcs/push_swap.c\
			srcs/push_swap_index1.c\
			srcs/push_swap_index2.c\
			srcs/push_swap_index3.c\
			srcs/fonction_S_P.c\
			srcs/fonction_R.c\
			srcs/radix.c\
	
OBJ		= $(SRC:.c=.o)

LIBFT_PATH	= ./libft
LIBFT_H		= $(LIBFT_PATH)/libft.h
LIBFT		= $(LIBFT_PATH)/libft.a

all : $(NAME) 

$(NAME): $(OBJ) $(LIBFT) $(LIBFT_H)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_PATH) clean
	
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re