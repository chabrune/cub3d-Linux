
// int get_rgba(int r, int g, int b, int a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// void get_map_dimensions(char **map, t_game_2d *game)
// {
// 	int i;
// 	int line_length;

// 	i = -1;
// 	line_length = 0;
//     while (map[++i])
//     {
//         line_length = strlen(map[i]);
//         if (line_length > game->width)
//             game->width = line_length;
//         (game->height)++;
//     }
// }

// char	**dup_tab(char **tab)
// {
// 	char	**new_tab;
// 	int		i;

// 	i = 0;
// 	while (tab[i])
// 		i++;
// 	new_tab = ft_calloc(sizeof(char *), i + 1);
// 	if (!new_tab)
// 		return (0);
// 	i = -1;
// 	while (tab[++i])
// 		new_tab[i] = ft_strdup(tab[i]);
// 	return (new_tab);
// }

// void	init_player_pos(t_game_2d *game)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (game->map[++i])
// 	{
// 		j = -1;
// 		while (game->map[i][++j])
// 		{
// 			if (game->map[i][j] == 'N' || game->map[i][j] == 'E' || game->map[i][j] == 'W' || game->map[i][j] == 'S')
// 			{
// 				game->posx = i;
// 				game->posy = j;
// 			}
// 		}
// 	}
// }

// void	put_pixel(t_game_2d *game, uint32_t x, uint32_t y, int color)
// {
// 	int i;
// 	int j;

// 	i = -1;
// 	while (++i < 32)
// 	{
// 		j = -1;
// 		while (++j < 32)
// 			mlx_put_pixel(game->window, x + i, y + j, color);
// 	}
// }

// void	put_map_pixel(t_game_2d *game)
// {
// 	uint32_t i;
// 	uint32_t j;
// 	int color;

// 	i = -1;
// 	while (game->map[++i])
// 	{
// 		j = -1;
// 		while (game->map[i][++j])
// 		{
// 			if (game->map[i][j] == '1')
// 				color = get_rgba(255, 255, 255, 255);
// 			else if (game->map[i][j] == '0')
// 				color = get_rgba(0, 0, 0, 255);
// 			else if (game->map[i][j] == '2')
// 				color = get_rgba(255, 0, 0, 255);
// 			else if (game->map[i][j] == 'N' || game->map[i][j] == 'E' || game->map[i][j] == 'W' || game->map[i][j] == 'S')
// 				color = get_rgba(0, 255, 0, 255);
// 			put_pixel(game, j * 32, i * 32, color);
// 		}
// 	}
// }

// int	open_window(char **map)
// {
// 	t_game_2d *game;

// 	game = ft_calloc(sizeof(t_game_2d), 1);
// 	game->map = dup_tab(map);
// 	get_map_dimensions(game->map, game);
// 	init_player_pos(game);
// 	game->mlx = mlx_init((1400), (700), "MLX42", true);
// 	game->window = mlx_new_image(game->mlx, 1400, 700);
// 	mlx_image_to_window(game->mlx, game->window, 0, 0);
// 	put_map_pixel(game);
// 	// put_player_pixel(game);
// 	// mlx_loop_hook(game->mlx, ft_hook, game);
// 	mlx_loop(game->mlx);
// 	mlx_terminate(game->mlx);
// 	free(game);
// 	return (EXIT_SUCCESS);
// }

// // Il faudra peut etre combler les vides par des 1
// // pour eviter de passer a travers les murs dans les angles
// int	main(int argc, char **argv)
// {
// 	int			fd;
// 	char		**full_file;
// 	char		**map;
// 	// t_texture	tex;

// 	if (argc != 2)
// 		return (write_wrong_num_ar(argc));
// 	if (check_map_format(argv[1]) == -1)
// 		return (1);
// 	fd = open(argv[1], O_RDWR);
// 	if (fd == -1)
// 		return (printf("Error \nInvalid map : map does not exist\n"));
// 	full_file = read_map(fd);
// 	// tex = read_texture_data(full_file);
// 	map = extract_map_from_file(full_file);
// 	// dans les textures il peut y avoir une error si 2 fois la meme est ecrite et qu'il en manque une,
// 	// dans se cas on veux exit quand on essayerait d'ouvrir ue texture qui n'a pas ete remplie
// 	if (open_window(map) == 1)
// 	{
// 		printf("Error\n");
// 		return (1);
// 	}
// 	free_tab(full_file);
// 	free_tab(map);
// 	return (0);
// }





/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:52:47 by emuller           #+#    #+#             */
/*   Updated: 2023/06/23 20:50:20 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_window(char **map)
{
	t_game_2d *game;

	game = ft_calloc(sizeof(t_game_2d), 1);
	game->keys = ft_calloc(sizeof(t_keys), 1);

	game->map = dup_tab(map);
	get_map_dimensions(game->map, game);
	init_player_pos(game);
	game->mlx = mlx_init((DISPLAY_WIDTH), (DISPLAY_HEIGHT), "cub3d", true);
	game->window = mlx_new_image(game->mlx, DISPLAY_WIDTH, DISPLAY_HEIGHT);
	mlx_image_to_window(game->mlx, game->window, 0, 0);
	put_map_pixel(game);
	mlx_key_hook(game->mlx, &key_handler, &game);
	mlx_loop_hook(game->mlx, &draw, &game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free(game);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	int			fd;
	char		**full_file;
	char		**map;

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
	if (open_window(map) == 1)
	{
		printf("Error\n");
		return (1);
	}
	free_tab(full_file);
	free_tab(map);
	return (0);
}