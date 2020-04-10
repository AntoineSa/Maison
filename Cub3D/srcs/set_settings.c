/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:41:19 by asablayr          #+#    #+#             */
/*   Updated: 2020/02/23 12:46:01 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int		convert_color(int *rgb)
{
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

void	get_color(int *set, char *str)
{
	set[0] = ft_atoi(++str);
	while (*str != ',')
		str++;
	set[1] = ft_atoi(++str);
	while (*str != ',')
		str++;
	set[2] = ft_atoi(++str);
}

char	*get_text(char *str)
{
	while (*str == ' ')
			str++;
	return (ft_strdup(str));
}

void	get_res(int *res_x, int *res_y, char *str)
{
		*res_x = ft_atoi(++str);
		while (*str == ' ')
			str++;
		while (*str >= '0' && *str <= '9')
			str++;
		*res_y = ft_atoi(str);
}

void	init_set(t_settings *set)
{
	if (!(set->rgb_f = (int*)malloc(sizeof(int) * 3)))
		return ;
	if (!(set->rgb_c = (int*)malloc(sizeof(int) * 3)))
		return ;
	set->res_x = 320;
	set->res_y = 200;
	set->t_n = "../textures/t_n";
	set->t_e = "../textures/t_e";
	set->t_s = "../textures/t_s";
	set->t_w = "../textures/t_w";
	set->t_sp = "../textures/t_sp";
	set->rgb_f[0] = 116;
	set->rgb_f[1] = 102;
	set->rgb_f[2] = 59;
	set->rgb_c[0] = 135;
	set->rgb_c[1] = 206;
	set->rgb_c[2] = 235;
}
