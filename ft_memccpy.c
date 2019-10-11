/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:29:07 by asablayr          #+#    #+#             */
/*   Updated: 2019/10/10 09:48:01 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*str_d;
	char			*str_s;
	unsigned char	check;

	str_d = (char *)dst;
	str_s = (char *)src;
	check = (unsigned char)c;
	while (n > 0 && *str_s != check)
	{
		*str_d = *str_s;
		str_d++;
		str_s++;
		n--;
	}
	if (n == 0)
		return (NULL);
	else if (*str_s == check)
		*str_d = *str_s;
	return (str_d + 1);
}
