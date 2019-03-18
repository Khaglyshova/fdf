/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 18:24:44 by mroland-          #+#    #+#             */
/*   Updated: 2018/12/21 19:42:59 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countc(char *src, char c)
{
	int i;
	int count;

	if (!src)
		return (0);
	i = 0;
	count = 0;
	while (src[i] != '\0')
	{
		if (src[i] == c)
			count++;
		i++;
	}
	return (count);
}
