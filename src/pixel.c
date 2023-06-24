/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <chabrune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:28:37 by chabrune          #+#    #+#             */
/*   Updated: 2023/06/24 04:19:31 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	put_pixel(t_game_2d *game, uint32_t x, uint32_t y, int color)
{
	int i;
	int j;

	i = -1;
	while (++i < 32)
	{
		j = -1;
		while (++j < 32)
			mlx_put_pixel(game->window, x + i, y + j, color);
	}
}

void	put_map_pixel(t_game_2d *game)
{
	uint32_t i;
	uint32_t j;
	int color;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == '1')
				color = get_rgba(0, 0, 255, 255);
			else if (game->map[i][j] == '0')
				color = get_rgba(0, 0, 0, 255);
			else if (game->map[i][j] == 'N' || game->map[i][j] == 'E' || game->map[i][j] == 'W' || game->map[i][j] == 'S')
				color = get_rgba(0, 255, 0, 255);
    		put_pixel(game, j * 32, i * 32, color);
		}
	}
}