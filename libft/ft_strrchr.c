/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:17:47 by emuller           #+#    #+#             */
/*   Updated: 2022/11/04 13:01:56 by emuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = ft_strlen(str);
	if ((unsigned char)c == 0)
		return (str + i);
	if (i == 0)
		return (0);
	i--;
	while (str[i] && str[i] != (unsigned char)c && i > 0)
		i--;
	if (i <= 0 && (unsigned char)c != 0 && str[i] != (unsigned char)c)
		return (0);
	return (str + i);
}
