# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/05 15:35:48 by dbhujoo           #+#    #+#              #
#    Updated: 2025/10/02 09:57:56 by ebenoist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell
BONUS_NAME	= minishell_bonus
CC		= cc
CFLAGS		= -Wall -Werror -Wextra -g -Iincludes #-fsanitize=address,leak
AR		= ar
ARFLAGS		= rcs
OBJ_DIR		= obj
FILES	= utils/singleton.c \
				utils/free.c \
				utils/error.c \
				utils/signals.c \
				env/env_list.c \
				env/env_array.c \
				env/expand.c \
				env/update_env.c \
				builtins/pwd_builtin.c \
				builtins/env_builtin.c \
				builtins/export_utils.c \
				builtins/builtins.c \
				builtins/cd_builtin.c \
				builtins/cd_utils.c \
				builtins/echo_builtin.c \
				builtins/exit_builtin.c \
				builtins/export_builtin.c \
				builtins/unset_builtin.c \
				parsing/parsing.c\
				parsing/token_base.c\
				parsing/parsing_utils.c\
				parsing/parsing_utils2.c\
				parsing/token_dup.c\
				parsing/token_dup_utils.c\
				parsing/token_quote_word.c\
				parsing/tokenisation_utils.c \
				ast/ast_node.c \
				ast/ast_utils.c \
				ast/ast_node_utils.c\
				ast/ast_node_utils2.c\
				exec/exec.c \
				exec/env_path.c \
				exec/exec_utils.c \
				exec/exec_utils2.c \
				exec/get_env.c \
				exec/exec_redir.c \
				exec/exec_redir_utils.c \
				exec/exec_redir_utils2.c \
				exec/exec_redir_utils3.c \
				exec/exec_pipe.c \
				exec/exec_heredoc_utils.c \
				exec/exec_heredoc.c \
				main/main.c
				
HEADER		= includes/minishell.h

BONUS_SRC	= 

SRC_DIR		= srcs
SRCS		= $(addprefix $(SRC_DIR)/, $(FILES))

OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

BONUS_OBJS	= $(BONUS_SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a

RESET 		= \033[0m
GREEN 		= \033[0;32m
BLUE   		= \033[0;34m
YELLOW		= \033[1;33m

all: message $(NAME)

bonus : $(BONUS_NAME)
	
message:
	@printf "$(GREEN)compilation Minishell...$(RESET)\n"

$(NAME): $(OBJ)
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -lreadline
	@printf "$(GREEN)Minishell complete$(RESET)\n"

$(BONUS_NAME): $(BONUS_OBJS)
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
	@printf "$(GREEN)Minishell_bonus complete$(RESET)\n"
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(dir $@)
	@printf "$(YELLOW)Compiling $(notdir $<)$(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "$(BLUE)Cleaning objects$(RESET)\n"
	@rm -f $(OBJ) $(BONUS_OBJS)
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH) clean

fclean: clean
	@printf "$(BLUE)Cleaning all$(RESET)\n"
	@rm -f $(NAME) $(BONUS_NAME)
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH) fclean

re: fclean all
	@printf "$(GREEN)Recompil de Minishell...$(RESET)\n"

.PHONY: all clean fclean re
