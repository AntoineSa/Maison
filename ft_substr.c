/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:28:03 by asablayr          #+#    #+#             */
/*   Updated: 2019/10/10 16:50:59 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
		char	*str;
		int		i;

		str = (char *)malloc(sizeof(str) * len);
		i = 0;
		while (len > 0 && s[start] != '\0')
		{
				str[i] = s[start];
				i++;
				s++;
				len--;
		}
		str[i] = '\0';
		return (str);
}
