/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:25:50 by asablayr          #+#    #+#             */
/*   Updated: 2020/03/10 14:28:37 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <stdio.h>

static void	draw_red_line(t_img i, int x, int y, int dist)
{
	x *= 10;
	while (dist--)
		i.d_ptr[y * i.size_l + x++] = 0xff0000;
}

static void	draw_life(t_game g, t_player p)
{
	int	length;
	int i;

	length = p.life;
	i = 0;
	while (i < 10)
		draw_red_line(g.img, g.set.res_x - 20, i++, length);
}

static void	draw_blue_line(t_img i, int x, int y, int dist)
{
	x *= 10;
	while (dist--)
		i.d_ptr[y * i.size_l + x++] = 0x0000ff;
}

static void	draw_stamina(t_game g, t_player p)
{
	int	length;
	int i;

	length = p.stamina;
	i = 0;
	while (i < 10)
		draw_blue_line(g.img, g.set.res_x - 20, 20 + i++, length);
}

void		draw_hud(t_game g)
{
	draw_life(g, g.p);
	draw_stamina(g, g.p);
}
