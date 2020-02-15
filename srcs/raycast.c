/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:51:50 by asablayr          #+#    #+#             */
/*   Updated: 2020/02/15 12:11:37 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cube.h"
#include "libft.h"
#include <stdio.h>

int	check_w(t_game g, float x, float y)
{
/*	if (g.r.side == 1)//v
	{
		if (x < g.p.x)
			x = (int)x - 1;
		else
			x = (int)x;
	}
	else//h
	{
		if (y < g.p.y)
			y = (int)y - 1;
		else
			y = (int)y;
	}
*/	if (g.r.d > M_PI && g.r.d <= 2 * M_PI)
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
//	reset_dir(&d);
/*	if (d == 0 || d == M_PI || d == 2 * M_PI)
	{
		printf("v\n");
		return (r->v = get_wall_v(g, r));
	}
	else if (d == M_PI_2 || d == 3 * M_PI_2)
	{
		printf("h\n");
		return (r->h = get_wall_h(g, r));
	}
	else
	{
		r->h = get_wall_h(g, r);
		r->v = get_wall_v(g, r);
	}
*/	r->h = get_wall_h(g, r);
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
	d = (g.p.dir - M_PI / 6);
	reset_dir(&d);
//	draw_column(g, get_dist(g, d), j++);
//	printf("p.dir : %.4f, dist = %.4f, p_x : %.4f, p_y : %.4f\n", g.p.dir, get_dist(g, g.p.dir), g.p.x, g.p.y);
//	printf("dir : %.4f, dist = %.4f, p_x : %.4f, p_y : %.4f\n", d, get_dist(g, d), g.p.x, g.p.y);
	while (j < g.set.res_x)
	{
		d += i;
		reset_dir(&d);
		draw_column(g, get_dist(g, d, &g.r), j++);
		if (g.r.side == 0)
			printf("v dist = %.4f, dir %.4f p.x : %.4f, p.y : %.4f\n", g.r.v, g.r.d, g.r.v_x, g.r.v_y);
		else
			printf("h dist = %.4f, dir %.4f p.x : %.4f, p.y : %.4f\n", g.r.h, g.r.d, g.r.h_x, g.r.h_y);
	}
	draw_map(g);
//	draw_window(g.img);
}
