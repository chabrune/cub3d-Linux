/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <chabrune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:33:44 by chabrune          #+#    #+#             */
/*   Updated: 2023/06/24 13:03:26 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player_pos(t_game_2d *game)
{
	int	i;
	int	j;

	game->player = ft_calloc(1, sizeof(t_player));
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'E'
					|| game->map[i][j] == 'W' || game->map[i][j] == 'S')
			{
				game->player->coord.x = j;
				game->player->coord.y = i;
				game->posx = j;
				game->posy = i;
			}
		}
	}
	init_player_direction(game);
}

void	init_player_direction(t_game_2d *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'N')
				game->pa = PI/2;
			else if (game->map[i][j] == 'E')
				game->pa = 0;
			else if (game->map[i][j] == 'W')
				game->pa = PI;
			else if (game->map[i][j] == 'S')
				game->pa = 3*PI/2;
		}
	}
}