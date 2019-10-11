/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:28:19 by asablayr          #+#    #+#             */
/*   Updated: 2019/10/09 12:28:23 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *str;
	unsigned char c_;

	str = (unsigned char *)b;
	c_ = (unsigned char)c;
	while (len > 0)
	{
		*str = c_;
		str++;
		len--;
	}
	return (b);
}
