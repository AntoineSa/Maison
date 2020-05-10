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

static int	check_wall_h(t_game *g, float x, float y)
{
	if (g->r.d > M_PI && g->r.d <= 2 * M_PI)
		y = y - 1;
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

static void	get_h_const(float dir, float *ray_x, float *ray_y)
{
	float	x_a;
	float	y_a;

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
	*ray_x = x_a;
	*ray_y = y_a;
}

static void	get_first_h(t_player p, double d, float *ray_x, float *ray_y)
{
	if (d > 0 && d < M_PI)
		*ray_y = (int)p.y + 1;
	else
		*ray_y = (int)p.y;
	*ray_x = p.x + (*ray_y - p.y) / tan(d);
}

float		get_wall_h(t_game *g, t_ray *r)
{
	int		check;
	float	const_h[2];
	float	ray[2];
	float	dist;

	get_h_const(r->d, &const_h[0], &const_h[1]);
	get_first_h(g->p, r->d, &ray[0], &ray[1]);
	while ((check = check_wall_h(g, ray[0], ray[1])) != '1' && check != ' ')
	{
		ray[0] += const_h[0];
		ray[1] += const_h[1];
	}
	r->h_x = ray[0];
	r->h_y = ray[1];
	dist = sqrt(pow((g->p.x - r->h_x), 2) + pow((g->p.y - r->h_y), 2));
	return (dist);
}
