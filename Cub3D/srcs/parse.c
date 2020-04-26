/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
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
#include <stdio.h>

static int	check_utils_txt(char *s)//BONUS
{
	int	fd;
	char	*tmp;
	char	s2[10];

	tmp = ft_strjoin(TXT_PATH, s);
	fd = open(tmp, O_RDONLY);
	free(tmp);
	if (read(fd, &s2, 10) <= 0 )
		return(1);
	return (0);
}

static int	check_color(int *x, int *y)
{
	if ((0 > x[0] && x[0] > 255) || (0 > x[1] && x[1] > 255) ||
			(0 > x[2] && x[2] > 255))
		return (1);
	if ((0 > y[0] && y[0] > 255) || (0 > y[0] && y[0] > 255) ||
			(0 > y[0] && y[0] > 255))
		return (1);
	return (0);
}

static int	check_res(int x, int y)
{
	if (x <= 0 || y <= 0)
		return (1);
	if (x > 1920)
		x = 1920;
	if (y > 1200)
		y = 1200;
	return (0);
}

static int	check_text(char *s)
{
	int		fd;
	int 	ret;
	char	s2[10];

	fd  = open(s, O_RDONLY);
	ret = read(fd, &s2, 10);
	close(fd);
	if (ret <= 0)
		return (1);
	return (0);
}

int	check_utils(void)
{
	if (check_utils_txt("red_cross.xpm") || check_utils_txt("blue_light.xpm"))//BONUS
		return (1);
	if (check_utils_txt("sniper_aim.xpm") || check_utils_txt("sniper.xpm"))
		return (1);//can improve
	if (check_utils_txt("dead_screen.xpm"))
		return (1);
	return (0);
}

int	parse(t_settings *set)
{
	if (check_res(set->res_x, set->res_y))
		return (3);
	if (check_utils())
		return (4);//can improve
	if (check_text(set->t_n) ||check_text(set->t_e) ||check_text(set->t_s) ||
			check_text(set->t_w))
		return (4);
	if (check_text(set->t_sp))
		return (5);
	if (check_color(set->rgb_f, set->rgb_c))
		return (6);
	return (check_map(set->map, &set->map_x, &set->map_y));
}
