/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 11:20:16 by asablayr          #+#    #+#             */
/*   Updated: 2020/02/16 11:17:13 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static char		*spe_copy(char *str)
{
	char	*s;
	char	*s1;
	int		i;
	int		j;
	
	if (!(s = (char *)malloc(sizeof(char) * ft_strlen(str))))
		return (NULL);
	i = 0;
	j = 0;
	while (str[j])
	{
		if (str[j] != ' ')
			s[i++] = str[j];
		j++;
	}
	s[i] = '\0';
	s1 = ft_strdup(s);
	free(s);
	free(str);
	return (s1);
}

int	in_set(char c, char *charset)
{
	while (*charset)
		if (c == *(charset++))
			return (1);
	return (0);
}

static int	check_map_line(char *str, int width)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[1] == ' ')
			str = spe_copy(str);
		if (in_set(str[i++], "012NESW") != 1)
			return (1);
	}
	if (i != width)
		return (1);
	return (0);
}

int	check_map(char **map, int *map_x, int *map_y)
{
	int		i;
	int		length;
	int		width;

	i = 0;
	length = 0;
	width = map[0][1] == ' ' ? (ft_strlen(map[0]) / 2) + 1 : ft_strlen(map[0]);
	while (map[length])
		if (check_map_line(map[length++], width) != 0)
			return (1);
	width = 0;
	while (map[0][width])
		width++;
	while (map[0][i])
		if (map[0][i++] != '1')
			return (1);
	i = 0;
	while (map[length - 1][i])
		if (map[length - 1][i++] != '1')
			return (1);
	i = 1;
	while (i < length - 1)
		if (map[i][0] != '1' || map[i++][width - 1] != '1')
			return (1);
	*map_x = width;
	*map_y = length;
	return (0);
}
