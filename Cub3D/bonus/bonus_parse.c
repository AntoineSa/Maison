/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 12:37:57 by asablayr          #+#    #+#             */
/*   Updated: 2020/03/12 17:52:52 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static int	check_utils_txt(char *s)
{
	int		fd;
	char	*tmp;
	char	s2[10];

	tmp = ft_strjoin(TXT_PATH, s);
	fd = open(tmp, O_RDONLY);
	free(tmp);
	if (read(fd, &s2, 10) <= 0)
		return (1);
	return (0);
}

int			check_utils(void)
{
	if (check_utils_txt("red_cross.xpm") || check_utils_txt("blue_light.xpm"))
		return (1);
	if (check_utils_txt("sniper_aim.xpm") || check_utils_txt("sniper.xpm"))
		return (1);
	if (check_utils_txt("dead_screen.xpm"))
		return (1);
	return (0);
}
