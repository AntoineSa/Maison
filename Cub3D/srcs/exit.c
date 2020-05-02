/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:11:43 by asablayr          #+#    #+#             */
/*   Updated: 2020/03/12 19:05:29 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <stdlib.h>
#include <mlx.h>

static void	map_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
}

static void	txt_free(t_game *g)
{
	mlx_destroy_image(g->mlx_ptr, g->hud[0].t.ptr);
	mlx_destroy_image(g->mlx_ptr, g->hud[1].t.ptr);
	mlx_destroy_image(g->mlx_ptr, g->hud[2].t.ptr);
	mlx_destroy_image(g->mlx_ptr, g->hud[3].t.ptr);
	mlx_destroy_image(g->mlx_ptr, g->hud[4].t.ptr);
	mlx_destroy_image(g->mlx_ptr, g->txt[0].ptr);
	mlx_destroy_image(g->mlx_ptr, g->txt[1].ptr);
	mlx_destroy_image(g->mlx_ptr, g->txt[2].ptr);
	mlx_destroy_image(g->mlx_ptr, g->txt[3].ptr);
	mlx_destroy_image(g->mlx_ptr, g->txt[4].ptr);
	mlx_destroy_image(g->mlx_ptr, g->txt[5].ptr);
	mlx_destroy_image(g->mlx_ptr, g->txt[6].ptr);
	mlx_destroy_image(g->mlx_ptr, g->txt[7].ptr);
	mlx_destroy_image(g->mlx_ptr, g->txt[8].ptr);
	mlx_destroy_image(g->mlx_ptr, g->txt[9].ptr);
	mlx_destroy_image(g->mlx_ptr, g->img.ptr);
}

static char	**init_err_msg(void)
{
	char	**msg;

	if (!(msg = ft_calloc(sizeof(char *), 14)))
		return (NULL);
	msg[1] = "No file specified.\n";
	msg[2] = "Specified file is not a .cub file.\n";
	msg[3] = "Invalid screen resolution.\n";
	msg[4] = "Wrong texture path.\n";
	msg[5] = "Wrong sprite texture path.\n";
	msg[6] = "Invalid color.\n";
	msg[7] = "Invalid map.\n";
	msg[8] = "Map not closed sides.\n";
	msg[9] = "Map not closed top/bottom.\n";
	msg[10] = "Map not closed south.\n";
	msg[11] = "No player starting point.\n";
	msg[12] = "Multiple player starting point.\n";
	msg[13] = "Missing utils textures.\n";
	msg[14] = "Invalid screen resolution.\n";
	return (msg);
}


int 		clean_exit(int err, t_game *g)
{
	char	**msg;

	if (err == 0)
	{
		txt_free(g);
		map_free(g->set.map);
		free(g->z_buff);
		exit(0);
	}
	msg = init_err_msg();
	ft_putstr_fd("Error\n", 1);
	if (err > 2)
		map_free(g->set.map);
	if (err == 14)
	mlx_destroy_image(g->mlx_ptr, g->img.ptr);
	ft_putstr_fd(msg[err], 1);
	free(msg);
	exit(0);
	return (0);
}
