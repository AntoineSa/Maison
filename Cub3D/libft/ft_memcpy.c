/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:28:55 by asablayr          #+#    #+#             */
/*   Updated: 2019/10/23 18:16:08 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *str_d;
	unsigned char *str_s;

	if (!src && !dst)
		return (NULL);
	str_d = (unsigned char *)dst;
	str_s = (unsigned char *)src;
	while (n > 0)
	{
		*str_d = *str_s;
		str_d++;
		str_s++;
		n--;
	}
	return (dst);
}
