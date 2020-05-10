/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:40:44 by asablayr          #+#    #+#             */
/*   Updated: 2020/03/09 11:13:00 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cube.h"

void	look_right(t_player *p, char c)
{
	c = 0;
	p->dir += LOOK_SPEED;
	if (p->dir > 2 * M_PI)
		p->dir -= 2 * M_PI;
}

void	look_left(t_player *p, char c)
{
	c = 0;
	p->dir -= LOOK_SPEED;
	if (p->dir < 0)
		p->dir += 2 * M_PI;
}

void	reset_dir(double *d)
{
	if (*d > 2 * M_PI)
		*d -= 2 * M_PI;
	else if (*d < 0)
		*d += 2 * M_PI;
}
