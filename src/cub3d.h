/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:53:38 by emuller           #+#    #+#             */
/*   Updated: 2023/06/13 18:12:08 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
}	t_texture;

typedef struct s_game_2d
{
	mlx_t		*mlx;
	mlx_image_t	*player;
	char		**map;
	int			posx;
	int			posy;
	int			width;
	int			height;
}	t_game_2d;

//utils
void	free_tab(char **tab);
int		line_empty(char *str);
int		is_valid_char(char c);
void	exit_error(char	**map, char *msg);

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

#endif
