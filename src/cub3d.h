/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <chabrune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:53:38 by emuller           #+#    #+#             */
/*   Updated: 2023/06/24 04:33:49 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define DISPLAY_WIDTH 1600
# define DISPLAY_HEIGHT 900
# define PI M_PI
# include "../libft/libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include "../MLX42/include/MLX42/MLX42.h"

# define R "\033[0;31m"

typedef struct s_point
{
	float	x;
	float	y;
}	t_point;

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
}	t_texture;

typedef struct s_player
{
	float	angle;
	t_point	coord;
}	t_player;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	q;
	int	e;
}	t_keys;

typedef struct s_game_2d
{
	t_player	*player;
	t_keys		*keys;
	mlx_t		*mlx;
	mlx_image_t	*window;
	char		**map;
	mlx_image_t **image_map;
	mlx_image_t	*rayon;
	float		posx;
	float		posy;
	int			width;
	int			height;
	float		pdy;
	float		pdx;
	float		pa;
	float		rdx;
	float		rdy;
}	t_game_2d;

//utils
void	free_tab(char **tab);
int		line_empty(char *str);
int		is_valid_char(char c);
void	exit_error(char	**map, char *msg);
void	get_map_dimensions(char **map, t_game_2d *game);
char	**dup_tab(char **tab);
int		init_player(t_game_2d *game);
void	init_player_pos(t_game_2d *game);
int		get_rgba(int r, int g, int b, int a);

// Parsing de la map
int		check_map_format(char *s);
int		write_wrong_num_ar(int ar);
t_list	*create_list_from_map(t_list *lst, int fd);
char	**read_map(int fd);
int		find_map_len(int i, char **map);
int		find_beginning_map(char *str);
int		check_valid_line(char *str);
void	check_closed_map(int i, char **map);
int		find_end_map(char **map);
int		check_closed_around_space(char **map);
int		check_around(char **map, int i, size_t j);
char	**extract_map_from_file(char **map_full_file);
int		write_wrong_num_ar(int ar);

// Parsing textures
void		check_tex_num(char 	**file);
void		fill_tex_data(t_texture *tex, char **file);
t_texture	read_texture_data(char	**file);

// Hook
void	ft_key_d(t_game_2d *game);
void	ft_key_w(t_game_2d *game);
void	ft_key_a(t_game_2d *game);
void	ft_key_s(t_game_2d *game);
void	ft_key_right(t_game_2d *game);
void	ft_key_left(t_game_2d *game);
void 	ft_hook(void* param);

// Pixel
void 	put_player_pixel(t_game_2d *game);
void	put_pixel(t_game_2d *game, uint32_t x, uint32_t y, int color);
void 	put_map_pixel(t_game_2d *game);

// Player
void	init_player_direction(t_game_2d *game);
void 	put_rayon_pixel(t_game_2d *game);
void	key_handler(mlx_key_data_t k, void *param);
void	draw(void *param);
void	movements_handler(t_game_2d *game);


#endif