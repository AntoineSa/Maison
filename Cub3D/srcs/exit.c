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
#include <stdio.h>

static void	map_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
}

static char	**init_err_msg(void)
{
	char	**msg;

	msg = ft_calloc(sizeof(char *), 11);
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
	return (msg);
}


int 		clean_exit(int err, t_game *g)
{
	char	**msg;

	printf("err : %d\n", err);
	if (err == 0)
	{
		mlx_destroy_image(g->mlx_ptr, g->win_ptr);
		map_free(g->set.map);
		free(g->z_buff);
		exit(0);
	}
	msg = init_err_msg();
	ft_putstr_fd("Error\n", 1);
	if (err > 2)
		map_free(g->set.map);
	ft_putstr_fd(msg[err], 1);
	free(msg);
	exit(0);
	return (0);
}
