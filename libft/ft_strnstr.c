/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:21:20 by mroland-          #+#    #+#             */
/*   Updated: 2018/12/23 20:18:02 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0' && len)
	{
		j = 0;
		while ((haystack[i + j] == needle[j])
				&& needle[j] && (len >= j))
		{
			j++;
		}
		if (needle[j] == '\0')
			return ((char*)&haystack[i]);
		i++;
		len--;
	}
	return (0);
}
