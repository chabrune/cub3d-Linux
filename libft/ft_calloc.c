/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <chabrune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 10:28:57 by emuller           #+#    #+#             */
/*   Updated: 2023/06/13 21:57:48 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;
	size_t	i;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	i = 0;
	s = malloc(count * size);
	if (!s)
		return (0);
	while (i < (count * size))
	{
		*(s + i) = 0;
		i++;
	}
	return (s);
}
