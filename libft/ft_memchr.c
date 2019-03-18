/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:34:25 by mroland-          #+#    #+#             */
/*   Updated: 2018/11/30 16:50:35 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*a;

	a = s;
	i = 0;
	while (i < n)
	{
		if (a[i] == (unsigned char)c)
			return ((unsigned char*)&a[i]);
		i++;
	}
	return (NULL);
}
