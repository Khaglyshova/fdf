/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:40:34 by mroland-          #+#    #+#             */
/*   Updated: 2018/12/04 20:12:33 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t i;
	size_t k;

	i = ft_strlen(s1);
	k = 0;
	while (s2[k] != '\0')
	{
		s1[i] = s2[k];
		i++;
		k++;
	}
	s1[i] = '\0';
	return (s1);
}
