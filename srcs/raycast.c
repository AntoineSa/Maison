/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:51:50 by asablayr          #+#    #+#             */
/*   Updated: 2020/01/28 15:58:56 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cube.h"
#include "libft.h"
#include <stdio.h>

static float		*get_first_h_point(t_player p, float c, double d)
{
	float	*ray;

	ray = ft_calloc(sizeof(float), 2);
	if (p.dir > 0 && p.dir < M_PI)
		ray[1] = (int)p.y + 1;
	else
		ray[1] = (int)p.y;
	if (p.dir == M_PI_2 || p.dir == 3 * M_PI_2)
		ray[0] = p.x;
	else
		ray[0] = p.x + (p.y - c) / tan(d);
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
	ray[1] = p.y + (p.x - c) / tan(d);
	return (ray);
}

static float		get_wall_h(t_player p, t_settings set, double d)
{
	int		check;
	float	*const_h;
	float	*ray;
	float	dist;

	check = 0;
	const_h = get_h_const(d);
	ray = get_first_h_point(p, const_h[1], d);
	check = check_w(d, set, ray[0], ray[1]);
	while (check != 1 && ray[0] <= set.map_x && ray[1] <= set.map_y
			&& ray[0] >= 0 && ray[1] >= 0)
	{
		ray[0] += const_h[0];
		ray[1] += const_h[1];
		check = check_w(d, set, ray[0], ray[1]);
	}
	dist = sqrt(pow((p.x - ray[0]), 2) + pow((p.y - ray[1]), 2));
	return (dist);
}

static float		get_wall_v(t_player p, t_settings set, double d)
{
	int		check;
	float	*const_v;
	float	*ray;
	float	dist;

	check = 0;
	const_v = get_v_const(d);
	ray = get_first_v_point(p, const_v[0], d);
	check = check_w(d, set, ray[0], ray[1]);
	while (check != 1 && ray[0] <= set.map_x && ray[1] <= set.map_y
			&& ray[0] >= 0 && ray[1] >= 0)
	{
		ray[0] += const_v[0];
		ray[1] += const_v[1];
		check = check_w(d, set, ray[0], ray[1]);
	}
	dist = sqrt(pow((p.x - ray[0]), 2) + pow((p.y - ray[1]), 2));
	return (dist);
}

float		get_dist(t_game game, double d)
{
	float	ray_h;
	float	ray_v;

//	reset_dir(&d);
	if (d == 0 || d == M_PI)
		return (get_wall_v(game.p, game.set, d));
	else if (d == M_PI_2 || d == 3 * M_PI_2)
		return (get_wall_h(game.p, game.set, d));
	else
	{
		ray_h = get_wall_h(game.p, game.set, d);
		ray_v = get_wall_v(game.p, game.set, d);
	}
	if (ray_h >= ray_v)
	{
//		printf("v");
		return (ray_v);
	}
	else
	{
//		printf("h");
		return (ray_h);
	}
	//return (ray_h >= ray_v ? ray_v : ray_h);
}

void		raycast(t_game g)
{
	int		j;
	double	i;
	double	d;

	j = 0;
	i = g.p.fov / g.set.res_x;
	d = (g.p.dir - M_PI / 6);
	draw_column(g, get_dist(g, d), j++);
	printf("dir : %f, dist = %f, p_x : %f, p_y : %f\n", g.p.dir, get_dist(g, g.p.dir), g.p.x, g.p.y);
	while (j < g.set.res_x)
	{
		d += i;
		reset_dir(&d);
		draw_column(g, get_dist(g, d), j++);
//		printf("break %d, dist = %f, dir %f p.x : %f, p.y  : %f\n", j, get_dist(g, d), d, g.p.x, g.p.y);
	}
	draw_map(g);
	draw_window(g.img);
}
