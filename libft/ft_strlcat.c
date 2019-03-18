/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 17:26:52 by mroland-          #+#    #+#             */
/*   Updated: 2018/12/03 15:09:13 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t sizedst;
	size_t sizesrc;
	size_t i;

	sizedst = ft_strlen(dst);
	sizesrc = ft_strlen(src);
	if (sizedst < size)
	{
		size = size - sizedst - 1;
		i = 0;
		while (size > i && src[i] != '\0')
		{
			dst[sizedst + i] = src[i];
			i++;
		}
		dst[sizedst + i] = '\0';
		return (sizedst + sizesrc);
	}
	return (sizesrc + size);
}
