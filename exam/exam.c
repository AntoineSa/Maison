#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>

int ft_strlen(char* str)
{
	int i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	ft_strncpy(char* src, int length, char* dst, size_t n)
{
	int i = 0;
	while (i < length && src[i])
	{
		dst[n + i] = src[i];
		i++;
	}
	dst[n + i] = 0;
}

void	ft_strcpy(char* src, char* dst, size_t n)
{
	int i = 0;
	int j = ft_strlen(src);
	while (i < j)
	{
		dst[n + i] = src[i];
		i++;
	}
	dst[n + i] = 0;
}

char**	ft_split_whitespace(char* str)
{
	char**	words = 0;
	int i = 0;
	int j = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			str++;
		while (str[i] && !(str[i] == ' ' || str[i] == '\t'))
			i++;
		words = realloc(words, sizeof(char*) * (++j + 1));
		words[j - 1] = calloc(1, i);
		ft_strncpy(str, i, words[j - 1], 0);
		str += i;
		i = 0;
	}
	words[j] = 0;
	return (words);
}


char**	ft_split_line(char* words)
{
	char**	lines = (void*)0;
	int i = 0;
	int j = 0;

	while (words[i])
	{
		while (words[i] == '\n')
			words++;
		while (words[i] && words[i] != '\n')
			i++;
		lines = realloc(lines, sizeof(char*)* (j + 2));
		lines[j] = calloc(sizeof(char), i + 1);
		ft_strncpy(words, i, lines[j], 0);
		words += i;
		j++;
		i = 0;
	}
	lines[j] = 0;
	printf("i : %i\n", j);
	return (lines);
}

int	ft_atoi(char* str)
{
	int res = 0;
	int	neg = 0;
	if (!str)
		return (0);
	if (*str == '-')
	{
		neg = 1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		res *= 10;
		res += *str - '0';
		str++;
	}
	if (neg)
		res *= -1;
	return (res);
}

float	ft_atof(char* str)
{
	float res = 0;
	int	neg = 0;
	float div = 1;
	if (*str == '-')
	{
		neg = 1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		res *= 10;
		res += *str - '0';
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (*str && *str >= '0' && *str <= '9')
		{
			div /= 10;
			res += (*str - '0') * div;
			str++;
		}
	}
	if (neg)
		res *= -1;
	return (res);
}

char* get_file(FILE* file)
{
	int		size = 1;
	int		mult = 2;
	int 	ret = 0;
	char*	big_buff = 0;
	char	small_buff[20 + 1];
	bzero(small_buff, 21);
	while((ret = fread(small_buff, sizeof(char), 20, file)) >  0)
	{
		size += ret;
		if (big_buff == 0)
		{
			big_buff = calloc(1, size);
			ft_strncpy(small_buff, ret, big_buff, 0);
		}
		else
		{
			big_buff = realloc(big_buff, size);
			ft_strncpy(small_buff, ret, big_buff, ft_strlen(big_buff));
		}
	}
	fclose(file);
	return (big_buff);
}

void	draw(char full, float pos_x, float pos_y, float width, float height, char c)
{
	printf("full : %c\n", full);
	printf("pos_x : %f\n", pos_x);
	printf("pos_y : %f\n", pos_y);
	printf("width : %f\n", width);
	printf("height : %f\n", height);
	printf("char : %c\n", c);
}

int parse_file(char* file)
{
	char	**lines = ft_split_line(file);
	char	**line = ft_split_whitespace(lines[0]);
	int		i = 1;
	int j = 0;

	while(lines[j])
	{
		printf("ok\n");
		j++;
	}

	if (ft_atoi(line[0]) <= 0 || ft_atoi(line[0]) > 300)
	{
		free(line);
		free(lines);
		return (1);
	}
	if (ft_atoi(line[1]) <= 0 || ft_atoi(line[1]) > 300)
	{
		free(line);
		free(lines);
		return (1);
	}
	free(line);
	while (lines[i])
	{
		line = ft_split_whitespace(lines[i]);
		printf("line: %s\n", lines[i]);
		if (*line[0] != 'r' && *line[0] != 'R')
			return (1);
		if (ft_atof(line[3]) <= 0)
			return (1);
		if (ft_atof(line[4]) <= 0)
			return (1);
		draw(*line[0], ft_atof(line[1]), ft_atof(line[2]), ft_atof(line[3]), ft_atof(line[4]), *line[5]);
		free(line);
		i++;
	}
	free(lines);
	return (0);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "Error: argument\n", ft_strlen("Error: argument\n"));
		return (0);
	}
    FILE * file = fopen(av[1], "r");
    if (file == 0 || parse_file(get_file(file)))
	{
		write(1, "Error: Operation file corrupted\n", ft_strlen("Error: Operation file corrupted\n"));
		return (1);
	}
	
	return (0);
}
