/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:51:50 by asablayr          #+#    #+#             */
/*   Updated: 2020/02/20 08:55:40 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cube.h"
#include "libft.h"
#include <stdio.h>

int	check_w(t_game g, float x, float y)
{
	if (g.r.d > M_PI && g.r.d <= 2 * M_PI)
		y = (int)y - 1;
	else
		y = (int)y;
	if (g.r.d > M_PI_2 && g.r.d < 3 * M_PI_2)
		x = (int)x - 1;
	else
		x = (int)x;
	if (x > g.set.map_x - 1)//bad opti
		x = g.set.map_x - 1;
	else if (x < 0)
		x = 0;
	if (y > g.set.map_y - 1)
		y = g.set.map_y - 1;
	else if (y < 0)
		y = 0;
	return(g.set.map[(int)y][(int)x] - '0');
}

float		get_dist(t_game g, double d, t_ray *r)
{
	r->d = d;
	r->h = get_wall_h(g, r);
	r->v = get_wall_v(g, r);
	r->side = r->h >= r->v ? 0 : 1;
	if (!g.press.aim)
		return (r->side == 0 ? r->v : r->h);
	else
		return (r->side == 0 ? r->v / 2 : r->h / 2);
}

void		raycast(t_game g)
{
	int		j;
	double	i;
	double	d;

	j = 0;
	i = g.p.fov / g.set.res_x;
	d = g.p.dir - M_PI / 6;
	if (g.press.aim)
	{
		i /= 2;
		d = g.p.dir - (M_PI / 12);
	}
	while (j < g.set.res_x)
	{
		reset_dir(&d);
		draw_column(g, get_dist(g, d, &g.r), j++);
		d += i;
	}
	draw_map(g);
}
