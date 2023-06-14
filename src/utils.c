/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuller <emuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:57:31 by emuller           #+#    #+#             */
/*   Updated: 2023/06/05 18:37:07 by emuller          ###   ########.fr       */
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
