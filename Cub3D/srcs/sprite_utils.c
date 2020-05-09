/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
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

int		sp_in_fov(t_player p, t_sprite s)
{
	double	left;
	double	right;
	double	p_l;
	double	p_r;

	left = s.dir - atan(0.5 / sqrt(pow(p.x - s.x, 2) + pow(p.y - s.y, 2)));
	right = s.dir + atan(0.5 / sqrt(pow(p.x - s.x, 2) + pow(p.y - s.y, 2)));
//	reset_dir(&left);
//	reset_dir(&right);
	p_l = p.dir - M_PI / 6;
	p_r = p.dir + M_PI / 6;
	printf("p_l : %f\t< right : %f\tp_r %f\t> left %f\n", p_l, right, p_r, left);
/*	if (p_l < 0)
	{
		p_l += 2 * M_PI;
		right += 2 * M_PI;
	}
	if (p_r > 2 * M_PI)
	{
		p_r -= 2 * M_PI;
		left -= 2 * M_PI;
	}
//	reset_dir(&p_l);
//	reset_dir(&p_r);
*/	printf(" p_l : %f\t< right : %f\tp_r %f\t> left %f\n", p_l, right, p_r, left);
	if (right > p_l || left < p_r)
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
//	reset_dir(&res);
	printf("res : %f\tp : %f\n", res, p.dir);
	return (res);
}
