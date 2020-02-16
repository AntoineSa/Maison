/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_v.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:57:04 by asablayr          #+#    #+#             */
/*   Updated: 2020/02/16 11:04:05 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "cube.h"
#include "libft.h"

static int		check_wall_v(t_game g, float x, float y)
{
	if (g.r.d > M_PI_2 && g.r.d <= 3 * M_PI_2)
		x = x - 1;
	if (x > g.set.map_x - 1)
		x = g.set.map_x - 1;
	else if (x < 0)
		x = 0;
	if (y > g.set.map_y - 1)
		y = g.set.map_y - 1;
	else if (y < 0)
		y = 0;
	return (g.set.map[(int)y][(int)x] - '0');
}

static float	*get_v_const(float dir)
{
	float	x_a;
	float	y_a;
	float	*ray;

	ray = ft_calloc(sizeof(float), 2);
	if (dir == M_PI_2 || dir == 3 * M_PI_2)
		x_a = 0;
	else if ((dir >= 0 && dir < M_PI_2) || (dir > 3 * M_PI_2 && dir <= 2 * M_PI))
		x_a = 1;
	else
		x_a = -1;
	if (dir == 0 || dir == M_PI)
		y_a = 0;
	else if (dir == M_PI_2)
		y_a = 1;
	else if (dir == 3 * M_PI_2)
		y_a = -1;
	else if ((dir >= 0 && dir < M_PI_2) || dir > 3 * M_PI_2)
	{
//		y_a = x_a / (1/tan(dir));
		y_a = tan(dir);
	}
	else
	{
//		y_a = -x_a / (1/tan(dir));
		y_a = -tan(dir);
	}
	ray[0] = x_a;
	ray[1] = y_a;
	return (ray);
}

static float		*get_first_v_point(t_player p, float c, double d)
{
	float	*ray;

	ray = ft_calloc(sizeof(float), 2);
	if (p.dir < M_PI_2 || p.dir > 3 * M_PI_2)
		ray[0] = (int)p.x + 1;
	else
		ray[0] = (int)p.x;
	c = 0;
	ray[1] = p.y + (ray[0] - p.x) * tan(d);//nope !!
//	ray[1] = p.y + sin(d);
	return (ray);
}

float				get_wall_v(t_game g, t_ray *r)
{
	int		check;
	float	*const_v;
	float	*ray;
	float	dist;

	check = 0;
	const_v = get_v_const(r->d);
	ray = get_first_v_point(g.p, const_v[0], r->d);
	check = check_wall_v(g, ray[0], ray[1]);
	while (check != 1 && ray[0] <= g.set.map_x && ray[1] <= g.set.map_y
			&& ray[0] >= 0 && ray[1] >= 0)
	{
		ray[0] += const_v[0];
		ray[1] += const_v[1];
		check = check_wall_v(g, ray[0], ray[1]);
	}
	r->v_x = ray[0];
	r->v_y = ray[1];
	dist = sqrt(pow((g.p.x - ray[0]), 2) + pow((g.p.y - ray[1]), 2));
	dist = cos(g.p.dir - r->d) * dist;
	free(const_v);
	return (dist);
}
