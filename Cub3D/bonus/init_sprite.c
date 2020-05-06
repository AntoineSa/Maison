/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:36:58 by asablayr          #+#    #+#             */
/*   Updated: 2020/03/11 13:18:24 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <stdlib.h>

t_sprite	*sort_sprite(t_sprite *sp, int count)
{
	t_sprite	tmp;
	int			i;
	int			j;

	i = 0;
	while (i + 1 < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (sp[i].dist < sp[j].dist)
			{
				tmp = sp[i];
				sp[i] = sp[j];
				sp[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (sp);
}

int			count_sprite(t_settings s)
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

static void	set_sprite(t_sprite *s, int x, int y)
{
	s->x = x + 0.5;
	s->y = y + 0.5;
	s->dist = -1;
	s->dir = 0;
}

void		init_sprite(t_game *g, t_settings s)
{
	int i;
	int j;
	int k;

	g->sp_num = count_sprite(s);
	if (!(g->sp = (t_sprite *)malloc(sizeof(t_sprite) * g->sp_num)))
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
				set_sprite(&(g->sp[k++]), i, j);
				g->set.map[j][i] = '0';
			}
			i++;
		}
		j++;
	}
}
