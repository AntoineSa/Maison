/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:02:03 by asablayr          #+#    #+#             */
/*   Updated: 2020/01/05 12:43:32 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int	get_line(int fd, char **left, char **line)
{
	int		ret;
	char	buff[BUFFER_SIZE + 1];
	char	*end_line;

	ret = 1;
	while ((ret = read(fd, buff, BUFFER_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		if (!(*left = ft_strf1join(*left, buff)))
			return (-1);
		if ((end_line = ft_strchr(*left, '\n')))
		{
			if (!(*line = ft_substr(*left, 0, (end_line - *left))) ||
				!(*left = ft_subfstr(*left, (end_line - *left) + 1, ret)))
				return (-1);
			return (1);
		}
	}
	*line = *left;
	*left = NULL;
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char *left = NULL;
	char		*end_line;
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!left)
	{
		if (!(left = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
		left = ft_memset(left, 0, BUFFER_SIZE + 1);
	}
	else if ((end_line = ft_strchr(left, '\n')))
	{
		if (!(*line = ft_substr(left, 0, (end_line - left))) ||
			!(left = ft_subfstr(left, (end_line - left) + 1, BUFFER_SIZE)))
			return (-1);
		return (1);
	}
	ret = get_line(fd, &left, line);
	if (ret == 1)
		return (1);
	if (ret == 0)
		return (0);
	return (-1);
}
