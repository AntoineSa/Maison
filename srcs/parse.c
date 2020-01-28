/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 12:37:57 by asablayr          #+#    #+#             */
/*   Updated: 2020/01/18 13:21:51 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

static int	check_color(int *x, int *y)
{
	if ((0 > x[0] && x[0] > 255) || (0 > x[1] && x[1] > 255) ||
			(0 > x[2] && x[2] > 255))
		return (0);
	if ((0 > y[0] && y[0] > 255) || (0 > y[0] && y[0] > 255) ||
			(0 > y[0] && y[0] > 255))
		return (0);
	return (1);
}

static int	check_res(int x, int y)
{
	if (x <= 0 || y <= 0)
		return (0);
	if (x > 1920)
		x = 1920;
	if (y > 1200)
		y = 1200;
	return (1);
}

static int	check_text(char *s)
{
	int		fd;
	int 	ret;
	char	*s2;

	s2 = NULL;
	fd  = open(s, O_RDONLY);
	ret = read(fd, s2, 10);
	close(fd);
	if (ret <= 0)
		return (0);
	return (0);// <- replace 0 by 1 or smth
}

int	parse(t_settings *set)
{
	if (check_res(set->res_x, set->res_y) == 0)
		return (1);
	if (check_text(set->t_n))
		return (2);
	if (check_text(set->t_e))
		return (2);
	if (check_text(set->t_s))
		return (2);
	if (check_text(set->t_w))
		return (2);
	if (check_text(set->t_sp))
		return (2);
	check_color(set->rgb_f, set->rgb_c);
	check_map(set->map, &set->map_y, &set->map_x);
	return (0);
}
