/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:29:35 by asablayr          #+#    #+#             */
/*   Updated: 2019/10/24 11:16:10 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	check;

	str = (unsigned char *)s;
	check = (unsigned char)c;
	while (n--)
		if (*str++ == check)
			return ((void *)str - 1);
	return (NULL);
}
