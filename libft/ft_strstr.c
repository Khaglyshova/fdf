/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:21:20 by mroland-          #+#    #+#             */
/*   Updated: 2018/12/03 17:38:11 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;
	size_t len;

	i = 0;
	len = ft_strlen(needle);
	if (*needle == '\0')
		return ((char*)&haystack[i]);
	while (haystack[i] != '\0')
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && (needle[j] != '\0'))
		{
			j++;
		}
		if (j == len)
			return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}
