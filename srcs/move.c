/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:18:45 by asablayr          #+#    #+#             */
/*   Updated: 2020/01/21 17:05:26 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <math.h>
#include <stdio.h>

void	move_front(t_player *p, t_settings s)
{
	float x;
	float y;

	x = p->x + cos(p->dir) * SPEED;
	y = p->y + sin(p->dir) * SPEED;
	if (!(check_w(p->dir, s, x, p->y)))
		p->x = x;
	if (!(check_w(p->dir, s, p->x, y)))
		p-> y = y;
}
void	move_back(t_player *p, t_settings s)
{
	float x;
	float y;

	x = p->x - cos(p->dir) * SPEED;
	y = p->y -sin(p->dir) * SPEED;
	if (!(check_w(p->dir + M_PI, s, x, p->y)))
		p->x = x;
	if (!(check_w(p->dir + M_PI, s, p->x, y)))
		p-> y = y;
}

void	move_left(t_player *p, t_settings s)
{
	float x;
	float y;

	x = p->x + sin(p->dir) * SPEED;
	y = p->y + cos(p->dir) * SPEED;
	if (!(check_w(p->dir + M_PI_2, s, x, p->y)))
		p->x = x;
	if (!(check_w(p->dir + M_PI_2, s, p->x, y)))
		p-> y = y;
}

void	move_right(t_player *p, t_settings s)
{
	float x;
	float y;

	x = p->x - sin(p->dir) * SPEED;
	y = p->y - cos(p->dir) * SPEED;
	if (!(check_w(p->dir, s, x, p->y)))
		p->x = x;
	if (!(check_w(p->dir, s, p->x, y)))
		p-> y = y;
}
