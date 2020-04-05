/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:28:19 by asablayr          #+#    #+#             */
/*   Updated: 2019/10/23 18:27:12 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *str;
	unsigned char d;

	str = (unsigned char *)b;
	d = (unsigned char)c;
	while (len--)
	{
		*str = d;
		str++;
	}
	return (b);
}
