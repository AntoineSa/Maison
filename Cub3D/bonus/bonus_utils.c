/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:25:50 by asablayr          #+#    #+#             */
/*   Updated: 2020/03/10 14:28:37 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void		draw_icon(t_hud hud, t_img img)
{
	int	i;
	int	j;

	j = 0;
	img.d_ptr += (hud.offset_y) * img.size_l;
	img.d_ptr += (int)(hud.offset - (hud.t.x / hud.s) - 5);
	while (j * hud.s < hud.t.y)
	{
		i = 0;
		while (i * hud.s < hud.t.x)
		{
			*(img.d_ptr++) = get_txt_color(hud.t, i * hud.s, j * hud.s);
			i++;
		}
		img.d_ptr += img.size_l - i;
		j++;
	}
}
