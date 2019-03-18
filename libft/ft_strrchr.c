/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:00:38 by mroland-          #+#    #+#             */
/*   Updated: 2018/12/04 20:26:22 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*adr;

	i = 0;
	adr = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			adr = (char*)&s[i];
		i++;
	}
	if (s[i] == (unsigned char)c)
		adr = (char*)&s[i];
	if (adr == 0)
		return (NULL);
	else
		return (adr);
}
