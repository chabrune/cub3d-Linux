/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <chabrune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:52:47 by emuller           #+#    #+#             */
/*   Updated: 2023/06/14 01:16:45 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void get_map_dimensions(char **map, t_game_2d *game)
{
	int i;
	int line_length;

	i = -1;
	line_length = 0;
    while (map[++i])
    {
        line_length = strlen(map[i]);
        if (line_length > game->width)
            game->width = line_length;
        (game->height)++;
    }
}

void	put_map_pixel(t_game_2d *game)
{
	uint32_t i = 0;
	uint32_t y = 0;
	mlx_image_t *map;
	
	map = mlx_new_image(game->mlx, 64, 64);

	i = 0;
	while (game->map[i])
	{
		y = 0;
		while (game->map[i][y])
		{
			if(game->map[i][y] == '1')
			{
				mlx_image_to_window(game->mlx, game->player, (i * 64), (y * 64));
				mlx_put_pixel(game->player, i, y, get_rgba(0, 0, 0, 0));
			}
			y++;
		}
		i++;
	}
}


void put_player_pixel(t_game_2d *game)
{
	uint32_t i;
	uint32_t y;

	i = 0;
	while (i < game->player->width)
	{
		y = 0;
		while (y < game->player->height)
		{
			mlx_put_pixel(game->player, i, y, get_rgba(0,0,0,255));
			y++;
		}
		i++;
	}
}

void ft_hook(void* param)
{
	t_game_2d *game = param;

	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		game->player->instances[0].y -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		game->player->instances[0].y += 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		game->player->instances[0].x -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		game->player->instances[0].x += 5;
}

char	**dup_tab(char **tab)
{
	char	**new_tab;
	int		i;

	i = 0;
	while (tab[i])
		i++;
	new_tab = ft_calloc(sizeof(char *), i + 1);
	if (!new_tab)
		return (0);
	i = -1;
	while (tab[++i])
		new_tab[i] = ft_strdup(tab[i]);
	return (new_tab);
}

void	init_player_pos(t_game_2d *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'E' || game->map[i][j] == 'W' || game->map[i][j] == 'S')
			{
				game->posx = i;
				game->posy = j;
			}
		}
	}
}

int	open_window(char **map)
{
	t_game_2d *game;

	game = ft_calloc(sizeof(t_game_2d), 1);
	game->map = dup_tab(map);
	get_map_dimensions(game->map, game);
	init_player_pos(game);
	if (!(game->mlx = mlx_init((game->height * 64), (game->width * 64), "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(game->player = mlx_new_image(game->mlx, 64, 64)))
	{
		mlx_close_window(game->mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(game->mlx, game->player, (game->posy * 64), (game->posx * 64)) == -1)
	{
		mlx_close_window(game->mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	put_map_pixel(game);
	put_player_pixel(game);
	mlx_loop_hook(game->mlx, ft_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}

// Il faudra peut etre combler les vides par des 1
// pour eviter de passer a travers les murs dans les angles
int	main(int argc, char **argv)
{
	int			fd;
	char		**full_file;
	char		**map;
	// t_texture	tex;

	if (argc != 2)
		return (write_wrong_num_ar(argc));
	if (check_map_format(argv[1]) == -1)
		return (1);
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
		return (printf("Error \nInvalid map : map does not exist\n"));
	full_file = read_map(fd);
	// tex = read_texture_data(full_file);
	map = extract_map_from_file(full_file);
	// dans les textures il peut y avoir une error si 2 fois la meme est ecrite et qu'il en manque une,
	// dans se cas on veux exit quand on essayerait d'ouvrir ue texture qui n'a pas ete remplie
	if (open_window(map) == 1)
	{
		printf("Error\n");
		return (1);
	}
	free_tab(full_file);
	free_tab(map);
	return (0);
}
