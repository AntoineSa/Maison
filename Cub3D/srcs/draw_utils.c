/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 09:16:05 by asablayr          #+#    #+#             */
/*   Updated: 2020/03/10 13:34:52 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <math.h>

unsigned int	get_txt_color(t_img t, int x, int y)
{
	return (t.d_ptr[x + (y * t.size_l)]);
}

t_img			select_text(t_game g)
{
	if (g.r.side == 1)
		return (g.r.d > M_PI ? g.txt[0] : g.txt[2]);
	else
		return (g.r.d > M_PI_2 && g.r.d < 3 * M_PI_2 ? g.txt[1] : g.txt[3]);
}

void			draw_square(t_img img, int c, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j <= img.index)
	{
		i = 0;
		while (i <= img.index)
			img.d_ptr[(j + y) * (img.size_l) + x + i++] = c;
		j++;
	}
}

void			draw_ray(t_img i, t_player p, double dir, int d)
{
	while (d--)
	{
		p.x += cos(dir);
		p.y += sin(dir);
		i.d_ptr[(int)(p.y) * i.size_l + (int)(p.x)] = 0xffffff;
	}
}

void			draw_line(t_img *i, int x, int y, int dist)
{
	int	*img;

	img = i->d_ptr;
	img += y * i->size_l + x;
	while (dist--)
		*(img++) = 0xc0c0c0;
}
