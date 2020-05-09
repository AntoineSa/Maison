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
#include "def.h"
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
	msg[NO_ARG] = "No file specified.\n";
	msg[NOT_CUB] = "Specified file is not a .cub file.\n";
	msg[INV_CUB] = "Invalid .cub file.\n";
	msg[INV_RES] = "Invalid screen resolution.\n";
	msg[INV_PATH] = "Wrong texture path.\n";
	msg[INV_SP] = "Wrong sprite texture path.\n";
	msg[NO_UTI] = "Missing utils textures.\n";
	msg[INV_CLR] = "Invalid color.\n";
	msg[INV_MAP] = "Invalid map.\n";
	msg[NOT_CLS] = "Map not closed sides.\n";
	msg[NO_PLA] = "No player starting point.\n";
	msg[MULT_PLA] = "Multiple player starting point.\n";
	return (msg);
}

int			clean_exit(int err, t_game *g)
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
	if (err > INV_CUB)
		map_free(g->set.map);
	ft_putstr_fd(msg[err], 1);
	free(msg);
	exit(0);
	return (0);
}
