/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 09:58:44 by ebenoist          #+#    #+#             */
/*   Updated: 2025/07/15 09:48:53 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		p;
	int		collect_count;
	int		moves;
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_exit2;
	void	*img_enemy;
	void	*img_enemy2;
	void	*img_collect;
	int		current_frame;
	int		frame_delay;
}			t_game;

void		ft_arg_error(int ac, char *file);
void		ft_error_file(void);
char		**read_file(char *file);
void		ft_error_malloc(char **tab);
void		ft_error_malloc_2(t_game *game);
void		free_map(char **map);
void		ft_invalid_map(char **map);
void		ft_check_norm(t_game *game);
void		parse_map_char(t_game *game);
int			ft_path(char **map);
void		error_mlx(t_game *game);
void		load_image(t_game *game);
void		error_load(t_game *game);
void		destroy_error(t_game *game);
void		destroy_game(t_game *game);
void		render_map(t_game *game);
int			handle_key(int keycode, t_game *game);
void		count_moves(t_game *game);
void		loose_game(t_game *game);
void		sucess_game(t_game *game);
void		take_collectible(t_game *game, int y, int x);
int			game_loop(t_game *game);
void		update_animation(t_game *game);

# define TILE_SIZE 64

#endif