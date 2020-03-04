/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:36:58 by asablayr          #+#    #+#             */
/*   Updated: 2020/03/04 12:38:22 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cube.h"
#include <mlx.h>
#include <math.h>
#include <stdlib.h>

void	put_sprite_to_img(t_sprite sp, t_game g)
{
	t_img	t;
	int		i;
	int		j;

	t = g.txt[4];
	y_txt = t.y / dist;
	while (j > t.y && )
	{
		while (i > t.x)
	}
	g.img.d_ptr[] = get_txt_color();
} //here

int		is_in_fov(t_player p, t_sprite sp, t_game *g)
{
	if (sp.dir < p.dir - M_PI / 6 && sp.dir > p.dir + M_PI / 6)
		if (get_dist(*g, sp.dir, &g->r) < sp.dist)
			return (1);
	return (0);
}

t_sprite	*sort_sprite(t_sprite *sp, int count)
{
	t_sprite	*tmp;
	int			i;
	int			j;

	i = 0;
	tmp = NULL;
	while (i + 1 < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (sp[i].dist > sp[j].dist)
			{
				*tmp = sp[i];
				sp[i] = sp[j];
				sp[j] = *tmp;
			}
			j++;
		}
		i++;
	}
	return (sp);
}

int		count_sprite(t_settings s)
{
	int i;
	int	j;
	int count;

	j = 1;
	count = 0;
	while (s.map[j])
	{
		i = 1;
		while (s.map[j][i])
			if (s.map[j][i++] == '2')
				count++;
		j++;
	}
	return (count);
}

void	init_sprite(t_game *g, t_settings s)
{
	int i;
	int j;
	int k;

	if (!(g->sp = (t_sprite *)malloc(sizeof(t_sprite) * count_sprite(s))))
		return ;
	j = 1;
	k = 0;
	while (s.map[j])
	{
		i = 1;
		while (s.map[j][i])
		{
			if (s.map[j][i] == '2')
			{
				g->sp[k].x = i;
				g->sp[k++].y = j;
			}
			i++;
		}
		j++;
	}
}

static double	sprite_dir(t_player p, t_sprite sp)
{
	float x;
	float y;

	x = sp.x - p.x;
	y = sp.y - p.y;
	return (atan(x / y));
}

static float	sprite_dist(t_player p, t_sprite sp)
{
	float r;

	r  = sqrt(pow(p.x - sp.x, 2) + pow(p.y - sp.y, 2));
	return (r);
}

void	draw_sprite(t_game g)
{
	int i;

	i = 0;
	g.sp_num = count_sprite(g.set);
	while (i < g.sp_num)
	{
		g.sp[i].dir = sprite_dir(g.p, g.sp[i]);
		if (is_in_fov(g.p, g.sp[i], &g))
			g.sp[i].dist = sprite_dist(g.p, g.sp[i]);
		else
			g.sp[i].dist = -1;
		i++;
	}
	sort_sprite(g.sp, g.sp_num);
	i = 0;
	while (g.sp[i].dist >= 0)
		put_sprite_to_img(g.sp[i++]);
}