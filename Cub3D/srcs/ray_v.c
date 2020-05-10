/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_v.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:57:04 by asablayr          #+#    #+#             */
/*   Updated: 2020/02/18 19:29:16 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "cube.h"
#include "libft.h"

static int	check_wall_v(t_game *g, float x, float y)
{
	if (g->r.d > M_PI_2 && g->r.d <= 3 * M_PI_2)
		x = x - 1;
	if (x > g->set.map_x - 1)
		x = g->set.map_x - 1;
	else if (x < 0)
		x = 0;
	if (y > g->set.map_y - 1)
		y = g->set.map_y - 1;
	else if (y < 0)
		y = 0;
	return (g->set.map[(int)y][(int)x]);
}

static void	get_v_const(double d, float *ray_x, float *ray_y)
{
	float	x_a;
	float	y_a;

	if (d == M_PI_2 || d == 3 * M_PI_2)
		x_a = 0;
	else if ((d >= 0 && d < M_PI_2) || (d > 3 * M_PI_2 && d <= 2 * M_PI))
		x_a = 1;
	else
		x_a = -1;
	if (d == 0 || d == M_PI)
		y_a = 0;
	else if (d == M_PI_2)
		y_a = 1;
	else if (d == 3 * M_PI_2)
		y_a = -1;
	else if ((d >= 0 && d < M_PI_2) || d > 3 * M_PI_2)
		y_a = tan(d);
	else
		y_a = -tan(d);
	*ray_x = x_a;
	*ray_y = y_a;
}

static void	get_first_v(t_player p, double d, float *ray0, float *ray1)
{
	if (d < M_PI_2 || d > 3 * M_PI_2)
		*ray0 = (int)p.x + 1;
	else
		*ray0 = (int)p.x;
	*ray1 = p.y + (*ray0 - p.x) * tan(d);
}

float		get_wall_v(t_game *g, t_ray *r)
{
	int		check;
	float	const_v[2];
	float	ray[2];
	float	dist;

	get_v_const(r->d, &const_v[0], &const_v[1]);
	get_first_v(g->p, r->d, &ray[0], &ray[1]);
	while ((check = check_wall_v(g, ray[0], ray[1])) != '1' && check != ' ')
	{
		ray[0] += const_v[0];
		ray[1] += const_v[1];
	}
	r->v_x = ray[0];
	r->v_y = ray[1];
	dist = sqrt(pow((g->p.x - ray[0]), 2) + pow((g->p.y - ray[1]), 2));
	dist = cos(g->p.dir - r->d) * dist;
	return (dist);
}
