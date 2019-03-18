/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 20:56:30 by mroland-          #+#    #+#             */
/*   Updated: 2018/12/10 22:23:33 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && len > 0)
	{
		len--;
		i++;
	}
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	j = 0;
	while (j < len)
		str[j++] = s[i++];
	return (str);
}
