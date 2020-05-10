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

float	sprite_dist(t_player *p, t_sprite *sp)
{
	float	r;

	r = sqrt(pow(p->x - sp->x, 2) + pow(p->y - sp->y, 2));
	return (cos(p->dir - sp->dir) * r);
}

int		sprite_bite(t_game *g)
{
	int		i;
	float	j;

	i = g->sp_num - 1;
	while (i >= 0)
	{
		j = g->sp[i--].dist;
		if (j > 0 && j < 0.5)
			return (1);
	}
	return (0);
}

int		sp_in_fov(t_player p, t_sprite s)
{
	double	left;
	double	p_l;
	double	right;
	double	p_r;

	p_l = p.dir - M_PI / 6;
	p_r = p.dir + M_PI / 6;
	left = s.dir - atan(0.5 / sqrt(pow(p.x - s.x, 2) + pow(p.y - s.y, 2)));
	right = s.dir + atan(0.5 / sqrt(pow(p.x - s.x, 2) + pow(p.y - s.y, 2)));
	if (right > p_l && left < p_r)
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
	res = atan2(y, x);
	if ((res >= 0 && res <= p.fov) && p.dir > 3 * M_PI_2)
		res += 2 * M_PI;
	else if ((res >= 0 && res <= p.fov) && p.dir > 2 * M_PI - p.fov)
		res += 2 * M_PI;
	else if (res < 0 && p.dir > p.fov)
		res += 2 * M_PI;
	return (res);
}

void	shoot(t_player p, t_game *g)
{
	int			i;
	double		left;
	double		right;
	t_sprite	s;

	i = g->sp_num - 1;
	while (i >= 0)
	{
		s = g->sp[i];
		left = s.dir - atan(0.5 / sqrt(pow(p.x - s.x, 2) + pow(p.y - s.y, 2)));
		right = s.dir + atan(0.5 / sqrt(pow(p.x - s.x, 2) + pow(p.y - s.y, 2)));
		if (right > p.dir && left < p.dir && s.dist > 0 &&
			g->z_buff[(int)(g->set.res_x / 2 * p.fov)] > s.dist)
		{
			g->sp[i].dist = -2;
			return ;
		}
		i--;
	}
}
