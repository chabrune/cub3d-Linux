/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <chabrune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:25:53 by chabrune          #+#    #+#             */
/*   Updated: 2023/06/24 13:04:45 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw(void *param)
{
	t_game_2d	*game;

	game = (t_game_2d *)param;
	movements_handler(game);
	// mlx_delete_image(game->mlx, game->window);
	game->window = mlx_new_image(game->mlx, DISPLAY_WIDTH, DISPLAY_HEIGHT);
	// raycaster(game);
	mlx_image_to_window(game->mlx, game->window, 0, 0);
}

static t_point	move_point(t_game_2d *game, float angle, float step)
{
	t_point	p;
	int		x;
	int		y;

	p.x = game->player->coord.x + cos(game->player->angle + angle) * step;
	p.y = game->player->coord.y + sin(game->player->angle + angle) * step;
	x = p.x / 32;
	y = p.y / 32;
	if (game->map[y][x] == '1' || \
		(game->map[\
			(int)(game->player->coord.y / 32)][x] == '1' \
		&& game->map[y][\
			(int)(game->player->coord.x / 32)] == '1'))
		p = game->player->coord;
	if (game->map[y][x] == 'D' || \
		(game->map[\
			(int)(game->player->coord.y / 32)][x] == 'D' \
		&& game->map[y][\
			(int)(game->player->coord.x / 32)] == 'D'))
		p = game->player->coord;
	return (p);
}

void	movements_handler(t_game_2d *game)
{
	game->keys = ft_calloc(1, sizeof(t_keys));
	if (game->keys->w)
		game->player->coord = move_point(game, 0, 5);
	if (game->keys->s)
		game->player->coord = move_point(game, M_PI, 5);
	if (game->keys->a)
		game->player->coord = move_point(game, -(M_PI / 2), 5);
	if (game->keys->d)
		game->player->coord = move_point(game, M_PI / 2, 5);
	// if (game->keys.q)
	// 	game->player.angle = adjust_angle(game->player.angle - 2 * PI / 72);
	// if (game->keys.e)
	// 	game->player.angle = adjust_angle(game->player.angle + 2 * PI / 72);
	// if (game->bonus)
	// 	mouse_handler(game);

}

void	key_handler(mlx_key_data_t k, void *param)
{
	t_game_2d	*game;

	game = param;
	if (k.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	if (k.action == MLX_PRESS || k.action == MLX_RELEASE)
	{
		if (k.key == MLX_KEY_W || k.key == MLX_KEY_UP)
			game->keys->w ^= 1;
		if (k.key == MLX_KEY_S || k.key == MLX_KEY_DOWN)
			game->keys->s ^= 1;
		if (k.key == MLX_KEY_A)
			game->keys->a ^= 1;
		if (k.key == MLX_KEY_D)
			game->keys->d ^= 1;
		if (k.key == MLX_KEY_Q || k.key == MLX_KEY_LEFT)
			game->keys->q ^= 1;
		if (k.key == MLX_KEY_E || k.key == MLX_KEY_RIGHT)
			game->keys->e ^= 1;
	}
}