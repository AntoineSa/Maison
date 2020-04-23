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

void	draw_icon(t_img t, t_img img, int x, int y)
{
	float	s;
	int	i;
	int	j;

	s = (float)t.y / (float)img.index;
	j = 0;
	while (j * s < t.y)
	{
		i = 0;
		img.index = (y + j) * img.size_l;
		img.index += (x - (t.x / s) - 5 + i);
		while (i * s < t.x)
		{
			img.d_ptr[img.index] = get_txt_color(t, i * s, j * s);
			i++;
			img.index++;
		}
		j++;
	}
}

static void	draw_red_line(t_img i, int x, int y, int dist)
{
	while (dist--)
		i.d_ptr[y * i.size_l + x++] = 0xff0000;
}

static void	draw_life(t_game g, t_player p)
{
	float	length;
	int	i;
	int	offset;
	int	offset_y;

	offset = g.set.res_x / 10;//scale to ratio
	offset_y = g.set.res_y / 50;//scale
	length = offset * (p.life / 100);
	i = 0;
	offset = g.set.res_x - (offset + offset / 9);//scale
	g.img.index = offset_y;
	draw_icon(g.txt[7], g.img, offset, offset_y);
	while (i < offset_y)
		draw_red_line(g.img, offset, offset_y + i++, length);
}

static void	draw_blue_line(t_img i, int x, int y, int dist)
{
	while (dist--)
		i.d_ptr[y * i.size_l + x++] = 0x0000ff;
}

static void	draw_stamina(t_game g, t_player p)
{
	int	length;
	int	i;
	int	offset;
	int	offset_y;

	offset = g.set.res_x / 10;//scale to ratio
	offset_y = g.set.res_y / 50;//scale
	length = offset * (p.stamina / 100);
	i = 0;
	offset = g.set.res_x - (offset + offset / 9);//scale
	g.img.index = offset_y;
	draw_icon(g.txt[8], g.img, offset, offset_y * 3);
	while (i < offset_y)
		draw_blue_line(g.img, offset, offset_y * 3 + i++, length);
}

void		draw_hud(t_game g)
{
	draw_map(g);
	draw_life(g, g.p);
	draw_stamina(g, g.p);
}
