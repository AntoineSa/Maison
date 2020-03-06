/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:36:58 by asablayr          #+#    #+#             */
/*   Updated: 2020/03/06 09:21:20 by asablayr         ###   ########.fr       */
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
				g->sp[k].x = i + 0.5;
				g->sp[k++].y = j + 0.5;
			}
			i++;
		}
		j++;
	}
}
