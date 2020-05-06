/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:18:45 by asablayr          #+#    #+#             */
/*   Updated: 2020/03/10 11:29:49 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <math.h>

void	move_front(t_player *p, t_game *g)
{
	float x;
	float y;

	x = p->x + cos(p->dir) * SPEED;
	y = p->y + sin(p->dir) * SPEED;
	if (g->press.run && p->stamina > 0)
	{
		x += cos(p->dir) * SPEED;
		y += sin(p->dir) * SPEED;
		p->stamina -= 1;
	}
	if (check_w(g, x, p->y) != 1)
		p->x = x;
	if (check_w(g, p->x, y) != 1)
		p->y = y;
}

void	move_back(t_player *p, t_game *g)
{
	float x;
	float y;

	x = p->x - cos(p->dir) * SPEED;
	y = p->y - sin(p->dir) * SPEED;
	if (g->press.run && p->stamina > 0)
	{
		x -= cos(p->dir) * SPEED;
		y -= sin(p->dir) * SPEED;
		p->stamina -= 1;
	}
	if (check_w(g, x, p->y) != 1)
		p->x = x;
	if (check_w(g, p->x, y) != 1)
		p->y = y;
}

void	move_left(t_player *p, t_game *g)
{
	float x;
	float y;

	x = p->x + sin(p->dir) * SPEED;
	y = p->y - cos(p->dir) * SPEED;
	if (g->press.run && p->stamina > 0)
	{
		x += sin(p->dir) * SPEED;
		y += cos(p->dir) * SPEED;
	}
	if (check_w(g, x, p->y) != 1)
		p->x = x;
	if (check_w(g, p->x, y) != 1)
		p->y = y;
}

void	move_right(t_player *p, t_game *g)
{
	float x;
	float y;

	x = p->x - sin(p->dir) * SPEED;
	y = p->y + cos(p->dir) * SPEED;
	if (g->press.run && p->stamina > 0)
	{
		x -= sin(p->dir) * SPEED;
		y -= cos(p->dir) * SPEED;
	}
	if (check_w(g, x, p->y) != 1)
		p->x = x;
	if (check_w(g, p->x, y) != 1)
		p->y = y;
}
