/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:46:02 by mroland-          #+#    #+#             */
/*   Updated: 2018/11/30 16:51:17 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*a;
	unsigned const char	*b;

	a = dst;
	b = src;
	i = 0;
	while (i < n)
	{
		a[i] = b[i];
		if (b[i] == (unsigned char)c)
			return ((unsigned char*)&a[i + 1]);
		i++;
	}
	return (NULL);
}
