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
#include "def.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static int	check_color(int *x, int *y)
{
	if (0 > x[0] || x[0] > 255 || 0 > x[1] || x[1] > 255 ||
		0 > x[2] || x[2] >= 255)
		return (1);
	if (0 > y[0] || y[0] > 255 || 0 > y[1] || y[1] > 255 ||
		0 > y[2] || y[2] >= 255)
		return (1);
	return (0);
}

static int	check_res(int x, int y)
{
	if (x <= 0 || y <= 0)
		return (1);
	return (0);
}

int			check_file(char *s)
{
	int		fd;
	int		ret;
	char	s2[10];

	fd = open(s, O_RDONLY);
	ret = read(fd, &s2, 10);
	close(fd);
	if (ret <= 0)
		return (1);
	return (0);
}

int			parse(t_settings *set)
{
	if (check_res(set->res_x, set->res_y))
		return (INV_RES);
	if (check_utils())
		return (NO_UTI);
	if (check_file(set->t_n) || check_file(set->t_e) ||
		check_file(set->t_s) || check_file(set->t_w))
		return (INV_PATH);
	if (check_file(set->t_sp))
		return (INV_SP);
	if (check_color(set->rgb_f, set->rgb_c))
	{
		free(set->rgb_f);
		free(set->rgb_c);
		return (INV_CLR);
	}
	set->c_c = convert_color(set->rgb_c);
	set->c_f = convert_color(set->rgb_f);
	free(set->rgb_f);
	free(set->rgb_c);
	return (check_map(set->map, &set->map_x, &set->map_y));
}
