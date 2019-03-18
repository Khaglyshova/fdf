/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:20:03 by mroland-          #+#    #+#             */
/*   Updated: 2018/12/07 22:37:52 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s11;
	unsigned char	*s22;
	size_t			i;

	s11 = (unsigned char*)s1;
	s22 = (unsigned char*)s2;
	if ((*s11 == '\0' && *s22 == '\0') || n == 0)
		return (0);
	i = 0;
	while (s11[i] == s22[i] && (s11[i] != '\0' && s22[i] != '\0') && i < n)
		i++;
	if (i == n && s11[i - 1] == s22[i - 1])
		return (s11[i - 1] - s22[i - 1]);
	return (s11[i] - s22[i]);
}
