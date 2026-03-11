# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/27 10:47:12 by ebenoist          #+#    #+#              #
#    Updated: 2025/11/13 16:53:06 by ebenoist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Cub3D_bonus
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g -Iincludes
AR			= ar
ARFLAGS		= rcs
OBJ_DIR		= obj
FILES	=	main.c\
			utils/error.c\
			utils/end_of_programme.c\
			keys/close_game.c\
			keys/mouse.c\
			keys/init_keys.c\
			keys/move_player.c\
			keys/move_player2.c\
			keys/rotate_player.c\
			keys/key_loop.c\
			keys/key_loop_utils.c\
			parsing/check_arg.c\
			parsing/malloc_map.c\
			parsing/map_var.c\
			parsing/parsing_color.c\
			parsing/parsing_map.c\
			parsing/parsing_map2.c\
			parsing/parsing_map3.c\
			parsing/parsing_map_utils.c\
			player/init_player.c\
			graphics/init_window.c\
			graphics/init_text.c\
			graphics/init_text_utils.c\
			graphics/minimap.c\
			graphics/minimap_utils.c\
			graphics/put_pixel.c\
			graphics/draw_square.c\
			raycast/cast_ray.c\
			raycast/cast_ray2.c\
			raycast/raycast.c\
			texture/texture.c\
			texture/text_utils.c\

HEADER		= includes/cub3d.h

SRC_DIR		= srcs
SRCS		= $(addprefix $(SRC_DIR)/, $(FILES))

OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

LIBFT_PATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a
MLX_PATH	= ./minilibx-linux
MLX		= $(MLX_PATH)/libmlx_Linux.a
MLX_FLAGS	= -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lbsd
MLX_MAKE	= $(MAKE) -C $(MLX_PATH)

RESET 		= \033[0m
GREEN 		= \033[0;32m
BLUE   		= \033[0;34m
YELLOW		= \033[1;33m

all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(GREEN)compilation Cub3D_bonus...$(RESET)\n"
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH)
	@$(MLX_MAKE) --no-print-directory
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME) $(MLX_FLAGS)
	@printf "$(GREEN)Cub3D_bonus complete$(RESET)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(dir $@)
	@printf "$(YELLOW)Compiling $(notdir $<)$(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "$(BLUE)Cleaning objects$(RESET)\n"
	@rm -f $(OBJ)
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH) clean

fclean: clean
	@printf "$(BLUE)Cleaning all$(RESET)\n"
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH) fclean

re: fclean all
	@printf "$(GREEN)Recompil de Cub3D...$(RESET)\n"

.PHONY: all clean fclean re
