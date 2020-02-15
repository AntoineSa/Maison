/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:18:45 by asablayr          #+#    #+#             */
/*   Updated: 2020/02/15 12:54:12 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <math.h>
#include <stdio.h>

void	move_front(t_player *p, t_game g)
{
	float x;
	float y;

	x = p->x + cos(p->dir) * SPEED;
	y = p->y + sin(p->dir) * SPEED;
	if (g.press.run)
	{
		x += cos(p->dir) * SPEED;
		y += sin(p->dir) * SPEED;
	}
	if (!(check_w(g, x, p->y)))
		p->x = x;
	if (!(check_w(g, p->x, y)))
		p-> y = y;
}
void	move_back(t_player *p, t_game g)
{
	float x;
	float y;

	x = p->x - cos(p->dir) * SPEED;
	y = p->y - sin(p->dir) * SPEED;
	if (g.press.run)
	{
		x -= cos(p->dir) * SPEED;
		y -= sin(p->dir) * SPEED;
	}
	if (!(check_w(g, x, p->y)))
		p->x = x;
	if (!(check_w(g, p->x, y)))
		p-> y = y;
}

void	move_left(t_player *p, t_game g)
{
	float x;
	float y;

	x = p->x + sin(p->dir) * SPEED;
	y = p->y - cos(p->dir) * SPEED;
	if (g.press.run)
	{
		x += sin(p->dir) * SPEED;
		y += cos(p->dir) * SPEED;
	}
	if (!(check_w(g, x, p->y)))
		p->x = x;
	if (!(check_w(g, p->x, y)))
		p-> y = y;
}

void	move_right(t_player *p, t_game g)
{
	float x;
	float y;

	x = p->x - sin(p->dir) * SPEED;
	y = p->y + cos(p->dir) * SPEED;
	if (g.press.run)
	{
		x -= sin(p->dir) * SPEED;
		y -= cos(p->dir) * SPEED;
	}
	if (!(check_w(g, x, p->y)))
		p->x = x;
	if (!(check_w(g, p->x, y)))
		p-> y = y;
}
