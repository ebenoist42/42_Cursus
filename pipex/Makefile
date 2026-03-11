# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/26 10:00:22 by ebenoist          #+#    #+#              #
#    Updated: 2025/08/06 14:43:29 by ebenoist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
BONUS_NAME = pipex_bonus

CC		= cc -g
CFLAGS	= -Wall -Werror -Wextra -g -Ilibft/includes -Iincludes

SRC		=	srcs/main.c\
			srcs/error.c\
			srcs/path_arg.c\
			srcs/test_arg.c
			
BONUS_SRCS = bonus/main.c\
			 bonus/arg.c\
			 bonus/error.c\
			 bonus/init.c\
			 bonus/here_doc.c\
			 
OBJ		= $(SRC:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)
BONUS_INC	= -Ibonus/includes -Ilibft/includes
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus: CFLAGS += $(BONUS_INC)
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
	
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all bonus

.PHONY: all bonus clean fclean re
