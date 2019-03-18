/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:26:11 by mroland-          #+#    #+#             */
/*   Updated: 2018/12/21 19:41:24 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int min, int max)
{
	int i;

	i = 0;
	while (min < max)
	{
		min++;
		i++;
	}
	return (i);
}

int			*ft_range(int min, int max)
{
	int i;
	int *ar;

	if (min < max)
	{
		ar = (int*)malloc(sizeof(int) * ft_len(min, max));
		if (ar != NULL)
		{
			i = 0;
			while (min < max)
			{
				ar[i] = min;
				min++;
				i++;
			}
		}
	}
	else
		ar = 0;
	return (ar);
}
