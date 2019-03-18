/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 21:27:51 by mroland-          #+#    #+#             */
/*   Updated: 2018/12/28 17:28:09 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i - 1] == c || (i == 0)))
			count++;
		i++;
	}
	return (count);
}

static char		*new_row(char const *s, int len, int k)
{
	char *newstr;

	newstr = ft_strnew(len);
	len--;
	k--;
	while (len >= 0)
		newstr[len--] = s[k--];
	return (newstr);
}

static void		free_all(char **newstr, int i)
{
	if (i == 0)
	{
		free(newstr);
		newstr = NULL;
	}
	else
	{
		while (i-- >= 0)
			free(newstr[i]);
		free(newstr);
		newstr = NULL;
	}
}

static char		**new_array(char **newstr, char const *s, char c, int n)
{
	int len;
	int i;
	int k;

	k = 0;
	i = -1;
	while (s[k] != '\0' && n-- > 0)
	{
		len = 0;
		while (s[k] == c)
			k++;
		while (s[k] != c && s[k] != '\0')
		{
			len++;
			k++;
		}
		if (len > 0)
			if (!(newstr[++i] = new_row(s, len, k)))
				free_all(newstr, i);
		while (s[k] == c)
			k++;
	}
	return (newstr);
}

char			**ft_strsplit(char const *s, char c)
{
	int		n;
	char	**newstr;

	if (!s)
		return (NULL);
	n = count_word(s, c);
	newstr = (char**)malloc(sizeof(char*) * (n + 1));
	if (!newstr)
		return (NULL);
	newstr[n] = NULL;
	newstr = new_array(newstr, s, c, n);
	return (newstr);
}
