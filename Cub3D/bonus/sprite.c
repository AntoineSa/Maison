/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 11:20:16 by asablayr          #+#    #+#             */
/*   Updated: 2020/03/12 20:12:52 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cube.h"

float	sprite_dist(t_player p, t_sprite sp)
{
	float	r;

	r = sqrt(pow(p.x - sp.x, 2) + pow(p.y - sp.y, 2));
	return (cos(p.dir - sp.dir) * r);
}

int		sprite_bite(t_game *g)
{
	int		i;
	float	j;

	i = g->sp_num;
	while (i > 0)
	{
		j = g->sp[i--].dist;
		if (j > 0 && j < 0.5)
			return (1);
	}
	return (0);
}

int		sp_in_fov(t_player p, t_sprite sp)
{
	double	left;
	double	right;

	left = sp.dir - atan(sp.dist / (sp.x / 2));
	right = sp.dir + atan(sp.dist / (sp.x / 2));
	if (right > p.dir - M_PI / 6 && left < p.dir + M_PI / 6)
		return (1);
	return (0);
}

double	sprite_dir(t_player p, t_sprite sp)
{
	float	x;
	float	y;
	double	res;

	x = sp.x - p.x;
	y = sp.y - p.y;
	if (x == 0)
		return (y >= 0 ? M_PI_2 : 3 * M_PI_2);
	else if (y == 0)
		return (x >= 0 ? 0 : M_PI);
	res = atan2(y, x);
	reset_dir(&res);
	return (res);
}

void	shoot(t_player p, t_game *g)
{
	int			i;
	double		left;
	double		right;
	t_sprite	s;

	i = 0;
	while (i < g->sp_num)
	{
		s = g->sp[i];
		left = s.dir - atan(s.dist / (s.x / 2));
		right = s.dir + atan(s.dist / (s.x / 2));
		if (right > p.dir && left < p.dir && s.dist > 0 &&
			g->z_buff[(int)(g->set.res_x / 2 * p.fov)] > s.dist)
			g->sp[i].dist = -2;
		i++;
	}
}
