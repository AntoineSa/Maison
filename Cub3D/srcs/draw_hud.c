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

static void	draw_life(t_game g, t_player p)
{
	int	length;
	int i;

	length = 100 - p.life;
	i = 0;
	while (i > 10)
		draw_line(g.img, g.set.res_x - 20, i++, length);
}

static void	draw_stamina(t_game g, t_player p)
{
	int	length;
	int i;

	length = 100 - p.stamina;
	i = 0;
	while (i > 10)
		draw_line(g.img, g.set.res_x - 20, 20 + i++, length);
}

void		draw_hud(t_game g)
{
	draw_life(g, g.p);
	draw_stamina(g, g.p);
}
