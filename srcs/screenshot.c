/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:04:04 by asablayr          #+#    #+#             */
/*   Updated: 2020/02/10 16:54:24 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <mlx.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void	ft_print_char(unsigned char *data, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putnbr_fd(*(data + i), 1);
		i++;
		write(1, " ", 1);
	}
}

void	init_header(t_bmp *b, int size)
{
	b->file_size = size + 54;
	b->pixels_adr = 54;
	b->header_size = 40;
	b->clrs_planes = 1;
	b->bpp = 32;
	b->raw_size = size;
	b->res = 2835;
}

void	create_header(unsigned char *s, t_img i)
{
	t_bmp	b;
	int	size;

	size = i.x * i.y * 4;
	init_header(&b, size);
	s[0] = 'B';
	s[1] = 'M';
/*	ft_memcpy(s + 2, &d_size, sizeof(int));//size bmp (54 + x);
	s[10] = 0x36;
	s[14] = 0x28;
	ft_memcpy(s + 18, &i.x, sizeof(int));
	ft_memcpy(s + 22, &i.y, sizeof(int));
	s[26] = 0x01;//color planes
	s[28] = 0x18;//bpp
	s[30] = 0x0;//compression
	ft_memcpy(s + 34, &size, sizeof(int));
	s[38] = 0x13;
	s[39] = 0x0b;
	s[42] = 0x13;
	s[43] = 0x0b;
*/	ft_memcpy(&s[2], &(b.file_size), sizeof(int));
	ft_memcpy(&s[10], &(b.pixels_adr), sizeof(int));
	ft_memcpy(&s[14], &(b.header_size), sizeof(int));
	ft_memcpy(&s[18], &i.x, sizeof(int));
	ft_memcpy(&s[22], &i.y, sizeof(int));
	ft_memcpy(&s[26], &(b.clrs_planes), sizeof(short));
	ft_memcpy(&s[28], &(b.bpp), sizeof(short));
	ft_memcpy(&s[34], &(b.raw_size), sizeof(int));
	ft_memcpy(&s[38], &(b.res), sizeof(int));
	ft_memcpy(&s[42], &(b.res), sizeof(int));
}

void	create_body(unsigned char *data, t_img i)
{
	int l;
	int j;
	int k;

	j = i.y;
	k = 0;
	while (j >= 0)
	{
		l = 0;
		while (l < i.x)
		{
			ft_memcpy(&data[k], &i.d_ptr[j * (i.size_l / 4) + l], sizeof(int));
			l++;
			k += 4;
		}
		j--;
	}
}

void	screenshot(t_img i)
{
	int	fd;
	int size;
	unsigned char	*h;
	unsigned char	*body;

	fd = open("screenshot.bmp", O_RDWR | O_CREAT, 77777);
	size = i.x * i.y * 4;
	if (fd > 0)
	{
		if (!(h = ft_calloc(54, 1)) || !(body = ft_calloc(size, 1)))
			return ;
		create_header(h, i);
		create_body(body, i);
		write(fd, h, 54);
		ft_print_char(h, 54);
		write(1, "\nbody\n", 6);
		write(fd, body, size);
//		ft_print_char(body, size);
	}
}
