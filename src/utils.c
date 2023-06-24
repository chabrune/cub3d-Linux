/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <chabrune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:57:31 by emuller           #+#    #+#             */
/*   Updated: 2023/06/24 02:02:26 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	line_empty(char *str)
{
	int	i;

	if (!str || !str[0])
		return (1);
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == 0)
		return (1);
	return (0);
}

int	is_valid_char(char c)
{
	if (c == ' ' || c == '\t' || c == '0' || c == '1' || c == 'N' || c == 'E'
		|| c == 'S' || c == 'W')
		return (1);
	return (0);
}

void get_map_dimensions(char **map, t_game_2d *game)
{
	int i;
	int line_length;

	i = -1;
	line_length = 0;
    while (map[++i])
    {
        line_length = ft_strlen(map[i]);
        if (line_length > game->width)
            game->width = line_length;
        (game->height)++;
    }
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