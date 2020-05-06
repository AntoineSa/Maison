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

static void	draw_red_line(t_img i, int x, int y, int dist)
{
	int	j;

	j = y * i.size_l + x;
	i.d_ptr += j;
	while (dist--)
		*(i.d_ptr++) = 0xff0000;
}

static void	draw_life(t_game g, t_hud hud, int life)
{
	float	length;
	int		i;

	length = (g.set.res_x / 10) * ((float)life / 100);
	i = 0;
	draw_icon(hud, g.img);
	while (i < hud.offset_y)
		draw_red_line(g.img, hud.offset, hud.offset_y + i++, length);
}

static void	draw_blue_line(t_img i, int x, int y, int dist)
{
	int	j;

	j = y * i.size_l + x;
	i.d_ptr += j;
	while (dist--)
		*(i.d_ptr++) = 0x0000ff;
}

static void	draw_stamina(t_game g, t_hud hud, int stamina)
{
	float	length;
	int		i;
	int		width;

	length = (g.set.res_x / 10) * ((float)stamina / 100);
	i = 0;
	width = g.set.res_y / 50;
	draw_icon(hud, g.img);
	while (i < width)
		draw_blue_line(g.img, hud.offset, hud.offset_y + i++, length);
}

void		draw_hud(t_game *g)
{
	draw_map(g);
	draw_life(*g, g->hud[0], g->p.life);
	draw_stamina(*g, g->hud[1], g->p.stamina);
	draw_weapon(g->hud[2], &g->img);
	draw_cursor(&g->img);
}
