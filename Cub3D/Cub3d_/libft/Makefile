# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/05 15:35:48 by dbhujoo           #+#    #+#              #
#    Updated: 2025/07/16 09:54:50 by dbhujoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar
ARFLAGS = rcs
OBJ_DIR = obj
BASE_SRC = \
	   base/ft_strlen.c\
	   base/ft_bzero.c\
	   base/ft_strlcpy.c\
	   base/ft_strlcat.c\
	   base/ft_strcmp.c\
	   base/ft_strchr.c\
	   base/ft_strrchr.c\
	   base/ft_strncmp.c\
	   base/ft_strnstr.c\
	   base/ft_atoi.c\
	   base/ft_calloc.c\
	   base/ft_strdup.c\
	   base/ft_substr.c\
	   base/ft_strjoin.c\
	   base/ft_strtrim.c\
	   base/ft_split.c\
	   base/ft_itoa.c\
	   base/ft_strmapi.c\
	   base/ft_striteri.c\
	   base/ft_putchar_fd.c\
	   base/ft_putstr_fd.c\
	   base/ft_putendl_fd.c\
	   base/ft_putnbr_fd.c\

CHAIN_LIST_SRC = \
	 chain_list/ft_lstadd_front_bonus.c\
	 chain_list/ft_lstsize_bonus.c\
	 chain_list/ft_lstlast_bonus.c\
	 chain_list/ft_lstadd_back_bonus.c\
	 chain_list/ft_lstdelone_bonus.c\
	 chain_list/ft_lstclear_bonus.c\
	 chain_list/ft_lstiter_bonus.c\
	 chain_list/ft_lstmap_bonus.c\
	 chain_list/ft_lstnew_bonus.c\

FT_PRINTF_SRC = \
	ft_printf/ft_printf.c\
	ft_printf/ft_printf_p.c\
	ft_printf/ft_putcharpf_fd.c\
	ft_printf/ft_putnbrpf_fd.c\
	ft_printf/ft_putstrpf_fd.c\
	ft_printf/ft_u_putnbr_fd.c\

GNL_SRC = \
	  gnl/get_next_line.c\
	  gnl/get_next_line_utils.c\

MEMFCT_SRC = \
	memfct/ft_memchr.c\
	memfct/ft_memcmp.c\
	memfct/ft_memcpy.c\
	memfct/ft_memmove.c\
	memfct/ft_memset.c\

USELESS_SRC = \
	useless/ft_isalpha.c\
	useless/ft_isdigit.c\
	useless/ft_isalnum.c\
	useless/ft_isascii.c\
	useless/ft_isprint.c\
	useless/ft_toupper.c\
	useless/ft_tolower.c\
	useless/ft_isspace.c\

SRC = $(BASE_SRC) $(CHAIN_LIST_SRC) $(FT_PRINTF_SRC) $(GNL_SRC) $(MEMFCT_SRC) $(USELESS_SRC)

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
