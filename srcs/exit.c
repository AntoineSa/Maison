/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:11:43 by asablayr          #+#    #+#             */
/*   Updated: 2020/02/21 12:52:02 by asablayr         ###   ########.fr       */
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

static char	**init_err_msg(void)
{
	char	**msg;

	msg = ft_calloc(sizeof(char *), 5);
	msg[1] = "No file specified.\n";
	msg[2] = "Specified file is not a .cub file.\n";
	msg[3] = "Wrong texture path.\n";
	msg[4] = "Invalid map.\n";
	msg[5] = "No player starting point.\n";
	return (msg);
}


void 		clean_exit(int err, t_game *g)
{
	char	**msg;

	if (err == 0)
	{
		mlx_destroy_image(g->mlx_ptr, g->win_ptr);
	}
	msg = init_err_msg();
	ft_putstr_fd("Error\n", 1);
	if (err > 2)
		map_free(g->set.map);
	ft_putstr_fd(msg[err], 1);
	free(msg);
	exit(0);
}
