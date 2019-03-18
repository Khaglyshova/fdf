/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:48:38 by mroland-          #+#    #+#             */
/*   Updated: 2018/12/06 15:58:56 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*map;
	size_t	len;
	size_t	i;

	if (s != NULL)
	{
		len = ft_strlen(s);
		map = ft_strnew(len);
		if (!map)
			return (NULL);
		i = 0;
		while (i < len)
		{
			map[i] = f(s[i]);
			i++;
		}
		return (map);
	}
	return (NULL);
}
