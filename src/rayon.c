/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayon.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <chabrune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:54:04 by chabrune          #+#    #+#             */
/*   Updated: 2023/06/24 02:02:08 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void put_rayon_pixel(t_game_2d *game)
{
    uint32_t i;
    uint32_t y;

    i = -1;
    while (++i < 4)
    {
        y = -1;
        while (++y < 32)
        {
            double rayX = game->pdx + y  * cos(game->pa);
            double rayY = game->pdy + y  * sin(game->pa);
            mlx_put_pixel(game->window, (uint32_t)rayY, (uint32_t)rayX, get_rgba(0, 255, 0, 255));
        }
    }
}