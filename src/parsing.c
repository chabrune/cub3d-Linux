/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <chabrune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:59:55 by emuller           #+#    #+#             */
/*   Updated: 2023/06/13 21:51:01 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**extract_map_from_file(char **map_full_file)
{
	char	**map;
	int		i;
	int		j;
	int		len_map;

	i = 0;
	while (map_full_file[i] && !find_beginning_map(map_full_file[i]))
		i++;
	len_map = find_map_len(i, map_full_file);
	check_closed_map(i, map_full_file);
	j = 0;
	map = ft_calloc(sizeof(char *), len_map + 1);
	while (map_full_file[i] && line_empty(map_full_file[i]) != 1)
	{
		map[j] = ft_strdup(map_full_file[i]);
		i++;
		j++;
	}
	if (check_closed_around_space(map))
	{
		free_tab(map);
		free_tab(map_full_file);
		exit(1);
	}
	return (map);
}

t_texture	read_texture_data(char	**file)
{
	t_texture	tex;
	char		**file_tex_only;
	int			i;

	i = 0;
	while (file[i] && find_beginning_map(file[i]) == 0)
		i++;
	file_tex_only = ft_calloc(i + 1, sizeof(char *));
	i = -1;
	while (file[++i] && find_beginning_map(file[i]) == 0)
		file_tex_only[i] = ft_strdup(file[i]);
	check_tex_num(file_tex_only); // il faut free les 2 char ** quand on exit
	fill_tex_data(&tex, file_tex_only); // il faut free les 2 char ** quand on exit
	free_tab(file_tex_only);
	return (tex);
}

void	check_tex_num(char 	**file)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (file[++i])
	{
		if (line_empty(file[i]))
			continue ;
		count++;
	}
	if (count != 6)
	{
		printf("Error \nInvalid texture: wrong number of textures\n");
		exit (1);
	}
}

void	fill_tex_data(t_texture *tex, char **file)
{
	char	**tmp;
	int		i;

	i = -1;
	while (file[++i])
	{
		if (line_empty(file[i]))
			continue ;
		tmp = ft_split(file[i], ' ');
		if (!ft_strncmp(tmp[0], "NO", 2) && !tmp[0][2] && !tmp[2])
			tex->north = ft_strdup(tmp[1]);
		else if (!ft_strncmp(tmp[0], "SO", 2) && !tmp[0][2] && !tmp[2])
			tex->south = ft_strdup(tmp[1]);
		else if (!ft_strncmp(tmp[0], "WE", 2) && !tmp[0][2] && !tmp[2])
			tex->west = ft_strdup(tmp[1]);
		else if (!ft_strncmp(tmp[0], "EA", 2) && !tmp[0][2] && !tmp[2])
			tex->east = ft_strdup(tmp[1]);
		else if (!ft_strncmp(tmp[0], "F", 1) && !tmp[0][1] && !tmp[2])
			tex->floor = ft_strdup(tmp[1]);		// au lieu d'un char * on veux atoi dans un tableau d'int
		else if (!ft_strncmp(tmp[0], "C", 1) && !tmp[0][1] && !tmp[2])
			tex->ceiling = ft_strdup(tmp[1]);   // au lieu d'un char * on veux atoi dans un tableau d'int
		else
		{
			printf("Error \nInvalid texture: wrong identifier\n");
			exit (1);
		}
		free_tab(tmp);
		tmp = NULL;
	}
}