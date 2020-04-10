/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:09:01 by asablayr          #+#    #+#             */
/*   Updated: 2019/10/14 17:17:56 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	src_size;

	src_size = ft_strlen(src);
	if (src_size + 1 < dst_size)
		ft_memcpy(dst, src, src_size + 1);
	else if (dst_size)
	{
		ft_memcpy(dst, src, dst_size - 1);
		dst[dst_size] = '\0';
	}
	return (src_size);
}
