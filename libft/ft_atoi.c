/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:30:26 by mroland-          #+#    #+#             */
/*   Updated: 2018/12/06 18:38:30 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long long int	n;
	int				i;
	int				znak;

	n = 0;
	i = 0;
	znak = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		i++;
		znak = znak * -1;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (n * 10 / 10 != n)
			return ((znak == 1) ? -1 : 0);
		n = 10 * n + (str[i] - '0');
		i++;
	}
	return (n * znak);
}
