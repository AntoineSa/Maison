/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 11:20:16 by asablayr          #+#    #+#             */
/*   Updated: 2020/02/22 09:38:17 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

/*static char		*spe_copy(char *str)
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
*/
int	check_map_close(char **map, int x, int y)
{
	char	*cur;

	cur = ft_strchr(map[0], '1');
	map[y][x] = '.';
	if (map[y][x + 1] == '1')
		check_map_close(map, x + 1, y);
	if (map[y + 1][x] == '1')
		check_map_close(map, x, y + 1);
	if (map[y - 1][x] == '1')
		check_map_close(map, x, y - 1);
	if (map[y][x - 1] == '1')
		check_map_close(map, x + 1, y);
	return (
}

int	in_set(char c, char *charset)
{
	while (*charset)
		if (c == *(charset++))
			return (1);
	return (0);
}
static int	check_map_line(char *str, int *width)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
		if (in_set(str[i++], " 012NESW") != '1')
			return (1);
	*width = i;
	return (0);
}

int	backtrack(char **map, char c)
{
	char 	*cur;
	int	x;
	int	y;

	y = 0;
	while (!cur)
		cur = ft_strchr(map[y++], c);
	y--; 
	x = map[y] - cur;
	x1 = ft_strchr(map[y] + x, '1') - cur;
	if (check_map_close(map, x + x1, y)
		return (1);
	if (ft_strnchr(map[y] + x
	x1 = cur - ft_strrchr(map[y] + x, '1');
	if (check_map_close(map, x - x1, y)
		return (1);
	y1 = search y;
}

int	check_map(char **map, int *map_x, int *map_y)
{
	int		i;
	int		length;
	int		width;
	int		tmp;

	i = 0;
	length = 0;
//	width = map[0][1] == ' ' ? (ft_strlen(map[0]) / 2) + 1 : ft_strlen(map[0]);
	width = 0;
	while (map[length])
	{
		if (check_map_line(map[length++], &tmp) != 0)
			return (1);
		if (tmp > width)
			width = tmp;
	}
	if (backtrack(map, c))
		return (2);
	format_char_map(map);
	format_width_map(map, width);
	*map_x = width;
	*map_y = length;
	return (0);
}
