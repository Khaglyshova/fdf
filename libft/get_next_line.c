/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:01:32 by mroland-          #+#    #+#             */
/*   Updated: 2019/01/20 16:43:18 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	f_end(char **gnl, char **tmp)
{
	gnl[0] = NULL;
	tmp = NULL;
	return (0);
}

static int	f_read(char **tmp, char **gnl, int i)
{
	tmp = gnl;
	gnl[0] = ft_strsub(gnl[0], i + 1, ((ft_strlen(gnl[0]) - i)));
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	static char	*gnl[4096];
	char		*tmp;
	int			i;

	if (fd < 0 || line == NULL || read(fd, buf, 0))
		return (-1);
	if (gnl[fd] == NULL)
		gnl[fd] = ft_strnew(0);
	while ((ft_strchr(gnl[fd], '\n') == NULL) &&
			((ret = read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[ret] = '\0';
		tmp = gnl[fd];
		gnl[fd] = ft_strjoin(gnl[fd], buf);
		free(tmp);
	}
	i = 0;
	while (gnl[fd][i] != '\n' && gnl[fd][i] != '\0')
		i++;
	*line = ft_strsub(gnl[fd], 0, ((size_t)i));
	return (gnl[fd][0] == '\0') ? (f_end(&gnl[fd], &tmp)) : (f_read(&tmp,
				&gnl[fd], i));
}
