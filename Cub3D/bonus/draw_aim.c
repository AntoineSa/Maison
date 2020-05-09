/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_aim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:23:21 by asablayr          #+#    #+#             */
/*   Updated: 2020/03/11 10:43:10 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	draw_weapon(t_hud h, t_img *img)
{
	int	i;
	int	j;
	int	k;
	int	*p;

	j = 0;
	p = img->d_ptr;
	p += h.offset_y * img->size_l;
	p += h.offset;
	while (j * h.s < h.t.y)
	{
		i = 0;
		while (i * h.s < h.t.x)
		{
			if ((k = get_txt_color(h.t, i * h.s, j * h.s)))
				*p = k;
			i++;
			p++;
		}
		p += img->size_l - i;
		j++;
	}
}

void	draw_cursor(t_img *img)
{
	int	i;
	int	coor[2];
	int	length;
	int	width;

	if (img->x < img->y)
		length = img->x / 20;
	else
		length = img->y / 20;
	width = length / 10;
	i = 0;
	coor[0] = img->x / 2 - length / 2;
	coor[1] = img->y / 2 - width / 2;
	while (i < width)
		draw_line(img, coor[0], coor[1] + i++, length);
	i = 0;
	coor[0] = img->x / 2 - width / 2;
	coor[1] = img->y / 2 - length / 2;
	while (i < length)
		draw_line(img, coor[0], coor[1] + i++, width);
}

void	draw_aim(t_hud h, t_img *img)
{
	int		i[2];
	float	j;
	int		k;
	int		*p;

	j = (float)h.t.x / (float)img->x;
	p = img->d_ptr;
	p += h.offset_y * img->size_l;
	p += h.offset;
	i[1] = 0;
	while (i[1] * h.s < h.t.y)
	{
		i[0] = 0;
		while (i[0] * j < h.t.x)
		{
			if (!(k = get_txt_color(h.t, i[0] * j, i[1] * h.s)))
				*p = 0;
			i[0]++;
			p++;
		}
		p += img->size_l - i[0];
		i[1]++;
	}
}

void	draw_death(t_hud h, t_img *img)
{
	int		i[2];
	float	j;
	int		k;
	int		*p;

	j = (float)h.t.x / ((float)img->x / 2);
	p = img->d_ptr;
	p += h.offset_y * img->size_l;
	p += h.offset;
	i[1] = 0;
	while (i[1] * h.s < h.t.y)
	{
		i[0] = 0;
		while (i[0] * j < h.t.x)
		{
			k = get_txt_color(h.t, i[0] * j, i[1] * h.s);
			*p = k;
			i[0]++;
			p++;
		}
		p += img->size_l - i[0];
		i[1]++;
	}
}
