/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:29:24 by asablayr          #+#    #+#             */
/*   Updated: 2019/10/23 18:21:55 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str_d;
	unsigned char	*str_s;

	if (!src && !dst)
		return (NULL);
	str_d = (unsigned char *)dst;
	str_s = (unsigned char *)src;
	if (str_d > str_s)
	{
		while (len--)
			str_d[len] = str_s[len];
	}
	else
		ft_memcpy(str_d, str_s, len);
	return (dst);
}
