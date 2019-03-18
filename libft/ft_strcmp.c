/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:24:29 by mroland-          #+#    #+#             */
/*   Updated: 2018/12/06 18:30:55 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*s11;
	unsigned char	*s22;
	int				i;

	s11 = (unsigned char*)s1;
	s22 = (unsigned char*)s2;
	if (*s11 == '\0' && *s22 == '\0')
		return (0);
	i = 0;
	while (s11[i] == s22[i] && (s11[i] != '\0' && s22[i] != '\0'))
		i++;
	return (s11[i] - s22[i]);
}
