/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:46:26 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/14 13:43:23 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termcap.h>
# include <termios.h>
# include <unistd.h>

# define WIDTH 1920
# define HEIGHT 1080
# define BLOCK 32
# define PI 3.14159265359

# define COLLISION_BUFFER 0.2

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_SPACE 32
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct s_ray
{
	double			ray_dir_x;
	double			ray_dir_y;
	double			distance;
	int				side;
	int				screen_x;
	int				screen_y;
	double			wall_x;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			ray_angle;
}					t_ray;

typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				pitch;
}					t_player;

typedef struct s_keys
{
	int				w;
	int				a;
	int				s;
	int				d;
	int				left;
	int				right;
	int				space;
	int				esc;
}					t_keys;

typedef struct s_var
{
	char			**map;
	char			*f;
	char			*c;
	char			*no;
	char			*no2;
	char			*so;
	char			*ea;
	char			*we;
}					t_var;

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*w_ptr;
	int				anim_frame;
	void			*img_wall_no;
	void			*img_wall_no_2;
	void			*img_wall_ea;
	void			*img_wall_so;
	void			*img_wall_we;
	void			*img_floor;
	void			*img_player;
	char			*img_data;
	int				bpp;
	int				line_len;
	int				endian;
	int				win_width;
	int				win_height;
}					t_mlx;

typedef struct s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct s_tex_data
{
	int				width;
	int				height;
	int				endian;
	int				bpp;
	int				size_line;
	unsigned int	*data;
}					t_tex_data;

typedef struct s_texture
{
	void			*no;
	void			*no2;
	void			*so;
	void			*we;
	void			*ea;
	unsigned int	*no_data;
	unsigned int	*so_data;
	unsigned int	*we_data;
	unsigned int	*ea_data;
	t_tex_data		tex_ptr[4];
	t_tex_data		alt_tex_ptr[4];
	void			*img_alt[4];
}					t_texture;

typedef struct s_mm_data
{
	int				tile_size;
	int				mm_size;
	int				mm_x;
	int				mm_y;
	int				tiles_to_show;
	int				i;
	int				j;
	int				draw_x;
	int				draw_y;
	int				i_min;
	int				i_max;
	int				j_min;
	int				j_max;
	int				map_height;
	int				player_pixel_x;
	int				player_pixel_y;
}					t_mm_data;

typedef struct s_game
{
	char			**map;
	char			cell;
	t_var			var;
	t_mlx			mlx;
	t_rgb			c;
	t_rgb			f;
	t_keys			keys;
	t_player		player;
	t_ray			ray;
	t_texture		texture;
	t_mm_data		mm;
	void			*ig;
	int				frame_toggle;
}					t_game;

typedef struct s_token
{
	int				no;
	int				so;
	int				we;
	int				ea;
	int				f;
	int				c;
	int				error;

}					t_token;

// Parsing
void				check_arg(int ac, char **av);
int					check_map_valide(t_game *game);
int					check_map(char **map, int i, int j, int x);
int					ft_control_zero(char **map, int i, int j);
int					check_char_valide(char j);
int					check_good_char(char j);
int					ft_is_player(char c);
int					parsing_color(char *str, t_rgb *color);
int					all_tokens_are_one(t_token token);
t_token				process_colors(char *map, t_token token, int j,
						t_game *game);

// malloc map
char				**malloc_maps(char *av);
char				*extract_texture_path(char *map, int j, int offset);
char				*extract_color_line(char *map, int j, int offset);
char				**extract_map(char **full_file, int start);

// graphics
void				init_window(t_game *game);
void				draw_map_2d(t_game *game);
int					is_walkable_tile(char tile);
int					is_valid_tile(t_game *game);
int					rgb_to_hex(int r, int g, int b);

// raycast
void				init_ray_params(t_game *game, double ray_dir_x,
						double ray_dir_y);
void				calc_step_x(t_game *game, double ray_dir_x);
void				calc_step_y(t_game *game, double ray_dir_y);
void				recast(t_game *game);
void				cast_ray(t_game *game, double ray_dir_x, double ray_dir_y);
int					can_move_to(t_game *game, double x, double y);

// texture
void				init_texture(t_game *game);
void				draw_textured_column(t_game *game, int x);
int					get_texture_pixel(t_game *game, t_tex_data *tex_data,
						double tex_x, double tex_y);
void				draw_floor_ceiling(t_game *game, int x);
void				init_north2_texture(t_game *game);
void				init_door_open_texture(t_game *game);
void				init_door_close_texture(t_game *game);

// keys
int					close_game(t_game *game);
void				init_keys(t_keys *keys);
int					key_press(int keycode, t_game *game);
int					key_release(int keycode, t_game *game);
void				handle_movement(t_game *game);
void				move_player_forward(t_game *game, double move_speed);
void				handle_rotation(t_game *game);
int					game_loop(t_game *game);
int					mouse_move(int x, int y, t_game *game);

// player
void				init_player(t_game *game);

// Error
void				free_end_of_programme(t_game *game);
void				msg_and_quit(char *str);
void				msg_and_eof(t_game *game, char *str);
void				ft_error_file(void);
void				ft_error_malloc(char **map);
void				free_map(char **map);

// test
void				draw_map_2d(t_game *game);
void				draw_square(int size, int color, t_game *game);
void				draw_square2(int size, int color, t_game *game);
void				put_pixel(int x, int y, int color, t_game *game);
void				draw_minimap_background(t_game *game, int mm_x, int mm_y,
						int mm_size);
void				clear_image(t_game *game);
int					get_line_length(char *line);
int					get_map_height(char **map);

#endif