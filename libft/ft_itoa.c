/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:47:39 by mroland-          #+#    #+#             */
/*   Updated: 2018/12/17 19:17:19 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_n(int n, int count)
{
	while ((n / 10) > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static char	*filler(char *s, int n, int len, int flag)
{
	if (flag == 0)
	{
		while (len > 0)
		{
			s[len - 1] = (n % 10 + '0');
			n = n / 10;
			len--;
		}
	}
	if (flag == 1)
	{
		s[0] = '-';
		while (len - 1 > 0)
		{
			s[len - 1] = (n % 10 + '0');
			n = n / 10;
			len--;
		}
	}
	return (s);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		flag;

	flag = 0;
	len = 1;
	if (n == -2147483648)
	{
		s = ft_strnew(11);
		s = ft_strcpy(s, "-2147483648");
		return (s);
	}
	if (n < 0)
	{
		n = -n;
		len = len + 1;
		flag = 1;
	}
	len = count_n(n, len);
	s = ft_strnew((size_t)len);
	if (!s)
		return (NULL);
	s = filler(s, n, len, flag);
	return (s);
}
