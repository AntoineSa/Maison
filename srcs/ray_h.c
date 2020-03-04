/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_h.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:54:42 by asablayr          #+#    #+#             */
/*   Updated: 2020/02/27 12:32:46 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <math.h>
#include <stdlib.h>

static int		check_wall_h(t_game g, float x, float y)
{
	if (g.r.d > M_PI && g.r.d <= 2 * M_PI)
		y = y - 1;
	if (x > g.set.map_x - 1)
		x = g.set.map_x - 1;
	else if (x < 0)
		x = 0;
	if (y > g.set.map_y - 1)
		y = g.set.map_y - 1;
	else if (y < 0)
		y = 0;
	return (g.set.map[(int)y][(int)x] -'0');
}

static float	*get_h_const(float dir)
{
	float	x_a;
	float	y_a;
	float	*ray;

	ray = ft_calloc(sizeof(float), 2);
	if (dir == 0 || dir == M_PI)
		y_a = 0;
	else if (dir > 0 && dir < M_PI)
		y_a = 1;
	else
		y_a = -1;
	if (dir == 0)
		x_a = 1;
	else if (dir == M_PI_2 || dir == 3 * M_PI_2)
		x_a = 0;
	else if (dir == M_PI)
		x_a = -1;
	else if (dir > 0 && dir < M_PI)
		x_a = 1 / tan(dir);
	else
		x_a = -1 / tan(dir);
	ray[0] = x_a;
	ray[1] = y_a;
	return (ray);
}

static float		*get_first_h_point(t_player p, float c, double d)
{
	float	*ray;

	ray = ft_calloc(sizeof(float), 2);
	if (d > 0 && d < M_PI)
		ray[1] = (int)p.y + 1;
	else
		ray[1] = (int)p.y;
	c = 0;
	ray[0] = p.x + (ray[1] - p.y) / tan(d);
	return (ray);
}

float		get_wall_h(t_game g, t_ray *r)
{
	int		check;
	float	*const_h;
	float	*ray;
	float	dist;

	check = 0;
	const_h = get_h_const(r->d);
	ray = get_first_h_point(g.p, const_h[1], r->d);
	r->h_x = ray[0];
	r->h_y = ray[1];
	check = check_wall_h(g, ray[0], ray[1]);
	while (check != 1 && ray[0] <= g.set.map_x && ray[1] <= g.set.map_y
			&& ray[0] >= 0 && ray[1] >= 0)
	{
		r->h_x += const_h[0];
		r->h_y += const_h[1];
		check = check_wall_h(g, r->h_x, r->h_y);
	}
	dist = sqrt(pow((g.p.x - r->h_x), 2) + pow((g.p.y - r->h_y), 2));
	dist = cos(g.p.dir - r->d) * dist;
	free(const_h);
	return (dist);
}
