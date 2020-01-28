/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 12:16:33 by asablayr          #+#    #+#             */
/*   Updated: 2020/01/20 14:28:10 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <math.h>
#include <stdlib.h>

static double		set_dir(char c)
{
	double	dir;

	if (c == 'N')
		dir = 3 * M_PI_2;
	else if (c == 'E')
		dir = 0;
	else if (c == 'S')
		dir = M_PI_2;
	else
		dir = M_PI;
	return (dir);
}
	
static int			get_pos_player(char **map, int *i, int *j)
{
	while (map[*i])
	{
		*j = 1;
		while (map[*i][*j])
		{
			if (in_set(map[*i][*j], "NESW"))
				return (1);
			(*j)++;
		}
		(*i)++;
	}
	return (0);
}

void			init_player(t_player *p, t_settings set)
{
	int			i;
	int			j;

	i = 1;
	j = 1;
	if (!(get_pos_player(set.map, &i, &j)))
		return ;
//		clean_exit(4);
	p->x = j + 0.5;
	p->y = i + 0.5;
	p->dir = set_dir(set.map[i][j]);
	p->fov = M_PI / 3;
}
